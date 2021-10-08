/*
 ============================================================================
 Name        : labprog_parcial1.c
 Author      : franc
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMESTADIA 1000
#define TAMPERRO 200

int main(void) {
	setbuf(stdout, NULL);

	eEstadia arrEstadia[TAMESTADIA];
	ePerro arrPerro[TAMPERRO]={
			{7000, "Lobo", "Sharpei", 2, 1},
			{7001, "Sheila", "Golden", 12, 1},
			{7002, "Reina", "Galgo", 13, 1}
	};

	int opcion;
	int ultimoIdIngresado=10000;
	int cantidadEstadias=0;

	estadia_inicializarArray(arrEstadia, TAMESTADIA);

	do{
		printLine("GUARDERIA DE PERRITOS");
		opcion=getInt("1. RESERVAR ESTADIA\n"
					  "2. MODIFICAR ESTADIA\n"
					  "3. CANCELAR ESTADIA\n"
					  "4. LISTAR ESTADIAS\n"
					  "5. LISTAR PERROS\n"
					  "6. SALIR\n"
					  "----------------------------\n"
					  "Ingrese una opcion (1-6): ",
					  "1. RESERVAR ESTADIA\n"
					  "2. MODIFICAR ESTADIA\n"
					  "3. CANCELAR ESTADIA\n"
					  "4. LISTAR ESTADIAS\n"
					  "5. LISTAR PERROS\n"
					  "6. SALIR\n"
					  "----------------------------\n"
				      "Opcion invalida, reingrese (1-6): ", 1, 6);
		switch(opcion)
		{
			case 1:
				if(estadia_reservarUna(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, TAMNOMBRE, TAMNOMBREPERRO, &ultimoIdIngresado)==0)
				{
					cantidadEstadias++;
				}
				system("pause");
			break;
			case 2:
				if(cantidadEstadias>0)
				{
					if(estadia_subMenuModificarUna(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, TAMNOMBREPERRO)==-1)
					{
						printf("\nNo se pudo modificar la estadía...\n");
					}
				}
				else
				{
					printf("\nNo hay estadías para modificar...\n");
				}
				system("pause");
			break;
			case 6:
				printLine("SALIENDO DEL PROGRAMA");
				printf("         ||_/|\n"
					   "	 | @ @   Woof! Vuelva pronto...\n"
					   "	 |   <>              _\n"
					   "	 |  _/| -----____ ((| |))\n"
					   "	 |               `--' |\n"
					   "     ____|_       ___|   |___.'\n"
					   "    /_/_____/____/_______| \n");
			break;
		}
	}while(opcion!=6);

	return EXIT_SUCCESS;
}
