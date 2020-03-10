//
// Created by moon misty on 2019/9/18.
//

#ifndef INFANTRY_RECONSTRUCTION_CAN2_H
#define INFANTRY_RECONSTRUCTION_CAN2_H

#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/SYSTEM/delay.h"


uint8_t CAN2_mode_init(uint8_t tsjw, uint8_t tbs2, uint8_t tbs1, uint16_t brp, uint8_t mode);
void CAN2_STOP(void);
void CAN2_START(void);


#endif //INFANTRY_RECONSTRUCTION_CAN2_H
