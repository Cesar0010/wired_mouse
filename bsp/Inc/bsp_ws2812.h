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

void bsp_ws2812_set_color(uint8_t g, uint8_t r, uint8_t b);
void bsp_ws2812_refresh();

#endif //WIRED_MOUSE_BSP_WS2812_H