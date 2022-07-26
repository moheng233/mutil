#ifndef __LIB_MUTIL_MPACK
#define __LIB_MUTIL_MPACK

#include <stdint.h>
#include <stdlib.h>

#include "stm32f10x_usart.h"

#include "mutil_conf_inter.h"
#ifdef __cplusplus
extern "C" {
#endif
#if ENABLE_MPACK == 1
typedef struct {
    uint8_t *data;
    unsigned int max;
    unsigned int cur;
} MPack;

/// 新建一个数据包
/// 默认不做包长度附加数据检查，请确保数据包长度足够
MPack *MPack_CreatePack(unsigned int max);
/// 释放数据包
void MPack_FreePack(MPack *pack);

/// 将数据包使用Usart发送
/// 默认会在包尾增加CRC校验
/// CRC校验为一个字节
/// 使用算法为CRC8 USB
void MPack_UsartSend(MPack *pack, USART_TypeDef *usart);

/// 将一个Int类型附加到数据包的结尾
void MPack_PackInt(MPack *pack, int data);
/// 将一个Char类型附加到数据包的结尾
void MPack_PackChar(MPack *pack, char data);
/// 将一个UInt16类型附加到数据包的结尾
void MPack_PackU16(MPack *pack, uint16_t data);

#endif
#ifdef __cplusplus
}
#endif
#endif // !__LIB_MUTIL_MPACK