/*
 * SPI_Private.h
 *
 *  Created on: Jul 10, 2023
 *      Author: hassan
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define SPCR *(volatile u8*)0x2D
#define SPSR *(volatile u8*)0x2E
#define SPDR *(volatile u8*)0x2F

#define SPIE 7
#define SPE 6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPIF 7
#define WCOL 6
#define SPI2X 2

#define F_4 0
#define F_16 1
#define F_64 2
#define F_128 3
#define F_2 4
#define F_8 5
#define F_32 6

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
