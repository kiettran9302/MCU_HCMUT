/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */

#include "fsm.h"

int status = INIT;

void fsm_simple_buttons_run(){
	switch(status){
	case INIT:
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
		break;
	case RESET:
		counter = 0;
		status = WAIT;
		break;
	case INC:
		if (counter == 9) {
			counter = 0;
			status = WAIT;
			break;
		}
		counter++;
		status = WAIT;
		break;
	case DEC:
		if (counter == 0) {
			counter = 9;
			status = WAIT;
			break;
		}
		counter--;
		status = WAIT;
		break;
	default :
		break;
	}
}
