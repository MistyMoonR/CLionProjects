//
// Created by moon misty on 2019/9/16.
//

#ifndef INFANTRY_RECONSTRUCTION_CHASSIS_H
#define INFANTRY_RECONSTRUCTION_CHASSIS_H

#include "../../main.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/SYSTEM/delay.h"

/**预定义*/
#define keypad_K 2   //键盘 加速度
#define remote_K 1.6 //摇杆 加速度
#define limit 1012 //底盘速度 限制范围
#define ACC_STEP_NUM 335 //
#define PI_mu 0.01745f // PI 圆周率定义 搞不清单位

/**扭腰(小陀螺)全局变量*/
static uint8_t NIUYAO;

/**按键设定值 映射到AccStep中*/
float deal_W, deal_A, deal_S, deal_D ;
int t_W, t_A, t_S, t_D;


/**底盘电机数据更新及发送*/
void chassis_set_update(void); //无形参的函数 不接受任何实参也不返回任何值
void chassis_out_update(void);
void Set_ChassisMotor_Current(int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq);	//底盘电机电流发送函数


/**底盘输出计算*/
void mecanum_Resolving(float *a ,float *b,float *c,float *d,int z);    //麦伦结算
void Chassis_follow(float *x, float *y);

/**键盘模式辅助函数*/
void remote_fifo(void);


extern Chassis_set chassis_set;


/**底盘起步缓加速*/
unsigned short AccStep[ACC_STEP_NUM] =
        {
                0,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,15,15,16,16,16,17,17,18,18,19,20,20,21,21,22,23,23,24,25,25,26,27,28,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,46,47,48,49,51,52,54,55,57,58,60,61,63,64,66,68,70,72,73,75,77,79,81,83,85,88,90,92,94,97,99,101,104,106,109,111,114,117,119,122,125,128,131,133,136,139,142,146,149,152,155,158,162,165,168,171,175,178,182,185,189,192,196,199,203,207,210,214,218,221,225,229,233,236,240,244,248,251,255,259,262,266,270,274,277,281,285,288,292,296,299,303,307,310,314,317,321,324,327,331,334,337,341,344,347,350,353,357,360,363,366,368,371,374,377,380,382,385,388,390,393,395,398,400,403,405,407,410,412,414,416,418,420,422,424,426,428,430,431,433,435,437,438,440,441,443,444,446,447,449,450,451,453,454,455,456,458,459,460,461,462,463,464,465,466,467,468,469,470,471,471,472,473,474,474,475,476,477,477,478,478,479,480,480,481,481,482,482,483,483,484,484,485,485,486,486,486,487,487,488,488,488,489,489,489,490,490,490,490,491,491,491,492,492,492,492,492,493,493,493,493,494,494,494,494,494,494,495,495,495,495,495,495,495,496,496,496,496,496,496,496,496,497,497
        };


/**
  * @brief  麦轮 结构体
  * @param  typedef
  * @retval Chassis_set
  * @attention 底盘四个电机设定 和真实角度 底盘跟随云台模式 小陀螺Y轴电机角度
  */

typedef struct Chassis_set
{

    float cm1_set;
    float cm2_set;
    float cm3_set;
    float cm4_set;

    float cm1_real;
    float cm2_real;
    float cm3_real;
    float cm4_real;
    float follow_set;
    float follow_real;
    float YAW_CENTRE;
    // 小陀螺部分 云台与底盘编码器角度
    float RAD_RC_last;
    float RAD_RC_now;
    float RAD_RC_diff;
}Chassis_set;



//volatile Chassis_set chassis_set;
#endif //INFANTRY_RECONSTRUCTION_CHASSIS_H
