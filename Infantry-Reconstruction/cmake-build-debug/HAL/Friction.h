//
// Created by moon misty on 2019/9/18.
//

#ifndef INFANTRY_RECONSTRUCTION_FRICTION_H
#define INFANTRY_RECONSTRUCTION_FRICTION_H

#include <stdint.h>
#include "../USER/stm32f4xx.h"

void fireMotor_stop(void);
void fireMotor_fire(void);
void fireMotor(void);
void ramp_calc(void);
void ramp_init(void);

typedef struct
{
    float input;
    float out;
    float target;
    float min;
    float max;
    float frame_period;
    uint8_t add_each_second;
    float add_real;
}Ramp_Start;



#endif //INFANTRY_RECONSTRUCTION_FRICTION_H
