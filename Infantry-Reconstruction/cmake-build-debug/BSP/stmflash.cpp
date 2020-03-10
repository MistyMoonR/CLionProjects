//
// Created by moon misty on 2019/9/27.
//

#include "stmflash.h"


float OFFSET_Buffer[6] = {0, 0, 0, 0, 0, 0};
#define OFFSET_LENGTH sizeof(OFFSET_Buffer)
#define SIZE OFFSET_LENGTH / 4 + ((OFFSET_LENGTH%4)?1:0)

#define FLASH_SAVE_ADDR  0X08010004			//存入扇区4 代码内存 < 64k



u32 STMFLASH_ReadWord(u32 faddr)
{
    return *(vu32*)faddr;
}
//获取某个地址所在的flash扇区
//addr:flash地址
//返回值:0~11,即addr所在的扇区

uint16_t STMFLASH_GetFlashSector(u32 addr)
{
    if(addr<ADDR_FLASH_SECTOR_1)return FLASH_Sector_0;
    else if(addr<ADDR_FLASH_SECTOR_2)return FLASH_Sector_1;
    else if(addr<ADDR_FLASH_SECTOR_3)return FLASH_Sector_2;
    else if(addr<ADDR_FLASH_SECTOR_4)return FLASH_Sector_3;
    else if(addr<ADDR_FLASH_SECTOR_5)return FLASH_Sector_4;
    else if(addr<ADDR_FLASH_SECTOR_6)return FLASH_Sector_5;
    else if(addr<ADDR_FLASH_SECTOR_7)return FLASH_Sector_6;
    else if(addr<ADDR_FLASH_SECTOR_8)return FLASH_Sector_7;
    else if(addr<ADDR_FLASH_SECTOR_9)return FLASH_Sector_8;
    else if(addr<ADDR_FLASH_SECTOR_10)return FLASH_Sector_9;
    else if(addr<ADDR_FLASH_SECTOR_11)return FLASH_Sector_10;
    return FLASH_Sector_11;
}
//从指定地址开始写入指定长度的数据
//特别注意:因为STM32F4的扇区实在太大,没办法本地保存扇区数据,所以本函数
//         写地址如果非0XFF,那么会先擦除整个扇区且不保存扇区数据.所以
//         写非0XFF的地址,将导致整个扇区数据丢失.建议写之前确保扇区里
//         没有重要数据,最好是整个扇区先擦除了,然后慢慢往后写.
//该函数对OTP区域也有效!可以用来写OTP区!
//OTP区域地址范围:0X1FFF7800~0X1FFF7A0F
//WriteAddr:起始地址(此地址必须为4的倍数!!)
//pBuffer:数据指针
//NumToWrite:字(32位)数(就是要写入的32位数据的个数.)
void STMFLASH_Write(u32 WriteAddr,u32 *pBuffer,u32 NumToWrite)
{
    FLASH_Status status = FLASH_COMPLETE;
    u32 addrx=0;
    u32 endaddr=0;
    if(WriteAddr<STM32_FLASH_BASE||WriteAddr%4)return;	//非法地址
    FLASH_Unlock();									//解锁
    FLASH_DataCacheCmd(DISABLE);//FLASH擦除期间,必须禁止数据缓存

    addrx=WriteAddr;				//写入的起始地址
    endaddr=WriteAddr+NumToWrite*4;	//写入的结束地址
    if(addrx<0X1FFF0000)			//只有主存储区,才需要执行擦除操作!!
    {
        while(addrx<endaddr)		//扫清一切障碍.(对非FFFFFFFF的地方,先擦除)
        {
            if(STMFLASH_ReadWord(addrx)!=0XFFFFFFFF)//有非0XFFFFFFFF的地方,要擦除这个扇区
            {
                status=FLASH_EraseSector(STMFLASH_GetFlashSector(addrx),VoltageRange_3);//VCC=2.7~3.6V之间!!
                if(status!=FLASH_COMPLETE)break;	//发生错误了
            }else addrx+=4;
        }
    }
    if(status==FLASH_COMPLETE)
    {
        while(WriteAddr<endaddr)//写数据
        {
            if(FLASH_ProgramWord(WriteAddr,*pBuffer)!=FLASH_COMPLETE)//写入数据
            {
                break;	//写入异常
            }
            WriteAddr+=4;
            pBuffer++;
        }
    }
    FLASH_DataCacheCmd(ENABLE);	//FLASH擦除结束,开启数据缓存
    FLASH_Lock();//上锁
}

//从指定地址开始读出指定长度的数据
//ReadAddr:起始地址
//pBuffer:数据指针
//NumToRead:字(4位)数
void STMFLASH_Read(u32 ReadAddr,u32 *pBuffer,u32 NumToRead)
{
    u32 i;
    for(i=0;i<NumToRead;i++)
    {
        pBuffer[i]=STMFLASH_ReadWord(ReadAddr);//读取4个字节.
        ReadAddr+=4;//偏移4个字节.
    }
}

u8 Stop_To_Offset(u8 t)
{
    if(t)
    {
        TIM6_Stop();
        IMU_EXIT_STOP();
        SPI5_DMA_DISABLE();
        CAN1_STOP();
        CAN2_STOP();
        fireMotor_stop();
    }
    u8 tempp = 2;
    delay_ms(1000);
    delay_ms(1000);
    while(tempp) tempp=mpu6500_init();//MPU初始化
    delay_ms(500);
    MPU6050_Calibration();
    STMFLASH_Write(FLASH_SAVE_ADDR,(u32*)OFFSET_Buffer,SIZE);
    buzzer_on();
    delay_ms(1000);
    delay_ms(1000);
    buzzer_off();
    return 1;
}

void Read_Offset()
{
    float offset[SIZE] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    STMFLASH_Read(FLASH_SAVE_ADDR,(u32*)offset,SIZE);
    GyroSavedCaliData.GyroXOffset = offset[0];
    GyroSavedCaliData.GyroYOffset = offset[1];
    GyroSavedCaliData.GyroZOffset = offset[2];
    Gyro_x_err = offset[3];
    Gyro_y_err = offset[4];
    Gyro_z_err = offset[5];
}














