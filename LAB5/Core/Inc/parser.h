/*
 * parser.h
 *
 *  Created on: Dec 3, 2022
 *      Author: hp
 */

#ifndef INC_PARSER_H_
#define INC_PARSER_H_

#include "global.h"

void command_parser_fsm(void);

void updateBuffer(uint8_t updated);
void clearBuffer(void);

#endif /* INC_PARSER_H_ */
