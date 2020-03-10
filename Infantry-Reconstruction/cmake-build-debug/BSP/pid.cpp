//
// Created by moon misty on 2019/9/16.
//
#include "pid.h"

/**
 * source：https://blog.csdn.net/guwhao/article/details/47346291
 * 串级 PID 算法中，角速度内环占着极为重要的地位。在对四旋翼飞行的物理模型进
 * 行分析后，可以知道造成系统不稳定的物理表现之一就是不稳定的角速度。
 * 因此，若能够直接对系统的角速度进行较好的闭环控制，必然会改善系统的动态特性及其稳定性，
 * 通常也把角速度内环称为增稳环节。而角度外环的作用则体现在对四旋翼飞行器的姿态角的精确控制。
 *
 * 外环：输入为角度,输出为角速度
 * 内环：输入为角速度，输出为PWM增量
 *
 * 使用串级pid，分为：角度环控制pid环，和角速度控制环稳定环。主调为角度环（外环），副调为角速度环（内环）。
 * 参数整定原则为先内后外，故在整定内环时将外环的PID均设为0
 * 所谓外环就是只是一个P在起作用，也就是比例在起作用；P也就是修正力度，越大越容易使飞机震荡。
 * 震荡的特点是：频率小、幅度大
 */

PID pid[ALL_PID];		//定义所有PID结构体数组  来自头文件typedef struct PID
float out[ALL_PID] = {0};//PID输出值数组


//pid值初始化
static void pid_init(PID *pid, float kp, float ki, float kd, float poutmax, float ioutmax, float doutmax, float outmax)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;

    pid->poutmax = poutmax;
    pid->ioutmax = ioutmax;
    pid->doutmax = doutmax;
    pid->outmax = outmax;

    pid->f_pid_reset = pid_reset;
    pid->f_pid_reset(pid);

    pid->err = 0;
    pid->err_last = 0;
    pid->err_llast = 0;
    pid->integral = 0;

}

//pid输出值重置
static void pid_reset(PID *pid)
{

    pid->pout = 0;
    pid->iout = 0;
    pid->dout = 0;
    pid->out  = 0;

}

/**
先整定内环，后整定外环。
参数整定找最佳，从小到大顺序查

先是比例后积分，最后再把微分加

曲线振荡很频繁，比例度盘要放大

曲线漂浮绕大湾，比例度盘往小扳

曲线偏离回复慢，积分时间往下降

曲线波动周期长，积分时间再加长

曲线振荡频率快，先把微分降下来

动差大来波动慢。微分时间应加长

理想曲线两个波，前高后低4比1
*/


//所有电机pid值初始化（形参需要后续更改，第一次测试形参全为0）
void All_Pid_Configuration(PID pid[])
{
    // 底盘四个电机部分
    pid[FR].f_pid_init = pid_init;
    pid[FR].f_pid_init(&pid[FR], 65.0f, 0.0f, 0.8f, 5000.0f, 500.0f, 1000.0f, 6000.0f);  //左前

    pid[FL].f_pid_init = pid_init;
    pid[FL].f_pid_init(&pid[FL], 65.0f, 0.0f, 0.8f, 5000.0f, 500.0f, 1000.0f, 6000.0f);  //左前

    pid[BL].f_pid_init = pid_init;
    pid[BL].f_pid_init(&pid[BL], 65.0f, 0.0f, 0.8f, 5000.0f, 500.0f, 1000.0f, 6000.0f);  //左前

    pid[BR].f_pid_init = pid_init;
    pid[BR].f_pid_init(&pid[BR], 65.0f, 0.0f, 0.8f, 5000.0f, 500.0f, 1000.0f, 6000.0f);  //左前


    // 云台两个电机部分
    pid[PITCH_ANGLE].f_pid_init = pid_init;
    pid[PITCH_ANGLE].f_pid_init(&pid[PITCH_ANGLE], 25.0f, 0.0f, 0.0f, 250.0f, 0.0f, 50.0f, 250.0f);

    pid[PITCH_SPEED].f_pid_init = pid_init;
    pid[PITCH_SPEED].f_pid_init(&pid[PITCH_SPEED], 15.0f, 0.0f, 0.0f, 5000.0f, 100.0f, 1000.0f, 5000.0f);


    pid[YAW_ANGLE].f_pid_init = pid_init;
    pid[YAW_ANGLE].f_pid_init(&pid[YAW_ANGLE], 15.0f, 0.0f, 0.0f, 1000.0f, 50.0f, 500.0f, 1000.0f);

    pid[YAW_SPEED].f_pid_init = pid_init;
    pid[YAW_SPEED].f_pid_init(&pid[YAW_SPEED], 90.0f, 0.0f, 0.0f, 30000.0f, 1000.0f, 10000.0f, 30000.0f);



    // 剩余部分
    pid[CHASSIS_FOLLOW].f_pid_init = pid_init;
    pid[CHASSIS_FOLLOW].f_pid_init(&pid[CHASSIS_FOLLOW], 28.0f, 0.0f, 0.0f, 800.0f, 0.0f, 0.0f, 800.0f);

    pid[FEED_MOTOR_SINGLE].f_pid_init = pid_init;
    pid[FEED_MOTOR_SINGLE].f_pid_init(&pid[FEED_MOTOR_SINGLE], 80.0f, 0.0f, 0.0f, 5000.0f, 0.0f, 0.0f, 5000.0f);

    pid[FEED_MOTOR_DOUBLE_ANGLE].f_pid_init = pid_init;
    //pid[FEED_MOTOR_DOUBLE_ANGLE].f_pid_init(&pid[FEED_MOTOR_DOUBLE_ANGLE], 2.5f, 0.0f, 0.0f, 800.0f, 0.0f, 10.0f, 800.0f); // 电机不同的PID 输出 MAX 要注意下
    pid[FEED_MOTOR_DOUBLE_ANGLE].f_pid_init(&pid[FEED_MOTOR_DOUBLE_ANGLE], 12.5f, 0.0f, 100.0f, 5000.0f, 0.0f, 5000.0f, 5000.0f);


    pid[VISUAL_YAW_OFFSET].f_pid_init = pid_init;
    pid[VISUAL_YAW_OFFSET].f_pid_init(&pid[VISUAL_YAW_OFFSET], 0.005f, 0.0f, 0.0001f, 1.5f, 0.0f, 0.2f, 1.7f);

    pid[VISUAL_PITCH_OFFSET].f_pid_init = pid_init;
    pid[VISUAL_PITCH_OFFSET].f_pid_init(&pid[VISUAL_PITCH_OFFSET], 0.005f, 0.0f, 0.0001f, 1.5f, 0.0f, 0.2f, 1.7f);


}

