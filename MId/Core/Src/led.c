/*
 * led.c
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */


#include "led.h"

void ledRun(){
	if (checkFlag1()) {
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer1(1000);
	}
}
