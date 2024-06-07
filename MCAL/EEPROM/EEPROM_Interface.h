/*
 * EEPROM_Interface.h
 *
 *  Created on: Aug 30, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_EEPROM_EEPROM_INTERFACE_H_
#define INCLUDE_MCAL_EEPROM_EEPROM_INTERFACE_H_

void MEEPROM_voidWriteByte(u16 A_u16Address, u8 A_u8Data);
u8 MEEPROM_u8ReadByte(u16 A_u16Address);

#endif /* INCLUDE_MCAL_EEPROM_EEPROM_INTERFACE_H_ */
