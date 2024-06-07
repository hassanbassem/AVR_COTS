/*
 * TWI_Interface.h
 *
 *  Created on: Jul 31, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_TWI_TWI_INTERFACE_H_
#define INCLUDE_MCAL_TWI_TWI_INTERFACE_H_

typedef enum
{
	NO_ERROR,
	START_CONDITION_ERROR,
	REPEATED_START_CONDITION_ERROR,
	SLA_W_TRANSMIT_ERROR,
	SLA_R_TRANSMIT_ERROR,
	SLA_W_RECEIVE_ERROR,
	SLA_R_RECEIVE_ERROR,
	DATA_TRANSMIT_ERROR,
	DATA_RECEIVE_ERROR
}ERROR_STATUS;

typedef enum
{
	WRITE,
	READ
}REQUEST;

void MTWI_voidMasterInit(void);
void MTWI_voidSlaveInit(void);
ERROR_STATUS MTWI_errorStatusSendStartCondition(void);
ERROR_STATUS MTWI_errorStatusSendRepeatedStartCondition(void);
ERROR_STATUS MTWI_errorStatusSendSlaveAddressAndRequest(u8 A_u8SlaveAddress, REQUEST A_request);
ERROR_STATUS MTWI_errorStatusMasterSendData(u8 A_u8Data);
ERROR_STATUS MTWI_errorStatusMasterReadData(u8* P_u8ReceivedData);
ERROR_STATUS MTWI_errorStatusSlaveSendData(u8 A_u8Data);
ERROR_STATUS MTWI_errorStatusSlaveReadData(u8* P_u8ReceivedData);
void MTWI_voidSendStopCondition(void);

#endif /* INCLUDE_MCAL_TWI_TWI_INTERFACE_H_ */
