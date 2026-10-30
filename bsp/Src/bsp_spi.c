//
// Created by Cesar on 2026/10/28.
//

#include "bsp_spi.h"
#include "main.h"
#include "spi.h"
#include "bsp_delay.h"

void bsp_spi1_cs_low()
{
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
}

void bsp_spi1_cs_high()
{
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
}

uint8_t bsp_spi_send_receive(const uint8_t data)
{
    uint8_t rx;
    HAL_SPI_TransmitReceive(&hspi1, &data, &rx, 1, 100);
    return rx;
}

uint8_t bsp_read_register(const uint8_t address)
{
    unsigned char temp;
    bsp_spi1_cs_low();
    bsp_dwt_delay_ns(120);

    bsp_spi_send_receive(address & 0x7F);

    bsp_dwt_delay_us(2);

    temp = bsp_spi_send_receive(0xFF);

    bsp_dwt_delay_ns(120);
    bsp_spi1_cs_high();

    bsp_dwt_delay_us(2);
    return temp;
}

void bsp_write_register(const uint8_t address, const uint8_t value)
{
    bsp_spi1_cs_low();
    bsp_dwt_delay_ns(120);

    bsp_spi_send_receive(address | 0x80);

    bsp_dwt_delay_us(5);

    bsp_spi_send_receive(value);

    bsp_dwt_delay_us(1);
    bsp_spi1_cs_high();

    bsp_dwt_delay_us(5);
}