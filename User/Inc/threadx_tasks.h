//
// Created by Cesar on 2026/10/30.
//

#ifndef WIRED_MOUSE_THREADX_TASKS_H
#define WIRED_MOUSE_THREADX_TASKS_H

#include "tx_api.h"
#include "tx_port.h"

#define TIME_TO_SEND_DATA_TO_PC            (1 << 0)

extern TX_EVENT_FLAGS_GROUP event_group;

void threadx_application_define();
void app_task_start(ULONG thread_input);
void app_tasks_create();
void app_obj_create();

#endif //WIRED_MOUSE_THREADX_TASKS_H