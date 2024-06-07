/*
 * bit_math.h
 *
 *  Created on: Apr 16, 2023
 *      Author: hassan
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(Reg, bitNum) (Reg |= 1<<bitNum)
#define CLR_BIT(Reg, bitNum) (Reg &= ~(1<<bitNum))
#define TOGGLE_BIT(Reg, bitNum) (Reg ^= 1<<bitNum)
#define GET_BIT(Reg, bitNum) (Reg>>bitNum & 1)

#define GET_LOWER_NIBBLE(Reg) (Reg << 4)
#define GET_UPPER_NIBBLE(Reg) (Reg & 0b11110000)

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif /* LIB_BIT_MATH_H_ */
