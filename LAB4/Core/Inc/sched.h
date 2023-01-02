/*
 * sched.h
 *
 *  Created on: Nov 26, 2022
 *      Author: hp
 */

#ifndef INC_SCHED_H_
#define INC_SCHED_H_

#include <stdint.h>
#define SYSTEM_DELAY 	10

//#include <task.h>

typedef struct{
	void (*pTask)(void); //function pointer
	uint32_t 	Delay;
	uint32_t	Period;
	uint8_t		RunMe;

	uint32_t	TaskID;
}sTask;

#define SCH_MAX_TASKS 	40
#define NO_TASK_ID		0


void SCH_Init(void);
uint32_t SCH_Add_Task (void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD); //SetTimer

void SCH_Update(void); //TimerRun

void SCH_Dispatch_Task(void);//Check Flag

void SCH_Delete(uint32_t ID);
#endif /* INC_SCHED_H_ */
