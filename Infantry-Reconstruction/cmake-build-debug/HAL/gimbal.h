//
// Created by moon misty on 2019/9/16.
//

#ifndef INFANTRY_RECONSTRUCTION_GIMBAL_H
#define INFANTRY_RECONSTRUCTION_GIMBAL_H


//空间云台极限值
#define PITHCH_SPACE_TOP 	0.0f
#define PITCH_SPACE_LOW 	0.0f
#define YAW_SPACE_LEFT 		0.0f
#define YAW_SPACE_RIGHT		0.0f

//机械云台极限值
#define PITCH_MECHANICAL_LOW 	-158.0f
#define PITCH_MECHANICAL_CENTRE -145.75f
#define PITCH_MECHANICAL_TOP	-136.8f
//#define YAW_MECHANICAL_LEFT	35.3f  // YAW 不加限位
//#define YAW_MECHANICAL_RIGHT	-27.5f

#define YAW_MECHANICAL_CENTRE	-30.0f


#define PITCH_AND	1000.0f
#define YAW_AND		0.0f


typedef struct Angle  // 空间云台
{
    float yaw_target;
    float pitch_target;							//中间值
    float yaw_set;                              //yaw设定值，输出到PID电流环中
    float pitch_set;
    int back_flag;	    							//回中标志位
    float pitch_remote_last;
    float pitch_remote_now;
    float pitch_differ;

}Angle;

void angle_init(struct Angle *angle);
void angle_out_update(struct Angle *angle); //电机输出值
void angle_set_update(struct Angle *angle); //电机更新值
void Set_CloudMotor_Current(int16_t gimbal_yaw_iq, int16_t gimbal_pitch_iq);


extern Angle t_angle;



#endif
