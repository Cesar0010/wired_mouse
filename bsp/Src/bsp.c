//
// Created by Cesar on 2026/10/4.
//

#include "bsp.h"

void bsp_init()
{
    bsp_key_init();
    bsp_encoder_init();
    bsp_ws2812_init();
    bsp_dwt_init();
    bsp_paw3395_init();
}