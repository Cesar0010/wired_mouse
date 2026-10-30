//
// Created by Cesar on 2026/10/30.
//

#include "threadx_ws2812.h"
#include "bsp.h"
#include "tx_api.h"

void app_task_ws2812(ULONG thread_input)
{
    (void)thread_input;
    while(1)
    {
        bsp_ws2812_breathe();
        tx_thread_sleep(4);
    }
}
