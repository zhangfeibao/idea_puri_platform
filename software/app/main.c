#include "portable.h"

idea_fast_bool_t SysTick_1ms;

idea_fast_int_t test;

int main()
{
    idea_fast_int_t taskIndex = 0;
    idea_fast_int_t taskIndexExt = 0;

    SysClock_Config();
    GPIO_Config();
    UartIot_Init();

    while(1)
    {
        if (SysTick_1ms)
        {
            SysTick_1ms--;

            taskIndex++;
            switch (taskIndex)
            {
            case 1:

            	break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
            default:
                taskIndex = 0;

                taskIndexExt++;
                if (taskIndexExt >= 20)
                {
                    taskIndexExt = 0;

                    test++;
                }
                break;
            }
        }
    }
}
