/*
 * ADC_Interface.h
 *
 *  Created on: Jun 17, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

typedef enum
{
	AREF,
	AVCC,
	Internal = 3
}VOLT_REFS;

typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	ADC_0_0_10,
	ADC_1_0_10,
	ADC_0_0_200,
	ADC_1_0_200,
	ADC_2_2_10,
	ADC_3_2_10,
	ADC_2_2_200,
	ADC_3_2_200,
	ADC_0_1,
	ADC_1_1,
	ADC_2_1,
	ADC_3_1,
	ADC_4_1,
	ADC_5_1,
	ADC_6_1,
	ADC_7_1,
	ADC_0_2,
	ADC_1_2,
	ADC_2_2,
	ADC_3_2,
	ADC_4_2,
	ADC_5_2,
}ADC_CHANNELS;

typedef enum
{
	D2 = 1,
	D4,
	D8,
	D16,
	D32,
	D64,
	D128
}DIV_FACTOR;

typedef enum
{
	ADC_DISABLE,
	ADC_ENABLE
}ADC_STATUS;

void MADC_voidInit(void);
u16 MADC_u16GetDigitalValue(void);
void MADC_voidSetPIE(ADC_STATUS A_STATUS);
void MADC_voidStartConversion(void);
void MADC_voidSetCallback(void* (ptrToFunc)(u32));

#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
