/*
 * EXTERNAL_Program.c
 *
 *  Created on: Jun 14, 2023
 *      Author: hassan
 */

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include <stdlib.h>
#include "../include/LIB/std_types.h"
#include "../include/LIB/bit_math.h"

/****************************************************/
/* EXTERNAL INTERRUPT Directives		     					    */
/****************************************************/
#include "../include/MCAL/EXTERNAL/EXTERNAL_Interface.h"
#include "../include/MCAL/EXTERNAL/EXTERNAL_Private.h"
#include "../include/MCAL/EXTERNAL/EXTERNAL_Cfg.h"

void(*INT0_Callback)(void) = NULL;
void(*INT1_Callback)(void) = NULL;
void(*INT2_Callback)(void) = NULL;

void MEXTERNAL_voidSetGIE(EXTERNAL_STATUS A_STATUS)
{
	if (A_STATUS)
	{
		SET_BIT(SREG, I_BIT);
	}
	else
	{
		CLR_BIT(SREG, I_BIT);
	}

}

void MEXTERNAL_voidSetPIE(INTS A_INT, EXTERNAL_STATUS A_STATUS)
{
	u8 bitsArray[3] = {INT0_E_BIT, INT1_E_BIT, INT2_E_BIT};
	if (A_STATUS)
	{
		SET_BIT(GICR, bitsArray[A_INT]);
	}
	else
	{
		CLR_BIT(GICR, bitsArray[A_INT]);
	}
}

void MEXTERNAL_voidSetSenseMode(INTS A_INT, SENSE_MODE A_SENSE_MODE)
{
	switch(A_INT)
	{
	case INT0:
		MCUCR &= ~3;
		MCUCR |= A_SENSE_MODE;
		break;
	case INT1:
		MCUCR &= ~(3 << 2);
		MCUCR |= (A_SENSE_MODE << 2);
		break;
	case INT2:
		switch(A_SENSE_MODE)
		{
		case RISING: SET_BIT(MCUCSR, 6);
			break;
		case FALLING: CLR_BIT(MCUCSR, 6);
			break;
		default:
			break;
		}
	default:
		break;
	}
}

void MEXTERNAL_voidClearflag(INTS A_INT)
{
	u8 bitsArray[3] = {INT0_FLAG_BIT, INT1_FLAG_BIT, INT2_FLAG_BIT};
		SET_BIT(GIFR, bitsArray[A_INT]);
}

void MEXTERNAL_voidSetCallback(INTS A_INT, void*(ptrToFunction)(void))
{
	switch (A_INT) {
		case INT0:
			INT0_Callback = ptrToFunction;
			break;
		case INT1:
			INT1_Callback = ptrToFunction;
			break;
		case INT2:
			INT2_Callback = ptrToFunction;
			break;
		default:
			break;
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (INT0_Callback != NULL)
		INT0_Callback();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (INT1_Callback != NULL)
		INT1_Callback();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (INT2_Callback != NULL)
		INT2_Callback();
}
