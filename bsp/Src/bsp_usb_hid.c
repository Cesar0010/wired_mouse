//
// Created by Cesar on 2026/11/4.
//

#include "stm32f4xx_hal.h"
#include "usb_otg.h"
#include "tx_port.h"
#include "ux_api.h"
#include "ux_dcd_stm32.h"
#include "ux_device_class_hid.h"
#include "bsp_usb_hid.h"
#include "bsp_cathe.h"
#include "bsp_usbx.h"
#include "bsp_key.h"

void bsp_usb_hid_init()
{
    // 配置FIFO
    HAL_PCD_SetRxFiFo(&hpcd_USB_OTG_FS, 0x200);
    HAL_PCD_SetTxFiFo(&hpcd_USB_OTG_FS, 0, 0x10);
    HAL_PCD_SetTxFiFo(&hpcd_USB_OTG_FS, 1, 0x10);

    // 链接底层驱动并启动
    ux_dcd_stm32_initialize((ULONG)USB_OTG_FS, (ULONG)&hpcd_USB_OTG_FS);
    HAL_PCD_Start(&hpcd_USB_OTG_FS);
}

void bsp_usb_hid_pack_and_go()
{
    UX_SLAVE_CLASS_HID_EVENT hid_event;
    uint8_t reportData[6] = {0};

    if (usb_hid_data.left_key == KEY_DOWN)
    {
        reportData[0] |= (1 << 0);
    }
    if (usb_hid_data.right_key == KEY_DOWN)
    {
        reportData[0] |= (1 << 1);
    }
    if (usb_hid_data.middle_key == KEY_DOWN)
    {
        reportData[0] |= (1 << 2);
    }
    if (usb_hid_data.left_back_key == KEY_DOWN)
    {
        reportData[0] |= (1 << 3);
    }
    if (usb_hid_data.left_front_key == KEY_DOWN)
    {
        reportData[0] |= (1 << 4);
    }

    int16_t dx = usb_hid_data.dx;
    int16_t dy = usb_hid_data.dy;
    reportData[1] = dx & 0xFF;
    reportData[2] = (dx >> 8) & 0xFF;
    reportData[3] = dy & 0xFF;
    reportData[4] = (dy >> 8) & 0xFF;

    int16_t encoder_raw = usb_hid_data.encoder_step;
    int8_t wheel_clamped = 0;
    if (encoder_raw > 127) {
        wheel_clamped = 127;
    } else if (encoder_raw < -127) {
        wheel_clamped = -127;
    } else {
        wheel_clamped = (int8_t)encoder_raw;
    }
    reportData[5] = (uint8_t)wheel_clamped;

    memcpy(hid_event.ux_device_class_hid_event_buffer, reportData, sizeof(reportData));
    hid_event.ux_device_class_hid_event_length = sizeof(reportData);

    ux_device_class_hid_event_set(hid_mouse, &hid_event);
}