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
#include "nexo.h"

#define TAMESTADIA 50
#define TAMPERRO 50

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
	perro_inicializarArray(arrPerro, TAMPERRO);

	do{
		printLine("GUARDERIA DE PERRITOS");
		opcion=getInt("1. RESERVAR ESTADIA\n"
					  "2. MODIFICAR ESTADIA\n"
					  "3. CANCELAR ESTADIA\n"
					  "4. LISTAR ESTADIAS\n"
					  "5. LISTAR PERROS\n"
					  "6. PROMEDIO DE EDAD DE PERROS\n"
					  "7. SALIR\n"
					  "----------------------------\n"
					  "Ingrese una opcion (1-7): ",
					  "1. RESERVAR ESTADIA\n"
					  "2. MODIFICAR ESTADIA\n"
					  "3. CANCELAR ESTADIA\n"
					  "4. LISTAR ESTADIAS\n"
					  "5. LISTAR PERROS\n"
					  "6. PROMEDIO DE EDAD DE PERROS\n"
					  "7. SALIR\n"
					  "----------------------------\n"
				      "Opcion invalida, reingrese (1-7): ", 1, 7);
		switch(opcion)
		{
			case 1:
				if(estadia_reservarUna(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, TAMNOMBRE, TAMNOMBREPERRO, &ultimoIdIngresado)==0)
				{
					cantidadEstadias++;
				}
				else
				{
					printf("\nNo es posible cargar más estadías...\n");
				}
				system("pause");
			break;
			case 2:
				if(cantidadEstadias>0)
				{
					estadia_subMenuModificarUna(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, TAMNOMBREPERRO);
				}
				else
				{
					printf("\nNo hay estadías para modificar...\n");
				}
				system("pause");
			break;
			case 3:
				if(cantidadEstadias>0)
				{
					if (estadia_cancelarUna(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, TAMNOMBREPERRO)==0)
					{
						cantidadEstadias--;
					}
				}
				else
				{
					printf("\nNo hay estadías para cancelar...\n");
				}
				system("pause");
			break;
			case 4:
				if(cantidadEstadias>0)
				{
					estadia_ordenarTodas(arrEstadia, TAMESTADIA, TAMNOMBRE);
					estadia_mostrarTodas(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, TAMNOMBREPERRO);
				}
				else
				{
					printf("\nNo hay estadías para listar...\n");
				}
				system("pause");
			break;
			case 5:
				if (perro_obtenerCantidad(arrPerro, TAMPERRO)>0)
				{
					perro_mostrarTodos(arrPerro, TAMPERRO);
				}
				else
				{
					printf("\nNo hay perritos para listar...\n");
				}
				system("pause");
			break;
			case 6:
				perro_promedioEdad(arrPerro, TAMPERRO);
				system("pause");
			break;
			case 7:
				if(verify("Seguro que desea salir? Ingrese 's': ")==0)
				{
					printLine("SALIENDO DEL PROGRAMA");
					printf("         ||_/|\n""	 | @ @   Woof! Vuelva pronto...\n""	 |   <>              _\n""	 |  _/| -----____ ((| |))\n"
							"	 |               `--' |\n""     ____|_       ___|   |___.'\n""    /_/_____/____/_______| \n\n");
				}
				else
				{
					opcion=0;
				}
			break;
		}
	}while(opcion!=7);

	return EXIT_SUCCESS;
}
