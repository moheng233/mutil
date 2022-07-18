#include "mpack.h"
#include <stdint.h>
#include <stdlib.h>

MPack *MPack_CreatePack(unsigned int max)
{
    MPack *pack = malloc(sizeof(MPack));
    pack->max = max;
    pack->data = malloc(sizeof(int) * max);
    pack->cur = 0;

    return pack;
}

void MPack_FreePack(MPack *pack)
{
    free(pack->data);
    free(pack);
}

void MPack_PackInt(MPack *pack, int data)
{
    if (pack->cur < pack->max) {
        pack->data[pack->cur] = data;
        pack->cur += 1;
    }
}

void MPack_PackU16(MPack *pack, uint16_t data)
{
    if (pack->cur < pack->max) {
        pack->data[pack->cur] = (int)data;
        pack->cur += 1;
    }
}

void MPack_PackChar(MPack *pack, char data)
{
    if (pack->cur < pack->max) {
        pack->data[pack->cur] = data;
        pack->cur += 1;
    }
}

void MPack_UsartSend(MPack *pack, USART_TypeDef *usart)
{
    while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
        ;
    USART_SendData(usart, '!');

    for (size_t i = 0; i < pack->cur; i++) {
        while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
            ;
        USART_SendData(usart, pack->data[i]); // L当前照度开头
    }
    
    while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
        ;
    USART_SendData(usart, '\n');

    MPack_FreePack(pack);
}