//
// Created by Cesar on 2026/10/30.
//

#include "threadx_pc.h"
#include "threadx_tasks.h"
#include "tx_api.h"
#include "bsp.h"
#include "tim.h"

void app_task_pc(ULONG thread_input)
{
    (void)thread_input;
    ULONG time_to_pack_and_go;
    while(1)
    {
        tx_event_flags_get(&event_group,TIME_TO_SEND_DATA_TO_PC,TX_OR_CLEAR,&time_to_pack_and_go,TX_WAIT_FOREVER);
        /*
         *pack and go;
         */
        uint8_t buffer[12] = {0};
        bsp_paw3395_burst_read(buffer);
        usb_hid_data.dx = (int16_t)((buffer[3] << 8) | buffer[2]);
        usb_hid_data.dy = (int16_t)((buffer[5] << 8) | buffer[4]);
    }
}