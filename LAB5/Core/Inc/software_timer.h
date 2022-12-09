/*
 * software_timer.h
 *
 *  Created on: Dec 3, 2022
 *      Author: hp
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
#include "global.h"

#define TICK 		10 //ms


extern int LED_timer_flag;
extern int SYS_timer_flag;
extern int COM_timer_flag;

void setLEDTimer(int duration);
void setCOMTimer(int duration);
void setSYSTimer(int duration);
int checkLED();
int checkCOM();
int checkSYS();
void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
