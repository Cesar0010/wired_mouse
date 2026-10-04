//
// Created by Cesar on 2026/10/4.
//

#ifndef WIRED_MOUSE_BSP_ENCODER_H
#define WIRED_MOUSE_BSP_ENCODER_H

#include <stdint.h>

typedef struct
{
    int16_t last_cnt;
    int16_t cnt;
    int16_t step;
}ENCODER_T;

void bsp_encoder_init();
void bsp_encoder_scan();
int16_t bsp_encoder_get_step();

#endif //WIRED_MOUSE_BSP_ENCODER_H