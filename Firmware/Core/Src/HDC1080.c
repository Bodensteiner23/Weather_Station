#include "main.h"
#include <stm32f1xx_hal_i2c.h>

#include "HDC1080.h"


void HDC1080_initSensor(I2C_HandleTypeDef _hi2c) {

	uint8_t data_send[2];
	uint16_t config_data = 0;

	config_data |= 1 << 12;					// Temp and Humid readout
	config_data |= (1 << 8) | (1 << 9);		// Set Humidity to 11 bit
	config_data |= 1 << 10;					// Set Temp to 11 bit

	data_send[0] = (config_data >> 0) & 0xFF;
	data_send[1] = (config_data >> 8) & 0xFF;

	HAL_I2C_Mem_Write(&_hi2c, HDC1080_I2C_Address, Config_Register_Address,
			1, data_send, 2, 100);
}


void HDC1080_readData(I2C_HandleTypeDef _hi2c, uint8_t data_read[4]) {

	uint8_t data_send[1];
	ws_value_t temp_humid_values;

	// Start data pull request
	HAL_I2C_Mem_Write(&_hi2c, HDC1080_I2C_Address, Temperature_Register_Address,
			1, data_send, 1, 100);

	HAL_Delay(15);

	// Read Temp Data
	uint16_t temp_raw_val = HAL_I2C_Mem_Read(&_hi2c, HDC1080_I2C_Address, Temperature_Register_Address,
						1, &data_read[0], 2, 100);
	// Read Humid Data
	uint16_t humid_raw_val = HAL_I2C_Mem_Read(&_hi2c, HDC1080_I2C_Address, Humidity_Register_Address,
						1, &data_read[2], 2, 100);

	if ((temp_raw_val | humid_raw_val) == HAL_ERROR) {
		Error_Handler();			 // Transmission Error
	}

	temp_humid_values.temp_val = (temp_raw_val << 8) | temp_raw_val;


}
