//
// Created by moon misty on 2019/9/16.
//

#include "chassis.h"

extern int fly_flag;
Chassis_set chassis_set = {0, 0, 0, 0, 0, 0, 0, 0}; // 头文件 结构体声明变量


/**
  * @brief  键盘数据处理
  * @param  void
  * @retval void
  * @attention 处理W A S D 键位，并且限制在一定范围内
  */

void remote_fifo()
{
    if(rc.W!=0)
        t_W++; //加速
    else
        t_W--; //减速

    if(rc.A!=0)
        t_A++;
    else
        t_A--;

    if(rc.S!=0)
        t_S++;
    else
        t_S--;

    if(rc.D!=0)
        t_D++;
    else
        t_D--;

     /**键盘限制在0-334范围内**/
    t_W = t_W > 334 ? 334 : t_W;
    t_W = t_W < 0 ? 0 : t_W;
    t_A = t_A > 334 ? 334 : t_A;
    t_A = t_A < 0 ? 0 : t_A;
    t_S = t_S > 334 ? 334 : t_S;
    t_S = t_S < 0 ? 0 : t_S;
    t_D = t_D > 334 ? 334 : t_D;
    t_D = t_D < 0 ? 0 : t_D;

    /**直接用AccStep数组覆盖进去，可能更快些吧？*/
    deal_W=AccStep[t_W];
    deal_A=AccStep[t_A];
    deal_S=AccStep[t_S];
    deal_D=AccStep[t_D];
}

/**
  * @brief  底盘电机更新设定值
  * @param  void
  * @retval void
  * @attention 底盘正常控制 遥控器+鼠标+YAW电机， 小陀螺/扭腰
  */

void chassis_set_update()
{
    /**电机编码器 速度环*/
    chassis_set.cm1_real = CM1Encoder.filter_rate;
    chassis_set.cm2_real = CM2Encoder.filter_rate;
    chassis_set.cm3_real = CM3Encoder.filter_rate;
    chassis_set.cm4_real = CM4Encoder.filter_rate;

    /**键盘模式检测，决定是否开小陀螺(扭腰)*/
    if(((rc.Ctrl ==1) && (rc.Q == 1)) || (rc.sl == 2))
    {
        NIUYAO = 1;
    }
    else if(((rc.Ctrl ==1) && (rc.E == 1)) || (rc.sl != 2))
    {
        NIUYAO = 0;
    }

    /**扭腰(小陀螺)部分代码*/
    if(NIUYAO == 1)
    {
        /**小陀螺*/
        chassis_set.RAD_RC_now = t_angle.yaw_set;
        chassis_set.RAD_RC_diff = chassis_set.RAD_RC_now - chassis_set.RAD_RC_last;
        chassis_set.RAD_RC_last = chassis_set.RAD_RC_now;

        chassis_set.YAW_CENTRE += (0.3f + chassis_set.RAD_RC_diff);
        chassis_set.follow_set = chassis_set.YAW_CENTRE;
    }
    else
    {
        /**回中*/
        chassis_set.RAD_RC_last = t_angle.yaw_set;
        if(GMYawEncoder.ecd_angle < (int16_t)(chassis_set.YAW_CENTRE / 360.0f) * 360.0f + YAW_MECHANICAL_CENTRE + 180.0f)
            chassis_set.follow_set = (int16_t)(chassis_set.YAW_CENTRE / 360.0f) * 360.0f + YAW_MECHANICAL_CENTRE;
        else if(GMYawEncoder.ecd_angle >= (int16_t)(chassis_set.YAW_CENTRE / 360.0f) * 360.0f + YAW_MECHANICAL_CENTRE + 180.0f)
            chassis_set.follow_set = (int16_t)(chassis_set.YAW_CENTRE / 360.0f + 1) * 360.0f + YAW_MECHANICAL_CENTRE;

        /**正常模式*/
        chassis_set.YAW_CENTRE = chassis_set.follow_set;
    }

    /**电机输出 PID解算*/
    out[CHASSIS_FOLLOW] = Calculate_Current_Value(&pid[CHASSIS_FOLLOW], chassis_set.follow_set, GMYawEncoder.ecd_angle);
    mecanum_Resolving(&chassis_set.cm1_set, &chassis_set.cm2_set, &chassis_set.cm3_set, &chassis_set.cm4_set, -(int)out[CHASSIS_FOLLOW]);
}

