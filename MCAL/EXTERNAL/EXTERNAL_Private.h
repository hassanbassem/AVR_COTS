/*
 * MEXTERNAL_Private.h
 *
 *  Created on: Jun 14, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_INTERRUPTS_EXTERNAL_EXTERNAL_PRIVATE_H_
#define INCLUDE_MCAL_INTERRUPTS_EXTERNAL_EXTERNAL_PRIVATE_H_

#define SREG (*(volatile u8*)0x5F)
#define GICR (*(volatile u8*)0x5B)
#define GIFR (*(volatile u8*)0x5A)
#define MCUCR (*(volatile u8*)0x55)
#define MCUCSR (*(volatile u8*)0x54)

#define I_BIT 7
#define INT0_E_BIT 6
#define INT1_E_BIT 7
#define INT2_E_BIT 5

#define INT0_FLAG_BIT 6
#define INT1_FLAG_BIT 7
#define INT2_FLAG_BIT 5

#endif /* INCLUDE_MCAL_INTERRUPTS_EXTERNAL_EXTERNAL_PRIVATE_H_ */
