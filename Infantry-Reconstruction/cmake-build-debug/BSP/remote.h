//
// Created by moon misty on 2019/9/16.
//

#ifndef INFANTRY_RECONSTRUCTION_REMOTE_H
#define INFANTRY_RECONSTRUCTION_REMOTE_H

#include <ntsid.h>
#include "../USER/stm32f4xx.h"


typedef struct
{
    int16_t R_x;  //????x		??1684 ??364 ??1024  1684-1024 = 1024 - 364 = 660
    int16_t R_y;	 //????y    ??1684 ??364 ??1024
    int16_t L_x;
    int16_t L_y;
    uint8_t sl;			//??????  ??1 ??3 ??2
    uint8_t sr;

    int16_t mouse_x;	//???
    int16_t mouse_y;
    int16_t mouse_z;
    uint8_t mouse_l;	//?????
    uint8_t mouse_r;
    uint16_t key;		//????
    u8 W;
    u8 S;
    u8 A;
    u8 D;
    u8 Q;
    u8 E;
    u8 Shift;
    u8 Ctrl;
}RC;
extern RC rc;
void Remote_uart1_init(void);	//??????????
//RC GetRemoteData(void);	//????RC???????????



#endif //INFANTRY_RECONSTRUCTION_REMOTE_H
