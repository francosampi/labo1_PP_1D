/*
 * nexo.c
 *
 *  Created on: 10 oct. 2021
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

/**
 * @fn int estadia_reservarUna(eEstadia*, int, ePerro*, int, int, int, int, int)
 * @brief Esta funcion nos deja reservar una estadia
 *
 * @param _arr el arreglo de estadias
 * @param _tam el tama�o del arreglo de estadias
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tama�o del arreglo de perros
 * @param _index index disponible para asignar la estadia
 * @param _id toma ultimo id ingresado
 * @param _tamCharsDuenio tama�o del arreglo de caracteres del due�o
 * @param _tamCharsPerro tama�o del arreglo de caracteres del perrito
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

				getName(_arrEstadia[index].nombreDuenio,
						"Ingrese nombre del/a due�o/a: ",
						"El nombre no debe superar los 50 caracteres\n",
						"El nombre no debe tener caracteres especiales\n",
						"El nombre no puede estar vac�o\n",
						_tamCharsDuenio);
				_arrEstadia[index].telefonoContacto=getInt("Ingrese su numero de telefono (8 digitos): ", "Ingrese un numero de telefono valido (8 digitos): ", 9999999, 99999999);
				_arrEstadia[index].idPerro=perro_obtenerId(_arrPerro, _tamPerro);
				_arrEstadia[index].fecha=pedirFecha("INGRESAR FECHA");

				printLine("");
				if(_arrEstadia[index].idPerro!=-1)
				{
					printf("ESTADIA A RESERVAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUE�O", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
					estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _tamCharsPerro);
					printLine("");

					if(verify("\nConfirmar reserva? Ingrese 's': ")==0)
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
						printf("\nSe cancel� el alta de la reserva...");
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

void estadia_mostrarTodas(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamChars)
{
	printLine("LISTA DE ESTADIAS");
	printf("\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUE�O", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");

	for(int i=0; i<_tam; i++)
	{
		if(_arrEstadia[i].estado==1)
		{
			estadia_mostrarUna(_arrEstadia[i], _arrPerro, _tamPerro, _tamChars);
			printf("\n");
		}
	}
	printf("\n");
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

		idIngresado=getInt("Ingrese ID de su estad�a (10000-19999): ", "Error. opcion inv�lida. Reingrese su ID (10000-19999): ", 10000, 19999);
		index = estadia_buscarDesdeId(_arrEstadia, _tam, idIngresado);

		if(index!=-1)
		{
			printLine("MODIFICAR ESTADIA");
			printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUE�O", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
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
						printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUE�O", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
						estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _tamCharsPerro);
						auxEstadia.telefonoContacto=getInt("\nIngrese su numero de telefono (8 digitos): ", "Ingrese un numero de telefono valido (8 digitos): ", 9999999, 99999999);

						printf("\nCONTACTO MODIFICADO:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUE�O", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
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
							printf("\nSe cancel� la modificacion");
							printLine("");
						}
						system("pause");
					break;
					case 2:
						printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUE�O", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
						estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _tamCharsPerro);
						auxEstadia.idPerro=perro_obtenerId(_arrPerro, _tamPerro);

						printf("\nPERRITO REASIGNADO:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUE�O", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
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
							printf("\nSe cancel� la modificacion");
							printLine("");
						}
						system("pause");
					break;
					case 3:
						if(verify("\nVolver atr�s? Ingresar 's': ")==0)
						{
							printf("\nVolviendo al men� principal");
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
			printf("\nError. La estad�a no fue encontrada bajo esa ID (ID: %d)\n", idIngresado);
		}
	}
	return ret;
}

int estadia_cancelarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsPerro)
{
	int index=-1;
	int idIngresado=getInt("Ingrese ID a cancelar: ", "Error. Reingrese ID a cancelar: ", 10000, 19999);

	index=estadia_buscarDesdeId(_arrEstadia, _tam, idIngresado);

	if(_arrEstadia!=NULL && index!=-1)
	{
		printf("\nESTADIA A CANCELAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUE�O", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
		estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _tamCharsPerro);
		printLine("");

		if (verify("\nConfirmar baja? Ingrese 's': ")==0)
		{
			_arrEstadia[index].estado=0;
			printf("Estadia dada de baja correctamente! (ID: %d)\n", _arrEstadia[index].id);
			return 0;
		}
	}
	return -1;
}
