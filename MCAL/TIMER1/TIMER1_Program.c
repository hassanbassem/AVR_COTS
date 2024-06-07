/*
 * TIMER1_Program.c
 *
 *  Created on: Jun 27, 2023
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
#include "../include/MCAL/TIMER1/TIMER1_Interface.h"
#include "../include/MCAL/TIMER1/TIMER1_Private.h"
#include "../include/MCAL/TIMER1/TIMER1_Cfg.h"

void (*callBackInputCapture) (void) = NULL;
void (*callBackOutputCompareAmatch) (void) = NULL;
void (*callBackOutputCompareBmatch) (void) = NULL;
void (*callBackOverflow1) (void) = NULL;

void MTIMER1_voidInit(void)
{
	TCCR1A &= ~(3<<WGM10_BIT);
	TCCR1A |= ((WGM_CHOICE&3)<<WGM10_BIT);
	TCCR1B &= ~(3<<WGM12_BIT);
	TCCR1B |= ((WGM_CHOICE>>2)<<WGM12_BIT);

	MTIMER1_voidSetCOM1A(COM1A_CHOICE);
	MTIMER1_voidSetCOM1B(COM1B_CHOICE);

	MTIMER1_voidSetICR1Register(ICR1_VALUE);

	MTIMER1_voidSet0CR1ARegister(OCR1A_VALUE);
	MTIMER1_voidSet0CR1BRegister(OCR1B_VALUE);

	MTIMER1_voidSetInputCaptureInterruptEnable(INPUT_CAPTURE_INTERRUPT_ENABLE);
	MTIMER1_voidSetOutputCompareAmatchInterruptEnable(OUTPUT_COMPARE_A_MATCH_INTERRUPT_ENABLE);
	MTIMER1_voidSetOutputCompareBmatchInterruptEnable(OUTPUT_COMPARE_B_MATCH_INTERRUPT_ENABLE);
	MTIMER1_voidSetOverflowInterruptEnable(OVERFLOW_INTERRUPT_ENABLE);

	TCCR1B &= ~(7<<CS10_BIT);
	TCCR1B |= (CLK_CHOICE<<CS10_BIT);
}

void MTIMER1_voidSetCOM1A(TIMER1_COM A_COM)
{
	TCCR1A &= ~(3<<COM1A_BIT);
	TCCR1A |= (A_COM<<COM1A_BIT);
}

void MTIMER1_voidSetCOM1B(TIMER1_COM A_COM)
{
	TCCR1A &= ~(3<<COM1B_BIT);
	TCCR1A |= (A_COM<<COM1B_BIT);
}

void MTIMER1_voidSetCounterRegister(u16 A_counterValue)
{
	TCNT1 = A_counterValue;
}

void MTIMER1_voidSet0CR1ARegister(u16 A_OCR1AValue)
{
	OCR1A = A_OCR1AValue;
}

void MTIMER1_voidSet0CR1BRegister(u16 A_OCR1BValue)
{
	OCR1B = A_OCR1BValue;
}

void MTIMER1_voidSetICR1Register(u16 A_ICR1Value)
{
	ICR1 = A_ICR1Value;
}

void MTIMER1_voidSetInputCaptureInterruptEnable(TIMER1_STATUS A_STATUS)
{
	if (A_STATUS)
		SET_BIT(TIMSK, TICIE1_BIT);
	else
		CLR_BIT(TIMSK, TICIE1_BIT);
}

void MTIMER1_voidSetOutputCompareAmatchInterruptEnable(TIMER1_STATUS A_STATUS)
{
	if (A_STATUS)
		SET_BIT(TIMSK, OCIE1A_BIT);
	else
		CLR_BIT(TIMSK, OCIE1A_BIT);
}

void MTIMER1_voidSetOutputCompareBmatchInterruptEnable(TIMER1_STATUS A_STATUS)
{
	if (A_STATUS)
		SET_BIT(TIMSK, OCIE1B_BIT);
	else
		CLR_BIT(TIMSK, OCIE1B_BIT);
}

void MTIMER1_voidSetOverflowInterruptEnable(TIMER1_STATUS A_STATUS)
{
	if (A_STATUS)
		SET_BIT(TIMSK, TOIE1_BIT);
	else
		CLR_BIT(TIMSK, TOIE1_BIT);
}

void MTIMER1_voidClearInputCaptureInterruptFlag(void)
{
	SET_BIT(TIFR, ICF1_BIT);
}

void MTIMER1_voidClearOutputCompareAmatchInterruptFlag(void)
{
	SET_BIT(TIFR, OCF1A_BIT);
}

void MTIMER1_voidClearOutputCompareBmatchInterruptFlag(void)
{
	SET_BIT(TIFR, OCF1B_BIT);
}

void MTIMER1_voidClearOverflowInterruptFlag(void)
{
	SET_BIT(TIFR, TOV1_BIT);
}

void MTIMER1_voidSetCallbackInputCapture(void (*A_ptrToFunction)(void))
{
	callBackInputCapture = A_ptrToFunction;
}

void MTIMER1_voidSetCallbackOutputCompareAmatch(void (*A_ptrToFunction)(void))
{
	callBackOutputCompareAmatch = A_ptrToFunction;
}

void MTIMER1_voidSetCallbackOutputCompareBmatch(void (*A_ptrToFunction)(void))
{
	callBackOutputCompareBmatch = A_ptrToFunction;
}

void MTIMER1_voidSetCallbackOverflow(void (*A_ptrToFunction)(void))
{
	callBackOverflow1 = A_ptrToFunction;
}

u16 MTIMER1_u16GetCounterRegister(void)
{
	u16 local_u16CounterRegister = TCNT1;
	return local_u16CounterRegister;
}

void MTIMER1_voidStopTimer(void)
{
	TCCR1B &= ~(7<<CS10_BIT);
}

void MTIMER1_voidSetICP1EdgeSelect(ICP1_EDGE_SELECT A_EdgeSelect)
{
	if (A_EdgeSelect)
		SET_BIT(TCCR1B, ICES1_BIT);
	else
		CLR_BIT(TCCR1B, ICES1_BIT);
}

u16 MTIMER1_u16GetICR1Register(void)
{
	u16 local_u16ICR1Register = ICR1;
	return local_u16ICR1Register;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	(*callBackInputCapture)();
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	(*callBackOutputCompareAmatch)();
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	(*callBackOutputCompareBmatch)();
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	(*callBackOverflow1)();
}
