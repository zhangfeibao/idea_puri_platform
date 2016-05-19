#ifndef PORTABLE_H
#define PORTABLE_H

#include <intrinsics.h>
#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
#include "macrodef.h"


typedef unsigned char idea_uint8_t;
typedef signed char idea_int8_t;
typedef unsigned short idea_uint16_t;
typedef signed short idea_int16_t;
typedef unsigned int idea_uint32_t;
typedef signed int idea_int32_t;
typedef unsigned long long idea_uint64_t;
typedef signed long long idea_int64_t;
typedef float idea_float32_t;
typedef double idea_float64_t;

typedef unsigned int idea_fast_int_t;
typedef unsigned int idea_fast_bool_t;

typedef enum
{
    IDEA_FALSE,
    IDEA_TRUE = !IDEA_FALSE
}idea_bool_t;

typedef void(*task_t)(void);



#include "IC_1668.h"



#define UART_IOT_EN     1


#define ISR_NMI_HANDLER         void NMI_Handler(void)
#define ISR_HARD_FAULT_HANDLER  void HardFault_Handler(void)
#define ISR_SYSTEM_TICK_HANDLER void SysTick_Handler(void)
#define ISR_SYSTEM_TICK_RESET_FLAG      
#define ISR_UART_IOT_RX_HANDLER 0
#define ISR_UART_IOT_RX_RESET_FLAG
#define ISR_UART_IOT_TX_HANDLER 0
#define ISR_UART_IOT_TX_RESET_FLAG
#define ISR_UART_IOT_RX_TX_HANDLER void USART3_4_IRQHandler(void)
#define ISR_UART_IOT_RX_TX_RESET_FLAG


#define nop() __no_operation()
#define FEED_DOG
#define EI  __enable_interrupt()
#define DI  __disable_interrupt()


#define IC_1668_EN 1

#if IC_1668_EN

#define IC1668_STB_SET      HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET)
#define IC1668_CLK_SET      HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET)
#define IC1668_DIO_SET      HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET)

#define IC1668_STB_RESET    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET)
#define IC1668_CLK_RESET    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET)
#define IC1668_DIO_RESET    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET)

#endif

void SysClock_Config(void);
void GPIO_Config(void);

extern UART_HandleTypeDef uart_iot;
void UartIot_Init(void);


#endif 