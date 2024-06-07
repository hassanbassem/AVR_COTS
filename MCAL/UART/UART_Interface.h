/*
 * UART_Interface.h
 *
 *  Created on: Jul 8, 2023
 *      Author: hassan
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

typedef enum
{
	TRANSMIT_COMPLETE,
	DATA_REGISTER_EMPTY,
	RECEIVE_COMPLETE
}INTERRUPTS;

typedef enum
{
	UART_DISABLE,
	UART_ENABLE
}UART_STATUS;

void MUART_voidInit(void);
void MUART_voidTransmitChar(u8 A_u8Char);
void MUART_voidTransmitString(u8* A_pu8String);
u8 MUART_u8ReceiveChar(void);
void MUART_voidInterruptEnable(INTERRUPTS A_interrupt, UART_STATUS A_UART_status);
void MUART_voidSetCallback(INTERRUPTS A_interrupt, void (*ptrToFunction)(void));
void MUART_voidSetCallbackRx(void (*ptrToFunction)(u8));

#endif /* MCAL_UART_UART_INTERFACE_H_ */
