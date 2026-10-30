//
// Created by Cesar on 2026/10/30.
//

#ifndef WIRED_MOUSE_BSP_CATHE_H
#define WIRED_MOUSE_BSP_CATHE_H

#include <stdint.h>

typedef struct
{
    uint8_t left_key;
    uint8_t middle_key;
    uint8_t right_key;
    uint8_t left_front_key;
    uint8_t left_back_key;

    int16_t encoder_step;

    int16_t dx;
    int16_t dy;
}USB_HID_T;

extern USB_HID_T usb_hid_data;

void bsp_cathe_init();

#endif //WIRED_MOUSE_BSP_CATHE_H