/*
 * funciones.h
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */

#ifndef ESTADIA_H_
#define ESTADIA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	int idPerro;
	int idDuenio;
	eFecha fecha;
	int estado; //0-Vacio, 1-Ocupado
}eEstadia;

/**
 * @fn void estadia_inicializarArray(eEstadia*, int)
 * @brief pone en estado 0 (libre) todos los elemntos del arreglo de estadias
 *
 * @param _arrEstadia arreglo de estadia
 * @param _tam tamanio del arreglo de estadia
 */
void estadia_inicializarArray(eEstadia *_arrEstadia, int _tam);

/**
 * @fn int estadia_buscarEspacio(eEstadia*, int)
 * @brief busca espacio libre en el arreglo y devuelve el index
 *
 * @param _arrEstadia arreglo de estadia
 * @param _tam tamanio del arreglo de estadia
 * @return -1 si hubo error (no hay espacio o el arreglo es NULL) o 0 si no hubo errores
 */
int estadia_buscarEspacio(eEstadia *_arrEstadia, int _tam);

/**
 * @fn int estadia_buscarDesdeId(eEstadia*, int, int)
 * @brief se pasa el ID y encuentra el index en el que se encuentra la estadia
 *
 * @param _arrEstadia arreglo de estadia
 * @param _tam tamanio del arreglo de estadia
 * @param _id el ID pasado por parametro
 * @return el index encontrado o -1 si hubo error (no se encontro el index)
 */
int estadia_buscarDesdeId(eEstadia *_arrEstadia, int _tam, int _id);

/**
 * @fn void estadia_swapear(eEstadia*, eEstadia*)
 * @brief intercambia los datos de una estadia por otra sin pisar los datos
 *
 * @param _est1 primer estadia
 * @param _est2 segunda estadia
 */
void estadia_swapear(eEstadia *_est1, eEstadia *_est2);

/**^
 * @fn eFecha pedirFecha(char*)
 * @brief le pide al usuario que ingrese la fecha (dia, mes anio) y la devuelve como estructura de tipo fecha
 *
 * @param _msj mensaje que aparece arriba del ingreso de datos
 * @return la estructura fecha
 */
eFecha pedirFecha(char *_msj);

#endif /* ESTADIA_H_ */
