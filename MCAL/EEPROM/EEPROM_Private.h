/*
 * EEPROM_Private.h
 *
 *  Created on: Aug 30, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_EEPROM_EEPROM_PRIVATE_H_
#define INCLUDE_MCAL_EEPROM_EEPROM_PRIVATE_H_

#define EEAR (*(volatile u16*)0x3E)
#define EEDR (*(volatile u8*)0x3D)
#define EECR (*(volatile u8*)0x3C)

#define EERIE 3
#define EEMWE 2
#define EEWE 1
#define EERE 0

#endif /* INCLUDE_MCAL_EEPROM_EEPROM_PRIVATE_H_ */
