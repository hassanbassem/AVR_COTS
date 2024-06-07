/*
 * ADC_Private.h
 *
 *  Created on: Jun 17, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX (*(volatile u8*)0x27)
#define ADCSRA (*(volatile u8*)0x26)
#define ADC_DATA (*(volatile u16*)0x24)

#define ADLAR_BIT 5

#define ADEN_BIT 7
#define ADSC_BIT 6
#define ADATE_BIT 5
#define ADIF_BIT 4
#define ADIE_BIT 3

#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
