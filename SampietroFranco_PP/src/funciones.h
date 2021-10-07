/*
 * funciones.h
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "inputs.h"

#define TAMNOMBRE 51
#define TAMNOMBREPERRO 21

typedef struct
{
	int id;
	char nombre[TAMNOMBREPERRO];
	char raza[TAMNOMBREPERRO];
	int edad;
}ePerro;

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char nombreDuenio[TAMNOMBRE];
	int telefonoContacto;
	int idPerro;
	eFecha fecha;
	int estado; //0-Vacio, 1-Ocupado
}eEstadia;

eFecha pedirFecha(char *_msj);
int reservarEstadia(eEstadia _arr, int _tam);

#endif /* FUNCIONES_H_ */
