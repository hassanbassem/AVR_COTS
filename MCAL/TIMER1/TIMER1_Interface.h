/*
 * TIMER1_Interface.h
 *
 *  Created on: Jun 27, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_

typedef enum
{
	TIMER1_NORMAL_DIO,
	TOGGLE_ON_COMPARE_MATCH,
	CLEAR_ON_COMPARE_MATCH,
	SET_ON_COMPARE_MATCH,
	TOGGLE_ON_COMPARE_MATCH_PWM = 1,
	NON_INVERTING_PWM,
	INVERTING_PWM
}TIMER1_COM;

typedef enum
{
	TIMER1_NORMAL,
	PWM_PHASE_CORRECT_8_BIT,
	PWM_PHASE_CORRECT_9_BIT,
	PWM_PHASE_CORRECT_10_BIT,
	CTC_OCR1A,
	FAST_PWM_8_BIT,
	FAST_PWM_9_BIT,
	FAST_PWM_10_BIT,
	PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1,
	PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A,
	PWM_PHASE_CORRECT_ICR1,
	PWM_PHASE_CORRECT_OCR1A,
	CTC_ICR1,
	FAST_PWM_ICR1 = 14,
	FAST_PWM_OCR1A
}TIMER1_WGM;

typedef enum
{
	TIMER1_NO_CLK,
	TIMER1_CLK,
	TIMER1_CLK_8,
	TIMER1_CLK_64,
	TIMER1_CLK_256,
	TIMER1_CLK_1024,
	TIMER1_CLK_FALLING,
	TIMER1_CLK_RISING
}TIMER1_CLK_SELECT;

typedef enum
{
	TIMER1_DISABLE,
	TIMER1_ENABLE
}TIMER1_STATUS;

typedef enum
{
	TIMER1_FALLING,
	TIMER1_RISING
}ICP1_EDGE_SELECT;

void MTIMER1_voidInit(void);
void MTIMER1_voidSetCOM1A(TIMER1_COM A_COM);
void MTIMER1_voidSetCOM1B(TIMER1_COM A_COM);
void MTIMER1_voidSetCounterRegister(u16 A_counterValue);
void MTIMER1_voidSet0CR1ARegister(u16 A_OCR1AValue);
void MTIMER1_voidSet0CR1BRegister(u16 A_OCR1BValue);
void MTIMER1_voidSetICR1Register(u16 A_ICR1Value);
void MTIMER1_voidSetInputCaptureInterruptEnable(TIMER1_STATUS A_STATUS);
void MTIMER1_voidSetOutputCompareAmatchInterruptEnable(TIMER1_STATUS A_STATUS);
void MTIMER1_voidSetOutputCompareBmatchInterruptEnable(TIMER1_STATUS A_STATUS);
void MTIMER1_voidSetOverflowInterruptEnable(TIMER1_STATUS A_STATUS);
void MTIMER1_voidClearInputCaptureInterruptFlag(void);
void MTIMER1_voidClearOutputCompareAmatchInterruptFlag(void);
void MTIMER1_voidClearOutputCompareBmatchInterruptFlag(void);
void MTIMER1_voidClearOverflowInterruptFlag(void);
void MTIMER1_voidSetCallbackInputCapture(void (*A_ptrToFunction)(void));
void MTIMER1_voidSetCallbackOutputCompareAmatch(void (*A_ptrToFunction)(void));
void MTIMER1_voidSetCallbackOutputCompareBmatch(void (*A_ptrToFunction)(void));
void MTIMER1_voidSetCallbackOverflow(void (*A_ptrToFunction)(void));
u16 MTIMER1_u16GetCounterRegister(void);
void MTIMER1_voidStopTimer(void);
void MTIMER1_voidSetICP1EdgeSelect(ICP1_EDGE_SELECT A_EdgeSelect);
u16 MTIMER1_u16GetICR1Register(void);

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
