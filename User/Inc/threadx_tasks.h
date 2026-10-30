//
// Created by Cesar on 2026/10/30.
//

#ifndef WIRED_MOUSE_THREADX_TASKS_H
#define WIRED_MOUSE_THREADX_TASKS_H

#include "tx_port.h"

void threadx_application_define();
void app_task_start(ULONG thread_input);
void app_tasks_create();
void app_obj_create();

#endif //WIRED_MOUSE_THREADX_TASKS_H