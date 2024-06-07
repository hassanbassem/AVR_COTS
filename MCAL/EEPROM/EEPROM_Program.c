/*
 * EEPROM_Program.h
 *
 *  Created on: Aug 30, 2023
 *      Author: hassan
 */

#include <util/delay.h>
#include "../include/LIB/bit_math.h"
#include "../include/LIB/std_types.h"
#define F_CPU 8000000UL

#include "../include/MCAL/EEPROM/EEPROM_Interface.h"
#include "../include/MCAL/EEPROM/EEPROM_Private.h"
#include "../include/MCAL/EEPROM/EEPROM_Cfg.h"

#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/HAL/LED/LED_Interface.h"

void MEEPROM_voidWriteByte(u16 A_u16Address, u8 A_u8Data)
{
	EEAR = A_u16Address;
	EEDR = A_u8Data;

	SET_BIT(EECR, EEMWE);

	SET_BIT(EECR, EEWE);

	while(GET_BIT(EECR, EEWE));

	HLED_voidSetLedStatus(PORTA, PIN0, ON);
}

u8 MEEPROM_u8ReadByte(u16 A_u16Address)
{
	EEAR = A_u16Address;

	SET_BIT(EECR, EERE);

	return EEDR;
}
