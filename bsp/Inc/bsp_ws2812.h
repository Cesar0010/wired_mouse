//
// Created by Cesar on 2026/10/5.
//

#ifndef WIRED_MOUSE_BSP_WS2812_H
#define WIRED_MOUSE_BSP_WS2812_H

#include <stdint.h>

#define WS2812_LED_SIZE 24
#define WS2812_BIT0_CCR 25
#define WS2812_BIT1_CCR 59
#define WS2812_RESET_SIZE 224

#define COLOR_NUM 6
#define LIGHT_STATE 25

typedef struct
{
    uint8_t green;
    uint8_t red;
    uint8_t blue;
}WS2812_GRB_t;

void bsp_ws2812_set_color(const WS2812_GRB_t *grb);
void bsp_ws2812_refresh();
void bsp_ws2812_init();
void bsp_ws2812_breathe();

#endif //WIRED_MOUSE_BSP_WS2812_H