//pid计算出输出值
float Calculate_Current_Value(PID *pid, float set, float real)
{
    //首先置零上一次的输出值
    pid->f_pid_reset = pid_reset;
    pid->f_pid_reset(pid);

    pid->set = set ;
    pid->real = real;

    /**计算速度误差*/
    pid->err_last = pid->err;
    pid->err = pid->set - pid->real;
    pid->integral += pid->err;

    /**比列*/
    pid->pout = pid->kp * pid->err;
    pid->pout = pid->pout < pid->poutmax ? pid->pout : pid->poutmax;
    pid->pout = pid->pout > -pid->poutmax ? pid->pout : -pid->poutmax;

    /**积分*/
    pid->iout = pid->ki * pid->integral;
    pid->iout = pid->iout < pid->ioutmax  ? pid->iout : pid->ioutmax;
    pid->iout = pid->iout > -pid->ioutmax ? pid->iout : -pid->ioutmax;

    /**微分*/
    pid->dout = pid->kd * (pid->err - pid->err_last);
    pid->dout = pid->dout < pid->doutmax ? pid->dout : pid->doutmax;
    pid->dout = pid->dout > -pid->doutmax ? pid->dout : -pid->doutmax;

    /**总输出*/
    pid->out = pid->pout + pid->iout + pid->dout;
    pid->out = pid->out < pid->outmax ? pid->out : pid->outmax;
    pid->out = pid->out > -pid->outmax ? pid->out : -pid->outmax;
    return pid->out;
}


float Calculate_Current_Value_For_Err(PID *pid, float err)
{
    pid->f_pid_reset = pid_reset;
    pid->f_pid_reset(pid);


    pid->err_last = pid->err;
    pid->err = err;
    pid->integral += pid->err;

    pid->pout = pid->kp * pid->err;
    pid->pout = pid->pout < pid->poutmax ? pid->pout : pid->poutmax;
    pid->pout = pid->pout > -pid->poutmax ? pid->pout : -pid->poutmax;

    pid->iout = pid->ki * pid->integral;
    pid->iout = pid->iout < pid->ioutmax  ? pid->iout : pid->ioutmax;
    pid->iout = pid->iout > -pid->ioutmax ? pid->iout : -pid->ioutmax;

    pid->dout = pid->kd * (pid->err - pid->err_last);
    pid->dout = pid->dout < pid->doutmax ? pid->dout : pid->doutmax;
    pid->dout = pid->dout > -pid->doutmax ? pid->dout : -pid->doutmax;

    pid->out = pid->pout + pid->iout + pid->dout;
    pid->out = pid->out < pid->outmax ? pid->out : pid->outmax;
    pid->out = pid->out > -pid->outmax ? pid->out : -pid->outmax;

    return pid->out;
}

