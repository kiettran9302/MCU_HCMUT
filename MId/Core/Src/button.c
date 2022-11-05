/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */

#include "button.h"
#include "main.h"

#define NO_OF_BUTTONS	3
#define NO_OF_VALUES 	10

GPIO_TypeDef * buttonPort[NO_OF_BUTTONS] = {
	BUTTON_1_GPIO_Port,
	BUTTON_2_GPIO_Port,
	BUTTON_3_GPIO_Port,
};

uint16_t buttonPin[NO_OF_BUTTONS] = {
	BUTTON_1_Pin,
	BUTTON_2_Pin,
	BUTTON_3_Pin,
};


//Flag
int button_flag[] = {0,0,0};
int button_long_flag[] = {0,0,0};

//Bien chong rung
int KeyReg0[] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimerForKeyPress = 200;

//Bien Chong De
int KeyReg3[] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

//BienDe
int TimerForLongPress[] = {300,300,300};

int isButtonPressed(int button) {
	if (button_flag[button] == 1){
		button_flag[button] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int button){
	//ToDO
	button_flag[button] = 1;
}

int isButtonLongPressed(int button) {
	if (button_long_flag[button] == 1){
		return 1;
	}
	return 0;
}

void getKeyInput(int button) {
	KeyReg0[button] = KeyReg1[button];
	KeyReg1[button] = KeyReg2[button];
	KeyReg2[button]	= HAL_GPIO_ReadPin(buttonPort[button],buttonPin[button]);
	if ((KeyReg0[button] == KeyReg1[button]) && (KeyReg1[button] == KeyReg2[button])) {
		if (KeyReg3[button] != KeyReg2[button])  {
			//Nhan Tha
			KeyReg3[button] = KeyReg2[button];
			if (KeyReg2[button] == PRESSED_STATE) {
				//TODO
				TimerForLongPress[button]--;
				if (TimerForLongPress[button] <= 0){
					TimerForLongPress[button] = 0;
					button_long_flag[button] = 1;
				}
				subKeyProcess(button);
				TimerForKeyPress = 200;
			}

		} else if (KeyReg3[button] == KeyReg2[button]){
			if (KeyReg3[button] == PRESSED_STATE) {
				TimerForLongPress[button]--;
				if (TimerForLongPress[button] <= 0){
					TimerForLongPress[button] = 0;
					button_long_flag[button] = 1;
				}
			}
		}
		else {
			//Nhan De
			TimerForKeyPress--;
			if (TimerForKeyPress == 0) {
				KeyReg3[button] = NORMAL_STATE;
				button_long_flag[button] = 0;
				TimerForLongPress[button] = 300;
			}
		}
	} else {
		button_long_flag[button] = 0;
		button_flag[button] = 0;
		TimerForLongPress[button] = 300;
	}
}
