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

int perro_obtenerId(ePerro *_arrPerro, int _tamPerro)
{
	int opcion;
	int idPerrito=-1;
	int cantidadPerritos = perro_obtenerCantidad(_arrPerro, _tamPerro);

	if(_arrPerro!=NULL)
	{
		perro_mostrarTodos(_arrPerro, _tamPerro);
		printf("Ingrese su perrito: (0-%d): ", cantidadPerritos-1);
		opcion=getInt("", "Error. opcion inválida. Reingrese su perrito: ", 0, cantidadPerritos-1);

		idPerrito=_arrPerro[opcion].id;

		return idPerrito;
	}
	return -1;
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

void perro_mostrarTodos(ePerro *_arrPerro, int _tamPerro)
{
	printLine("LISTA DE PERRITOS");
	if(_arrPerro!=NULL)
	{
		for(int i=0; i<_tamPerro; i++)
		{
			if(_arrPerro[i].estado==1)
			{
				printf("%d - %s, '%s'\n", i, _arrPerro[i].nombre, _arrPerro[i].raza);
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
