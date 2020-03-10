//
// Created by moon misty on 2019/9/18.
//

#ifndef INFANTRY_RECONSTRUCTION_CAN1_H
#define INFANTRY_RECONSTRUCTION_CAN1_H

#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/SYSTEM/delay.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/main.h"

uint8_t CAN1_mode_init(uint8_t tsjw, uint8_t tbs2, uint8_t tbs1, uint16_t brp, uint8_t mode);
void CAN1_STOP(void);
void CNA1_START(void);
#endif //INFANTRY_RECONSTRUCTION_CAN1_H
