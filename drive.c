#include "stm32f10x.h"

#include "drive.h"

#include "mutil_conf_inter.h"

#if ENABLE_DRIVE == 1

#define DRIVE_RCC_ENABLE_HELPER(_CLOCK, _Periph) RCC_##_CLOCK##PeriphClockCmd(RCC_##_CLOCK##Periph_##_Periph, ENABLE);

void DRIVE_RCC_ENABLE(RCCPeriphClock clock)
{
    switch (clock) {
    case RCCPeriphClock_GPIOA:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOA);
        break;
    case RCCPeriphClock_GPIOB:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOB);
        break;
    case RCCPeriphClock_GPIOC:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOC);
        break;
    case RCCPeriphClock_GPIOD:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOD);
        break;
    case RCCPeriphClock_GPIOE:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOE);
        break;
    case RCCPeriphClock_GPIOF:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOF);
        break;
    case RCCPeriphClock_TIM1:
        DRIVE_RCC_ENABLE_HELPER(APB2, TIM1);
        break;
    case RCCPeriphClock_TIM8:
        DRIVE_RCC_ENABLE_HELPER(APB2, TIM8);
        break;
    case RCCPeriphClock_SPI1:
        DRIVE_RCC_ENABLE_HELPER(APB2, SPI1);
        break;
    case RCCPeriphClock_USART1:
        DRIVE_RCC_ENABLE_HELPER(APB2, USART1);
        break;
    case RCCPeriphClock_ADC1:
        DRIVE_RCC_ENABLE_HELPER(APB2, ADC1);
        break;
    case RCCPeriphClock_ADC2:
        DRIVE_RCC_ENABLE_HELPER(APB2, ADC2);
        break;
    case RCCPeriphClock_ADC3:
        DRIVE_RCC_ENABLE_HELPER(APB2, ADC3);
        break;
    case RCCPeriphClock_TIM2:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM2);
        break;
    case RCCPeriphClock_TIM3:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM3);
        break;
    case RCCPeriphClock_TIM4:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM4);
        break;
    case RCCPeriphClock_TIM5:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM5);
        break;
    case RCCPeriphClock_TIM6:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM6);
        break;
    case RCCPeriphClock_TIM7:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM7);
        break;
    case RCCPeriphClock_USART2:
        DRIVE_RCC_ENABLE_HELPER(APB1, USART2);
        break;
    case RCCPeriphClock_USART3:
        DRIVE_RCC_ENABLE_HELPER(APB1, USART3);
        break;
    case RCCPeriphClock_UART4:
        DRIVE_RCC_ENABLE_HELPER(APB1, UART4);
        break;
    case RCCPeriphClock_UART5:
        DRIVE_RCC_ENABLE_HELPER(APB1, UART5);
        break;
    default:
        break;
    }
}

#endif