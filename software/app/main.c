#include "portable.h"

unsigned char testTab[14] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff ,0xff,0xff,0xff,0xff ,0xff,0xff};

int main()
{
  SysClock_Config();
  GPIO_Config();


  while(1)
  {
      CT1668_WriteDisplayData(testTab, 16, BRIGHTNESS_LEVEL3);
  }
}
