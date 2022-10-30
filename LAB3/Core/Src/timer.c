/*
 * timer.c
 *
 *  Created on: Oct 30, 2022
 *      Author: hp
 */


#include "main.h"
#include "input_reading.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		button_reading();
	}
}
