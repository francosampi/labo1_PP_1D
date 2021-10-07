/*
 * inputs.h
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */

#ifndef INPUTS_H_
#define INPUTS_H_

void getString(char *_str, char *_msg, char *_errMsg, int _max);
int getInt(char *_msg, char *_errMsg, int _min, int _max);
float getFloat(char *_msg, char *_errMsg, int _min, int _max);
int getCharacter(char *_char, char *_msg);
int verify(char *_msg);
void printLine(char *_msg);

#endif /* INPUTS_H_ */
