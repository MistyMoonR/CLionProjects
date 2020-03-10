//
// Created by moon misty on 2019/9/19.
//

#include "bsp.h"
/**
 * 板级支持包（BSP）（Board Support Package）
 * 是介于主板硬件和操作系统中驱动层程序之间的一层，
 * 一般认为它属于操作系统一部分，主要是实现对操作系统的支持，
 * 为上层的驱动程序提供访问硬件设备寄存器的函数包，
 * 使之能够更好的运行于硬件主板。在嵌入式系统软件的组成中，就有BSP。
*/

// 貌似添加开发板A板 电源管理配置，没啥用忽略不计

uint8_t mpu_temp = 2;//MPU初始化标志位

void BSP_Init(/*u8 t*/)						//底层初始化
{

    Read_Offset();
    if(!t)
    {
        while(mpu_temp) mpu_temp = mpu6500_init();//MPU初始化
    }

    power_ctrl_configuration();
 //   laser_configuration();
    ramp_init();
    CAN1_mode_init(CAN_SJW_1tq, CAN_BS2_2tq, CAN_BS1_6tq, 5, CAN_Mode_Normal);
    CAN2_mode_init(CAN_SJW_1tq, CAN_BS2_2tq, CAN_BS1_6tq, 5, CAN_Mode_Normal);
    delay_ms(1000);//等CAN发过来第一次数据


    for (uint8_t i = POWER1_CTRL_SWITCH; i < POWER4_CTRL_SWITCH + 1; i++)
    {
        power_ctrl_on(i);
        delay_us(POWER_CTRL_ONE_BY_ONE_TIME);
    }
    TIM6_Configure();
    TIM1_FireMotor_Configure();

    laser_on();
    All_Pid_Configuration(pid);//pid参数初始化
    IMU_Configure();//MPU中断初始化
    //TIM3_Int_Init();//计算热量
    TIM6_Start();
}
