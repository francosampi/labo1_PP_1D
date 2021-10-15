/*
 * duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: franc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duenio.h"
#include "inputs.h"

void duenio_inicializarArray(eDuenio *_arrDuenio, int _tamDuenio)
{
	if(_arrDuenio!=NULL)
	{
		for(int i=5; i<_tamDuenio; i++)
		{
			_arrDuenio[i].estado=0;
		}
	}
}

int duenio_obtenerIdDesdeLista(eDuenio *_arrDuenio, int _tamDuenio)
{
	int opcion;
	int index=-1;

	if(_arrDuenio!=NULL)
	{
		while(index==-1)
		{
			duenio_mostrarTodos(_arrDuenio, _tamDuenio);
			opcion=getInt("Ingrese su dueño(30000-30050): ", "Error. opcion inválida. Reingrese su dueño(30000-30050): ", 30000, 30050);

			if (duenio_buscarDesdeId(_arrDuenio, _tamDuenio, opcion)!=-1)
			{
				return opcion;
			}
			else
			{
				printf("\nError. No se encuentra al dueño bajo esa ID (ID: %d)\n", opcion);
			}
		}
	}
	return -1;
}


int duenio_obtenerIdDesdeIndex(eDuenio *_arrDuenio, int _tamDuenio, int _id)
{
	int id=-1;

	if(_arrDuenio!=NULL)
	{
		for(int i=0; i<_tamDuenio; i++)
		{
			if(_arrDuenio[i].estado==1 && i==_id)
			{
				id=_id;
				return id;
			}
		}
	}
	return id;
}


int duenio_buscarDesdeId(eDuenio *_arrDuenio, int _tamDuenio, int _id)
{
	int index =-1;

	if(_arrDuenio!=NULL)
	{
		for(int i=0; i<_tamDuenio; i++)
		{
			if(_arrDuenio[i].estado==1 && _arrDuenio[i].id==_id)
			{
				index = i;
				return index;
			}
		}
	}
	return index;
}

int duenio_obtenerNombre(eDuenio *_arrDuenio, int _tamDuenio, int _idDuenio, char *_nombreDuenio)
{
	if(_arrDuenio!=NULL)
	{
		for(int j=0; j<_tamDuenio;j++)
		{
			if(_idDuenio==_arrDuenio[j].id)
			{
				strcpy(_nombreDuenio, _arrDuenio[j].nombre);
				return 0;
			}
		}
	}
	return -1;
}

int duenio_obtenerTelefono(eDuenio *_arrDuenio, int _tamDuenio, int _idDuenio, int *_telDuenio)
{
	if(_arrDuenio!=NULL)
	{
		for(int j=0; j<_tamDuenio;j++)
		{
			if(_idDuenio==_arrDuenio[j].id)
			{
				*_telDuenio=_arrDuenio[j].telefonoContacto;
				return 0;
			}
		}
	}
	return -1;
}

void duenio_mostrarUno(eDuenio _duenio)
{
	printf("%-10d %-40s %-20d", _duenio.id, _duenio.nombre, _duenio.telefonoContacto);
}

void duenio_mostrarTodos(eDuenio *_arrDuenio, int _tamDuenio)
{
	printLine("LISTA DE DUEÑOS");
	printf("\n%-10s %-40s %-20s\n", "ID", "NOMBRE", "TELEFONO");
	if(_arrDuenio!=NULL)
	{
		for(int i=0; i<_tamDuenio; i++)
		{
			if(_arrDuenio[i].estado==1)
			{
				duenio_mostrarUno(_arrDuenio[i]);
				printf("\n");
			}
		}
	}
	printLine("");
}
