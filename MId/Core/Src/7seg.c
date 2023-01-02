/*
 * 7seg.c
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */


#include "7seg.h"

#define NO_OF_SEGMENTS	7
#define NO_OF_VALUES 	10

#define SECOND 			1000 // 1s = 1000ms


//seven segment ports and pins
GPIO_TypeDef * sevenSegPort[NO_OF_SEGMENTS] = {
	SEG_A_GPIO_Port,
	SEG_B_GPIO_Port,
	SEG_C_GPIO_Port,
	SEG_D_GPIO_Port,
	SEG_E_GPIO_Port,
	SEG_F_GPIO_Port,
	SEG_G_GPIO_Port
};

uint16_t sevenSegPin[NO_OF_SEGMENTS] = {
	SEG_A_Pin,
	SEG_B_Pin,
	SEG_C_Pin,
	SEG_D_Pin,
	SEG_E_Pin,
	SEG_F_Pin,
	SEG_G_Pin
};


//seven segment display
const uint8_t sevenSegValue[NO_OF_VALUES] = {
	0x40, // 0
	0x79, // 1
	0x24, // 2
	0x30, // 3
	0x19, // 4
	0x12, // 5
	0x02, // 6
	0x78, // 7
	0x00, // 8
	0x10, // 9
};

void driver7SEG(int num) {
	if(num < 0 || num > 9) return;
	for(int i = 0; i < NO_OF_SEGMENTS; i++) {
		HAL_GPIO_WritePin(sevenSegPort[i], sevenSegPin[i], (sevenSegValue[num] >> i) & 0x01);
	}
}

void display7SEG(int index) {
	driver7SEG(index);
}

