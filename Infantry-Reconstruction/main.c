#include <stdio.h>
#include "main.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/bsp.h"

void ramp_calc();

int main() {
    printf("Hello, World!\n");
    return 0;
}


void control_task()
{
    BSP_Init();
    angle_out_update(&t_angle);//云台电机控制
    if(t_angle.back_flag == 1)
    {
        Shoot();//拨弹电机控制
        chassis_out_update();//底盘电机控制
        ramp_calc();
    }



}



//u8 bsp_flag = 0;
//u8 offset_flag = 0;
//int main(void)
//{
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//    delay_init(180);
//    Remote_uart1_init();//遥控初始化
//    buzzer_init(30000, 90);
//////		miniPC_uart6_init();//miniPC通信初始化
//////		miniPC_Init();//miniPC数据初始化
//    while(!bsp_flag)
//    {		//上电之后首先进行bsp初始化 或者 IMU校准(在无其他操作下 只会进行一次初始化或者校准)
//
//        if(rc.sr == 2 && offset_flag == 0)
//        {
//            offset_flag = Stop_To_Offset(0);
//        }
//        else if(rc.sr == 3 && bsp_flag == 0)
//        {
//            BSP_Init(offset_flag);
//            bsp_flag = 1;
//        }
//    }
//
//    while(1)
//    {
//        if(t_angle.back_flag == 1)//云台初始化完成
//        {
//            fireMotor();//摩擦轮控制
//        }
//    }
//}
