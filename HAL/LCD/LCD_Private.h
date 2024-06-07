/*
 * LCD_Private.h
 *
 *  Created on: Apr 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_


#define FUNCTION_SET CONC_BIT(0,0,1,LCD_DL,LCD_NO_OF_LINES,LCD_CHAR_FONT,0,0)

#define DISPLAY_ON_OFF_CONTROL CONC_BIT(0,0,0,0,1,DISPLAY_ON,CURSOR_DISPLAY,CURSOR_BLINK)

#define DISPLAY_CLEAR 0b00000001

#define ENTRY_MODE_SET CONC_BIT(0,0,0,0,0,1,DATA_DIRECTION,SHIFT_DISPLAY)

#define ROW1_ADDRESS 0

#define ROW2_ADDRESS 64

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
