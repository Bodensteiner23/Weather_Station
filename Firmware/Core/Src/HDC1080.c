#include <stm32f1xx_hal.h>
#include <math.h>

#include "HDC1080.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

//void HDC1080_initI2C(I2C_HandleTypeDef _hi2c) {
//	hi2c1 = _hi2c;
//
//}

void HDC1080_initSensor(void) {

	uint8_t data_send[2];
	uint16_t config_data = 0;

	config_data |= 1 << 12;					// Temp and Humid readout
	config_data |= 1 << 15;
	
	data_send[0] = (config_data >> 8) & 0xFF;
	data_send[1] = (config_data >> 0) & 0xFF;

	HAL_I2C_Mem_Write(&hi2c1, HDC1080_I2C_Address, Config_Register_Address,
			1, data_send, 2, 1000);
}


ws_value_t HDC1080_readData(void) {

	uint8_t data_send = Temperature_Register_Address;
	uint8_t data_read[4];
	ws_value_t temp_humid_values;

	// Start data pull request
	HAL_I2C_Mem_Write(&hi2c1, HDC1080_I2C_Address, Temperature_Register_Address,
			1, &data_send, 0, 1000);
	HAL_Delay(50);

	// Read Temp and Humid Data
	HAL_I2C_Master_Receive(&hi2c1, HDC1080_I2C_Address, data_read, 4, 1000);
	uint16_t temp_raw_val = (data_read[0] << 8) | data_read[1];
	uint16_t humid_raw_val = (data_read[2] << 8) | data_read[3];

	if ((temp_raw_val | humid_raw_val) == HAL_ERROR) {
		Error_Handler();			 // Transmission Error
	}

	temp_humid_values.temp_val = (((double)temp_raw_val / 65536) * 165) - 40;

	temp_humid_values.humid_val = ((double)humid_raw_val / 65536) * 100;	

	return temp_humid_values;
}
