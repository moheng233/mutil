#ifndef __LIB_MUTIL_SYSTICK
#define __LIB_MUTIL_SYSTICK

#include "stdint.h"

extern volatile uint64_t ticks;

void Systick_Init(uint32_t frequency);

uint64_t Systick_tick();

void Systick_Update();

#endif