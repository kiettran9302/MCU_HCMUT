/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonPressed(int button);

// Vua xu ly chong rung
void subKeyProcess(int button);
void getKeyInput(int button);



#endif /* INC_BUTTON_H_ */
