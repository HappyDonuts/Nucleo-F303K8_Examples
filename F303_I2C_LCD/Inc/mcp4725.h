/**
  ******************************************************************************
  * @file           : mcp4725.h
  * @brief          : I2C DAC library header
  * @Author			: Javier Morales

  *
  ******************************************************************************
  */

#include "stm32f3xx_hal.h"
//#include "stm32f1xx_hal.h"

/**
 * @brief  Initializes MCP4725 DAC I2C
 * @param  None
 * @retval None
 */
void mcp4725_init(void);

/**
 * @brief  Initializes SSD1306 LCD
 * @param  value: DAC value, up to 4095
 * @param  eeprom: If set to 1, writes on EEPROM, else just DAC
 * @retval None
 */
void mcp4725_setVoltage(uint16_t value, uint8_t eeprom);
