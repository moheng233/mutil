#include "stm32f10x.h"

#include "drive.h"

#include "mutil_conf_inter.h"

#if ENABLE_DRIVE == 1

#define DRIVE_RCC_ENABLE_HELPER(_CLOCK, _Periph) RCC_##_CLOCK##PeriphClockCmd(RCC_##_CLOCK##Periph_##_Periph, ENABLE);

void DRIVE_RCC_ENABLE(uint32_t clock)
{
    switch (clock) {
    case (uint32_t)GPIOA:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOA);
        break;
    case (uint32_t)GPIOB:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOB);
        break;
    case (uint32_t)GPIOC:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOC);
        break;
    case (uint32_t)GPIOD:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOD);
        break;
    case (uint32_t)GPIOE:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOE);
        break;
    case (uint32_t)GPIOF:
        DRIVE_RCC_ENABLE_HELPER(APB2, GPIOF);
        break;
    case (uint32_t)TIM1:
        DRIVE_RCC_ENABLE_HELPER(APB2, TIM1);
        break;
    case (uint32_t)TIM8:
        DRIVE_RCC_ENABLE_HELPER(APB2, TIM8);
        break;
    case (uint32_t)SPI1:
        DRIVE_RCC_ENABLE_HELPER(APB2, SPI1);
        break;
    case (uint32_t)USART1:
        DRIVE_RCC_ENABLE_HELPER(APB2, USART1);
        break;
    case (uint32_t)ADC1:
        DRIVE_RCC_ENABLE_HELPER(APB2, ADC1);
        break;
    case (uint32_t)ADC2:
        DRIVE_RCC_ENABLE_HELPER(APB2, ADC2);
        break;
    case (uint32_t)ADC3:
        DRIVE_RCC_ENABLE_HELPER(APB2, ADC3);
        break;
    case (uint32_t)TIM2:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM2);
        break;
    case (uint32_t)TIM3:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM3);
        break;
    case (uint32_t)TIM4:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM4);
        break;
    case (uint32_t)TIM5:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM5);
        break;
    case (uint32_t)TIM6:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM6);
        break;
    case (uint32_t)TIM7:
        DRIVE_RCC_ENABLE_HELPER(APB1, TIM7);
        break;
    case (uint32_t)USART2:
        DRIVE_RCC_ENABLE_HELPER(APB1, USART2);
        break;
    case (uint32_t)USART3:
        DRIVE_RCC_ENABLE_HELPER(APB1, USART3);
        break;
    case (uint32_t)UART4:
        DRIVE_RCC_ENABLE_HELPER(APB1, UART4);
        break;
    case (uint32_t)UART5:
        DRIVE_RCC_ENABLE_HELPER(APB1, UART5);
        break;
    case (uint32_t)DMA1:
        DRIVE_RCC_ENABLE_HELPER(AHB, DMA1);
        break;
    case (uint32_t)DMA2:
        DRIVE_RCC_ENABLE_HELPER(AHB, DMA2);
        break;
    default:
        break;
    }
}

#endif