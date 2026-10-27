//
// Created by Cesar on 2026/10/27.
//

#ifndef WIRED_MOUSE_BSP_DELAY_H
#define WIRED_MOUSE_BSP_DELAY_H

#include <stdint.h>

void bsp_dwt_init();
void bsp_dwt_delay_us(uint32_t us);
void bsp_dwt_delay_ns(uint32_t ns);

#endif //WIRED_MOUSE_BSP_DELAY_H