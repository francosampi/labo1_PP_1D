/*
 * funciones.c
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "inputs.h"

void estadia_inicializarArray(eEstadia *_arr, int _tam)
{
	int i;
	for(i=0; i<_tam; i++)
	{
		_arr[i].estado = 0;
	}
}

int estadia_buscarEspacio(eEstadia *_arr, int _tam)
{
	int index = -1;

	for(int i=0; i<_tam; i++)
	{
		if(_arr[i].estado == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

int estadia_reservarUna(eEstadia *_arr, int _tam, ePerro *_arrPerro, int _tamPerro, int _index, int _id)
{
	_arr[_index].id=_id;

	getString(_arr[_index].nombreDuenio, "Ingrese nombre del/a dueño/a: ", "Descripcion invalida, hasta 50 caracteres, reingrese: ", 51);
	_arr[_index].telefonoContacto=getInt("Ingrese su numero de contacto", "Ingrese una numero valido", 9999999, 99999999);
	_arr[_index].idPerro=perro_obtenerId(_arrPerro, _tamPerro);

	printf("\ESTADIA A RESERVAR:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO/CEL", "PERRO", "FECHA DE ESTADIA");
	estadia_mostrarUna(_arr[_index], _arrPerro, _tamPerro);

	if(verify("\nIngrese 's' para confirmar la reserva: ")==0)
	{
		_arr[_index].estado=1;
		return 0;
	}
	return -1;
}

void estadia_mostrarUna(eEstadia _est, ePerro _arrPerro, int _tamPerro)
{
	char nombrePerrito[];

	perro_obtenerNombre(_arrPerro, _tamPerro, nombrePerrito);

	printf("%-5d %-50s %-20d %-20s %-20d/%d/%d\n", _est.id, _est.nombreDuenio, _est.telefonoContacto, nombrePerrito, _est.fecha.dia, _est.fecha.mes, _est.fecha.anio);
}

int perro_obtenerId(ePerro _arrPerro, int _tamPerro)
{
	int opcion;
	int idPerrito = -1;
	int cantidadPerritos = strlen(_arrPerro);

	printf("Ingrese su perrito: \n");
	for(int i=0; i<cantidadPerritos; i++)
	{
		printf("%d - %s, '$s'\n", i, _arrPerro[i].nombre, _arrPerro[i].raza);
	}
	opcion=getInt("Ingrese su perrito: ", "Error. opcion inválida. Reingrese su perrito: ", 0, cantidadPerritos);

	idPerrito=_arrPerro[opcion].id;

	return idPerrito;
}

int perro_obtenerNombre(ePerro _arrPerro, int _tamPerro, int idPerro, char *_nombrePerro)
{
	for(int j=0; j<_tamPerro;j++)
	{
		if(idPerro == _arrPerro[j].id)
		{
			strcpy(_nombrePerro, _arrPerro[j].nombre);
			return 0;
		}
	}
	return -1;
}

eFecha pedirFecha(char *_msj)
{
	eFecha fecha;

	printf("%s", _msj);
	fecha.dia = getInt("Ingrese dia (1-30): ", "Error. Reingrese dia (1-30): ", 1, 31);
	fecha.mes = getInt("Ingrese mes (1-12): ", "Error. Reingrese mes (1-12): ", 1, 12);
	fecha.anio = getInt("Ingrese año (2019-2021): ", "Error. Reingrese año (2019-2021): ", 2019, 2021);

	return fecha;
}
