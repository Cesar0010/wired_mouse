//
// Created by Cesar on 2026/10/30.
//

#include "bsp_cathe.h"

USB_HID_T usb_hid_data;

void bsp_cathe_init()
{
    usb_hid_data.left_key = 0;
    usb_hid_data.right_key = 0;
    usb_hid_data.middle_key = 0;
    usb_hid_data.left_front_key = 0;
    usb_hid_data.left_back_key = 0;

    usb_hid_data.encoder_step = 0;

    usb_hid_data.dx = 0;
    usb_hid_data.dy = 0;
}