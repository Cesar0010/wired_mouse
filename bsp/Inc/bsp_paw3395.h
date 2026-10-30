//
// Created by Cesar on 2026/10/29.
//

#ifndef WIRED_MOUSE_BSP_PAW3395_H
#define WIRED_MOUSE_BSP_PAW3395_H

#include <stdint.h>

#define PAW3395_SPI_REGISTER_POWER_UP_RESET	0x3A
#define PAW3395_POWER_UP_RESET_POWER_ON	    0x5A
#define PAW3395_SPI_REGISTER_MOTION_BURST 	0x16
#define MOTION_CTRL							0x5C
#define SET_RESOLUTION						0x47
#define RESOLUTION_X_LOW					0x48
#define RESOLUTION_X_HIGH					0x49

void bsp_paw3395_init();
void bsp_paw3395_burst_read(uint8_t *buffer);
void bsp_paw3395_dpi_config(uint16_t dpi);

#endif //WIRED_MOUSE_BSP_PAW3395_H