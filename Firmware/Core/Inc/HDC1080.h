#ifndef INC_HDC1080_H_
#define INC_HDC1080_H_

#define HDC1080_I2C_Address 			0x40
#define Temperature_Register_Address 	0x00
#define Humidity_Register_Address 		0x01
#define Config_Register_Address 		0x02

typedef struct {
	uint16_t temp_val;
	uint16_t humid_val;
}ws_value_t;


void HDC1080_initI2C(I2C_HandleTypeDef _hi2c);
void HDC1080_initSensor(void);
ws_value_t HDC1080_readData(void);

#endif /* INC_HDC1080_H_ */
