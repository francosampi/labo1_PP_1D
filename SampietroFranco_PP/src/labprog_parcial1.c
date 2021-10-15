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
#define TAMDUENIO 50

int main(void) {
	setbuf(stdout, NULL);

	eEstadia arrEstadia[TAMESTADIA];
	ePerro arrPerro[TAMPERRO]={
			{7000, "Lobo", "Sharpei", 2, 0, 1},
			{7001, "Sheila", "Golden", 12, 0, 1},
			{7002, "Reina", "Galgo", 13, 0, 1}
	};
	eDuenio arrDuenio[TAMDUENIO]={
			{30000, "AA", 1140429405, 1},
			{30001, "BB", 1520203253, 1},
			{30002, "CC", 1185420352, 1}
	};

	int opcion;
	int ultimoIdEstadia=10000;
	int cantidadEstadias=0;

	estadia_inicializarArray(arrEstadia, TAMESTADIA);
	perro_inicializarArray(arrPerro, TAMPERRO);
	duenio_inicializarArray(arrDuenio, TAMDUENIO);

	do{
		printLine("GUARDERIA");
		opcion=getInt("1. RESERVAR ESTADIA\n"
					  "2. MODIFICAR ESTADIA\n"
					  "3. CANCELAR ESTADIA\n"
					  "4. LISTAR ESTADIAS\n"
					  "5. LISTAR PERROS\n"
					  "6. PROMEDIO DE EDAD DE PERROS\n"
					  "7. PERRO CON MAS ESTADIAS\n"
					  "8. PERRO CON SUS ESTADIAS DIARIAS\n"
					  "9. SALIR\n"
					  "----------------------------\n"
					  "Ingrese una opcion (1-9): ",
					  "1. RESERVAR ESTADIA\n"
					  "2. MODIFICAR ESTADIA\n"
					  "3. CANCELAR ESTADIA\n"
					  "4. LISTAR ESTADIAS\n"
					  "5. LISTAR PERROS\n"
					  "6. PROMEDIO DE EDAD DE PERROS\n"
					  "7. PERRO CON MAS ESTADIAS\n"
					  "8. PERRO CON SUS ESTADIAS DIARIAS\n"
					  "9. SALIR\n"
					  "----------------------------\n"
				      "Opcion invalida, reingrese (1-9): ", 1, 9);
		switch(opcion)
		{
			case 1:
				if (estadia_reservarUna(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, arrDuenio, TAMDUENIO, TAMNOMBREPERRO, TAMNOMBREDUENIO, &ultimoIdEstadia)==0)
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
				if (cantidadEstadias>0)
				{
					estadia_mostrarTodas(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, arrDuenio, TAMDUENIO, TAMNOMBREPERRO, TAMNOMBREDUENIO);
					estadia_subMenuModificarUna(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, arrDuenio, TAMDUENIO, TAMNOMBREPERRO, TAMNOMBREDUENIO);
				}
				else
				{
					printf("\nNo hay estadías para modificar...\n");
				}
				system("pause");
			break;
			case 3:
				if (cantidadEstadias>0)
				{
					estadia_mostrarTodas(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, arrDuenio, TAMDUENIO, TAMNOMBREPERRO, TAMNOMBREDUENIO);
					if (estadia_cancelarUna(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, arrDuenio, TAMDUENIO, TAMNOMBREPERRO, TAMNOMBREDUENIO)==0)
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
				if (cantidadEstadias>0)
				{
					estadia_ordenarTodas(arrEstadia, TAMESTADIA, arrDuenio, TAMPERRO, TAMNOMBREDUENIO);
					estadia_mostrarTodas(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, arrDuenio, TAMDUENIO, TAMNOMBREPERRO, TAMNOMBREDUENIO);
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
				if (cantidadEstadias>0)
				{
					if(perro_obtenerCantidad(arrPerro, TAMPERRO)>0)
					{
						perro_masEstadias(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO);
					}
					else
					{
						printf("\nNo hay perritos para listar...\n");
					}
				}
				else
				{
					printf("\nNo hay estadías para listar...\n");
				}
				system("pause");
			break;
			case 8:
				if (cantidadEstadias>0)
				{
					if(perro_obtenerCantidad(arrPerro, TAMPERRO)>0)
					{
						perro_conSusEstadias(arrEstadia, TAMESTADIA, arrPerro, TAMPERRO, arrDuenio, TAMDUENIO, TAMNOMBREPERRO, TAMNOMBREDUENIO);
					}
					else
					{
						printf("\nNo hay perritos para listar...\n");
					}
				}
				else
				{
					printf("\nNo hay estadías para listar...\n");
				}
				system("pause");
			break;
			case 9:
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
	}while(opcion!=9);

	return EXIT_SUCCESS;
}
