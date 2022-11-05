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
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
