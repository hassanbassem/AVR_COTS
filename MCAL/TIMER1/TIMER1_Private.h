/*
 * TIMER1_Private.h
 *
 *  Created on: Jun 27, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_

#define TCCR1A (*(volatile u8*)0x4F)
#define TCCR1B (*(volatile u8*)0x4E)
#define TCNT1 (*(volatile u16*)0x4C)
#define OCR1A (*(volatile u16*)0x4A)
#define OCR1B (*(volatile u16*)0x48)
#define ICR1 (*(volatile u16*)0x46)
#define TIMSK (*(volatile u8*)0x59)
#define TIFR (*(volatile u8*)0x58)

#define COM1A_BIT 6
#define COM1B_BIT 4
#define WGM10_BIT 0
#define WGM12_BIT 3
#define CS10_BIT 0
#define ICES1_BIT 6

#define TOIE1_BIT 2
#define OCIE1B_BIT 3
#define OCIE1A_BIT 4
#define TICIE1_BIT 5

#define TOV1_BIT 2
#define OCF1B_BIT 3
#define OCF1A_BIT 4
#define ICF1_BIT 5

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
