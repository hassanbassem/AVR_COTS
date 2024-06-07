/*
 * KEYPAD_Program.c
 *
 *  Created on: Apr 24, 2023
 *      Author: hassan
 */

/******************************/
/* Library Directives         */
/******************************/
#include <util/delay.h>
#include "../include/LIB/bit_math.h"
#include "../include/LIB/std_types.h"
#define F_CPU 8000000UL

/******************************/
/* DIO Directives         */
/******************************/
#include "../include/MCAL/DIO/DIO_Interface.h"


/******************************/
/* KEYPAD Directives         */
/******************************/
#include "../include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_Private.h"
#include "../include/HAL/KEYPAD/KEYPAD_Cfg.h"

u8 KEYPAD_ROWS[4] = ROWS_ARRAY;
u8 KEYPAD_COLS[4] = COLS_ARRAY;
u8 KEYPAD_KEYS[4][4] = KEYS_ARRAY;

u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 local_u8PressedKey = KEY_NOT_PRESSED;
	for (u8 i = 0; i < 4; i++)
	{
		MDIO_voidSetPinStatus(KEYPAD_PORT, KEYPAD_ROWS[i], DIO_RESET);
		for (u8 j = 0; j < 4; j++)
		{
			if (!MDIO_PinStatusGetPinValue(KEYPAD_PORT, KEYPAD_COLS[j]))
			{
				_delay_ms(30);
				while (!MDIO_PinStatusGetPinValue(KEYPAD_PORT, KEYPAD_COLS[j]))
				{
				}
				local_u8PressedKey = KEYPAD_KEYS[i][j];
				break;
			}
		}
		MDIO_voidSetPinStatus(KEYPAD_PORT, KEYPAD_ROWS[i], DIO_SET);
		if (local_u8PressedKey != KEY_NOT_PRESSED)
			break;
	}
	return local_u8PressedKey;
}
