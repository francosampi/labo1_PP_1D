/*
 * inputs.c
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

/**
 * @fn void getString(char*, char*, char*, int)
 * @brief this ask the user to enter an array of characters and validates it
 *
 * @param _str where the array will be stored
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if there was an error with the input
 * @param _max the limit of characters that the array can store
 */
void getString(char *_str, char *_msg, char *_errMsg, int _max)
{
	char str[200];
	int len;

	printf("%s", _msg);
	fflush(stdin);
	scanf("%[^\n]", str);
	len = strlen(str);

	while(len>_max)
	{
		printf("%s", _errMsg);
		fflush(stdin);
		scanf("%[^\n]", str);
		len = strlen(str);
	}
	strcpy(_str, str);
}

/**
 * @fn int getInt(char*, char*, int, int)
 * @brief this ask the user to enter an int number and validates it
 *
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if there was an error with the input (< min or > max)
 * @param _min the minimum possible number
 * @param _max the maximum possible number
 * @return returns the int number entered
 */
int getInt(char *_msg, char *_errMsg, int _min, int _max)
{
	int num;

	printf("%s", _msg);
	fflush(stdin);
	scanf("%d", &num);

	while(num < _min || num > _max)
	{
		printf("%s", _errMsg);
		fflush(stdin);
		scanf("%d", &num);
	}
	return num;
}

/**
 * @fn float getFloat(char*, char*, int, int)
 * @brief this ask the user to enter a float number and validates it
 *
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if there was an error with the input
 * @param _min the minimum possible number
 * @param _max the maximum possible number
 * @return returns the float number entered
 */
float getFloat(char *_msg, char *_errMsg, int _min, int _max)
{
	float num;

	printf("%s", _msg);
	fflush(stdin);
	scanf("%f", &num);

	while(num < _min || num > _max)
	{
		printf("%s", _errMsg);
		fflush(stdin);
		scanf("%f", &num);
	}
	return num;
}

/**
 * @fn int getCharacter(char*, char*)
 * @brief this asks the user to enter a char and validates it
 *
 * @param _character where the char will be stored
 * @param _msg the message that will show up
 * @return (-1) if error (character variable is null or message not found) - (0) if ok
 */
int getCharacter(char *_char, char *_msg)
{
	if(_char!=NULL && _msg!=NULL)
	{
		printf("%s", _msg);
		fflush(stdin);
		*_char = getchar();
		return 0;
	}
	return -1;
}

/**
 * @fn int verify(char*)
 * @brief this asks the user to enter a char and validates if its an 's' or an 'S'
 *
 * @param _msg the message that will show up
 * @return (-1) if error (character is not an 's' or an 'S') - (0) if ok
 */
int verify(char *_msg)
{
	char ver;

	getCharacter(&ver, _msg);
	if(ver == 's' || ver == 'S')
	{
		return 0;
	}
	return -1;
}

/**
 * @fn void printLine(char*)
 * @brief This shows a separator with a message (or not)
 *
 * @param _msg the message that will be in the middle of the separator
 */
void printLine(char *_msg)
{
	printf("\n----------------%s----------------\n", _msg);
}
