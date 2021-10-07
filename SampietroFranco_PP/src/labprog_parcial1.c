/*
 ============================================================================
 Name        : labprog_parcial1.c
 Author      : Sampietro Franco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define TAMESTADIA 1000
#define TAMPERRO 200

int main(void) {
	setbuf(stdout, NULL);

	int opcion;

	eEstadia arrEstadia[TAMESTADIA];
	ePerro arrPerro[TAMPERRO]={
			{7000, "Lobo", "Sharpei", 2},
			{7001, "Sheila", "Golden", 12},
			{7002, "Reina", "Galgo", 13}
	};

	return EXIT_SUCCESS;
}
