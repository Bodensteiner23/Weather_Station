#include "PCF8563.h"
#include <stm32f1xx_hal_i2c.h>

I2C_HandleTypeDef hi2c;

void PCF8563_initI2C(I2C_HandleTypeDef _hi2c) {
    hi2c = _hi2c;

}


void PCF8563_initRTC(void) {

    uint8_t data_send[3];

    data_send[0] = 0b110000;    // Set Day to 30.
    data_send[1] = 0b010010;    // Set Hour to 12
    data_send[2] = 0b0110000;   // Set Minute to 30

    HAL_I2C_Mem_Read(&hi2c, PCF8563_I2C_Write_Adress, Days_Addr, 1, &data_send[0], 1, 100);
    HAL_I2C_Mem_Read(&hi2c, PCF8563_I2C_Write_Adress, Hours_Addr, 1, &data_send[1], 1, 100);
    HAL_I2C_Mem_Read(&hi2c, PCF8563_I2C_Write_Adress, Minutes_Addr, 1, &data_send[1], 1, 100);

}
