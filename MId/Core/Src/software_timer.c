/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */

#include "software_timer.h"

#define TICK 10

//Timer1 = blinking
//Timer0 = LongPressed
//Timer2 = Auto
//Timer3 = counter

#define AUTO_CHANGE		1000 // 1 sec - inc seg 1

int timer1_flag = 0;
int timer1_counter = 0;
int timer0_flag = 0;
int timer0_counter = 0;
int timer2_flag = 0;
int timer2_counter = 0;


int checkFlag0(){
	if (timer0_flag == 1) {
		timer0_flag = 0;
		return 1;
	}
	return 0;
}

int checkFlag1(){
	if (timer1_flag == 1) {
		timer1_flag = 0;
		return 1;
	}
	return 0;
}

int checkFlag2(){
	if (timer2_flag == 1) {
		timer2_flag = 0;
		return 1;
	}
	return 0;
}

void setTimer0 (int duration){
	timer0_counter = duration/TICK;
}

void setTimer1 (int duration){
	timer1_counter = duration/TICK;
}

void setTimer2(int duration){
	timer2_counter = duration/TICK;
}

void timerRun(){
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter <= 0) {
			timer0_flag = 1;
		}
	}

	if (timer1_counter > 0){
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}

	if (timer2_counter > 0){
		timer2_counter--;
		if (timer2_counter <= 0) {
			timer2_flag = 1;
		}
	}
}
