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
			_arrEstadia[i].estado=0;
		}
	}
}

int estadia_buscarEspacio(eEstadia *_arrEstadia, int _tam)
{
	int index=-1;

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

	if(_arrEstadia!=NULL)
	{
		for(int i=0; i<_tam; i++)
		{
			if(_arrEstadia[i].estado==1 && _arrEstadia[i].id==_id)
			{
				index=i;
				break;
			}
		}
	}
	return index;
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
	fecha.anio = getInt("Ingrese año (2021-2023): ", "Error. Reingrese año (2021-2023): ", 2021, 2023);

	return fecha;
}
