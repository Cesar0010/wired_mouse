//
// Created by Cesar on 2026/10/30.
//

#include "threadx_tasks.h"
#include <stdint.h>

#include "bsp.h"
#include "stm32f4xx_hal.h"
#include "threadx_key.h"
#include "threadx_pc.h"
#include "threadx_encoder.h"
#include "threadx_ws2812.h"
#include "tx_api.h"

#define  APP_CFG_TASK_START_PRIO                          2u
#define  APP_CFG_TASK_PC_PRIO                             3u
#define  APP_CFG_TASK_ENCODER_PRIO                        4u
#define  APP_CFG_TASK_KEY_PRIO                            4u
#define  APP_CFG_TASK_WS2812_PRIO                         5u

#define  APP_CFG_TASK_START_STK_SIZE                    2048u
#define  APP_CFG_TASK_PC_STK_SIZE                       2048u
#define  APP_CFG_TASK_KEY_STK_SIZE                      1024u
#define  APP_CFG_TASK_ENCODER_STK_SIZE                  1024u
#define  APP_CFG_TASK_WS2812_STK_SIZE                   1024u

static  TX_THREAD   app_task_start_tcb;
static char app_task_start_name[] = "App Task Start";
static  uint64_t    app_task_start_stk[APP_CFG_TASK_START_STK_SIZE/8];

static  TX_THREAD   app_task_pc_tcb;
static char app_task_pc_name[] = "App Task Control";
static  uint64_t    app_task_pc_stk[APP_CFG_TASK_PC_STK_SIZE/8];

static  TX_THREAD   app_task_key_tcb;
static char app_task_key_name[] = "App Task Imu";
static  uint64_t    app_task_key_stk[APP_CFG_TASK_KEY_STK_SIZE/8];

static  TX_THREAD   app_task_encoder_tcb;
static char app_task_encoder_name[] = "App Task UART";
static  uint64_t    app_task_encoder_stk[APP_CFG_TASK_ENCODER_STK_SIZE/8];

static  TX_THREAD   app_task_ws2812_tcb;
static char app_task_ws2812_name[] = "App Task WS2812";
static uint64_t     app_task_ws2812_stk[APP_CFG_TASK_WS2812_STK_SIZE/8];

TX_EVENT_FLAGS_GROUP event_group;
static char event_group_name[] = "Event Group";

void threadx_application_define()
{
    tx_thread_create(&app_task_start_tcb,
                       app_task_start_name,
                       app_task_start,
                       0,
                       &app_task_start_stk[0],
                       APP_CFG_TASK_START_STK_SIZE,
                       APP_CFG_TASK_START_PRIO,
                       APP_CFG_TASK_START_PRIO,
                       TX_NO_TIME_SLICE,
                       TX_AUTO_START);
}

void app_task_start(ULONG thread_input)
{
    (void)thread_input;

    HAL_ResumeTick();
    bsp_init();
    app_tasks_create();
    app_obj_create();

    while (1)
    {
        tx_thread_sleep(1000);
    }
}

void app_tasks_create()
{
    tx_thread_create(&app_task_pc_tcb,
                        app_task_pc_name,
                        app_task_pc,
                        0,
                        &app_task_pc_stk[0],
                        APP_CFG_TASK_PC_STK_SIZE,
                        APP_CFG_TASK_PC_PRIO,
                        APP_CFG_TASK_PC_PRIO,
                        TX_NO_TIME_SLICE,
                        TX_AUTO_START);
    tx_thread_create(&app_task_key_tcb,
                        app_task_key_name,
                        app_task_key,
                        0,
                        &app_task_key_stk[0],
                        APP_CFG_TASK_KEY_STK_SIZE,
                        APP_CFG_TASK_KEY_PRIO,
                        APP_CFG_TASK_KEY_PRIO,
                        TX_NO_TIME_SLICE,
                        TX_AUTO_START);
    tx_thread_create(&app_task_encoder_tcb,
                        app_task_encoder_name,
                        app_task_encoder,
                        0,
                        &app_task_encoder_stk[0],
                        APP_CFG_TASK_ENCODER_STK_SIZE,
                        APP_CFG_TASK_ENCODER_PRIO,
                        APP_CFG_TASK_ENCODER_PRIO,
                        TX_NO_TIME_SLICE,
                        TX_AUTO_START);
    tx_thread_create(&app_task_ws2812_tcb,
                        app_task_ws2812_name,
                        app_task_ws2812,
                        0,
                        &app_task_ws2812_stk[0],
                        APP_CFG_TASK_WS2812_STK_SIZE,
                        APP_CFG_TASK_WS2812_PRIO,
                        APP_CFG_TASK_WS2812_PRIO,
                        TX_NO_TIME_SLICE,
                        TX_AUTO_START);
}

void app_obj_create()
{
    tx_event_flags_create(&event_group, event_group_name);
}