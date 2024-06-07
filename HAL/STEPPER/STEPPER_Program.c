/*
 * STEPPER_Program.c
 *
 *  Created on: Jun 13, 2023
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
/* STEPPER Directives         */
/******************************/
#include "../include/HAL/STEPPER/STEPPER_Interface.h"
#include "../include/HAL/STEPPER/STEPPER_Private.h"
#include "../include/HAL/STEPPER/STEPPER_Cfg.h"

void HSTEPPER_voidRotate(u16 A_u16Angle)
{
	for (u16 i = 0; i < A_u16Angle/360*FULL_ROTATION_TURNS; i++)
	{
		MDIO_voidSetPinStatus(STEPPER_PORT, BLUE_WIRE_PIN, DIO_RESET);
		MDIO_voidSetPinStatus(STEPPER_PORT, PINK_WIRE_PIN, DIO_SET);
		MDIO_voidSetPinStatus(STEPPER_PORT, YELLOW_WIRE_PIN, DIO_SET);
		MDIO_voidSetPinStatus(STEPPER_PORT, ORANGE_WIRE_PIN, DIO_SET);
		_delay_ms(DELAY_TIME_IN_MS);

		MDIO_voidSetPinStatus(STEPPER_PORT, BLUE_WIRE_PIN, DIO_SET);
		MDIO_voidSetPinStatus(STEPPER_PORT, PINK_WIRE_PIN, DIO_RESET);
		MDIO_voidSetPinStatus(STEPPER_PORT, YELLOW_WIRE_PIN, DIO_SET);
		MDIO_voidSetPinStatus(STEPPER_PORT, ORANGE_WIRE_PIN, DIO_SET);
		_delay_ms(DELAY_TIME_IN_MS);

		MDIO_voidSetPinStatus(STEPPER_PORT, BLUE_WIRE_PIN, DIO_SET);
		MDIO_voidSetPinStatus(STEPPER_PORT, PINK_WIRE_PIN, DIO_SET);
		MDIO_voidSetPinStatus(STEPPER_PORT, YELLOW_WIRE_PIN, DIO_RESET);
		MDIO_voidSetPinStatus(STEPPER_PORT, ORANGE_WIRE_PIN, DIO_SET);
		_delay_ms(DELAY_TIME_IN_MS);

		MDIO_voidSetPinStatus(STEPPER_PORT, BLUE_WIRE_PIN, DIO_SET);
		MDIO_voidSetPinStatus(STEPPER_PORT, PINK_WIRE_PIN, DIO_SET);
		MDIO_voidSetPinStatus(STEPPER_PORT, YELLOW_WIRE_PIN, DIO_SET);
		MDIO_voidSetPinStatus(STEPPER_PORT, ORANGE_WIRE_PIN, DIO_RESET);
		_delay_ms(DELAY_TIME_IN_MS);
	}
}
