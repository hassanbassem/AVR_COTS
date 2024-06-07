/*
 * TIMER_Interface.h
 *
 *  Created on: Jun 20, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_
#define INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_

typedef enum
{
	NO_CLK,
	CLK,
	CLK_8,
	CLK_64,
	CLK_256,
	CLK_1024,
	EXT_FALLING,
	EXT_RISING
}CLK_SELECT;

typedef enum
{
	TIMER_DISABLE,
	TIMER_ENABLE
}TIMER_STATUS;

typedef enum
{
	NORMAL_DIO,
	TOGGLE_OC0_CTC,
	CLEAR_OC0_CTC,
	SET_OC0_CTC,
	NON_INVERTING_MODE_PWM = 2,
	INVERTING_MODE_PWM
}COM;

void MTIMER_voidInit(void);
void MTIMER_voidSetOCRValue(u8 A_OCRValue);
void MTIMER_voidSetCounterRegister(u8 A_counterValue);
void MTIMER_voidSetOutputCompareMatchInterruptEnable(TIMER_STATUS A_STATUS);
void MTIMER_voidSetOverflowInterruptEnable(TIMER_STATUS A_STATUS);
void MTIMER_voidClearOutputCompareMatchInterruptFlag(void);
void MTIMER_voidClearOverflowInterruptFlag(void);
void MTIMER_voidSetCompareOutputMode(COM A_COM);
void MTIMER_voidSetPrescaler(CLK_SELECT A_CLK_SELECT);
void MTIMER_voidSetCallbackOverflow(void (*A_ptrToFunction)(void));
void MTIMER_voidSetCallbackCompareMatch(void (*A_ptrToFunction)(void));
u8 MTIMER_u8GetCounterRegister(void);

#endif /* INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_ */
