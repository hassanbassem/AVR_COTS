/*
 * EEPROM_Interface.h
 *
 *  Created on: Aug 2, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_
#define INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_

void HEEPROM_voidWriteByte(u16 A_u16Location, u8 A_u8Data);
u8 HEEPROM_u8ReadByte(u16 A_u16Location);

#endif /* INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_ */
