/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#include "7seg.h"

extern int timer1_flag;
extern int timer1_counter;

int checkFlag1();
void setTimer1(int duration);

extern int timer0_flag;
extern int timer0_counter;

int checkFlag0();
void setTimer0(int duration);

extern int timer2_flag;
extern int timer2_counter;

int checkFlag2();
void setTimer2(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
