#include "ssd1306.h"


void display_plotWeatherStationData(void) {

	ssd1306_Init();
	ssd1306_FlipScreenVertically();
	ssd1306_Clear();
	ssd1306_SetColor(White);

    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("Temperatur: ", Font_16x26);
    ssd1306_SetCursor(8, 0);
    ssd1306_WriteString("Feuchtigkeit: ", Font_16x26);



    ssd1306_UpdateScreen();
    HAL_Delay(2000);

}
