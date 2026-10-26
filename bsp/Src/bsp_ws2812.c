//
// Created by Cesar on 2026/10/5.
//

#include "bsp_ws2812.h"
#include "tim.h"

WS2812_GRB_t ws2812_grb[WS2812_LED_SIZE] = {
    {0, 4, 0},
    {2, 4, 0},
    {4, 0, 0},
    {4, 0, 4},
    {0, 0, 4},
    {0, 4, 4}
};

typedef struct
{
    uint8_t current_color_num;
    uint8_t current_light_state;
    uint8_t up_or_down;         //1是up，0是down。
    WS2812_GRB_t grb;
}WS2812_Breathe_t;

uint32_t ws2812_buf[WS2812_LED_SIZE + WS2812_RESET_SIZE];
volatile uint8_t ws2812_buf_busy = 0;
WS2812_Breathe_t ws2812_breathe;

void bsp_ws2812_set_color(const WS2812_GRB_t *grb)
{
    uint8_t color_buf[3] = {grb->green, grb->red, grb->blue};
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

void bsp_ws2812_init()
{
    ws2812_breathe.current_color_num = 0;
    ws2812_breathe.current_light_state = 0;
    ws2812_breathe.up_or_down = 1;
}

void bsp_ws2812_breathe()
{
    if (ws2812_breathe.up_or_down == 1)//亮度增大。
    {
        ws2812_breathe.current_light_state++;
        if (ws2812_breathe.current_light_state == LIGHT_STATE)
        {
            ws2812_breathe.up_or_down = 0;
        }
    }
    else
    {
        ws2812_breathe.current_light_state--;
        if (ws2812_breathe.current_light_state == 0)
        {
            ws2812_breathe.up_or_down = 1;
            ws2812_breathe.current_color_num++;
            if (ws2812_breathe.current_color_num == COLOR_NUM)
            {
                ws2812_breathe.current_color_num = 0;
            }
        }
    }
    ws2812_breathe.grb.green = ws2812_grb[ws2812_breathe.current_color_num].green * ws2812_breathe.current_light_state;
    ws2812_breathe.grb.red = ws2812_grb[ws2812_breathe.current_color_num].red * ws2812_breathe.current_light_state;
    ws2812_breathe.grb.blue = ws2812_grb[ws2812_breathe.current_color_num].blue * ws2812_breathe.current_light_state;
    bsp_ws2812_set_color(&ws2812_breathe.grb);
    bsp_ws2812_refresh();
}