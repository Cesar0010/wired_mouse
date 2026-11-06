//
// Created by Cesar on 2026/11/4.
//

#include "stm32f4xx_hal.h"
#include "tx_port.h"
#include "ux_api.h"
#include "ux_device_class_hid.h"
#include "ux_device_descriptors.h"
#include "bsp_usbx.h"
#include "app_azure_rtos_config.h"

UX_SLAVE_CLASS_HID *hid_mouse = UX_NULL;

void usb_hid_mouse_activate(void *hid_instance)
{
    hid_mouse = (UX_SLAVE_CLASS_HID *)hid_instance;
}

void usb_hid_mouse_deactivate(void *hid_instance)
{
    hid_mouse = UX_NULL;
}

uint8_t bsp_usbx_init(void *memory_ptr)
{
    TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL*)memory_ptr;
    uint8_t temp;

    void *pointer;
    ULONG framework_hs_len, framework_fs_len, string_len, langid_len;
    UX_SLAVE_CLASS_HID_PARAMETER hid_parameter;

    // 从传入的内存池中分出一块给 USBX 系统
    temp = tx_byte_allocate(byte_pool, &pointer, UX_DEVICE_APP_MEM_POOL_SIZE - 1024, TX_NO_WAIT);
    // 初始化 USBX 系统
    temp = ux_system_initialize(pointer, UX_DEVICE_APP_MEM_POOL_SIZE - 1024, UX_NULL, 0);

    // 获取你在 ux_device_descriptors.c 里生成的描述符
    uint8_t* framework_hs = USBD_Get_Device_Framework_Speed(USBD_HIGH_SPEED, &framework_hs_len);
    uint8_t* framework_fs = USBD_Get_Device_Framework_Speed(USBD_FULL_SPEED, &framework_fs_len);
    uint8_t* string_framework = USBD_Get_String_Framework(&string_len);
    uint8_t* langid_framework = USBD_Get_Language_Id_Framework(&langid_len);

    // 初始化 USBX 设备栈
    temp = ux_device_stack_initialize(framework_hs, framework_hs_len, framework_fs, framework_fs_len,
                                     string_framework, string_len, langid_framework, langid_len, UX_NULL);

    // 注册 HID 鼠标类
    hid_parameter.ux_device_class_hid_parameter_report_address = USBD_Get_Device_HID_MOUSE_ReportDesc();
    hid_parameter.ux_device_class_hid_parameter_report_length  = USBD_HID_MOUSE_REPORT_DESC_SIZE;
    hid_parameter.ux_slave_class_hid_instance_activate   = usb_hid_mouse_activate;
    hid_parameter.ux_slave_class_hid_instance_deactivate = usb_hid_mouse_deactivate;

    // 绑定软件协议和硬件接口
    temp = ux_device_stack_class_register(_ux_system_slave_class_hid_name, ux_device_class_hid_entry,
                                         1, 0, &hid_parameter);
    return temp;
}