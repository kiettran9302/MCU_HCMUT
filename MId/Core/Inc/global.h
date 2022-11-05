/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: hp
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "7seg.h"
#include "software_timer.h"
#include "button.h"

#define INIT		1
#define WAIT		2
#define RESET		3
#define INC			4
#define DEC			5

#define LONG_INC 	14
#define LONG_DEC 	15

#define AUTO 		20

extern int counter;
extern int status;

#endif /* INC_GLOBAL_H_ */
