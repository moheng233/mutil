#ifndef __LIB_MUTIL_DRIVE
#define __LIB_MUTIL_DRIVE

/// 标准通用GPIO初始化宏
#define DRIVE_GPIO_INIT(_GPIOx, _PINx, _Mode)    \
    {                                            \
        GPIO_InitTypeDef gpio_init;              \
        gpio_init.GPIO_Pin = _PINx;              \
        gpio_init.GPIO_Mode = _Mode;             \
        gpio_init.GPIO_Speed = GPIO_Speed_50MHz; \
        GPIO_Init(_GPIOx, &gpio_init);           \
    }

/// 注意！需要手动启用计时器
/// _RELOAD 自动重装值
/// _PSC 预分频
#define DRIVE_TIM_INIT(_TIMx, _RELOAD, _PSC)                        \
    {                                                               \
        TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;              \
        TIM_TimeBaseStructure.TIM_Period = _RELOAD;                 \
        TIM_TimeBaseStructure.TIM_Prescaler = _PSC;                 \
        TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     \
        TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; \
        TIM_TimeBaseInit(_TIMx, &TIM_TimeBaseStructure);            \
    }

/// 用于PWM输出的时钟通用初始化宏
#define DRIVE_TIM_PWM_INIT(_TIMx, _Channel, _Mode, _Pulse, _OCPolarity, _RELOAD, _PSC) \
    {                                                                                  \
        TIM_OCInitTypeDef TIM_OCInitStructure;                                         \
        DRIVE_TIM_INIT(_TIMx, _RELOAD, _PSC);                                          \
        TIM_OCInitStructure.TIM_OCMode = _Mode;                                        \
        TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;                  \
        TIM_OCInitStructure.TIM_Pulse = _Pulse;                                        \
        TIM_OCInitStructure.TIM_OCPolarity = _OCPolarity;                              \
        TIM_OC##_Channel##Init(_TIMx, &TIM_OCInitStructure);                           \
        TIM_Cmd(_TIMx, ENABLE);                                                        \
        TIM_CtrlPWMOutputs(_TIMx, ENABLE);                                             \
    }

// 通用的单个ADC初始化
// 别忘记RCC时钟
// 外部触发提前配号PWM输出 DRIVE_TIM_PWM_INIT(TIM2, 2, TIM_OCMode_PWM1, 9, TIM_OCPolarity_Low, 9, 7199);
// 使用外部触发的情况下需要手动 ADC_ExternalTrigConvCmd(ADCx, ENABLE); 来启用外部触发
#define DRIVE_ADC_INIT(_ADCx, _Channel, _ExternalTrig)                           \
    {                                                                            \
        ADC_InitTypeDef init;                                                    \
        ADC_DeInit(_ADCx);                                                       \
        ADC_StructInit(&init);                                                   \
        init.ADC_ContinuousConvMode = DISABLE;                                   \
        init.ADC_ExternalTrigConv = _ExternalTrig;                               \
        ADC_Init(_ADCx, &init);                                                  \
        ADC_Cmd(_ADCx, ENABLE);                                                  \
        ADC_ResetCalibration(_ADCx);                                             \
        ADC_StartCalibration(_ADCx);                                             \
        while (ADC_GetResetCalibrationStatus(_ADCx)) {                           \
        }                                                                        \
        while (ADC_GetCalibrationStatus(_ADCx)) {                                \
        }                                                                        \
        ADC_RegularChannelConfig(_ADCx, _Channel, 1, ADC_SampleTime_239Cycles5); \
    }

// 用于从外设到内存的序列DMA的通用初始化宏
#define DRIVE_DMA_PTM_INIT(_DMAC, _PADDR, _MADDR, _ARGS_COUNTS)            \
    {                                                                      \
        DMA_DeInit(_DMAC);                                                 \
        {                                                                  \
            DMA_InitTypeDef init;                                          \
            init.DMA_PeripheralBaseAddr = (uint32_t)_PADDR;                \
            init.DMA_MemoryBaseAddr = (uint32_t)_MADDR;                    \
            init.DMA_DIR = DMA_DIR_PeripheralSRC;                          \
            init.DMA_BufferSize = _ARGS_COUNTS;                            \
            init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;            \
            init.DMA_MemoryInc = DMA_MemoryInc_Enable;                     \
            init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; \
            init.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;         \
            init.DMA_Mode = DMA_Mode_Circular;                             \
            init.DMA_Priority = DMA_Priority_High;                         \
            init.DMA_M2M = DMA_M2M_Disable;                                \
            DMA_Init(_DMAC, &init);                                        \
        }                                                                  \
        DMA_Cmd(_DMAC, ENABLE);                                            \
    }

#define DRIVE_NVIC_INIT(_CHANNEL, _CPP, _CSP)          \
    {                                                  \
        NVIC_InitTypeDef init;                         \
        init.NVIC_IRQChannel = _CHANNEL;               \
        init.NVIC_IRQChannelPreemptionPriority = _CPP; \
        init.NVIC_IRQChannelSubPriority = _CSP;        \
        init.NVIC_IRQChannelCmd = ENABLE;              \
        NVIC_Init(&init);                              \
    }

#define DRIVE_TIM_MSLOOP_INIT(_TIMx, _MS, _CPP, _CSP)           \
    {                                                           \
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_##_TIMx, ENABLE); \
        DRIVE_TIM_INIT(_TIMx, ((_MS)*10) - 1, 7199);            \
        TIM_ITConfig(_TIMx, TIM_IT_Update, ENABLE);             \
        DRIVE_NVIC_INIT(_TIMx##_IRQn, _CPP, _CSP);              \
        TIM_Cmd(_TIMx, ENABLE);                                 \
    }

#endif // !__SRC_UTIL_DRIVE
