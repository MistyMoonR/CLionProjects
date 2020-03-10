//
// Created by moon misty on 2019/9/16.
//

#ifndef INFANTRY_RECONSTRUCTION_IMU_H
#define INFANTRY_RECONSTRUCTION_IMU_H


#include "../USER/stm32f4xx.h"


#define M_PI  (float)3.1415926535
#define DMA_RX_NUM 16
#define MPU6500_RX_BUF_DATA_OFFSET 1

void IMU_Configure(void);
void IMU_INT_Configure(void);
void IMU_EXIT_STOP(void);
void IMU_EXIT_START(void);
void IIRLowPass(float ax, float ay, float az, float gx, float gy, float gz);
void MPU6050_Calibration(void);

typedef __packed struct
{
    int16_t     GyroXOffset;
    int16_t     GyroYOffset;
    int16_t     GyroZOffset;
    uint8_t     GyroCaliFlag;
}GyroCaliStruct_t;

typedef struct packed_angle
{
    float yaw;
    float pitch;
    float gx;
    float gz;

}packed_angle;

extern GyroCaliStruct_t GyroSavedCaliData;
extern volatile packed_angle real_angle;
extern float Gyro_z_err;
extern float Gyro_x_err;
extern float Gyro_y_err;



#endif //INFANTRY_RECONSTRUCTION_IMU_H
