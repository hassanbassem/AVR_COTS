/*
 * SERVO_Program.c
 *
 *  Created on: Jun 29, 2023
 *      Author: hassan
 */

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/std_types.h"
#include "../include/LIB/bit_math.h"

/****************************************************/
/* TIMER1 Directives		     				    */
/****************************************************/
#include "../include/MCAL/TIMER1/TIMER1_Interface.h"


/****************************************************/
/* SERVO Directives		     					    */
/****************************************************/
#include "../include/HAL/SERVO/SERVO_Interface.h"
#include "../include/HAL/SERVO/SERVO_Private.h"
#include "../include/HAL/SERVO/SERVO_Cfg.h"

void HSERVO_voidMoveAngle(u8 A_angle)
{
	MTIMER1_voidSet0CR1ARegister((POSITIVE_90_ON_TIME - NEGATIVE_90_ON_TIME)/180*A_angle + NEGATIVE_90_ON_TIME);
}
