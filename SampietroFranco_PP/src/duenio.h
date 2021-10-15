/*
 * duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: franc
 */

#ifndef DUENIO_H_
#define DUENIO_H_

#define TAMNOMBREDUENIO 41

typedef struct
{
	int id;
	char nombre[TAMNOMBREDUENIO];
	int telefonoContacto;
	int estado; //0-Vacio, 1-Ocupado
}eDuenio;

void duenio_inicializarArray(eDuenio *_arrDuenio, int _tamDuenio);
int duenio_obtenerIdDesdeLista(eDuenio *_arrDuenio, int _tamDuenio);
int duenio_buscarDesdeId(eDuenio *_arrDuenio, int _tamDuenio, int _id);
int duenio_obtenerNombre(eDuenio *_arrDuenio, int _tamDuenio, int _idDuenio, char *_nombreDuenio);
int duenio_obtenerTelefono(eDuenio *_arrDuenio, int _tamDuenio, int _idDuenio, int *_telDuenio);
void duenio_mostrarUno(eDuenio _duenio);
void duenio_mostrarTodos(eDuenio *_arrDuenio, int _tamDuenio);

#endif /* DUENIO_H_ */
