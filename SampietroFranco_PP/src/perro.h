/*
 * perro.h
 *
 *  Created on: 10 oct. 2021
 *      Author: franc
 */

#ifndef PERRO_H_
#define PERRO_H_

#define TAMNOMBREPERRO 21

typedef struct
{
	int id;
	char nombre[TAMNOMBREPERRO];
	char raza[TAMNOMBREPERRO];
	int edad;
	int estado; //0-Vacio, 1-Ocupado
}ePerro;

/**
 * @fn int perro_obtenerId(ePerro*, int)
 * @brief muestra los perros del arreglo que tengan estado 1 (existen) y le pide al usuario ingresr el id para poder devolverlo
 *
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 * @return -1 si hubo error (no existe el arreglo) o el ID del perro si no hubo errores
 */
int perro_obtenerId(ePerro *_arrPerro, int _tamPerro);

/**
 * @fn int perro_buscarDesdeId(ePerro*, int, int)
 * @brief toma un id por parametro y busca si existe un perro disponible con esa id y devuelve el index
 *
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 * @param _id el id del perro
 * @return  -1 si hubo error (no se encuentra o el arreglo es NULL) o el index si no hubo errores
 */
int perro_buscarDesdeId(ePerro *_arrPerro, int _tamPerro, int _id);

/**
 * @fn int perro_obtenerCantidad(ePerro*, int)
 * @brief calcula y devuelve la cantidad de perritos disponibles en el arreglo
 *
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 * @return cantidad de perros
 */
int perro_obtenerCantidad(ePerro *_arrPerro, int _tamPerro);

/**
 * @fn int perro_obtenerNombre(ePerro*, int, int, char*)
 * @brief se obtiene el nombre de un perro a traves del ID de su estructura
 *
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 * @param _idPerro id pasado por parametro
 * @param _nombrePerro puntero al arreglo donde se guardara el nombre del perro encontrado
 * @return -1 si hubo error (no se encuentra o el arreglo es NULL) o 0 si no hubo errores
 */
int perro_obtenerNombre(ePerro *_arrPerro, int _tamPerro, int _idPerro, char *_nombrePerro);

/**
 * @fn void perro_mostrarTodos(ePerro*, int)
 * @brief recorre el arreglo de perros y muestra por consola cada nombre con su raza
 *
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 */
void perro_mostrarTodos(ePerro *_arrPerro, int _tamPerro);

/**
 * @fn int perro_promedioEdad(ePerro*, int)
 * @brief calcula el promedio de la edad de los perros disponibles del arreglo de perros y lo muestra por consola
 *
 * @param _arrPerro arreglo de perros
 * @param _tamPerro tamanio del arreglo de perros
 * @return -1 si hubo error (si el arreglo es NULL) o 0 si no hubo errores
 */
int perro_promedioEdad(ePerro *_arrPerro, int _tamPerro);

#endif /* PERRO_H_ */
