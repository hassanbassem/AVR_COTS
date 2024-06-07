

#include <util/delay.h>
#include <string.h>

#include "../../LIB/include/bit_math.h"
#include "../../LIB/include/std_types.h"

#include "../../MCAL/DIO/include/DIO_Interface.h"

#include "include/LCD_Cfg.h"
#include "include/LCD_Interface.h"
#include "include/LCD_Private.h"


#define F_CPU 8000000UL




void HLCD_voidSendCommand (u8 A_u8Command)
{
	// RS --> 0, RW --> 0
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_RESET);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_RESET);

	// Set Data port with the command
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);

	// Set Pulse on E Pin with 2ms delay
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidSendData (u8 A_u8Data)
{
	// RS --> 1, RW --> 0
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_SET);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_RESET);

	// Set Data port with the command
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);

	// Set Pulse on E Pin with 2ms delay
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidInit(void)
{
	// Wait for more than 30 ms
	_delay_ms(32);
	// Function Set Command
	HLCD_voidSendCommand(FUNCTION_SET);
	// wait for more than 39 us
	_delay_ms(1);
	// Display On/Off Control
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	// wait for more than 39 us
	_delay_ms(1);
	// Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	// wait for more than 1.53 ms
	_delay_ms(2);
	// Entry Mode Set
	HLCD_voidSendCommand(ENTRY_MODE_SET);
}

void HLCD_voidSendString (u8 *A_Pu8String)
{
	for (u8 i = 0; i < strlen(A_Pu8String); i++)
		HLCD_voidSendData(A_Pu8String[i]);
}

void HLCD_voidClearDisplay (void)
{
	// Display Clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	// wait for more than 1.53 ms
	_delay_ms(2);
}

void HLCD_voidDisplayNumber(u32 A_s32Number)
{
	u8 local_u8Counter = 0;
	u32 local_s32Number = A_s32Number;
	while (local_s32Number/10 > 0)
	{
		local_s32Number /= 10;
		local_u8Counter++;
	}
	for (u8 i = local_u8Counter + 1; i > 0; i--)
	{
		u32 local_u32Divisor = 1;
		for (u8 j = 0; j < i - 1; j++)
			local_u32Divisor *= 10;
		HLCD_voidSendData(A_s32Number/local_u32Divisor + 48);
		A_s32Number = A_s32Number % local_u32Divisor;
	}
}

void HLCD_voidSendCommand4bit (u8 A_u8Command)
{
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_RESET);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_RESET);

	MDIO_voidSetPortValue(LCD_DATA_PORT, GET_UPPER_NIBBLE(A_u8Command));
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_RESET);
	MDIO_voidSetPortValue(LCD_DATA_PORT, GET_LOWER_NIBBLE(A_u8Command));

	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidSendData4bit (u8 A_u8Data)
{
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_SET);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_RESET);

	MDIO_voidSetPortValue(LCD_DATA_PORT, GET_UPPER_NIBBLE(A_u8Data));
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_RESET);
	MDIO_voidSetPortValue(LCD_DATA_PORT, GET_LOWER_NIBBLE(A_u8Data));

	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidInit4bit (void)
{
		// Wait for more than 30 ms
		_delay_ms(32);
		// Function Set Command
		HLCD_voidSendCommand(0b00100000);
		HLCD_voidSendCommand4bit(FUNCTION_SET);
		// wait for more than 39 us
		_delay_ms(1);
		// Display On/Off Control
		HLCD_voidSendCommand4bit(DISPLAY_ON_OFF_CONTROL);
		// wait for more than 39 us
		_delay_ms(1);
		// Display Clear
		HLCD_voidSendCommand4bit(DISPLAY_CLEAR);
		// wait for more than 1.53 ms
		_delay_ms(2);
		// Entry Mode Set
		HLCD_voidSendCommand4bit(ENTRY_MODE_SET);
}

void HLCD_voidSendString4bit (u8 *A_Pu8String)
{
	for (u8 i = 0; i < strlen(A_Pu8String); i++)
		HLCD_voidSendData4bit(A_Pu8String[i]);
}

void HLCD_voidDisplayNumber4bit(u32 A_s32Number)
{
	u8 local_u8Counter = 0;
	u32 local_s32Number = A_s32Number;
	while (local_s32Number/10 > 0)
	{
		local_s32Number /= 10;
		local_u8Counter++;
	}
	for (u8 i = local_u8Counter + 1; i > 0; i--)
	{
		u32 local_u32Divisor = 1;
		for (u8 j = 0; j < i - 1; j++)
			local_u32Divisor *= 10;
		HLCD_voidSendData4bit(A_s32Number/local_u32Divisor + 48);
		A_s32Number = A_s32Number % local_u32Divisor;
	}
}

void HLCD_voidGoToPosition4bit(ROWS A_rowNumber, COLS A_colNumber)
{
	u8 local_colStart;
	if (A_rowNumber == 1)
		local_colStart = ROW1_ADDRESS;
	else
		local_colStart = ROW2_ADDRESS;
	HLCD_voidSendCommand4bit(0b10000000 | local_colStart+A_colNumber - 1);
	_delay_ms(1);
}

void HLCD_voidGenerateSpecialCharacter4bit(u8* A_patternArray, u8 A_patternNo)
{
	HLCD_voidSendCommand4bit(0b01000000 | A_patternNo*8);
	_delay_ms(1);
	for (u8 i = 0; i < 8; i++)
	{
		HLCD_voidSendData4bit(A_patternArray[i]);
		_delay_ms(1);
	}
}

void HLCD_voidClearDisplay4bit (void)
{
	HLCD_voidSendCommand4bit(DISPLAY_CLEAR);
	_delay_ms(2);
}