/**
  * @brief  底盘电机更新输出电流值
  * @param  void
  * @retval chassis_out_update
  * @attention 设定值输入到PID 电机开关
  */

void chassis_out_update()
{
    chassis_set_update();
    out[FR] = Calculate_Current_Value(&pid[FR], chassis_set.cm1_set, chassis_set.cm1_real);
    out[FL] = Calculate_Current_Value(&pid[FL], chassis_set.cm2_set, chassis_set.cm2_real);
    out[BL] = Calculate_Current_Value(&pid[BL], chassis_set.cm3_set, chassis_set.cm3_real);
    out[BR] = Calculate_Current_Value(&pid[BR], chassis_set.cm4_set, chassis_set.cm4_real);
    /**检测并且设定电机，分为有力模式和无力模式*/
    if(fly_flag == 0)
        Set_ChassisMotor_Current((int16_t) out[FR], (int16_t) out[FL], (int16_t) out[BL], (int16_t) out[BR]);
    else
        Set_ChassisMotor_Current(0, 0, 0, 0);
}

/**
  * @brief  底盘跟随云台模式
  * @param  void
  * @retval Chassis_follow
  * @attention 把云台的坐标系映射到底盘上
  */

void Chassis_follow(float *x, float *y)  //把云台的坐标映射到底盘上
{
    float raw_x = *x, raw_y = *y;
    float ecd_angle_chazhi;
    ecd_angle_chazhi=-(GMYawEncoder.ecd_angle - YAW_MECHANICAL_CENTRE);//(云台yaw轴的真实值减去编码器的值)
    *x = raw_x * cos(ecd_angle_chazhi * PI_mu) + raw_y * sin(ecd_angle_chazhi * PI_mu);
    *y = raw_y * cos(ecd_angle_chazhi * PI_mu) - raw_x * sin(ecd_angle_chazhi * PI_mu);
}

/**
  * @brief  麦轮解算
  * @param  void
  * @retval 底盘目标移动量
  * @attention 速度设定，圆形限速
  */

void mecanum_Resolving(float *a, float *b, float *c, float *d, int z)
{
    float rc_x, rc_y, X, Y, aa;
    int W = 0, A = 0, S = 0, D = 0;

    /**键盘*/
    remote_fifo();
    W = keypad_K * deal_W;
    A = keypad_K * deal_A;
    S = keypad_K * deal_S;
    D = keypad_K * deal_D;

    /**遥控器*/
    rc_x = rc.R_x * remote_K;
    rc_y = rc.R_y * remote_K;

    /**底盘 X Y 轴方向，由键盘和摇杆来设定*/
    Y = -W + S + rc_y;
    X = A - D + rc_x;

    /**圆形限速 防止超功率*/
    aa = sqrt(X * X + Y * Y);
    X = aa < limit ? X : X * (limit / aa);
    X = aa > -limit ? X : X * (limit / aa);
    Y = aa < limit ? Y : Y * (limit / aa);
    Y = aa > -limit ? Y : Y * (limit / aa);

    /**底盘跟随云台 控制转向*/
    Chassis_follow(&X, &Y);

    /**输出值，传递到第108行，不过Z貌似没有值*/
    *a = Y - X - z;
    *b = -Y - X - z;
    *c = -Y + X - z;
    *d = Y + X - z;
}

/**
  * @brief  CAN 发送协议
  * @param  void
  * @retval CAN 八位信号
  * @attention CAN1 ID：201 202 203 204
  */
void Set_ChassisMotor_Current(int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq)		//地盘电机电流发送函数
{
    CanTxMsg tx_message;
    tx_message.StdId = 0x200;
    tx_message.IDE = CAN_Id_Standard;
    tx_message.RTR = CAN_RTR_Data;
    tx_message.DLC = 0x08;

    tx_message.Data[0] = (uint8_t) (cm1_iq >> 8);
    tx_message.Data[1] = (uint8_t) cm1_iq;
    tx_message.Data[2] = (uint8_t) (cm2_iq >> 8);
    tx_message.Data[3] = (uint8_t) cm2_iq;
    tx_message.Data[4] = (uint8_t) (cm3_iq >> 8);
    tx_message.Data[5] = (uint8_t) cm3_iq;
    tx_message.Data[6] = (uint8_t) (cm4_iq >> 8);
    tx_message.Data[7] = (uint8_t) cm4_iq;
    CAN_Transmit(CAN1, &tx_message);
}
