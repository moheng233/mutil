#ifndef __LIB_MUTIL_MPACK
#define __LIB_MUTIL_MPACK

#include "stdlib.h"
#include <stdint.h>

#include "stm32f10x_usart.h"

typedef struct {
    uint8_t *data;
    unsigned int max;
    unsigned int cur;
} MPack;

MPack *MPack_CreatePack(unsigned int max);
void MPack_FreePack(MPack *pack);

void MPack_UsartSend(MPack *pack, USART_TypeDef *usart);

void MPack_PackInt(MPack *pack, int data);
void MPack_PackChar(MPack *pack, char data);
void MPack_PackU16(MPack *pack, uint16_t data);

#endif // !__LIB_MUTIL_MPACK