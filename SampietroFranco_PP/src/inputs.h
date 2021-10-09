/*
 * inputs.h
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */

#ifndef INPUTS_H_
#define INPUTS_H_

//VALIDATE STRING
int getString(char *_str, char *_msg, char *_errMsg, int _strMaxLen);
int isLetter(char *_str, char *_errMsg);
int isNotBlank(char *_str, char *_errMsg);
int getName(char *_str, char *_msg, char *_errMsgOnLen, char *_errMsgNotLetter, char *_errMsgIsBlank, int _strMaxLen);

//VALIDATE NUMBERS/CONFIRM
int getInt(char *_msg, char *_errMsg, int _min, int _max);
float getFloat(char *_msg, char *_errMsg, int _min, int _max);
int getCharacter(char *_char, char *_msg);
int verify(char *_msg);

//HUD
void printLine(char *_msg);

#endif /* INPUTS_H_ */
