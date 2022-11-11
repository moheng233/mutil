#include "systick.h"

#include "cmsis_compiler.h"

#include "stm32f10x.h"
#include "core_cm3.h"
#include "misc.h"

volatile uint64_t ticks = 0;

__WEAK void SysTick_Handler(void)
{
    Systick_Update();
}

void Systick_Init(uint32_t frequency)
{
    SysTick_Config(frequency);
}

void Systick_Update() {
    ticks += 1;
}

__INLINE uint64_t Systick_tick() {
    return ticks;
}