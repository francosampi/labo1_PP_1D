/*
 * nexo.h
 *
 *  Created on: 10 oct. 2021
 *      Author: franc
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "estadia.h"
#include "perro.h"
#include "inputs.h"

/**
 * @fn int estadia_reservarUna(eEstadia*, int, ePerro*, int, int, int, int*)
 * @brief se pide al usuario el alta de una estadia pidiendo nombre de duenio, telefono de contacto, id del perro, fecha... esto incrementará el ultimo id ingresado
 *
 * @param _arrEstadia arreglo de estadias
 * @param _tam tamanio del arreglo de estadias
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 * @param _tamCharsDuenio tamanio del arreglo de chars para el nombre del duenio
 * @param _tamCharsPerro tamanio del arreglo de chars para el nombre del perro
 * @param _id puntero al ultimo id ingresado
 * @return -1 si hubo error (el arreglo es NULL o no confirma los cambios) o 0 si no hubo errores
 */
int estadia_reservarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsDuenio, int _tamCharsPerro, int *_id);

/**
 * @fn void estadia_mostrarUna(eEstadia, ePerro*, int, int)
 * @brief toma los datos de una estadia y la muestra por consola
 *
 * @param _est la estructura de la estadia
 * @param _arrPerro el arreglo de perros para poder vincularlo con la estadia
 * @param _tamPerro el tamanio del arreglo de perros
 * @param _tamChars el tamanio del arreglo de chars para el nombre del duenio
 */
void estadia_mostrarUna(eEstadia _est, ePerro *_arrPerro, int _tamPerro, int _tamChars);

/**
 * @fn void estadia_mostrarTodas(eEstadia*, int, ePerro*, int, int)
 * @brief muestra todas las estadias del arreglo que tengan el estado 1 (dadas de alta)
 *
 * @param _arrEstadia arreglo de estadias
 * @param _tam tamanio del arreglo de estadias
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 * @param _tamCharsDuenio tamanio del arreglo de chars para el nombre del duenio
 */
void estadia_mostrarTodas(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsDuenio);

/**
 * @fn int estadia_subMenuModificarUna(eEstadia*, int, ePerro*, int, int)
 * @brief accede a un menu para que el usuario pueda modificar el contacto o el perro del usuario
 *
 * @param _arrEstadia arreglo de estadias
 * @param _tam tamanio del arreglo de estadias
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 * @param _tamCharsPerro tamanio del arreglo de chars para el nombre del perro
 * @return -1 si hubo error (el arreglo es NULL/ no confirma los cambios/ no hay estadias para modificar) o 0 si no hubo errores
 */
int estadia_subMenuModificarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsPerro);

/**
 * @fn int estadia_cancelarUna(eEstadia*, int, ePerro*, int, int)
 * @brief pide al usuario el ingreso de un ID y le da una baja logica a la estadia asociada a el
 *
 * @param _arrEstadia arreglo de estadias
 * @param _tam tamanio del arreglo de estadias
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 * @param _tamCharsPerro tamanio del arreglo de chars para el nombre del perro
 * @return -1 si hubo error (el arreglo es NULL/ no confirma los cambios/ no hay estadias para cancelar) o 0 si no hubo errores
 */
int estadia_cancelarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsPerro);

#endif /* NEXO_H_ */
