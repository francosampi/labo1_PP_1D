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
 * @brief se pide al usuario el alta de una estadia pidiendo nombre de duenio, telefono de contacto, id del perro, fecha...
 *
 * @param _arrEstadia
 * @param _tam
 * @param _arrPerro
 * @param _tamPerro
 * @param _tamCharsDuenio
 * @param _tamCharsPerro
 * @param _id
 * @return
 */
int estadia_reservarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsDuenio, int _tamCharsPerro, int *_id);
void estadia_mostrarUna(eEstadia _est, ePerro *_arrPerro, int _tamPerro, int _tamChars);
void estadia_mostrarTodas(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamChars);
int estadia_subMenuModificarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsPerro);
int estadia_cancelarUna(eEstadia *_arrEstadia, int _tam, ePerro *_arrPerro, int _tamPerro, int _tamCharsPerro);

#endif /* NEXO_H_ */
