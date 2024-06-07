/*
 * TWI_Private.h
 *
 *  Created on: Jul 31, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_TWI_TWI_PRIVATE_H_
#define INCLUDE_MCAL_TWI_TWI_PRIVATE_H_

#define TWBR *((volatile u8*)0x20)
#define TWCR *((volatile u8*)0x56)
#define TWSR *((volatile u8*)0x21)
#define TWDR *((volatile u8*)0x23)
#define TWAR *((volatile u8*)0x22)

#define TWINT 7
#define TWEA 6
#define TWSTA 5
#define TWSTO 4
#define TWWC 3
#define TWEN 2
#define TWIE 0
#define TWPS1 1
#define TWPS0 0
#define TWGCE 0

#define START 0x08
#define REPEATED_START 0x10
#define SLA_W_ACK 0x18
#define MASTER_DATA_TRANSMITTED_ACK 0x28
#define SLA_R_ACK 0x40
#define MASTER_DATA_RECEIVED_ACK 0x50
#define SLA_W_RECEIVED_ACK 0x60
#define GENERAL_CALL_RECEIVED_ACK 0x70
#define SLAVE_DATA_RECEIVED_ACK 0x80
#define GENERAL_CALL_DATA_RECEIVED_ACK 0x90
#define STOP_OR_REPEATED_START_RECEIVED 0xA0
#define SLA_R_RECEIVED_ACK 0xA8
#define SLAVE_DATA_TRANSMITTED_ACK 0xB8
#define SLAVE_LAST_DATA_TRANSMITTED_ACK 0xC8

#define TWSR_MASK 0xF8

#define F_CPU 8000000UL


#endif /* INCLUDE_MCAL_TWI_TWI_PRIVATE_H_ */
