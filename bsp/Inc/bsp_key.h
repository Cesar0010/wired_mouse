//
// Created by Cesar on 2026/10/4.
//

#ifndef WIRED_MOUSE_BSP_KEY_H
#define WIRED_MOUSE_BSP_KEY_H

#include <stdint.h>

#define KEY_FIFO_SIZE 10
#define KEY_NUM 6
#define KEY_FILTER_TIME 2 //2*10ms

//令左键id=0，右键id=1，中键id=2，分辨率设置键id=3，左侧前键id=4，左侧后键id=5。
typedef enum
{
    KEY_NONE = 0,

    KEY0_DOWN = 1,
    KEY0_UP = 2,

    KEY1_DOWN = 3,
    KEY1_UP = 4,

    KEY2_DOWN = 5,
    KEY2_UP = 6,

    KEY3_DOWN = 7,
    KEY3_UP = 8,

    KEY4_DOWN = 9,
    KEY4_UP = 10,

    KEY5_DOWN = 11,
    KEY5_UP = 12,
}KEY_ENUM;

typedef struct
{
    uint8_t buffer[KEY_FIFO_SIZE];
    uint8_t write;
    uint8_t read;
}KEY_FIFO_T;

typedef struct
{
    uint8_t state;
    uint8_t count;
}KEY_T;

void bsp_key_init();
uint8_t bsp_is_key_down(uint8_t key_id);//按键接到GND和MCU引脚之间,返回1是按下。
void bsp_put_key(uint8_t key_code);
uint8_t bsp_get_key();
void bsp_detect_key(uint8_t key_id);
void bsp_key_scan_per10ms();
uint8_t bsp_key_buffer_check(); //返回1是非空。

#endif //WIRED_MOUSE_BSP_KEY_H