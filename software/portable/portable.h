#ifndef PORTABLE_H
#define PORTABLE_H

#include <intrinsics.h>
#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
#include "macrodef.h"

#include "IC_1668.h"

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


#endif 