#ifndef __LIB_MUTIL_LED
#define __LIB_MUTIL_LED

#include <stdbool.h>

#include <stm32f10x.h>

#define DRIVE_LED1
#define DRIVE_LED1_GPIO GPIOE
#define DRIVE_LED1_PIN  GPIO_Pin_12

// 通用初始化LED
#define DRIVE_LED_INIT(_DRIVE_LED)                                              \
    {                                                                           \
        DRIVE_GPIO_INIT(_DRIVE_LED##_GPIO, _DRIVE_LED##_PIN, GPIO_Mode_Out_PP); \
    }

#define DRIVE_LED_ENABLE(_DRIVE_LED)                         \
    {                                                        \
        GPIO_ResetBits(_DRIVE_LED##_GPIO, _DRIVE_LED##_PIN); \
    }

#define DRIVE_LED_DISABLE(_DRIVE_LED)                      \
    {                                                      \
        GPIO_SetBits(_DRIVE_LED##_GPIO, _DRIVE_LED##_PIN); \
    }

#define DRIVE_LED_GET_STATE(_DRIVE_LED) GPIO_ReadOutputDataBit(_DRIVE_LED##_GPIO, _DRIVE_LED##_PIN)

#endif // !__LED_H