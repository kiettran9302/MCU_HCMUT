/*
 * sched.c
 *
 *  Created on: Nov 26, 2022
 *      Author: hp
 */


#include "sched.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];
uint32_t Current = 0;
uint32_t Size = 0;

void SCH_Init(void) {
	for(uint32_t Index = 0; Index < SCH_MAX_TASKS; Index++) {
		SCH_tasks_G[Index].pTask = 0x0000;
		SCH_tasks_G[Index].Delay = 0;
		SCH_tasks_G[Index].Period = 0;
		SCH_tasks_G[Index].RunMe = 0;
	}
}

uint32_t SCH_Add_Task(void (* pFunction)(void), uint32_t DELAY, uint32_t PERIOD) {
	if(Size == SCH_MAX_TASKS - 1) return SCH_MAX_TASKS;

	uint8_t flag = 0;
	uint32_t Index = 0;
	if(SYSTEM_DELAY > 0) {
		DELAY /= SYSTEM_DELAY;
	}
	for(; Index < Size && flag == 0; Index++) {
		if(DELAY > SCH_tasks_G[Index].Delay) {
			DELAY -= SCH_tasks_G[Index].Delay;
		}
		else {
			flag = 1;
			SCH_tasks_G[Index].Delay -= DELAY;
		}
	}
	if(flag == 1) {
		Index -= 1;
		for(uint32_t Temp = Size; Temp > Index; Temp--) {
			SCH_tasks_G[Temp].pTask = SCH_tasks_G[Temp - 1].pTask;
			SCH_tasks_G[Temp].Delay = SCH_tasks_G[Temp - 1].Delay;
			SCH_tasks_G[Temp].Period = SCH_tasks_G[Temp - 1].Period;
			SCH_tasks_G[Temp].RunMe = SCH_tasks_G[Temp - 1].RunMe;
			SCH_tasks_G[Temp].TaskID = SCH_tasks_G[Temp - 1].RunMe + 1;
		}
	}
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;
	SCH_tasks_G[Index].TaskID = Index;

	Size += 1;

	return Index;
}

void SCH_Delete(uint32_t ID) {
	if(SCH_tasks_G[ID].pTask == 0) return;

	for(uint32_t Temp = ID; Temp < Size - 1; Temp++) {
		SCH_tasks_G[Temp].pTask = SCH_tasks_G[Temp + 1].pTask;
		SCH_tasks_G[Temp].Delay = SCH_tasks_G[Temp + 1].Delay;
		SCH_tasks_G[Temp].Period = SCH_tasks_G[Temp + 1].Period;
		SCH_tasks_G[Temp].RunMe = SCH_tasks_G[Temp + 1].RunMe;
		SCH_tasks_G[Temp].TaskID = SCH_tasks_G[Temp + 1].TaskID - 1;
	}

	Size -= 1;
}

void SCH_Dispatch_Task(void) {
	if(SCH_tasks_G[0].RunMe == 1) {
		(*SCH_tasks_G[0].pTask)();

		if(SCH_tasks_G[0].Period > 0) {
			SCH_Add_Task(SCH_tasks_G[Current].pTask, SCH_tasks_G[Current].Period, SCH_tasks_G[Current].Period);
		}

		SCH_Delete(0);
	}
}

void SCH_Update(void) {
	if(SCH_tasks_G[0].Delay == 0) {
		SCH_tasks_G[0].RunMe = 1;
	}
	else {
		SCH_tasks_G[0].Delay--;
	}
}


