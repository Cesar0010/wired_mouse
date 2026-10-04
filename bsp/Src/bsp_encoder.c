//
// Created by Cesar on 2026/10/4.
//

#include "bsp_encoder.h"
#include "tim.h"

ENCODER_T wheel_encoder;

void bsp_encoder_init()
{
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
    wheel_encoder.cnt = 0;
    wheel_encoder.step = 0;
    wheel_encoder.last_cnt = 0;
}

void bsp_encoder_scan()
{
    wheel_encoder.cnt = (int16_t)__HAL_TIM_GET_COUNTER(&htim3);
    wheel_encoder.step = wheel_encoder.cnt - wheel_encoder.last_cnt;
    wheel_encoder.last_cnt = wheel_encoder.cnt;
}

int16_t bsp_encoder_get_step()
{
    return wheel_encoder.step;
}