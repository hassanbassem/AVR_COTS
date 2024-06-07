/*
 * GIE_Interface.h
 *
 *  Created on: Aug 25, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_GIE_GIE_INTERFACE_H_
#define INCLUDE_MCAL_GIE_GIE_INTERFACE_H_

typedef enum
{
	GIE_DISABLE,
	GIE_ENABLE
}GIE_STATUS;

void MGIE_voidSetGIE(GIE_STATUS A_STATUS);

#endif /* INCLUDE_MCAL_GIE_GIE_INTERFACE_H_ */
