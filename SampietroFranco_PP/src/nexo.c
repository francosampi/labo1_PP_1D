/*
 * nexo.c
 *
 *  Created on: 10 oct. 2021
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"

int estadia_reservarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, eDuenio *_arrDuenio, int _tamDuenio,  int _tamCharsPerro, int _tamCharsDuenio, int *_id)
{
	if(_arrEstadia!=NULL)
	{
		int index=estadia_buscarEspacio(_arrEstadia, _tam);
		int nuevoId=*_id;

		if (index!=-1)
		{
			printLine("RESERVAR ESTADIA");

			_arrEstadia[index].id=nuevoId;
			_arrEstadia[index].idDuenio=duenio_obtenerIdDesdeLista(_arrDuenio, _tamDuenio);
			_arrEstadia[index].idPerro=perro_obtenerId(_arrPerro, _tamPerro);
			_arrEstadia[index].fecha=pedirFecha("INGRESAR FECHA");

			printLine("");
			if(_arrEstadia[index].idPerro!=-1 && _arrEstadia[index].idDuenio!=-1)
			{
				printf("ESTADIA A RESERVAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO", "PERRO/A", "FECHA DE ESTADIA");
				estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _arrDuenio, _tamDuenio, _tamCharsPerro, _tamCharsDuenio);
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
					printf("\nSe canceló el alta de la reserva...");
					printLine("");
				}
			}
		}
	}
	return -1;
}

void estadia_mostrarUna(eEstadia _est, ePerro *_arrPerro, int _tamPerro, eDuenio *_arrDuenio, int _tamDuenio, int _tamCharsPerro, int _tamCharsDuenio)
{
	char nombrePerrito[_tamCharsPerro];
	char nombreDuenio[_tamCharsDuenio];
	long int telDuenio;

	if(
		perro_obtenerNombre(_arrPerro, _tamPerro, _est.idPerro, nombrePerrito)==0 &&
		duenio_obtenerNombre(_arrDuenio, _tamDuenio, _est.idDuenio, nombreDuenio)==0 &&
		duenio_obtenerTelefono(_arrDuenio, _tamDuenio, _est.idDuenio, &telDuenio)==0
		)
	{
		printf("%-10d %-20s %-20ld %-20s %d/%d/%d", _est.id, nombreDuenio, telDuenio, nombrePerrito, _est.fecha.dia, _est.fecha.mes, _est.fecha.anio);
	}
}

void estadia_mostrarTodas(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, eDuenio *_arrDuenio, int _tamDuenio, int _tamCharsPerro, int _tamCharsDuenio)
{
	printLine("LISTA DE ESTADIAS");
	printf("\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO", "PERRO/A", "FECHA DE ESTADIA");

	for(int i=0; i<_tam; i++)
	{
		if(_arrEstadia[i].estado==1)
		{
			estadia_mostrarUna(_arrEstadia[i], _arrPerro, _tamPerro, _arrDuenio, _tamDuenio, _tamCharsPerro, _tamCharsDuenio);
			printf("\n");
		}
	}
	printf("\n");
}


int estadia_subMenuModificarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, eDuenio *_arrDuenio, int _tamDuenio, int _tamCharsPerro, int _tamCharsDuenio)
{
	int ret=-1;

	if(_arrEstadia!=NULL)
	{
		int index;
		int idIngresado;
		int opcion;
		eEstadia auxEstadia;
		eDuenio auxDuenio;
		long int telefonoAux;

		idIngresado=getInt("Ingrese ID de la estadía (10000-19999): ", "Error. opcion inválida. Reingrese la ID (10000-19999): ", 10000, 19999);
		index = estadia_buscarDesdeId(_arrEstadia, _tam, idIngresado);

		if(index!=-1)
		{
			do{
				auxEstadia=_arrEstadia[index];

				printLine("MODIFICAR ESTADIA");
				printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO", "PERRO/A", "FECHA DE ESTADIA");
				estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _arrDuenio, _tamDuenio, _tamCharsPerro, _tamCharsDuenio);
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
						printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO", "PERRO/A", "FECHA DE ESTADIA");
						estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _arrDuenio, _tamDuenio, _tamCharsPerro, _tamCharsDuenio);
						printf("\n");
						telefonoAux=getlong("\nIngrese su numero de telefono (10 digitos): ", "Ingrese un numero de telefono valido (10 digitos): ", 100000000, 1599999999);

						int indexDuenio = duenio_buscarDesdeId(_arrDuenio, _tamDuenio, _arrEstadia[index].idDuenio);
						if (indexDuenio!=-1)
						{
							auxDuenio=_arrDuenio[indexDuenio];
							auxDuenio.telefonoContacto=telefonoAux;
						}

						printf("\n%-10s %-20s %-20s\n", "ID", "NOMBRE", "TELEFONO");
						duenio_mostrarUno(auxDuenio);
						printLine("");

						if (verify("\nGuardar cambios? Ingresar 's': ")==0)
						{
							_arrDuenio[indexDuenio].telefonoContacto = auxDuenio.telefonoContacto;
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
						printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO", "PERRO/A", "FECHA DE ESTADIA");
						estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _arrDuenio, _tamDuenio, _tamCharsPerro, _tamCharsDuenio);
						printf("\n");
						auxEstadia.idPerro=perro_obtenerId(_arrPerro, _tamPerro);

						printf("\nESTADIA A MODIFICAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO", "PERRO/A", "FECHA DE ESTADIA");
						estadia_mostrarUna(auxEstadia, _arrPerro, _tamPerro, _arrDuenio, _tamDuenio, _tamCharsPerro, _tamCharsDuenio);
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
			printf("\nError. La estadía no fue encontrada bajo esa ID (ID: %d)\n", idIngresado);
		}
	}
	return ret;
}

int estadia_cancelarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, eDuenio *_arrDuenio, int _tamDuenio, int _tamCharsPerro, int _tamCharsDuenio)
{
	int index=-1;
	int idIngresado=getInt("Ingrese ID a cancelar (10000-19999): ", "Error. Reingrese ID a cancelar (10000-19999): ", 10000, 19999);

	index=estadia_buscarDesdeId(_arrEstadia, _tam, idIngresado);

	if(_arrEstadia!=NULL && index!=-1)
	{
		printf("\nESTADIA A CANCELAR:\n\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
		estadia_mostrarUna(_arrEstadia[index], _arrPerro, _tamPerro, _arrDuenio, _tamDuenio, _tamCharsPerro, _tamCharsDuenio);
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

int estadia_ordenarTodas(eEstadia *_arrEstadia, int _tam, eDuenio *_arrDuenio, int _tamDuenio, int _tamChars)
{
	if(_arrEstadia!=NULL && _tam>-1)
	{
		char nombreDuenioUno[_tamChars];
		char nombreDuenioDos[_tamChars];

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
						duenio_obtenerNombre(_arrDuenio, _tamDuenio, _arrEstadia[i].idDuenio, nombreDuenioUno);
						duenio_obtenerNombre(_arrDuenio, _tamDuenio, _arrEstadia[j].idDuenio, nombreDuenioDos);
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
		return 0;
	}
	return -1;
}

int perro_masEstadias(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro)
{
	int indexPerroMasEstadias=-1;
	int flagMayor=0;
	int mayorCantidadEstadias=0;

	if(_arrEstadia!=NULL && _arrPerro!=NULL)
	{
		for(int i=0; i<_tamPerro; i++)
		{
			if(_arrPerro[i].estado==1)
			{
				for(int j=0; j<_tam; j++)
				{
					if(_arrEstadia[j].estado==1)
					{
						if(_arrEstadia[j].idPerro==_arrPerro[i].id)
						{
							_arrPerro[i].estadias++;
						}
					}
				}
			}
		}
		for(int a=0; a<_tamPerro; a++)
		{
			if(_arrPerro[a].estado==1 && (flagMayor==0 || _arrPerro[a].estadias>mayorCantidadEstadias))
			{
				mayorCantidadEstadias=_arrPerro[a].estadias;
				indexPerroMasEstadias=a;
				flagMayor=1;
			}
		}
		if(indexPerroMasEstadias!=-1)
		{
			printLine("PERRITO CON MAS ESTADIAS");
			printf("\n%-10s %-20s %-20s %-20s\n", "ID", "NOMBRE", "RAZA", "EDAD");
			perro_mostrarUno(_arrPerro[indexPerroMasEstadias]);
			printLine("");
			return 0;
		}
		else
		{
			printf("Hubo un error encontrando al perrito...");
		}
	}
	return -1;
}

int perro_conSusEstadias(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, eDuenio *_arrDuenio, int _tamDuenio, int _tamCharsPerro, int _tamCharsDuenio)
{
	if(_arrEstadia!=NULL && _arrPerro!=NULL)
	{
		for(int i=0; i<_tamPerro; i++)
		{
			int tieneEstadias=0;
			if(_arrPerro[i].estado==1)
			{
				char nombrePerroTitulo[_tamCharsPerro];
				perro_obtenerNombre(_arrPerro, _tamPerro, _arrPerro[i].id, nombrePerroTitulo);
				printLine(nombrePerroTitulo);
				printf("\n");
				printLine("ESTADIAS");
				for(int j=0; j<_tam; j++)
				{
					if(_arrEstadia[j].estado==1)
					{
						if(_arrEstadia[j].idPerro==_arrPerro[i].id)
						{
							tieneEstadias=1;
							printf("\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "DUEÑO", "TELEFONO/CEL", "PERRO/A", "FECHA DE ESTADIA");
							estadia_mostrarUna(_arrEstadia[j], _arrPerro, _tamPerro, _arrDuenio, _tamDuenio, _tamCharsPerro, _tamCharsDuenio);
							printf("\n");
						}
					}
				}
				if(tieneEstadias==0)
				{
					printf("No tiene reservada ninguna estadia...\n");
				}
			}
		}
		printLine("");
	}
	return -1;
}
