//
// Created by Cesar on 2026/10/28.
//

#ifndef WIRED_MOUSE_BSP_SPI_H
#define WIRED_MOUSE_BSP_SPI_H

#include <stdint.h>

void bsp_spi1_cs_low();
void bsp_spi1_cs_high();
uint8_t bsp_spi_send_receive(uint8_t data);
uint8_t bsp_read_register(uint8_t address);
void bsp_write_register(uint8_t address, uint8_t value);

#endif //WIRED_MOUSE_BSP_SPI_H