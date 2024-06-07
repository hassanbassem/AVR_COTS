/*
 * SPI_Interface.h
 *
 *  Created on: Jul 10, 2023
 *      Author: hassan
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

void MSPI_Init(void);
u8 MSPI_u8TransmitReceive(u8 A_u8Char);
void MSPI_voidSetCallBack(void (*A_PtrToFunction) (u8));

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
