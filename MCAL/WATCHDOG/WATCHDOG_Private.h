/*
 * WATCHDOG_Private.h
 *
 *  Created on: Jun 29, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_WATCHDOG_WATCHDOG_PRIVATE_H_
#define INCLUDE_MCAL_WATCHDOG_WATCHDOG_PRIVATE_H_

#define WDTCR (*(volatile u8*)0x41)

#define WDP0 0
#define WDE 3
#define WDTOE 4

#endif /* INCLUDE_MCAL_WATCHDOG_WATCHDOG_PRIVATE_H_ */
