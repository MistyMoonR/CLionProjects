//
// Created by moon misty on 2019/9/16.
//

#ifndef INFANTRY_RECONSTRUCTION_MAIN_H
#define INFANTRY_RECONSTRUCTION_MAIN_H

#include "/usr/local/Cellar/gcc/8.2.0/lib/gcc/8/gcc/x86_64-apple-darwin18.2.0/8.2.0/include-fixed/math.h"


#include "../../../../../../Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/ntsid.h"
#include "../../../../../../usr/local/Cellar/gcc/8.2.0/lib/gcc/8/gcc/x86_64-apple-darwin18.2.0/8.2.0/include/stdint-gcc.h"



#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/HAL/gimbal.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/encoder.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/pid.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/HAL/imu.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/HAL/chassis.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/mpu6500driver.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/mpu6500reg.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/mpu6500driver_hardware.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/remote.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/HAL/trigger.h"

#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/HAL/Friction.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/SYSTEM/delay.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/SYSTEM/sys.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/SYSTEM/usart.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/bsp.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/pwn.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/power_ctrl.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/USER/stm32f4xx.h"
#include "/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/BSP/timer.h"

void control_task(void);





#endif //INFANTRY_RECONSTRUCTION_MAIN_H

