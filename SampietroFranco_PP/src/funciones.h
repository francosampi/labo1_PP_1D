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
	int estado; //0-Vacio, 1-Ocupado
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

void estadia_inicializarArray(eEstadia *arrEstadia, int _tam);
int estadia_buscarEspacio(eEstadia *arrEstadia, int _tam);
int estadia_reservarUna(eEstadia *arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsDuenio, int _tamCharsPerro, int *_id);
void estadia_mostrarUna(eEstadia _est, ePerro *_arrPerro, int _tamPerro, int _tamChars);
int estadia_subMenuModificarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsPerro);
int estadia_buscarDesdeId(eEstadia *_arrEstadia, int _tam, int _id);
int perro_obtenerId(ePerro *_arrPerro, int _tamPerro);
int perro_obtenerCantidad(ePerro *_arrPerro, int _tamPerro);
int perro_obtenerNombre(ePerro *_arrPerro, int _tamPerro, int idPerro, char *_nombrePerro);
eFecha pedirFecha(char *_msj);

#endif /* FUNCIONES_H_ */
