//
// Created by Cesar on 2026/10/30.
//

#include "threadx_encoder.h"
#include "bsp.h"
#include "tx_api.h"

void app_task_encoder(ULONG thread_input)
{
    (void)thread_input;

    while(1)
    {
        bsp_encoder_scan();
        usb_hid_data.encoder_step = bsp_encoder_get_step();
        tx_thread_sleep(1);
    }
}
