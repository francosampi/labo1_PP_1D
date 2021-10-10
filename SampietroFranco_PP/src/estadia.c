/*
 * funciones.c
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadia.h"
#include "inputs.h"

void estadia_inicializarArray(eEstadia *_arrEstadia, int _tam)
{
	if(_arrEstadia!=NULL)
	{
		for(int i=0; i<_tam; i++)
		{
			_arrEstadia[i].estado = 0;
		}
	}
}

int estadia_buscarEspacio(eEstadia *_arrEstadia, int _tam)
{
	int index = -1;

	if(_arrEstadia!=NULL)
	{
		for(int i=0; i<_tam; i++)
		{
			if(_arrEstadia[i].estado == 0)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

int estadia_buscarDesdeId(eEstadia *_arrEstadia, int _tam, int _id)
{
	int index=-1;

	for(int i=0; i<_tam; i++)
	{
		if(_arrEstadia[i].estado==1 && _arrEstadia[i].id==_id)
		{
			index=i;
			break;
		}
	}
	return index;
}

int estadia_ordenarTodas(eEstadia *_arrEstadia, int _tam, int _tamChars)
{
	eEstadia auxEstadia;
	int flagSwap;
	int nuevoLimite;
	char nombreDuenioUno[_tamChars];
	char nombreDuenioDos[_tamChars];

	if(_arrEstadia!=NULL && _tam>-1)
	{
		for(int i=0; i<_tam-1; i++)
		{
			for(int j=i+1; j<_tam; j++)
			{
				if(_arrEstadia[i].estado==1 && _arrEstadia[j].estado==1)
				{
					if(_arrEstadia[i].fecha.dia<_arrEstadia[j].fecha.dia)
					{
						estadia_swapear(&_arrEstadia[i], &_arrEstadia[j]);
					}
					if(_arrEstadia[i].fecha.mes<_arrEstadia[j].fecha.mes)
					{
						estadia_swapear(&_arrEstadia[i], &_arrEstadia[j]);
					}
					if(_arrEstadia[i].fecha.anio<_arrEstadia[j].fecha.anio)
					{
						estadia_swapear(&_arrEstadia[i], &_arrEstadia[j]);
					}
					if(
						(_arrEstadia[i].fecha.anio==_arrEstadia[j].fecha.anio) &&
						(_arrEstadia[i].fecha.mes==_arrEstadia[j].fecha.mes) &&
						(_arrEstadia[i].fecha.dia==_arrEstadia[j].fecha.dia)
					)
					{
						strcpy(nombreDuenioUno, _arrEstadia[i].nombreDuenio);
						strcpy(nombreDuenioDos, _arrEstadia[j].nombreDuenio);
						strlwr(nombreDuenioUno);
						strlwr(nombreDuenioDos);

						if(strcmp(nombreDuenioUno, nombreDuenioDos)==1)
						{
							estadia_swapear(&_arrEstadia[i], &_arrEstadia[j]);
						}
					}
				}
			}
		}
		/*
		else if(_arrEstadia[i].fecha.mes<_arrEstadia[j].fecha.mes)
		{
			auxEstadia = _arrEstadia[i];
			_arrEstadia[i] = _arrEstadia[j];
			_arrEstadia[j] = auxEstadia;
		}
		else if(_arrEstadia[i].fecha.dia<_arrEstadia[j].fecha.dia)
		{
			auxEstadia = _arrEstadia[i];
			_arrEstadia[i] = _arrEstadia[j];
			_arrEstadia[j] = auxEstadia;
		}
		/*
		if(_arrEstadia[i].estado==1 && _arrEstadia[j].estado==1)
		{

			if(_arrEstadia[i].fecha.anio<_arrEstadia[j].fecha.anio)
			{
				auxEstadia = _arrEstadia[i];
				_arrEstadia[i] = _arrEstadia[j];
				_arrEstadia[j] = auxEstadia;
			}
			else if(_arrEstadia[i].fecha.mes<_arrEstadia[j].fecha.mes)
			{
				auxEstadia = _arrEstadia[i];
				_arrEstadia[i] = _arrEstadia[j];
				_arrEstadia[j] = auxEstadia;
			}
			else if(_arrEstadia[i].fecha.dia<_arrEstadia[j].fecha.dia)
			{
				auxEstadia = _arrEstadia[i];
				_arrEstadia[i] = _arrEstadia[j];
				_arrEstadia[j] = auxEstadia;
			}

			else if((_arrEstadia[i].fecha.anio==_arrEstadia[j].fecha.anio) &&
					(_arrEstadia[i].fecha.mes==_arrEstadia[j].fecha.mes) &&
					(_arrEstadia[i].fecha.dia==_arrEstadia[j].fecha.dia))
			{
				strcpy(nombreDuenioUno, _arrEstadia[i].nombreDuenio);
				strcpy(nombreDuenioDos, _arrEstadia[j].nombreDuenio);
				strlwr(nombreDuenioUno);
				strlwr(nombreDuenioDos);

				if(strcmp(nombreDuenioUno, nombreDuenioDos)==1)
				{
					estadia_swapear(&_arrEstadia[i], &_arrEstadia[j]);
					continue;
				}
			}
			if(
				(_arrEstadia[i].fecha.anio+_arrEstadia[i].fecha.mes+_arrEstadia[i].fecha.dia<_arrEstadia[j].fecha.anio+_arrEstadia[j].fecha.mes+_arrEstadia[j].fecha.dia) ||
				(strcmp(nombreDuenioUno, nombreDuenioDos)==1)
			)
			*/
		return 0;
	}
	return -1;
}

void estadia_swapear(eEstadia *_est1, eEstadia *_est2)
{
	eEstadia auxEstadia;

	auxEstadia = *_est1;
	*_est1 = *_est2;
	*_est2 = auxEstadia;
}

eFecha pedirFecha(char *_msj)
{
	eFecha fecha;

	printLine(_msj);
	fecha.dia = getInt("Ingrese dia (1-31): ", "Error. Reingrese dia (1-31): ", 1, 31);
	fecha.mes = getInt("Ingrese mes (1-12): ", "Error. Reingrese mes (1-12): ", 1, 12);
	fecha.anio = getInt("Ingrese año (2019-2021): ", "Error. Reingrese año (2019-2021): ", 2019, 2021);

	return fecha;
}

void estadia_hardCodear(eEstadia *_arrEstadias, int _tam) //!!
{
	int ids[] = {10000, 10001, 10002, 10004, 10005};
	char nombres[][21] = {"AA", "AB", "BA", "DD", "BB"};
	int telefonosContacto[] = {10101010, 20202020, 30303030, 40404040, 50505050};
	int idPerros[] = {7000, 7001, 7002, 7001, 7000};
	eFecha fechas[] = {
			{1,1,2021},
			{31,1,2021},
			{15,1,2019},
			{1,1,2021},
			{1,1,2021}
	};

	for(int i=0; i<_tam; i++)
	{
		_arrEstadias[i].id = ids[i];
		strcpy(_arrEstadias[i].nombreDuenio, nombres[i]);
		_arrEstadias[i].telefonoContacto = telefonosContacto[i];
		_arrEstadias[i].idPerro = idPerros[i];
		_arrEstadias[i].estado = 1;
		_arrEstadias[i].fecha=fechas[i];
	}
}
