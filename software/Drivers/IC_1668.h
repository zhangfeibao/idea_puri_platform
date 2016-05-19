#ifndef IC1668_H
#define IC1668_H


typedef enum
{
    BRIGHTNESS_LEVEL0 = 0X80,
    BRIGHTNESS_LEVEL1 = 0X88,
    BRIGHTNESS_LEVEL2 = 0X89,
    BRIGHTNESS_LEVEL3 = 0X8A,
    BRIGHTNESS_LEVEL4 = 0X8B,
    BRIGHTNESS_LEVEL5 = 0X8C,
    BRIGHTNESS_LEVEL6 = 0X8D,
    BRIGHTNESS_LEVEL7 = 0X8E,
    BRIGHTNESS_LEVEL8 = 0X8F
}BrightnessLevel_t;

extern BrightnessLevel_t Display_BrightnessLevel;

void CT1668_WriteDisplayData(idea_uint8_t datas[], idea_uint8_t dataLen, BrightnessLevel_t dispCtrl);

#endif
