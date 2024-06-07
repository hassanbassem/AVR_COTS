/*
 * SPI_Cfg.h
 *
 *  Created on: Jul 10, 2023
 *      Author: hassan
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

#define INTERRUPT 1
//1 -> LSB first
//0 -> MSB first
#define DATA_ORDER 0
//1 -> master
//0 -> slave
#define MASTER_SLAVE_SELECT 0
//1 -> falling first
//0 -> rising first
#define CLOCK_POLARITY 0
//1 -> setup first
//0 -> sampling first
#define CLOCK_PHASE 0

#define FREQ F_128



#endif /* MCAL_SPI_SPI_CFG_H_ */
