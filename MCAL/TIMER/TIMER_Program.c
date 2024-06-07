/*
 * TIMER_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: hassan
 */

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include <stdlib.h>
#include "../include/LIB/bit_math.h"
#include "../include/LIB/std_types.h"

/****************************************************/
/* TIMER Directives   							    */
/****************************************************/
#include "../include/MCAL/TIMER/TIMER_Interface.h"
#include "../include/MCAL/TIMER/TIMER_Private.h"
#include "../include/MCAL/TIMER/TIMER_Cfg.h"

void (*callBackOverflow)(void) = NULL;
void (*callBackCompareMatch)(void) = NULL;

void MTIMER_voidInit(void)
{
#if TIMER_MODE_CHOICE == 0
	CLR_BIT(TCCR0, WGM01_BIT);
	CLR_BIT(TCCR0, WGM00_BIT);

#elif TIMER_MODE_CHOICE == 1
	SET_BIT(TCCR0, WGM01_BIT);
	CLR_BIT(TCCR0, WGM00_BIT);

#elif TIMER_MODE_CHOICE == 2
	SET_BIT(TCCR0, WGM01_BIT);
	SET_BIT(TCCR0, WGM00_BIT);

#elif TIMER_MODE_CHOICE == 3
	CLR_BIT(TCCR0, WGM01_BIT);
	SET_BIT(TCCR0, WGM00_BIT);

#endif

	MTIMER_voidSetOutputCompareMatchInterruptEnable(TIMER_DISABLE);
	MTIMER_voidSetOverflowInterruptEnable(TIMER_DISABLE);

	MTIMER_voidSetOCRValue(OCR_VALUE);

	MTIMER_voidSetCompareOutputMode(COM_CHOICE);

	MTIMER_voidSetPrescaler(CLK_CHOICE);
}

void MTIMER_voidSetOCRValue(u8 A_OCRValue)
{
	OCR0 = A_OCRValue;
}

void MTIMER_voidSetCounterRegister(u8 A_counterValue)
{
	TCNT0 = A_counterValue;
}

void MTIMER_voidSetOutputCompareMatchInterruptEnable(TIMER_STATUS A_STATUS)
{
	if (A_STATUS)
		SET_BIT(TIMSK, OCIE0_BIT);
	else
		CLR_BIT(TIMSK, OCIE0_BIT);
}

void MTIMER_voidSetOverflowInterruptEnable(TIMER_STATUS A_STATUS)
{
	if (A_STATUS)
		SET_BIT(TIMSK, TOIE0_BIT);
	else
		CLR_BIT(TIMSK, TOIE0_BIT);
}

void MTIMER_voidClearOutputCompareMatchInterruptFlag(void)
{
	SET_BIT(TIFR, OCF0_BIT);
}

void MTIMER_voidClearOverflowInterruptFlag(void)
{
	SET_BIT(TIFR, TOV0_BIT);
}

void MTIMER_voidSetCompareOutputMode(COM A_COM)
{
	TCCR0 &= ~(3<<COM_BIT);
	TCCR0 |= A_COM<<COM_BIT;
}

void MTIMER_voidSetPrescaler(CLK_SELECT A_CLK_SELECT)
{
	TCCR0 &= ~(7<<CS00_BIT);
	TCCR0 |= A_CLK_SELECT<<CS00_BIT;
}

void MTIMER_voidSetCallbackOverflow(void (*A_ptrToFunction)(void))
{
		callBackOverflow = A_ptrToFunction;
}

void MTIMER_voidSetCallbackCompareMatch(void (*A_ptrToFunction)(void))
{
	callBackCompareMatch = A_ptrToFunction;
}

u8 MTIMER_u8GetCounterRegister(void)
{
	u8 local_counterRegister = TCNT0;
	return local_counterRegister;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	(*callBackCompareMatch)();
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	(*callBackOverflow)();
}
