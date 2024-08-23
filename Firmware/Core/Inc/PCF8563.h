#ifndef INC_PCF8563_H_
#define INC_PCF8563_H_
#include <stm32f1xx_ll_i2c.h>


#define PCF8563_I2C_Write_Adress	0xA2
#define PCF8563_I2C_Read_Adress		0xA3

#define Cntrl_status_1_Addr			0x00
#define Cntrl_status_2_Addr			0x01
#define VL_seconds_Addr				0x02
#define Minutes_Addr				0x03
#define Hours_Addr					0x04
#define Days_Addr					0x05
#define Weekdays_Addr				0x06
#define Century_months_Addr			0x07
#define Years_Addr			0x08


void PCF8563_initI2C(I2C_HandleTypeDef _hi2c);
void PCF8563_initRTC(void);


#endif /* INC_PCF8563_H_ */
