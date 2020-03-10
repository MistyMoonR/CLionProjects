//
// Created by moon misty on 2019/9/27.
//

#ifndef INFANTRY_RECONSTRUCTION_TIMER_H
#define INFANTRY_RECONSTRUCTION_TIMER_H



#include "../../main.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/SYSTEM/delay.h"

void TIM6_Configure(void);
void TIM6_Start(void);
void TIM6_Stop(void);
void TIM4_FireMotor_Configure(void);
void TIM3_Int_Init(void);
//extern int16_t firemotor_flag;


#endif //INFANTRY_RECONSTRUCTION_TIMER_H
