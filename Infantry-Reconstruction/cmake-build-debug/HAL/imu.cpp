//
// Created by moon misty on 2019/9/16.
//

#include "../USER/stm32f4xx.h"

//以下声明的四个数组 用于巴特沃斯滤波
float IIR_b[5] = {0.0009,    0.0037,    0.0056,    0.0037,    0.0009};
float IIR_a[5] = {1.0000,   -2.9768 ,   3.4223,   -1.7861,    0.3556};
float xBuf[6][5] = {0};
float yBuf[6][5] = {0};


//计算静态误差
float Gyro_z_err = 0.0f;
float Gyro_x_err = 0.0f;
float Gyro_y_err = 0.0f;
GyroCaliStruct_t GyroSavedCaliData;//gyro offset data

//处理角度值
volatile float Yaw_angle_sum_gz = 0;
volatile float Pitch_angle_sum_gx = 0;



//得到的数据
volatile float mygetqval[6];	//用于存放传感器转换结果的数组
volatile packed_angle real_angle = {0, 0, 0, 0};


#define MPU6500_DATA_READY_EXIT_INIT() IMU_INT_Configure() //初始化mpu6500的 外部中断 使用PB8 外部中断线 8
#define MPU6500_DATA_READY_EXIT_IRQHandler EXTI9_5_IRQHandler //宏定义外部中断函数，使用了line8外部中断
#define MPU6500_DATA_READY_EXIT_Line EXTI_Line8 //宏定义外部中断线
//宏定义初始化SPI的DMA，同时设置SPI为8位，4分频
#define MPU6500_SPI_DMA_Init(txbuf, rxbuf)                                 \
    {                                                                      \
        SPI5_DMA_Init((uint32_t)txbuf, (uint32_t)rxbuf, DMA_RX_NUM);       \
        SPI_I2S_DMACmd(SPI5, SPI_I2S_DMAReq_Rx, ENABLE);                   \
        SPI_I2S_DMACmd(SPI5, SPI_I2S_DMAReq_Tx, ENABLE);                   \
        SPI5SetSpeedAndDataSize(SPI_BaudRatePrescaler_8, SPI_DataSize_8b); \
    }

#define MPU6500_SPI_DMA_Enable() SPI5_DMA_Enable(DMA_RX_NUM) // 开始一次SPI的DMA传输
//宏定义SPI的DMA传输中断函数以及传输中断标志位
#define MPU6500_DMA_IRQHandler DMA2_Stream5_IRQHandler
#define MPU6500_DMA_Stream DMA2_Stream5
#define MPU6500_DMA_FLAG DMA_FLAG_TCIF5
//DMA的SPI 发送的buf，以INT_STATUS开始连续读取 DMA_RX_NUM大小地址的值
static const uint8_t mpu6500_spi_DMA_txbuf[DMA_RX_NUM] =
        {
                MPU_INT_STATUS | MPU_SPI_READ_MSB};

static uint8_t mpu6500_spi_rxbuf[DMA_RX_NUM]; //保存接收的原始数据
static mpu6500_real_data_t mpu6500_real_data; //转换为MPU6500数据


void IMU_Configure()
{
    MPU6500_DATA_READY_EXIT_INIT();
    MPU6500_SPI_DMA_Init(mpu6500_spi_DMA_txbuf, mpu6500_spi_rxbuf);
}


