/*
 * UART_Private.h
 *
 *  Created on: Jul 8, 2023
 *      Author: hassan
 */

#define F_CPU 8000000UL

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_

#define UDR   (*(volatile u8*)0x2C)
#define UCSRA (*(volatile u8*)0x2B)
#define UCSRB (*(volatile u8*)0x2A)
#define UCSRC (*(volatile u8*)0x40)
#define UBRRL (*(volatile u8*)0x29)
#define UBRRH (*(volatile u8*)0x40)

#define RXC 7
#define TXC 6
#define UDRE 5
#define FE 4
#define DOR 3
#define PE 2
#define U2X 1
#define MPCM 0

#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN 4
#define TXEN 3
#define UCSZ2 2
#define RXB8 1
#define TXB8 0

#define URSEL 7
#define UMSEL 6
#define UPM1 5
#define UPM0 4
#define USBS 3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0

#define NORMAL_SPEED 0
#define _2X_SPEED 1

#define UART_DISABLE 0
#define UART_ENABLE 1

#define ASYNCHRONOUS 0
#define SYNCHRONOUS 1

#define PARITY_DISABLED 0
#define PARITY_EVEN 2
#define PARITY_ODD 3

#define STOP_BIT_1 0
#define STOP_BIT_2 1

#define _5_BITS 0
#define _6_BITS 1
#define _7_BITS 2
#define _8_BITS 3
#define _9_BITS 7

#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
