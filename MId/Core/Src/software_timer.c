/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */

#include "software_timer.h"

#define TICK 10

int timer1_flag = 0;
int timer1_counter = 0;

int checkFlag1(){
	if (timer1_flag == 1) {
		timer1_flag = 0;
		return 1;
	}
	return 0;
}

void setTimer1 (int duration){
	timer1_counter = duration/TICK;
}

void timerRun(){
	if (timer1_counter > 0){
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
}
