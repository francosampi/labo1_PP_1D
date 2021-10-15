/*
 * perro.c
 *
 *  Created on: 10 oct. 2021
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perro.h"
#include "inputs.h"

void perro_inicializarArray(ePerro *_arrPerro, int _tamPerro) //Inicia en 3 por hardcodeo
{
	if(_arrPerro!=NULL)
	{
		for(int i=3; i<_tamPerro; i++)
		{
			_arrPerro[i].estadias=0;
			_arrPerro[i].estado=0;
		}
	}
}

int perro_obtenerId(ePerro *_arrPerro, int _tamPerro)
{
	int opcion;
	int index=-1;

	if(_arrPerro!=NULL)
	{
		while(index==-1)
		{
			perro_mostrarTodos(_arrPerro, _tamPerro);
			opcion=getInt("Ingrese su perrito(7000-7050): ", "Error. opcion inválida. Reingrese su perrito(7000-7050): ", 7000, 7050);

			if (perro_buscarDesdeId(_arrPerro, _tamPerro, opcion)!=-1)
			{
				return opcion;
			}
			else
			{
				printf("\nError. No se encuentra al perrito bajo esa ID (ID: %d)\n", opcion);
			}
		}
	}
	return -1;
}

int perro_buscarDesdeId(ePerro *_arrPerro, int _tamPerro, int _id)
{
	int index =-1;

	if(_arrPerro!=NULL)
	{
		for(int i=0; i<_tamPerro; i++)
		{
			if(_arrPerro[i].estado==1 && _arrPerro[i].id==_id)
			{
				index = i;
				return index;
			}
		}
	}
	return index;
}

int perro_obtenerCantidad(ePerro *_arrPerro, int _tamPerro)
{
	int cantidadPerritos=0;

	if(_arrPerro!=NULL)
	{
		for(int i=0; i<_tamPerro; i++)
		{
			if(_arrPerro[i].estado==1)
			{
				cantidadPerritos++;
			}
		}
		return cantidadPerritos;
	}
	return -1;
}

int perro_obtenerNombre(ePerro *_arrPerro, int _tamPerro, int _idPerro, char *_nombrePerro)
{
	if(_arrPerro!=NULL)
	{
		for(int j=0; j<_tamPerro;j++)
		{
			if(_idPerro==_arrPerro[j].id)
			{
				strcpy(_nombrePerro, _arrPerro[j].nombre);
				return 0;
			}
		}
	}
	return -1;
}

void perro_mostrarUno(ePerro _perro)
{
	printf("%-10d %-20s %-20s %-20d", _perro.id, _perro.nombre, _perro.raza, _perro.edad);
}

void perro_mostrarTodos(ePerro *_arrPerro, int _tamPerro)
{
	printLine("LISTA DE PERRITOS");
	printf("\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "RAZA", "EDAD");
	if(_arrPerro!=NULL)
	{
		for(int i=0; i<_tamPerro; i++)
		{
			if(_arrPerro[i].estado==1)
			{
				perro_mostrarUno(_arrPerro[i]);
				printf("\n");
			}
		}
	}
	printLine("");
}

int perro_promedioEdad(ePerro *_arrPerro, int _tamPerro)
{
	int edadAcum=0;
	int cantidadPerritos = perro_obtenerCantidad(_arrPerro, _tamPerro);

	if(_arrPerro!=NULL)
	{
		printLine("PROMEDIO DE EDAD");
		for(int i=0; i<_tamPerro; i++)
		{
			if(_arrPerro[i].estado==1)
			{
				edadAcum+=_arrPerro[i].edad;
			}
		}
		printf("%.2f años...\n", (float)edadAcum/cantidadPerritos);
		return 0;
	}
	return -1;
}
