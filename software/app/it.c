#include "portable.h"


ISR_NMI_HANDLER
{

}


ISR_HARD_FAULT_HANDLER
{

}

extern idea_fast_bool_t SysTick_1ms;
ISR_SYSTEM_TICK_HANDLER
{
    SysTick_1ms++;
    ISR_SYSTEM_TICK_RESET_FLAG;
}

ISR_UART_IOT_RX_TX_HANDLER
{
  
}

