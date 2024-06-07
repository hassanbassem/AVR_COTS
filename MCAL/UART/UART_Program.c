/*
 * UART_Program.c
 *
 *  Created on: Jul 8, 2023
 *      Author: hassan
 */


#include <stdlib.h>
#include "../../LIB/include/bit_math.h"
#include "../../LIB/include/std_types.h"

#include "include/UART_Cfg.h"
#include "include/UART_Interface.h"
#include "include/UART_Private.h"

void static (*callBackArray[2])(void) = {NULL, NULL};
void static (*callBackReceiveComplete)(u8) = NULL;

void MUART_voidInit(void)
{
#if UART_SPEED == 1
		SET_BIT(UCSRA, U2X);
#else
		CLR_BIT(UCSRA, U2X);
#endif

#if MPCM_ENABLE == 1
		SET_BIT(UCSRA, MPCM);
#else
		CLR_BIT(UCSRA, MPCM);
#endif

	SET_BIT(UCSRC, URSEL);

#if USART_MODE == 1
		SET_BIT(UCSRC, UMSEL);
#else
		CLR_BIT(UCSRC, UMSEL);
#endif

	UCSRC &= ~(3<<UPM0);
	UCSRC |= (PARITY<<UPM0);

#if STOP_BITS == 1
		SET_BIT(UCSRC, USBS);
#else
		CLR_BIT(UCSRC, USBS);
#endif

#if CHAR_SIZE == _9_BITS
		SET_BIT(UCSRB, UCSZ2);
		UCSRC |= (3<<UCSZ0);
#else
		CLR_BIT(UCSRB, UCSZ2);
		UCSRC &= ~(3<<UCSZ0);
		UCSRC |= (CHAR_SIZE<<UCSZ0);
#endif

		CLR_BIT(UBRRH, URSEL);
#if UART_SPEED == NORMAL_SPEED
		u16 local_UBRR_value = 51;//F_CPU/16/BAUD_RATE - 1;
#elif UART_SPEED == _2X_SPEED
		u16 local_UBRR_value = F_CPU/8/BAUD_RATE - 1;
#endif
		UBRRH = 0;
		UBRRH |= (local_UBRR_value>>8);
		UBRRL = (u8)local_UBRR_value;

		MUART_voidInterruptEnable(RECEIVE_COMPLETE, RX_INTERRUPT);
		MUART_voidInterruptEnable(TRANSMIT_COMPLETE, TX_INTERRUPT);
		MUART_voidInterruptEnable(DATA_REGISTER_EMPTY, DATA_REG_EMPTY_INTERRUPT);

		SET_BIT(UCSRB, RXEN);
		SET_BIT(UCSRB, TXEN);
}

void MUART_voidTransmitChar(u8 A_u8Char)
{
	while (!GET_BIT(UCSRA, UDRE));
	UDR = A_u8Char;
	while (!GET_BIT(UCSRA, UDRE));
	SET_BIT(UCSRA, TXC);
}

void MUART_voidTransmitString(u8* A_pu8String)
{
	u8 local_u8Length = strlen(A_pu8String);
	for (u8 i = 0; i < local_u8Length; i++)
		MUART_voidTransmitChar(A_pu8String[i]);
}

u8 MUART_u8ReceiveChar(void)
{
	while (!GET_BIT(UCSRA, RXC));
	if (GET_BIT(UCSRA, FE) | GET_BIT(UCSRA, DOR) | GET_BIT(UCSRA, PE))
		return 255;
	return UDR;
}

void MUART_voidInterruptEnable(INTERRUPTS A_interrupt, UART_STATUS A_UART_status)
{
	switch(A_interrupt)
	{
	case RECEIVE_COMPLETE:
		if (A_UART_status)
			SET_BIT(UCSRB, RXCIE);
		else
			CLR_BIT(UCSRB, RXCIE);
		break;
	case TRANSMIT_COMPLETE:
		if (A_UART_status)
			SET_BIT(UCSRB, TXCIE);
		else
			CLR_BIT(UCSRB, TXCIE);
		break;
	case DATA_REGISTER_EMPTY:
		if (A_UART_status)
			SET_BIT(UCSRB, UDRIE);
		else
			CLR_BIT(UCSRB, UDRIE);
		break;
	default:
		break;
	}
}

void MUART_voidSetCallback(INTERRUPTS A_interrupt, void (*ptrToFunction)(void))
{
	callBackArray[A_interrupt] = ptrToFunction;
}

void MUART_voidSetCallbackRx(void (*ptrToFunction)(u8))
{
	callBackReceiveComplete = ptrToFunction;
}


void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	u8 local_u8ReceivedData = UDR;
	(*callBackReceiveComplete)(local_u8ReceivedData);
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	(*callBackArray[DATA_REGISTER_EMPTY])();
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	(*callBackArray[TRANSMIT_COMPLETE])();
}
