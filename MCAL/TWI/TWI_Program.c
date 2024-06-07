/*
 * TWI_Program.c
 *
 *  Created on: Jul 31, 2023
 *      Author: hassan
 */

//Library
#include <stdlib.h>
#include <util/delay.h>
#include "../include/LIB/bit_math.h"
#include "../include/LIB/std_types.h"

//TWI

#include "../include/MCAL/TWI/TWI_Interface.h"
#include "../include/MCAL/TWI/TWI_Private.h"
#include "../include/MCAL/TWI/TWI_Cfg.h"


void MTWI_voidMasterInit(void)
{
	TWBR = (F_CPU/SCL_FREQ - 16)/2;

	CLR_BIT(TWSR, TWPS0);
	CLR_BIT(TWSR, TWPS1);

#if INTERRUPT_ENABLE == 1
	SET_BIT(TWCR, TWIE);
#else
	CLR_BIT(TWCR, TWIE);
#endif

#if ACK_ENABLE == 1
	SET_BIT(TWCR, TWEA);
#else
	CLR_BIT(TWCR, TWEA);
#endif

	TWAR = SLAVE_ADDRESS<<1;

	SET_BIT(TWCR, TWEN);
}

void MTWI_voidSlaveInit(void)
{
#if INTERRUPT_ENABLE == 1
	SET_BIT(TWCR, TWIE);
#else
	CLR_BIT(TWCR, TWIE);
#endif

#if ACK_ENABLE == 1
	SET_BIT(TWCR, TWEA);
#else
	CLR_BIT(TWCR, TWEA);
#endif

	TWAR = SLAVE_ADDRESS<<1;

	SET_BIT(TWCR, TWEN);
}

ERROR_STATUS MTWI_errorStatusSendStartCondition(void)
{
	SET_BIT(TWCR, TWSTA);

	SET_BIT(TWCR, TWINT);

	while(!GET_BIT(TWCR, TWINT));

	if((TWSR & TWSR_MASK)== START)
		return NO_ERROR;
	else
		return START_CONDITION_ERROR;
}

ERROR_STATUS MTWI_errorStatusSendRepeatedStartCondition(void)
{
	SET_BIT(TWCR, TWSTA);

	SET_BIT(TWCR, TWINT);

	while(!GET_BIT(TWCR, TWINT));

	if((TWSR & TWSR_MASK) == REPEATED_START)
		return NO_ERROR;
	else
		return REPEATED_START_CONDITION_ERROR;
}

ERROR_STATUS MTWI_errorStatusSendSlaveAddressAndRequest(u8 A_u8SlaveAddress, REQUEST A_request)
{
	TWDR = (A_u8SlaveAddress<<1) + A_request;

	CLR_BIT(TWCR, TWSTA);

	SET_BIT(TWCR, TWINT);

	while(!GET_BIT(TWCR, TWINT));

		if (!A_request)
		{
			if((TWSR & TWSR_MASK) == SLA_W_ACK)
				return NO_ERROR;
			else
				return SLA_W_TRANSMIT_ERROR;
		}
		else
		{
			if((TWSR & TWSR_MASK) == SLA_R_ACK)
				return NO_ERROR;
			else
				return SLA_R_TRANSMIT_ERROR;
		}
}

ERROR_STATUS MTWI_errorStatusMasterSendData(u8 A_u8Data)
{
	TWDR = A_u8Data;

	SET_BIT(TWCR, TWINT);

	while(!GET_BIT(TWCR, TWINT));

	if((TWSR & TWSR_MASK) == MASTER_DATA_TRANSMITTED_ACK)
		return NO_ERROR;
	else
		return DATA_TRANSMIT_ERROR;

}

ERROR_STATUS MTWI_errorStatusMasterReadData(u8* P_u8ReceivedData)
{
	SET_BIT(TWCR, TWINT);

	while(!GET_BIT(TWCR, TWINT));

	if ((TWSR & TWSR_MASK) == MASTER_DATA_RECEIVED_ACK)
	{
		*P_u8ReceivedData = TWDR;
		return NO_ERROR;
	}
	else
		return DATA_RECEIVE_ERROR;
}

ERROR_STATUS MTWI_errorStatusSlaveSendData(u8 A_u8Data)
{
	TWDR = A_u8Data;

	SET_BIT(TWCR, TWINT);

	while(!GET_BIT(TWCR, TWINT));

	if((TWSR & TWSR_MASK) == SLAVE_DATA_TRANSMITTED_ACK)
		return NO_ERROR;
	else
		return DATA_TRANSMIT_ERROR;

}

ERROR_STATUS MTWI_errorStatusSlaveReadData(u8* P_u8ReceivedData)
{
	SET_BIT(TWCR, TWINT);

	while(!GET_BIT(TWCR, TWINT));

	*P_u8ReceivedData = TWDR;

	if ((TWSR & TWSR_MASK) == SLAVE_DATA_RECEIVED_ACK)
		return NO_ERROR;
	else
		return DATA_RECEIVE_ERROR;
}

void MTWI_voidSendStopCondition(void)
{
	SET_BIT(TWCR, TWSTO);

	SET_BIT(TWCR, TWINT);
}
