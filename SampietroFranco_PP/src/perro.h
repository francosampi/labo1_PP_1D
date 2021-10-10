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

int perro_obtenerId(ePerro *_arrPerro, int _tamPerro);
int perro_obtenerCantidad(ePerro *_arrPerro, int _tamPerro);
int perro_obtenerNombre(ePerro *_arrPerro, int _tamPerro, int idPerro, char *_nombrePerro);
void perro_mostrarTodos(ePerro *_arrPerro, int _tamPerro);
int perro_promedioEdad(ePerro *_arrPerro, int _tamPerro);

#endif /* PERRO_H_ */
