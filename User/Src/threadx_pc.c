//
// Created by Cesar on 2026/10/30.
//

#include "threadx_pc.h"

#include "tx_api.h"

void app_task_pc(ULONG thread_input)
{
    (void)thread_input;
    while(1)
    {
        tx_thread_sleep(1000);
    }
}
