/*
 * funciones.c
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
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

/**
 * @fn int estadia_reservarUna(eEstadia*, int, ePerro*, int, int, int, int, int)
 * @brief Esta funcion nos deja reservar una estadia
 *
 * @param _arr el arreglo de estadias
 * @param _tam el tamaño del arreglo de estadias
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamaño del arreglo de perros
 * @param _index index disponible para asignar la estadia
 * @param _id toma ultimo id ingresado
 * @param _tamCharsDuenio tamaño del arreglo de caracteres del dueño
 * @param _tamCharsPerro tamaño del arreglo de caracteres del perrito
 * @return
 */
int estadia_reservarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsDuenio, int _tamCharsPerro, int *_id)
{
	if(_arrEstadia!=NULL)
	{
		int index=estadia_buscarEspacio(_arrEstadia, _tam);
		int nuevoId=*_id;

		if (index!=-1)
		{
			printLine("RESERVAR ESTADIA");
			_arrEstadia[index].id=nuevoId;

			getString(_arrEstadia[index].nombreDuenio, "Ingrese nombre del/a dueño/a: ", "Descripcion invalida, hasta 50 caracteres, reingrese: ", _tamCharsDuenio);
			_arrEstadia[index].telefonoContacto=getInt("Ingrese su numero de telefono (8 digitos): ", "Ingrese un numero de telefono valido (8 digitos): ", 9999999, 99999999);
			_arrEstadia[index].idPerro=perro_obtenerId(_arrPerro, _tamPerro);
			_arrEstadia[index].fecha=pedirFecha("INGRESAR FECHA");

			printLine("");
			if(_arrEstadia[index].idPerro!=-1)
			{
				printf("ESTADIA A RESERVAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
				estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _tamCharsPerro);
				printLine("");

				if(verify("\nIngrese 's' para confirmar la reserva: ")==0)
				{
					_arrEstadia[index].estado=1;
					nuevoId++;
					*_id=nuevoId;
					printf("\nSe dio de alta la reserva!");
					printLine("");
					return 0;
				}
				else
				{
					printf("\nSe canceló el alta de la reserva...");
					printLine("");
				}
			}
		}
	}
	return -1;
}

void estadia_mostrarUna(eEstadia _est, ePerro *_arrPerro, int _tamPerro, int _tamChars)
{
	char nombrePerrito[_tamChars];

	if(perro_obtenerNombre(_arrPerro, _tamPerro, _est.idPerro, nombrePerrito)==0)
	{
		printf("%-10d %-20s %-20d %-20s %d/%d/%d", _est.id, _est.nombreDuenio, _est.telefonoContacto, nombrePerrito, _est.fecha.dia, _est.fecha.mes, _est.fecha.anio);
	}
}

int estadia_subMenuModificarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsPerro)
{
	int ret=-1;

	if(_arrEstadia!=NULL)
	{
		int index;
		int idIngresado;
		int opcion;
		eEstadia auxEstadia;

		idIngresado=getInt("Ingrese ID de su estadía (10000-19999): ", "Error. opcion inválida. Reingrese su ID (10000-19999): ", 10000, 19999);
		index = estadia_buscarDesdeId(_arrEstadia, _tam, idIngresado);

		if(index!=-1)
		{
			printLine("MODIFICAR ESTADIA");
			printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
			estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _tamCharsPerro);

			do{
				auxEstadia=_arrEstadia[index];
				printLine("");
				opcion=getInt("1. MODIFICAR TELEFONO\n"
							  "2. MODIFICAR PERRO\n"
							  "3. SALIR\n"
							  "----------------------------\n"
							  "Ingrese una opcion (1-3): ",
							  "1. MODIFICAR TELEFONO\n"
							  "2. MODIFICAR PERRO\n"
							  "3. SALIR\n"
							  "----------------------------\n"
							  "Opcion invalida, reingrese (1-3): ", 1, 3);
				switch(opcion)
				{
					case 1:
						printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
						estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _tamCharsPerro);
						auxEstadia.telefonoContacto=getInt("Ingrese su numero de telefono (8 digitos): ", "Ingrese un numero de telefono valido (8 digitos): ", 9999999, 99999999);

						printf("\nCONTACTO MODIFICADO:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
						estadia_mostrarUna(auxEstadia, _arrPerro, _tamPerro, _tamCharsPerro);
						printLine("");

						if (verify("\nGuardar cambios? Ingresar 's': ")==0)
						{
							_arrEstadia[index].telefonoContacto = auxEstadia.telefonoContacto;
							printf("\nTelefono de contacto modificado correctamente!");
							printLine("");
							ret = 0;
						}
						else
						{
							printf("\nSe canceló la modificacion");
							printLine("");
						}
						system("pause");
					break;
					case 2:
						printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
						estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _tamCharsPerro);
						auxEstadia.idPerro=perro_obtenerId(_arrPerro, _tamPerro);

						printf("\nPERRITO REASIGNADO:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
						estadia_mostrarUna(auxEstadia, _arrPerro, _tamPerro, _tamCharsPerro);
						printLine("");

						if (verify("\nGuardar cambios? Ingresar 's': ")==0)
						{
							_arrEstadia[index].idPerro = auxEstadia.idPerro;
							printf("\nPerro reasignado correctamente!");
							printLine("");
							ret = 0;
						}
						else
						{
							printf("\nSe canceló la modificacion");
							printLine("");
						}
						system("pause");
					break;
					case 3:
						if(verify("\nVolver atrás? Ingresar 's': ")==0)
						{
							printf("\nVolviendo al menú principal");
							printLine("");
						}
						else
						{
							opcion=0;
						}
					break;
				}
			}while(opcion!=3);
		}
		else
		{
			printf("\nError. La estadía no fue encontrada bajo esa ID (ID: %d)", idIngresado);
		}
	}
	return ret;
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

int perro_obtenerId(ePerro *_arrPerro, int _tamPerro)
{
	int opcion;
	int idPerrito=-1;
	int cantidadPerritos = perro_obtenerCantidad(_arrPerro, _tamPerro);

	printLine("LISTA DE PERRITOS");
	for(int i=0; i<cantidadPerritos; i++)
	{
		printf("%d - %s, '%s'", i, _arrPerro[i].nombre, _arrPerro[i].raza);
		if(i<cantidadPerritos-1)
		{
			printf("\n");
		}
	}
	printLine("");
	opcion=getInt("Ingrese su perrito: ", "Error. opcion inválida. Reingrese su perrito: ", 0, cantidadPerritos-1);

	idPerrito=_arrPerro[opcion].id;

	return idPerrito;
}

int perro_obtenerCantidad(ePerro *_arrPerro, int _tamPerro)
{
	int cantidadPerritos=0;

	for(int i=0; i<_tamPerro; i++)
	{
		if(_arrPerro[i].estado==1)
		{
			cantidadPerritos++;
		}
	}
	return cantidadPerritos;
}

int perro_obtenerNombre(ePerro *_arrPerro, int _tamPerro, int idPerro, char *_nombrePerro)
{
	for(int j=0; j<_tamPerro;j++)
	{
		if(idPerro==_arrPerro[j].id)
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

	printLine(_msj);
	fecha.dia = getInt("Ingrese dia (1-31): ", "Error. Reingrese dia (1-31): ", 1, 31);
	fecha.mes = getInt("Ingrese mes (1-12): ", "Error. Reingrese mes (1-12): ", 1, 12);
	fecha.anio = getInt("Ingrese año (2019-2021): ", "Error. Reingrese año (2019-2021): ", 2019, 2021);

	return fecha;
}
