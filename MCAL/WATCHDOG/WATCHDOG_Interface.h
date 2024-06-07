/*
 * WATCHDOG_Interface.h
 *
 *  Created on: Jun 29, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_WATCHDOG_WATCHDOG_INTERFACE_H_
#define INCLUDE_MCAL_WATCHDOG_WATCHDOG_INTERFACE_H_

typedef enum
{
	MS_16,
	MS_32,
	MS_65,
	MS_130,
	MS_260,
	MS_520,
	S_1,
	S_2
}WATCHDOG_PRESCALER;

void MWATCHDOG_voidInit(void);
void MWATCHDOG_enable(void);
void MWATCHDOG_disable(void);

#endif /* INCLUDE_MCAL_WATCHDOG_WATCHDOG_INTERFACE_H_ */
