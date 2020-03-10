//
// Created by moon misty on 2019/9/16.
//

#ifndef INFANTRY_RECONSTRUCTION_ENCODER_H
#define INFANTRY_RECONSTRUCTION_ENCODER_H

#define RATE_BUF_SIZE  6

//地盘电机 can1 id
#define CAN_ID_CM1		0x201
#define CAN_ID_CM2		0x202
#define CAN_ID_CM3		0x203
#define CAN_ID_CM4		0x204
//云台电机 can1 id
#define CAN_ID_YAW		0x205
#define CAN_ID_PITCH	0x206
//拨弹电机 can2 id
#define CAN_ID_CM_FEED  0x207

typedef struct{

    int32_t raw_value;   					 //编码器不经处理的原始值  int32_t用法跟int一样
    int32_t last_raw_value;					 //上一次的编码器原始值
    int32_t ecd_value;                       //经过处理后连续的编码器值
    int32_t diff;							 //两次编码器之间的差值
    int32_t temp_count;                      //计数用
    uint8_t buf_count;						 //滤波更新buf用
    int32_t ecd_bias;						 //初始编码器值
    int32_t ecd_raw_rate;					 //通过编码器计算得到的速度原始值


    int32_t rate_buf[RATE_BUF_SIZE];	     //buf，for filter 滤波器
    int32_t round_cnt;						 //圈数
    int32_t filter_rate;					 //速度
    float ecd_angle;	//角度
    float ecd_angle_first;
    int flag;       //标志位
    float init_angle;//开始读一次数据

}Encoder;

void CanReceiveMsgProcess(CanRxMsg *message); // STM库
void getEncoderData(volatile Encoder *v, CanRxMsg * msg);

extern volatile Encoder CM1Encoder; //extern：全局变量，可以让别的源文件引用
extern volatile Encoder CM2Encoder;
extern volatile Encoder CM3Encoder;
extern volatile Encoder CM4Encoder;
extern volatile Encoder GMYawEncoder;
extern volatile Encoder GMPitchEncoder;
extern volatile Encoder CMFeedEncoder;  // volatile：易变，不稳定



#endif //INFANTRY_RECONSTRUCTION_ENCODER_H
