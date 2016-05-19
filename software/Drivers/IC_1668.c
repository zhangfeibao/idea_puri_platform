#include "portable.h"


#define NORMAL_FIXED            (0X44)
#define NORMAL_AUTO_INC         (0X40)
#define TEST_FIXED              (0X4C)
#define TEST_AUTO_INC           (0X48)

#define DISPMODE_4BIT_14SEG     (0x00)
#define DISPMODE_5BIT_13SEG     (0x01)
#define DISPMODE_6BIT_12SEG     (0x02)
#define DISPMODE_7BIT_11SEG     (0x03)


BrightnessLevel_t Display_BrightnessLevel;

void delayns(void)
{
    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();
}

void delayus(void)
{
    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();

    nop(); nop(); nop(); nop(); nop();
    nop(); nop(); nop(); nop(); nop();
}

static void sendByteToCt1668(unsigned char datas)
{
    idea_uint8_t i;

    IC1668_CLK_RESET;
    IC1668_DIO_RESET;

    for (i = 0; i < 8; i++)
    {
        IC1668_CLK_RESET;
        if (datas & 0x01)
        {
            IC1668_DIO_SET;
        }
        else
        {
            IC1668_DIO_RESET;
        }
        datas >>= 1;
        
        delayns();
        IC1668_CLK_SET;
        delayns();
    }
}

void CT1668_WriteDisplayData(idea_uint8_t datas[], idea_uint8_t dataLen,
    BrightnessLevel_t dispCtrl)
{
    idea_uint8_t i;

    IC1668_STB_SET;
    IC1668_DIO_SET;
    IC1668_CLK_SET;

    delayus();

    IC1668_STB_RESET;

    delayus();

    sendByteToCt1668(NORMAL_AUTO_INC);

    delayus();

    IC1668_STB_SET;

    delayus();

    IC1668_STB_RESET;

    delayus();

    sendByteToCt1668(0xc0);

    for (i = 0; i < dataLen; i++)
    {
        sendByteToCt1668(datas[i]);
        nop();
        nop();
    }

    IC1668_STB_SET;

    delayus();

    IC1668_STB_RESET;

    delayus();

    sendByteToCt1668(dispCtrl);

    delayus();

    IC1668_STB_SET;
}

