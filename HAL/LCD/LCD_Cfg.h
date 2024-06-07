/*
 * LCD_Cfg.h
 *
 *  Created on: Apr 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_


#define LCD_DATA_PORT    PORTC
#define LCD_CONTROL_PORT PORTD

#define LCD_RS_PIN  PIN7
#define LCD_RW_PIN  PIN6
#define LCD_E_PIN   PIN5

// 0 --> 4-bit mode
// 1 --> 8-bit mode
#define LCD_DL	0

// 0 --> 1 Line
// 1 --> 2 Lines
#define LCD_NO_OF_LINES	1

// 0 --> 5 * 7
// 1 --> 5 * 10
#define LCD_CHAR_FONT	0

// 0 --> Off
// 1 --> ON
#define DISPLAY_ON 1

// 0 --> Off
// 1 --> ON
#define CURSOR_DISPLAY 0

// 0 --> Off
// 1 --> ON
#define CURSOR_BLINK 0

// Left to Right --> 1
// Right to Left --> 0
#define DATA_DIRECTION 1

#define SHIFT_DISPLAY 0
#endif /* HAL_LCD_LCD_CFG_H_ */
