/*
 * LCD_Interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

typedef enum
{
	ROW1 = 1,
	ROW2
}ROWS;

typedef enum
{
	COL1 = 1,
	COL2,
	COL3,
	COL4,
	COL5,
	COL6,
	COL7,
	COL8,
	COL9,
	COL10,
	COL11,
	COL12,
	COL13,
	COL14,
	COL15,
	COL16
}COLS;



void HLCD_voidSendCommand (u8 A_u8Command);
void HLCD_voidSendData (u8 A_u8Data);
void HLCD_voidInit (void);
void HLCD_voidSendString (u8 *A_Pu8String);
void HLCD_voidClearDisplay (void);
void HLCD_voidDisplayNumber(u32 A_s32Number);
void HLCD_voidSendCommand4bit (u8 A_u8Command);
void HLCD_voidSendData4bit (u8 A_u8Data);
void HLCD_voidInit4bit (void);
void HLCD_voidSendString4bit (u8 *A_Pu8String);
void HLCD_voidDisplayNumber4bit(u32 A_s32Number);
void HLCD_voidGoToPosition4bit(ROWS A_rowNumber, COLS A_colNumber);
void HLCD_voidGenerateSpecialCharacter4bit(u8* A_patternArray, u8 A_patternNo);
void HLCD_voidClearDisplay4bit (void);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
