
#include "ssd1306.h"

void display_updateDisplay(char* _string) {
	ssd1306_Clear();
	ssd1306_SetColor(White);
	ssd1306_SetCursor(0, 5);
	ssd1306_WriteString(_string, Font_11x18);
	ssd1306_UpdateScreen();
}
