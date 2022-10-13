#include "mpack.h"

#if ENABLE_MPACK == 1
MPack *MPack_CreatePack(unsigned int max)
{
    MPack *pack = malloc(sizeof(MPack));
    pack->max = max;
    pack->data = malloc(sizeof(uint8_t) * max);
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
        pack->data[pack->cur] = (uint8_t)data;
        pack->cur += 1;
    }
}

void MPack_PackU16(MPack *pack, uint16_t data)
{
    if (pack->cur < pack->max) {
        pack->data[pack->cur] = data;
        pack->cur += 1;
        pack->data[pack->cur] = data << 8;
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

void MPack_PackStr(MPack *pack, char *data, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        MPack_PackChar(pack, data[i]);

        if (data[i + 1] == '\0') {
            break;
        }
    }
}

uint8_t MPack_CRC(uint8_t *data, uint16_t length)
{
    uint8_t i;
    uint8_t crc = 0x1F; // Initial value
    while (length--) {
        crc ^= *data++; // crc ^= *data; data++;
        for (i = 0; i < 8; ++i) {
            if (crc & 1)
                crc = (crc >> 1) ^ 0x14; // 0x14 = (reverse 0x05)>>(8-5)
            else
                crc = (crc >> 1);
        }
    }
    return crc ^ 0x1F;
}

void MPack_UsartSend(MPack *pack, USART_TypeDef *usart)
{
    while (USART_GetFlagStatus(usart, USART_FLAG_TC) == RESET)
        ;
    USART_SendData(usart, '!');

    for (size_t i = 0; i < pack->cur; i++) {
        while (USART_GetFlagStatus(usart, USART_FLAG_TC) == RESET)
            ;
        USART_SendData(usart, pack->data[i]);
    }

    while (USART_GetFlagStatus(usart, USART_FLAG_TC) == RESET)
        ;
    // 计算并发送CRC校验码
    USART_SendData(usart, MPack_CRC(pack->data, pack->cur));

    while (USART_GetFlagStatus(usart, USART_FLAG_TC) == RESET)
        ;
    USART_SendData(usart, '\n');

    MPack_FreePack(pack);
}
#endif