//
// Created by Cesar on 2026/10/5.
//

#include "bsp_ws2812.h"
#include "tim.h"

uint32_t ws2812_buf[WS2812_LED_SIZE + 224];
static uint8_t ws2812_buf_busy = 0;

void bsp_ws2812_set_color(const uint8_t g, const uint8_t r, const uint8_t b)
{
    uint8_t color_buf[3] = {g, r, b};
    uint8_t pos = 0;
    for (uint8_t byte = 0; byte < 3; byte++)
    {
        for (int8_t bit = 7; bit >= 0; bit--)
        {
            if (color_buf[byte] >> bit & 1)
            {
                ws2812_buf[pos++] = WS2812_BIT1_CCR;
            }
            else
            {
                ws2812_buf[pos++] = WS2812_BIT0_CCR;
            }
        }
    }

    for (uint8_t i = 0; i < WS2812_RESET_SIZE; i++)
    {
        ws2812_buf[pos++] = 0;
    }
}

void bsp_ws2812_refresh()
{

    if (ws2812_buf_busy)
    {
        return;
    }
    ws2812_buf_busy = 1;

    HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t*)ws2812_buf, WS2812_LED_SIZE + WS2812_RESET_SIZE);
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_1);
    ws2812_buf_busy = 0;
}