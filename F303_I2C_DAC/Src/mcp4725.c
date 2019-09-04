/**
  ******************************************************************************
  * @file           : mcp4725.h
  * @brief          : I2C DAC library header
  * @Author			: Javier Morales

  *
  ******************************************************************************
  */

#include "mcp4725.h"

I2C_HandleTypeDef hi2c_current;

uint8_t address_mcp4725 = 0xC0; //0xC4 - other address
uint8_t read_mcp4725 = 0x01;
uint8_t dac_mcp4725 = 0x40;  // Writes data to the DAC
uint8_t dac_eeprom_mcp4725 = 0x60;  // Writes data to the DAC and the EEPROM (persisting the assigned value after reset)

uint8_t buffer[3];

void mcp4725_init(I2C_HandleTypeDef *hi2c) {
	hi2c_current = *hi2c;
	mcp4725_setVoltage(0, 1);
}

void mcp4725_setVoltage(uint16_t value, uint8_t eeprom){
	if (eeprom == 1) {
		buffer[0] = dac_eeprom_mcp4725;	}// Persists after reset
	else {
		buffer[0] = dac_mcp4725;
	}
	buffer[1] = (value / 16);       // Upper data bits     (D11.D10.D9.D8.D7.D6.D5.D4)
	buffer[2] = (value % 16) << 4;  // Lower data bits     (D3.D2.D1.D0.x.x.x.x)
	HAL_I2C_Master_Transmit(&hi2c_current, address_mcp4725, buffer, 3, 1000);
}
