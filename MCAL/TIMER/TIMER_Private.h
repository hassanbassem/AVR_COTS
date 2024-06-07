/*
 * TIMER_Private.h
 *
 *  Created on: Jun 20, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_
#define INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_

#define TCCR0 (*(volatile u8*)0x53)
#define TCNT0 (*(volatile u8*)0x52)
#define OCR0 (*(volatile u8*)0x5C)
#define TIMSK (*(volatile u8*)0x59)
#define TIFR (*(volatile u8*)0x58)

#define WGM00_BIT 6
#define WGM01_BIT 3
#define CS00_BIT 0

#define TOIE0_BIT 0
#define OCIE0_BIT 1
#define TOV0_BIT 0
#define OCF0_BIT 1
#define COM_BIT 4

#endif /* INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_ */
