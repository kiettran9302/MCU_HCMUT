/*
 * 7seg.h
 *
 *  Created on: Oct 30, 2022
 *      Author: hp
 */
#include "main.h"

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

void Display7Seg(int num);
typedef enum State {One, Two, Three, Four} EState;
void tswitch (EState state);
void update7SEG ( int index );


#endif /* INC_7SEG_H_ */
