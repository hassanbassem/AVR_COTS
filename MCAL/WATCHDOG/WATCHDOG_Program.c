/*
 * WATCHDOG_Program.c
 *
 *  Created on: Jun 29, 2023
 *      Author: hassan
 */

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/std_types.h"
#include "../include/LIB/bit_math.h"

/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "../include/MCAL/WATCHDOG/WATCHDOG_Interface.h"
#include "../include/MCAL/WATCHDOG/WATCHDOG_Private.h"
#include "../include/MCAL/WATCHDOG/WATCHDOG_Cfg.h"


void MWATCHDOG_voidInit(void)
{
	WDTCR &= ~(7<<WDP0);
	WDTCR |= (PRESCALER<<WDP0);
}

void MWATCHDOG_enable(void)
{
	SET_BIT(WDTCR, WDE);
}

void MWATCHDOG_disable(void)
{
	WDTCR |= (1<<WDE) | (1<<WDTOE);
	CLR_BIT(WDTCR, WDE);
}
