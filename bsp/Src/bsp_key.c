//
// Created by Cesar on 2026/10/4.
//

#include "bsp_key.h"
#include "main.h"

GPIO_TypeDef* key_port[KEY_NUM] = {LEFT_KEY_GPIO_Port, RIGHT_KEY_GPIO_Port, MIDDLE_KEY_GPIO_Port, KEY_SET_GPIO_Port, KEY_LEFT_FRONT_GPIO_Port, KEY_LEFT_DOWN_GPIO_Port};
uint16_t key_pin[KEY_NUM] = {LEFT_KEY_Pin, RIGHT_KEY_Pin, MIDDLE_KEY_Pin, KEY_SET_Pin, KEY_LEFT_FRONT_Pin, KEY_LEFT_DOWN_Pin};

KEY_FIFO_T key_fifo;
KEY_T key[KEY_NUM];

void bsp_key_init()
{
    key_fifo.read = 0;
    key_fifo.write = 0;

    for(uint8_t i = 0; i < KEY_NUM; i++)
    {
        key[i].count = KEY_FILTER_TIME/2;
        key[i].state = 0;
    }
}

uint8_t bsp_is_key_down(const uint8_t key_id)
{
    if (HAL_GPIO_ReadPin(key_port[key_id], key_pin[key_id]) == GPIO_PIN_RESET)
    {
        return 1;
    }
    return 0;
}

void bsp_put_key(const uint8_t key_code)
{
    key_fifo.buffer[key_fifo.write] = key_code;
    if (++key_fifo.write >= KEY_FIFO_SIZE)
    {
        key_fifo.write = 0;
    }
}

uint8_t bsp_get_key()
{
    if (key_fifo.read == key_fifo.write)
    {
        return KEY_NONE;
    }
    uint8_t ret = key_fifo.buffer[key_fifo.read];
    if (++key_fifo.read >= KEY_FIFO_SIZE)
    {
        key_fifo.read = 0;
    }
    return ret;
}

void bsp_detect_key(uint8_t key_id)
{
    KEY_T* t_key = &key[key_id];

    if (bsp_is_key_down(key_id))
    {
        if (t_key->count < KEY_FILTER_TIME)
        {
            t_key->count = KEY_FILTER_TIME;
        }
        else if (t_key->count < 2 * KEY_FILTER_TIME)
        {
            t_key->count++;
        }
        else
        {
            if (t_key->state == 0)
            {
                t_key->state = 1;
                bsp_put_key((uint8_t)(2 * key_id + 1));
            }
        }
    }
    else
    {
        if (t_key->count > KEY_FILTER_TIME)
        {
            t_key->count = KEY_FILTER_TIME;
        }
        else if (t_key->count != 0)
        {
            t_key->count--;
        }
        else
        {
            if (t_key->state == 1)
            {
                t_key->state = 0;
                bsp_put_key((uint8_t)(2 * key_id + 2));
            }
        }
    }
}

void bsp_key_scan_per10ms()
{
    for (uint8_t i = 0; i < KEY_NUM; i++)
    {
        bsp_detect_key(i);
    }
}

uint8_t bsp_key_buffer_check()
{
    if (key_fifo.read != key_fifo.write)
    {
        return 1;
    }
    return 0;
}