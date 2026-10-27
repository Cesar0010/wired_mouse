//
// Created by Cesar on 2026/10/27.
//

#include "stm32f4xx.h"

void bsp_dwt_init()
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk; // 开启跟踪
    DWT->CYCCNT = 0;                                // 清零计数器
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;            // 开启周期计数
}

void bsp_dwt_delay_us(const uint32_t us)
{
    uint32_t start = DWT->CYCCNT;
    uint32_t cycles = us * (SystemCoreClock / 1000000UL);
    while((DWT->CYCCNT - start) < cycles);
}

void bsp_dwt_delay_ns(const uint32_t ns)
{
    uint32_t start = DWT->CYCCNT;
    uint32_t cycles = (uint64_t)ns * SystemCoreClock / 1000000000UL;
    while((DWT->CYCCNT - start) < cycles);
}