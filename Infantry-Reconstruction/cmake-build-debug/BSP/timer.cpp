//
// Created by moon misty on 2019/9/27.
//

#include "timer.h"
#include "../../main.h"

//int16_t firemotor_flag = 0;
u8 time_1ms = 0;
void TIM6_Configure(void)
{
    TIM_TimeBaseInitTypeDef  tim;
    NVIC_InitTypeDef         nvic;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);

    nvic.NVIC_IRQChannel = TIM6_DAC_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 1;
    nvic.NVIC_IRQChannelSubPriority = 0;
    nvic.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic);
    tim.TIM_Prescaler = 90-1;        //84M internal clock
    tim.TIM_CounterMode = TIM_CounterMode_Up;
    tim.TIM_ClockDivision = TIM_CKD_DIV1;
    tim.TIM_Period = 1000;  //1ms,1000Hz
    TIM_TimeBaseInit(TIM6,&tim);
}

void TIM6_Start(void)
{
    TIM_Cmd(TIM6, ENABLE);
    TIM_ITConfig(TIM6, TIM_IT_Update,ENABLE);
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);
}
void TIM6_Stop(void)
{
    TIM_Cmd(TIM6, DISABLE);
    TIM_ITConfig(TIM6, TIM_IT_Update,DISABLE);
}

void TIM6_DAC_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM6,TIM_IT_Update)!= RESET)
    {
        TIM_ClearITPendingBit(TIM6,TIM_IT_Update);
        TIM_ClearFlag(TIM6, TIM_FLAG_Update);

        if(time_1ms <= 3)//待数据稳定后开始执行
        {
            angle_init(&t_angle);//位置设定值初始化
            time_1ms ++;
        }
        else
        {
            control_task();         //底盘、云台控制任务
        }

    }
}


void TIM3_Int_Init()
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  //使能TIM3时钟

    TIM_TimeBaseInitStructure.TIM_Period = 1000 - 1; 	//自动重装载值
    TIM_TimeBaseInitStructure.TIM_Prescaler= 9000 - 1;  //定时器分频    84000000/84/500 = 2000HZ
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;

    TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//初始化TIM3

    TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //允许定时器3更新中断
    TIM_Cmd(TIM3,ENABLE); //使能定时器3

    NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //定时器3中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1; //抢占优先级1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=2; //子优先级3
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

int Q1=0;
void TIM3_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
    {
        TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
        TIM_ClearFlag(TIM6, TIM_FLAG_Update);
        if(Q1>0){
            Q1=Q1-40*0.1;
        }
    }
}
//void TIM2_Configuration(void)
//{
//    TIM_TimeBaseInitTypeDef  tim;

//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
//
//    tim.TIM_Prescaler = 90-1;        //84M internal clock
//    tim.TIM_CounterMode = TIM_CounterMode_Up;
//    tim.TIM_ClockDivision = TIM_CKD_DIV1;
//    tim.TIM_Period = 0xffffffff-1;
//    TIM_TimeBaseInit(TIM2,&tim);
//    TIM_Cmd(TIM2, ENABLE);
//}

