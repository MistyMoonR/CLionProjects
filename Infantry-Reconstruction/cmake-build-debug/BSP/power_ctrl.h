//
// Created by moon misty on 2019/9/19.
//

#ifndef INFANTRY_RECONSTRUCTION_POWER_CTRL_H
#define INFANTRY_RECONSTRUCTION_POWER_CTRL_H
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/SYSTEM/delay.h"
#include "../../main.h"


#include "../USER/stm32f4xx.h"

#define POWER1_CTRL_SWITCH 0
#define POWER2_CTRL_SWITCH 1
#define POWER3_CTRL_SWITCH 2
#define POWER4_CTRL_SWITCH 3

//四个24v 输出 依次开启 间隔 709us
#define POWER_CTRL_ONE_BY_ONE_TIME 709

void power_ctrl_configuration(void);

void power_ctrl_on(uint8_t num);
void power_ctrl_off(uint8_t num);
void power_ctrl_toggle(uint8_t num);

#endif //INFANTRY_RECONSTRUCTION_POWER_CTRL_H
