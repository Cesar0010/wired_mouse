//
// Created by Cesar on 2026/10/30.
//

#ifndef WIRED_MOUSE_THREADX_KEY_H
#define WIRED_MOUSE_THREADX_KEY_H

#include "tx_port.h"

typedef enum
{
    KEY_DOWN = 1,
    KEY_UP = 0
}KEY_STATUS_ENUM;

void app_task_key(ULONG thread_input);

#endif //WIRED_MOUSE_THREADX_KEY_H