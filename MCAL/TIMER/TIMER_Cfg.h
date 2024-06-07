/*
 * TIMER_Cfg.h
 *
 *  Created on: Jun 20, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_CFG_H_
#define INCLUDE_MCAL_TIMER_TIMER_CFG_H_

//normal 0
//ctc 1
//fast pwm 2
//phase correct pwm 3

#define TIMER_MODE_CHOICE 2

#define OCR_VALUE 100

#define COM_CHOICE NON_INVERTING_MODE_PWM

#define CLK_CHOICE CLK_8

#endif /* INCLUDE_MCAL_TIMER_TIMER_CFG_H_ */
