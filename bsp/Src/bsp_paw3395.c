//
// Created by Cesar on 2026/10/29.
//

#include "bsp_paw3395.h"
#include "bsp_delay.h"
#include "bsp_spi.h"
#include "main.h"
#include "tx_api.h"

void bsp_paw3395_init()
{
    HAL_GPIO_WritePin(NRESET_GPIO_Port, NRESET_Pin, GPIO_PIN_RESET);
    tx_thread_sleep(10);
    HAL_GPIO_WritePin(NRESET_GPIO_Port, NRESET_Pin, GPIO_PIN_SET);
    tx_thread_sleep(10);

    bsp_spi1_cs_low();
    bsp_dwt_delay_ns(120);
    bsp_spi1_cs_high();
    bsp_dwt_delay_ns(120);

    bsp_write_register(PAW3395_SPI_REGISTER_POWER_UP_RESET, PAW3395_POWER_UP_RESET_POWER_ON);
    tx_thread_sleep(1);

    bsp_write_register(0x7F ,0x07);
	bsp_write_register(0x40 ,0x41);
	bsp_write_register(0x7F ,0x00);
	bsp_write_register(0x40 ,0x80);
	bsp_write_register(0x7F ,0x0E);
	bsp_write_register(0x55 ,0x0D);
	bsp_write_register(0x56 ,0x1B);
	bsp_write_register(0x57 ,0xE8);
	bsp_write_register(0x58 ,0xD5);
	bsp_write_register(0x7F ,0x14);
	bsp_write_register(0x42 ,0xBC);
	bsp_write_register(0x43 ,0x74);
	bsp_write_register(0x4B ,0x20);
	bsp_write_register(0x4D ,0x00);
	bsp_write_register(0x53 ,0x0E);
	bsp_write_register(0x7F ,0x05);
	bsp_write_register(0x44 ,0x04);
	bsp_write_register(0x4D ,0x06);
	bsp_write_register(0x51 ,0x40);
	bsp_write_register(0x53 ,0x40);
	bsp_write_register(0x55 ,0xCA);
	bsp_write_register(0x5A ,0xE8);
	bsp_write_register(0x5B ,0xEA);
	bsp_write_register(0x61 ,0x31);
	bsp_write_register(0x62 ,0x64);
	bsp_write_register(0x6D ,0xB8);
	bsp_write_register(0x6E ,0x0F);
	bsp_write_register(0x70 ,0x02);
	bsp_write_register(0x4A ,0x2A);
	bsp_write_register(0x60 ,0x26);
	bsp_write_register(0x7F ,0x06);
	bsp_write_register(0x6D ,0x70);
	bsp_write_register(0x6E ,0x60);
	bsp_write_register(0x6F ,0x04);
	bsp_write_register(0x53 ,0x02);
	bsp_write_register(0x55 ,0x11);
	bsp_write_register(0x7A ,0x01);
	bsp_write_register(0x7D ,0x51);
	bsp_write_register(0x7F ,0x07);
	bsp_write_register(0x41 ,0x10);
	bsp_write_register(0x42 ,0x32);
	bsp_write_register(0x43 ,0x00);
	bsp_write_register(0x7F ,0x08);
	bsp_write_register(0x71 ,0x4F);
	bsp_write_register(0x7F ,0x09);
	bsp_write_register(0x62 ,0x1F);
	bsp_write_register(0x63 ,0x1F);
	bsp_write_register(0x65 ,0x03);
	bsp_write_register(0x66 ,0x03);
	bsp_write_register(0x67 ,0x1F);
	bsp_write_register(0x68 ,0x1F);
	bsp_write_register(0x69 ,0x03);
	bsp_write_register(0x6A ,0x03);
	bsp_write_register(0x6C ,0x1F);
	bsp_write_register(0x6D ,0x1F);
	bsp_write_register(0x51 ,0x04);
	bsp_write_register(0x53 ,0x20);
	bsp_write_register(0x54 ,0x20);
	bsp_write_register(0x71 ,0x0C);
	bsp_write_register(0x72 ,0x07);
	bsp_write_register(0x73 ,0x07);
	bsp_write_register(0x7F ,0x0A);
	bsp_write_register(0x4A ,0x14);
	bsp_write_register(0x4C ,0x14);
	bsp_write_register(0x55 ,0x19);
	bsp_write_register(0x7F ,0x14);
	bsp_write_register(0x4B ,0x30);
	bsp_write_register(0x4C ,0x03);
	bsp_write_register(0x61 ,0x0B);
	bsp_write_register(0x62 ,0x0A);
	bsp_write_register(0x63 ,0x02);
	bsp_write_register(0x7F ,0x15);
	bsp_write_register(0x4C ,0x02);
	bsp_write_register(0x56 ,0x02);
	bsp_write_register(0x41 ,0x91);
	bsp_write_register(0x4D ,0x0A);
	bsp_write_register(0x7F ,0x0C);
	bsp_write_register(0x4A ,0x10);
	bsp_write_register(0x4B ,0x0C);
	bsp_write_register(0x4C ,0x40);
	bsp_write_register(0x41 ,0x25);
	bsp_write_register(0x55 ,0x18);
	bsp_write_register(0x56 ,0x14);
	bsp_write_register(0x49 ,0x0A);
	bsp_write_register(0x42 ,0x00);
	bsp_write_register(0x43 ,0x2D);
	bsp_write_register(0x44 ,0x0C);
	bsp_write_register(0x54 ,0x1A);
	bsp_write_register(0x5A ,0x0D);
	bsp_write_register(0x5F ,0x1E);
	bsp_write_register(0x5B ,0x05);
	bsp_write_register(0x5E ,0x0F);
	bsp_write_register(0x7F ,0x0D);
	bsp_write_register(0x48 ,0xDD);
	bsp_write_register(0x4F ,0x03);
	bsp_write_register(0x52 ,0x49);
	bsp_write_register(0x51 ,0x00);
	bsp_write_register(0x54 ,0x5B);
	bsp_write_register(0x53 ,0x00);
	bsp_write_register(0x56 ,0x64);
	bsp_write_register(0x55 ,0x00);
	bsp_write_register(0x58 ,0xA5);
	bsp_write_register(0x57 ,0x02);
	bsp_write_register(0x5A ,0x29);
	bsp_write_register(0x5B ,0x47);
	bsp_write_register(0x5C ,0x81);
	bsp_write_register(0x5D ,0x40);
	bsp_write_register(0x71 ,0xDC);
	bsp_write_register(0x70 ,0x07);
	bsp_write_register(0x73 ,0x00);
	bsp_write_register(0x72 ,0x08);
	bsp_write_register(0x75 ,0xDC);
	bsp_write_register(0x74 ,0x07);
	bsp_write_register(0x77 ,0x00);
	bsp_write_register(0x76 ,0x08);
	bsp_write_register(0x7F ,0x10);
	bsp_write_register(0x4C ,0xD0);
	bsp_write_register(0x7F ,0x00);
	bsp_write_register(0x4F ,0x63);
	bsp_write_register(0x4E ,0x00);
	bsp_write_register(0x52 ,0x63);
	bsp_write_register(0x51 ,0x00);
	bsp_write_register(0x54 ,0x54);
	bsp_write_register(0x5A ,0x10);
	bsp_write_register(0x77 ,0x4F);
	bsp_write_register(0x47 ,0x01);
	bsp_write_register(0x5B ,0x40);
	bsp_write_register(0x64 ,0x60);
	bsp_write_register(0x65 ,0x06);
	bsp_write_register(0x66 ,0x13);
	bsp_write_register(0x67 ,0x0F);
	bsp_write_register(0x78 ,0x01);
	bsp_write_register(0x79 ,0x9C);
	bsp_write_register(0x40 ,0x00);
	bsp_write_register(0x55 ,0x02);
	bsp_write_register(0x23 ,0x70);
	bsp_write_register(0x22 ,0x01);

	bsp_dwt_delay_us(1000);
	uint8_t i = 0;
	for (i = 0; i < 60; i++)
	{
		if (bsp_read_register(0x6C) == 0x80)
		{
			break;
		}
		bsp_dwt_delay_us(1000);
	}

	if (i == 60)
	{
		bsp_write_register(0x7F ,0x14);
		bsp_write_register(0x6C ,0x00);
		bsp_write_register(0x7F ,0x00);
	}
	bsp_write_register(0x22 ,0x00);
	bsp_write_register(0x55 ,0x00);
	bsp_write_register(0x7F ,0x07);
	bsp_write_register(0x40 ,0x40);
	bsp_write_register(0x7F ,0x00);

	uint8_t reg_it = 0;
	for (reg_it = 2; reg_it <= 6; reg_it++)
	{
		bsp_read_register(reg_it);
	}
}

void bsp_paw3395_burst_read(uint8_t *buffer)
{
	bsp_spi1_cs_low();
	bsp_dwt_delay_ns(120);
	bsp_spi_send_receive(PAW3395_SPI_REGISTER_MOTION_BURST);
	bsp_dwt_delay_us(2);
	uint8_t i = 0;
	for (i = 0; i < 12; i++)
	{
		buffer[i] = bsp_spi_send_receive(0x00);
	}
	bsp_dwt_delay_ns(120);
	bsp_spi1_cs_high();
	bsp_dwt_delay_us(2);
}

void bsp_paw3395_dpi_config(const uint16_t dpi)
{
	bsp_write_register(MOTION_CTRL, 0x00);
	uint16_t temp = 0;
	temp = (uint8_t)(((dpi/50) << 8) >> 8);
	bsp_write_register(RESOLUTION_X_LOW, temp);
	temp = (uint8_t)((dpi/50) >> 8);
	bsp_write_register(RESOLUTION_X_HIGH, temp);
	bsp_write_register(SET_RESOLUTION, 0x01);
}