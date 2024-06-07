/*
 * EEPROM_Program.c
 *
 *  Created on: Aug 2, 2023
 *      Author: hassan
 */

//Library
#include <stdlib.h>
#include <util/delay.h>
#include "../include/LIB/bit_math.h"
#include "../include/LIB/std_types.h"
#define F_CPU 8000000UL

//TWI
#include "../include/MCAL/TWI/TWI_Interface.h"

//EEPROM
#include "../include/HAL/EEPROM/EEPROM_Interface.h"
#include "../include/HAL/EEPROM/EEPROM_Private.h"
#include "../include/HAL/EEPROM/EEPROM_Cfg.h"

void HEEPROM_voidWriteByte(u16 A_u16Location, u8 A_u8Data)
{
	(void)MTWI_errorStatusSendStartCondition();

//	u8 local_u8SlaveAddressToBeSent = CONSTANT_PART | (A2<<A2_POSITION) | (u8)(A_u16Location>>8);

	u8 local_u8SlaveAddressToBeSent = CONSTANT_PART | (A2<<A2_POSITION) | (0<<1) | (0<<0);

	(void)MTWI_errorStatusSendSlaveAddressAndRequest(local_u8SlaveAddressToBeSent, WRITE);

	(void)MTWI_errorStatusMasterSendData((u8)A_u16Location);

	(void)MTWI_errorStatusMasterSendData(A_u8Data);

	MTWI_voidSendStopCondition();

	_delay_ms(10);
}

u8 HEEPROM_u8ReadByte(u16 A_u16Location)
{
	u8 local_u8ReturnedByte;

	(void)MTWI_errorStatusSendStartCondition();

//	u8 local_u8SlaveAddressToBeSent = CONSTANT_PART | (A2<<A2_POSITION) | (u8)(A_u16Location>>8);

	u8 local_u8SlaveAddressToBeSent = CONSTANT_PART | (A2<<A2_POSITION) | (0<<1) | (0<<0);

	(void)MTWI_errorStatusSendSlaveAddressAndRequest(local_u8SlaveAddressToBeSent, WRITE);

	(void)MTWI_errorStatusMasterSendData((u8)A_u16Location);

	(void)MTWI_errorStatusSendRepeatedStartCondition();

	(void)MTWI_errorStatusSendSlaveAddressAndRequest(local_u8SlaveAddressToBeSent, READ);

	(void)MTWI_errorStatusSlaveReadData(&local_u8ReturnedByte);

	MTWI_voidSendStopCondition();

	_delay_ms(10);

	return local_u8ReturnedByte;
}

