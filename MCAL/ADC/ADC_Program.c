/*
 * ADC_Program.c
 *
 *  Created on: Jun 17, 2023
 *      Author: hassan
 */

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include <stdlib.h>
#include "../include/LIB/bit_math.h"
#include "../include/LIB/std_types.h"

/****************************************************/
/* ADC Directives   							    */
/****************************************************/
#include "../include/MCAL/ADC/ADC_Interface.h"
#include "../include/MCAL/ADC/ADC_Private.h"
#include "../include/MCAL/ADC/ADC_Cfg.h"

void (*callBack) (u32) = NULL;

void MADC_voidInit(void)
{
	ADMUX &= ~(3<<6);
	ADMUX |= VOLT_REF<<6;

	CLR_BIT(ADMUX, ADLAR_BIT);

	CLR_BIT(ADCSRA, ADATE_BIT);

	ADCSRA &= ~(7);
	ADCSRA |= PRESCALER;

	ADMUX &= ~(0b00011111);
	ADMUX |= ADC_CHANNEL;

	SET_BIT(ADCSRA, ADEN_BIT);
}

u16 MADC_u16GetDigitalValue(void)
{
	u16 local_digitalValue=0;

	while (!GET_BIT(ADCSRA, ADIF_BIT));

	SET_BIT(ADCSRA, ADIF_BIT);

	local_digitalValue = ADC_DATA;

	return local_digitalValue;
}

void MADC_voidSetPIE(ADC_STATUS A_STATUS)
{
	if (A_STATUS)
		SET_BIT(ADCSRA, ADIE_BIT);
	else
		CLR_BIT(ADCSRA, ADIE_BIT);
}

void MADC_voidStartConversion(void)
{
		SET_BIT(ADCSRA, ADSC_BIT);
}

void MADC_voidSetCallback(void* (ptrToFunc)(u32))
{
	callBack = ptrToFunc;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	u16 local_digitalValue = ADC_DATA;
	u16 local_analogValue = local_digitalValue*5000UL/1024;
	(*callBack)(local_analogValue);
	MADC_voidStartConversion();
}
