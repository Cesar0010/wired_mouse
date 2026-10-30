//
// Created by Cesar on 2026/10/30.
//

#include "threadx_key.h"
#include <stdint.h>
#include "bsp.h"
#include "tx_api.h"

uint16_t dpi = 1500;

void app_task_key(ULONG thread_input)
{
    (void)thread_input;
    uint8_t temp = KEY_NONE;
    while(1)
    {
        do
        {
            bsp_key_scan_per10ms();

            temp = bsp_get_key();
            switch (temp)
            {
                case KEY0_DOWN:usb_hid_data.left_key = KEY_DOWN;break;
                case KEY0_UP:usb_hid_data.left_key = KEY_UP;break;
                case KEY1_DOWN:usb_hid_data.right_key = KEY_DOWN;break;
                case KEY1_UP:usb_hid_data.right_key = KEY_UP;break;
                case KEY2_DOWN:usb_hid_data.middle_key = KEY_DOWN;break;
                case KEY2_UP:usb_hid_data.middle_key = KEY_UP;break;

                case KEY3_UP:
                    {
                        dpi += 500;
                        if (dpi > 3000)
                        {
                            dpi = 500;
                        }
                        bsp_paw3395_dpi_config(dpi);
                        break;
                    }

                case KEY4_DOWN:usb_hid_data.left_front_key = KEY_DOWN;break;
                case KEY4_UP:usb_hid_data.left_front_key = KEY_UP;break;
                case KEY5_DOWN:usb_hid_data.left_back_key = KEY_DOWN;break;
                case KEY5_UP:usb_hid_data.left_back_key = KEY_UP;break;
            }
        }while(temp != KEY_NONE);
        tx_thread_sleep(2);
    }
}
