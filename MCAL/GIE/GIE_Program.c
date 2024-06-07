/*
 * GIE_Program.c
 *
 *  Created on: Aug 25, 2023
 *      Author: hassan
 */

#include "../../LIB/include/bit_math.h"
#include "../../LIB/include/std_types.h"

#include "include/GIE_Interface.h"
#include "include/GIE_Private.h"
#include "include/GIE_Cfg.h"


void MGIE_voidSetGIE(GIE_STATUS A_STATUS)
{
	if (A_STATUS)
	{
		SET_BIT(SREG, I_BIT);
	}
	else
	{
		CLR_BIT(SREG, I_BIT);
	}
}
