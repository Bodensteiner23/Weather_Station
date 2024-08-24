#include <stdio.h>´

#include "ssd1306.h"
#include "HDC1080.h"



void display_plotWeatherStationData(ws_value_t _weatherStationData) {

    char buffer[50];


	ssd1306_Init();
	ssd1306_FlipScreenVertically();
	ssd1306_Clear();
	ssd1306_SetColor(White);

    ssd1306_SetCursor(0, 0);
    sprintf(buffer, "Temperature: %.1f", _weatherStationData.temp_val);
    ssd1306_WriteString(buffer, Font_16x26);
    
    ssd1306_SetCursor(8, 0);
    sprintf(buffer, "Feuchtigkeit: %.1f%", _weatherStationData.humid_val);
    ssd1306_WriteString(buffer, Font_16x26);

    ssd1306_UpdateScreen();
    HAL_Delay(2000);		//ToDo: Check if this delay is neccessary

}
