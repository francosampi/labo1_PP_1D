/*
 * funciones.h
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */

#ifndef ESTADIA_H_
#define ESTADIA_H_

#define TAMNOMBRE 21

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
int estadia_buscarDesdeId(eEstadia *_arrEstadia, int _tam, int _id);
int estadia_ordenarTodas(eEstadia *_arrEstadia, int _tam, int _tamChars);
eFecha pedirFecha(char *_msj);

#endif /* ESTADIA_H_ */
