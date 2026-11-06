//
// Created by Cesar on 2026/11/4.
//

#ifndef WIRED_MOUSE_BSP_USBX_H
#define WIRED_MOUSE_BSP_USBX_H

#include <stdint.h>
#include "tx_port.h"
#include "ux_api.h"
#include "ux_device_class_hid.h"

extern UX_SLAVE_CLASS_HID *hid_mouse;

uint8_t bsp_usbx_init(VOID *memory_ptr);

#endif //WIRED_MOUSE_BSP_USBX_H