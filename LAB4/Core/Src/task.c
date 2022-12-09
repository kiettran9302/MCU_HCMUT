/*
 * task.c
 *
 *  Created on: Nov 27, 2022
 *      Author: hp
 */


#include "task.h"

void task1(void){
	HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
}

void task2(void){
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
}
void task3(void){
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}
void task4(void){
	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
}
void task5(void){
	HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
}


