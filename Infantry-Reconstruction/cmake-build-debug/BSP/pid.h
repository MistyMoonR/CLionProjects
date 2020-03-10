//
// Created by moon misty on 2019/9/16.
//

#ifndef INFANTRY_RECONSTRUCTION_PID_H
#define INFANTRY_RECONSTRUCTION_PID_H

//#include "delay.h"


/**预定义 宏部分*/
#define FR 0
#define FL 1
#define BL 2
#define BR 3
#define PITCH_ANGLE 4
#define PITCH_SPEED 5
#define YAW_ANGLE  6
#define YAW_SPEED 7
#define CHASSIS_FOLLOW 8

#define FEED_MOTOR_SINGLE 9
#define FEED_MOTOR_DOUBLE_ANGLE 10
#define FEED_MOTOR_DOUBLE_SPEED 11

#define VISUAL_YAW_OFFSET 12
#define VISUAL_PITCH_OFFSET 13
#define ALL_PID 14

typedef struct PID
{
    float kp;
    float ki;
    float kd;

    float pout;
    float iout;
    float dout;

    float poutmax;
    float ioutmax;
    float doutmax;
    float outmax;

    float set;
    float real;
    float out;

    float err;							//定义偏差值
    float err_last;					    //上一次偏差值
    float err_llast;				    //上上次偏差值
    float integral;					    //累计偏差值
    void(*f_pid_init)(struct PID *pid, float kp, float ki, float kd, float poutmax, float ioutmax, float doutmax, float outmax);			//用来初始化pid
    void(*f_pid_reset)(struct PID *pid);
}PID;


extern PID pid[ALL_PID];
extern float out[ALL_PID];
static void pid_init(PID *pid, float kp, float ki, float kd, float poutmax, float ioutmax, float doutmax, float outmax);
static void pid_reset(PID *pid);

void All_Pid_Configuration(PID pid[]);
float Calculate_Current_Value(PID *pid, float set, float real);
float Calculate_Current_Value_For_Err(PID *pid, float err); // Err 和下面Look 一起看的

void Look(void);


#endif //INFANTRY_RECONSTRUCTION_PID_H
