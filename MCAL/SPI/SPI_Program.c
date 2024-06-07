/*
 * SPI_Program.c
 *
 *  Created on: Jul 10, 2023
 *      Author: hassan
 */

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../../LIB/include/std_types.h"
#include "../../LIB/include/bit_math.h"
#include <stdlib.h>

/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "include/SPI_Interface.h"
#include "include/SPI_Private.h"
#include "include/SPI_Cfg.h"

void (*callBackSPI) (u8) = NULL;

void MSPI_Init(void)
{
#if INTERRUPT == 1
	SET_BIT(SPCR, SPIE);
#else
	CLR_BIT(SPCR, SPIE);
#endif

#if DATA_ORDER == 1
	SET_BIT(SPCR, DORD);
#else
	CLR_BIT(SPCR, DORD);
#endif

#if MASTER_SLAVE_SELECT == 1
	SET_BIT(SPCR, MSTR);
#else
	CLR_BIT(SPCR, MSTR);
#endif

#if CLOCK_POLARITY == 1
	SET_BIT(SPCR, CPOL);
#else
	CLR_BIT(SPCR, CPOL);
#endif

#if CLOCK_PHASE == 1
	SET_BIT(SPCR, CPHA);
#else
	CLR_BIT(SPCR, CPHA);
#endif

	SPCR &= ~(3<<SPR0);
	SPCR |= ((FREQ&3)<<SPR0);
#if FREQ>>2 == 1
	SET_BIT(SPSR, SPI2X);
#else
	CLR_BIT(SPSR, SPI2X);
#endif

	SET_BIT(SPCR, SPE);
}

u8 MSPI_u8TransmitReceive(u8 A_u8Char)
{
	SPDR = A_u8Char;
	while(!GET_BIT(SPSR, SPIF));
	return SPDR;
}

void MSPI_voidSetCallBack(void (*A_PtrToFunction) (u8))
{
	callBackSPI = A_PtrToFunction;
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	u8 local_u8ReceivedData;
	local_u8ReceivedData = SPDR;
	(*callBackSPI)(local_u8ReceivedData);
	SPDR = local_u8ReceivedData;
}
