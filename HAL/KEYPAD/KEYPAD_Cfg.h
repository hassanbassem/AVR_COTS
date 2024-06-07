/*
 * KEYPAD_Cfg.h
 *
 *  Created on: Apr 24, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_

#define KEYPAD_PORT PORTA

#define ROW0 PIN4
#define ROW1 PIN5
#define ROW2 PIN6
#define ROW3 PIN7

#define COL0 PIN3
#define COL1 PIN2
#define COL2 PIN1
#define COL3 PIN0

#define ROWS_ARRAY {ROW0, ROW1, ROW2, ROW3}
#define COLS_ARRAY {COL0, COL1, COL2, COL3}

#define KEY_NOT_PRESSED 255

#define KEYS_ARRAY {{'1', '2', '3', '+'},{'4', '5', '6', '-'},{'7', '8', '9', '*'},{'C', '0', '=', '/'}};

#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_ */
