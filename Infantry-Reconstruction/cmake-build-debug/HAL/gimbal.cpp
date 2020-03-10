//
// Created by moon misty on 2019/9/16.
//
#include "../../main.h"

/**头文件结构体声明变量**/
Angle t_angle = {0, 0, 0, 0, 0, 0, 0, 0};

/**
  * @brief  云台电机pid参数初始化
  * @param  void
  * @retval void
  * @attention 设定set为空间云台角度
  */
void angle_init(struct Angle *angle)
{
    angle->back_flag = 0; // 标志位初始化 (*p).name 用法和 p->name 相等 PS: ->指向运算符
    angle->yaw_set = real_angle.yaw;
    angle->pitch_set = real_angle.pitch; // 真实角度  编码器位置转换MPU角度值
    angle->pitch_target = PITCH_MECHANICAL_CENTRE + (90 - GMPitchEncoder.init_angle); // init_angle 是从ecd_angle 滤波来的数据
    angle->yaw_target = YAW_MECHANICAL_CENTRE + (90 - GMYawEncoder.init_angle); // 没明白90 的作用
    chassis_set.YAW_CENTRE = YAW_MECHANICAL_CENTRE; // 底盘中间位置 需要注意下小陀螺和扭腰这个值应该是不同的
}

/**
  * @brief  云台电机更新设定值
  * @param  void
  * @retval void
  * @attention 云台回中，操作模式： 遥控器+鼠标+视觉
  */
void angle_set_update(struct Angle *angle)
{
    /**缓慢启动回中(采用空间云台)*/
    if(angle->back_flag == 0)
    {
        if(((int)angle->yaw_set != (int)angle->yaw_target) || ((int)angle->pitch_set != (int)angle->pitch_target)) //检测云台位置是否在中间位置
        {
            if(((int)angle->yaw_set != (int)angle->yaw_target))
                angle->yaw_set = angle->yaw_set < angle->yaw_target ? angle->yaw_set + 0.01f : angle->yaw_set - 0.01f; //yaw回中
            if(((int)angle->pitch_set != (int)angle->pitch_target))
                angle->pitch_set = angle->pitch_set < angle->pitch_target ? angle->pitch_set + 0.01f : angle->pitch_set - 0.01f; //pitch回中
        }
        else
            angle->back_flag = 1;	//云台回中标志
    }

    /**回中结束后开始正常操作*/
    else
    {
            //yaw轴不限位
        angle->yaw_set += rc.L_x / 3000.0f - (rc.mouse_x / 200.0f) + out[VISUAL_YAW_OFFSET];
            //pitch轴加入限位
        angle->pitch_remote_last = angle->pitch_remote_now;
        angle->pitch_remote_now += (-rc.L_y / 4000.0f) + (-rc.mouse_y / 266.0f) + out[VISUAL_PITCH_OFFSET];
        angle->pitch_differ = angle->pitch_remote_now - angle->pitch_remote_last;

        if (GMPitchEncoder.ecd_angle <= PITCH_MECHANICAL_LOW && angle->pitch_differ < 0)
            angle->pitch_set += (angle->pitch_differ);

        if (GMPitchEncoder.ecd_angle >= PITCH_MECHANICAL_TOP && angle->pitch_differ > 0)
            angle->pitch_set += (angle->pitch_differ);

        if (GMPitchEncoder.ecd_angle > PITCH_MECHANICAL_LOW && GMPitchEncoder.ecd_angle < PITCH_MECHANICAL_TOP)
            angle->pitch_set += angle->pitch_differ;

    }
}

/**
  * @brief  云台电机更新输出电流值
  * @param  void
  * @retval void
  * @attention 设定值输入到PID 电机开关
  */
void angle_out_update(struct Angle *angle)
{
    angle_set_update(angle);
    //pid计算输出值
    out[YAW_ANGLE] = Calculate_Current_Value(&pid[YAW_ANGLE], angle->yaw_set, real_angle.yaw);   //前面是设定值 后面是陀螺仪真实角度
    out[YAW_SPEED] = Calculate_Current_Value(&pid[YAW_SPEED], out[YAW_ANGLE], real_angle.gz); // 前面是上面两个结合 后面是加速度计 我曹根本看不懂

    out[PITCH_ANGLE] = Calculate_Current_Value(&pid[PITCH_ANGLE], angle->pitch_set, real_angle.pitch);
    out[PITCH_SPEED] = Calculate_Current_Value(&pid[PITCH_SPEED], out[PITCH_ANGLE], real_angle.gx);

    if(angle->back_flag == 1) // 会中标志位
        Set_CloudMotor_Current((int16_t)(out[YAW_SPEED] + YAW_AND),(int16_t)(out[PITCH_SPEED] + PITCH_AND)); // 看不懂为啥要加_AND这个函数
    else
        Set_CloudMotor_Current(0, 0);
}

/**
  * @brief  CAN 发送协议
  * @param  void
  * @retval CAN 四位信号
  * @attention CAN1 YAW 0x205 PITCH 0x206
  */
void Set_CloudMotor_Current(int16_t gimbal_yaw_iq, int16_t gimbal_pitch_iq)//云台电机电流发送函数
{
    CanTxMsg tx_message;
    tx_message.StdId = 0x1FF;
    tx_message.IDE = CAN_Id_Standard;
    tx_message.RTR = CAN_RTR_Data;
    tx_message.DLC = 0x08;

    tx_message.Data[0] = (unsigned char)(gimbal_yaw_iq >> 8);
    tx_message.Data[1] = (unsigned char)gimbal_yaw_iq;
    tx_message.Data[2] = (unsigned char)(gimbal_pitch_iq >> 8);
    tx_message.Data[3] = (unsigned char)gimbal_pitch_iq;
    tx_message.Data[4] = 0x00;
    tx_message.Data[5] = 0x00;
    tx_message.Data[6] = 0x00;
    tx_message.Data[7] = 0x00;
    CAN_Transmit(CAN1,&tx_message);
}
