/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */

#include "fsm.h"

#define AUTO_CHANGE		1000 // 1 sec - inc seg 1

int status = INIT;

void fsm_simple_buttons_run(){
	switch(status){
	case INIT:
		setTimer0(AUTO_CHANGE);
		setTimer1(1000);
		setTimer2(10000);
		status = WAIT;
		break;
	case WAIT:
		display7SEG(counter);
		if (isButtonPressed(0)){
			status = RESET;
		}
		if (isButtonPressed(1)){
			status = INC;
		}
		if (isButtonPressed(2)){
			status = DEC;
		}
		if (isButtonLongPressed(1)){
			status = LONG_INC;
		}
		if (isButtonLongPressed(2)){
			status = LONG_DEC;
		}
		if (checkFlag2()){
			status = AUTO;
		}
		break;
	case RESET:
		setTimer2(10000);
		counter = 0;
		status = WAIT;
		break;
	case INC:
		setTimer2(10000);
		if (counter == 9) {
			counter = 0;
			status = WAIT;
			break;
		}
		counter++;
		status = WAIT;
		break;
	case DEC:
		setTimer2(10000);
		if (counter == 0) {
			counter = 9;
			status = WAIT;
			break;
		}
		counter--;
		status = WAIT;
		break;
	case LONG_INC:
		setTimer2(10000);
		if (checkFlag0() && isButtonLongPressed(1)){
			setTimer0(AUTO_CHANGE);
			counter++;
			counter = counter %10;
			display7SEG(counter);
		}
		status = WAIT;
		break;
	case LONG_DEC:
		setTimer2(10000);
		if (checkFlag0() && isButtonLongPressed(2)){
			setTimer0(AUTO_CHANGE);
			counter--;
			if (counter < 0) counter = 9;
			display7SEG(counter);
		}
		status = WAIT;
		break;
	case AUTO:
		if (checkFlag0()){
			setTimer0(AUTO_CHANGE);
			counter--;
			display7SEG(counter);
		}
		if (counter == 0) {
			status = WAIT;
			break;
		}
	default :
		break;
	}
}