//中断线配置
void IMU_INT_Configure()  //涉及到DMA中断，这里不做深究。
{
    NVIC_InitTypeDef NVIC_InitStructure;
    EXTI_InitTypeDef EXTI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource8);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    EXTI_InitStructure.EXTI_Line = EXTI_Line8;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void IMU_EXIT_STOP()
{
    NVIC_InitTypeDef   NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void IMU_EXIT_START()
{
    NVIC_InitTypeDef   NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void MPU6500_DATA_READY_EXIT_IRQHandler(void)
{
    if (EXTI_GetITStatus(MPU6500_DATA_READY_EXIT_Line) != RESET)
    {

        EXTI_ClearITPendingBit(MPU6500_DATA_READY_EXIT_Line);

//如果开启DMA传输 唤醒任务由DMA中断完成
        mpu6500_SPI_NS_L();
        MPU6500_SPI_DMA_Enable();

    }
}

void MPU6500_DMA_IRQHandler(void)
{
    if (DMA_GetFlagStatus(MPU6500_DMA_Stream, MPU6500_DMA_FLAG))
    {
        DMA_ClearFlag(MPU6500_DMA_Stream, MPU6500_DMA_FLAG);
        mpu6500_SPI_NS_H();
        //数据处理
        mpu6500_read_over((mpu6500_spi_rxbuf + MPU6500_RX_BUF_DATA_OFFSET), &mpu6500_real_data);
        IIRLowPass(mpu6500_real_data.accel[0],mpu6500_real_data.accel[1],mpu6500_real_data.accel[2],mpu6500_real_data.gyro[0],mpu6500_real_data.gyro[1],mpu6500_real_data.gyro[2]);

        mygetqval[3] = (yBuf[3][0] - GyroSavedCaliData.GyroXOffset) / 32.8f - Gyro_x_err;
        mygetqval[4] = (yBuf[4][0] - GyroSavedCaliData.GyroYOffset) / 32.8f - Gyro_y_err;
        mygetqval[5] = (yBuf[5][0] - GyroSavedCaliData.GyroZOffset) / 32.8f - Gyro_z_err;



        //角度
        //Yaw
        Yaw_angle_sum_gz += (-mygetqval[5]) / 1000.0f;
        real_angle.yaw = Yaw_angle_sum_gz + 90.0f;
        //Pitch
        Pitch_angle_sum_gx += (-mygetqval[3]) / 1000.0f;
        real_angle.pitch = Pitch_angle_sum_gx + 90.0f;
        //角速度
        real_angle.gx = -mygetqval[3];
        real_angle.gz = -mygetqval[5];


    }
}


void IIRLowPass(float ax, float ay, float az, float gx, float gy, float gz)//巴特沃兹滤波
{
    int i;
//运算之前Buf向前移动一个位置，以保存之前Buf的数据；
    for(i	=	4; i	>	0; i--)
    {
        yBuf[0][i] = yBuf[0][i-1];
        xBuf[0][i] = xBuf[0][i-1];
        yBuf[1][i] = yBuf[1][i-1];
        xBuf[1][i] = xBuf[1][i-1];
        yBuf[2][i] = yBuf[2][i-1];
        xBuf[2][i] = xBuf[2][i-1];
        yBuf[3][i] = yBuf[3][i-1];
        xBuf[3][i] = xBuf[3][i-1];
        yBuf[4][i] = yBuf[4][i-1];
        xBuf[4][i] = xBuf[4][i-1];
        yBuf[5][i] = yBuf[5][i-1];
        xBuf[5][i] = xBuf[5][i-1];
    }
    xBuf[0][0] = ax;
    yBuf[0][0] = 0;
    xBuf[1][0] = ay;
    yBuf[1][0] = 0;
    xBuf[2][0] = az;
    yBuf[2][0] = 0;
    xBuf[3][0] = gx;
    yBuf[3][0] = 0;
    xBuf[4][0] = gy;
    yBuf[4][0] = 0;
    xBuf[5][0] = gz;
    yBuf[5][0] = 0;

    for(i = 1; i < 5; i++)
    {
        yBuf[0][0] = yBuf[0][0] + IIR_b[i] * xBuf[0][i];
        yBuf[0][0] = yBuf[0][0] - IIR_a[i] * yBuf[0][i];
        yBuf[1][0] = yBuf[1][0] + IIR_b[i] * xBuf[1][i];
        yBuf[1][0] = yBuf[1][0] - IIR_a[i] * yBuf[1][i];
        yBuf[2][0] = yBuf[2][0] + IIR_b[i] * xBuf[2][i];
        yBuf[2][0] = yBuf[2][0] - IIR_a[i] * yBuf[2][i];
        yBuf[3][0] = yBuf[3][0] + IIR_b[i] * xBuf[3][i];
        yBuf[3][0] = yBuf[3][0] - IIR_a[i] * yBuf[3][i];
        yBuf[4][0] = yBuf[4][0] + IIR_b[i] * xBuf[4][i];
        yBuf[4][0] = yBuf[4][0] - IIR_a[i] * yBuf[4][i];
        yBuf[5][0] = yBuf[5][0] + IIR_b[i] * xBuf[5][i];
        yBuf[5][0] = yBuf[5][0] - IIR_a[i] * yBuf[5][i];
    }
    yBuf[0][0] = yBuf[0][0] + IIR_b[0] * xBuf[0][0];
    yBuf[1][0] = yBuf[1][0] + IIR_b[0] * xBuf[1][0];
    yBuf[2][0] = yBuf[2][0] + IIR_b[0] * xBuf[2][0];
    yBuf[3][0] = yBuf[3][0] + IIR_b[0] * xBuf[3][0];
    yBuf[4][0] = yBuf[4][0] + IIR_b[0] * xBuf[4][0];
    yBuf[5][0] = yBuf[5][0] + IIR_b[0] * xBuf[5][0];
}

void MPU6050_Calibration()//算静差值
{
    for(int i = 0; i < 6; i++)
    {
        OFFSET_Buffer[i] = 0.0f;
    }
    int16_t gx,gy,gz;
    int16_t gz_sum = 0,gy_sum = 0,gx_sum = 0;
    float gz_sum_f = 0, gx_sum_f = 0, gy_sum_f = 0;
    int16_t z_max = 0, z_min = 32767;
    int16_t x_max = 0, x_min = 32767;
    int16_t y_max = 0, y_min = 32767;
    for(int i = 0; i < 20; i++)
    {
        mpu6500_read_muli_reg(MPU_INT_STATUS, mpu6500_spi_rxbuf, DMA_RX_NUM);
        gx=(((int16_t)mpu6500_spi_rxbuf[9]) << 8) | mpu6500_spi_rxbuf[10];
        gy=(((int16_t)mpu6500_spi_rxbuf[11]) << 8) | mpu6500_spi_rxbuf[12];
        gz=(((int16_t)mpu6500_spi_rxbuf[13]) << 8) | mpu6500_spi_rxbuf[14];
        delay_us(1000);
        if(gz > z_max)
            z_max = gz;
        else if(gz < z_min)
            z_min = gz;
        if(gx > x_max)
            x_max = gx;
        else if(gx < x_min)
            x_min = gx;
        if(gy > y_max)
            y_max = gy;
        else if(gy < y_min)
            y_min = gy;
    }

    OFFSET_Buffer[0] = (int16_t)(x_max+x_min)/2;
    OFFSET_Buffer[1] = (int16_t)(y_max+y_min)/2;
    OFFSET_Buffer[2] = (int16_t)(z_max+z_min)/2;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            mpu6500_read_muli_reg(MPU_INT_STATUS, mpu6500_spi_rxbuf, DMA_RX_NUM);
            gx=(((int16_t)mpu6500_spi_rxbuf[9]) << 8) | mpu6500_spi_rxbuf[10];
            gy=(((int16_t)mpu6500_spi_rxbuf[11]) << 8) | mpu6500_spi_rxbuf[12];
            gz=(((int16_t)mpu6500_spi_rxbuf[13]) << 8) | mpu6500_spi_rxbuf[14];

            gz_sum = gz_sum + gz - OFFSET_Buffer[2];
            gy_sum = gy_sum +gy - OFFSET_Buffer[1];
            gx_sum = gx_sum +gx - OFFSET_Buffer[0];
            delay_us(500);
        }

        if(gz_sum>0)
            OFFSET_Buffer[2] += ((20-i)/2+1);
        else if(gz_sum<0)
            OFFSET_Buffer[2] -= ((20-i)/2+1);
        gz_sum = 0;

        if(gx_sum>0)
            OFFSET_Buffer[0] += ((20-i)/2+1);
        else if(gx_sum<0)
            OFFSET_Buffer[0] -= ((20-i)/2+1);
        gx_sum = 0;

        if(gy_sum>0)
            OFFSET_Buffer[1] += ((20-i)/2+1);
        else if(gy_sum<0)
            OFFSET_Buffer[1] -= ((20-i)/2+1);
        gy_sum = 0;


    }
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            mpu6500_read_muli_reg(MPU_INT_STATUS, mpu6500_spi_rxbuf, DMA_RX_NUM);
            gx=(((int16_t)mpu6500_spi_rxbuf[9]) << 8) | mpu6500_spi_rxbuf[10];
            gy=(((int16_t)mpu6500_spi_rxbuf[11]) << 8) | mpu6500_spi_rxbuf[12];
            gz=(((int16_t)mpu6500_spi_rxbuf[13]) << 8) | mpu6500_spi_rxbuf[14];

            gx_sum_f += ((float)(gx - OFFSET_Buffer[0])/32.8f - OFFSET_Buffer[3]);
            gy_sum_f += ((float)(gy - OFFSET_Buffer[1])/32.8f - OFFSET_Buffer[4]);
            gz_sum_f += ((float)(gz - OFFSET_Buffer[2])/32.8f - OFFSET_Buffer[5]);
            delay_us(500);
        }

        if(gz_sum_f>0)
            OFFSET_Buffer[5] += 0.0011f*((float)(20-i)/2.0f);
        else if(gz_sum_f<0)
            OFFSET_Buffer[5] -= 0.0012f*((float)(20-i)/2.0f);
        gz_sum_f = 0;

        if(gx_sum_f>0)
            OFFSET_Buffer[3] += 0.0011f*((float)(20-i)/2.0f);
        else if(gx_sum_f<0)
            OFFSET_Buffer[3] -= 0.0012f*((float)(20-i)/2.0f);
        gx_sum_f = 0;

        if(gy_sum_f>0)
            OFFSET_Buffer[4] += 0.0011f*((float)(20-i)/2.0f);
        else if(gy_sum_f<0)
            OFFSET_Buffer[4] -= 0.0012f*((float)(20-i)/2.0f);
        gy_sum_f = 0;
    }
}
