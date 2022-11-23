/*
 ============================================================================
 Name        : prueba-segundo-parcial-computadoras.c
 Author      : Marecos Leandro
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "participante.h"
#include "controler.h"
#include "UTN.h"

int main(void) {
	setbuf(stdout, NULL);

	char archivo[100];
	char auxArchivo[100] = "src/";
	int opcion = 0, opcionFilter = 0;

	LinkedList* listaParticipantes = ll_newLinkedList();
	LinkedList* listaFilter = NULL;

	do
	{
		opcion = menuGenericoInt("\n╔═══════════════════════════════════════╗\n"
								   "║     »»»»» MENU DE OPCIONES «««««      ║\n"
								   "╠═══════════════════════════════════════╣\n"
								   "╠═»»» 1.  CARGA DE ARCHIVO              ║\n"
								   "╠═»»» 2.  ORDENAR LA LISTA              ║\n"
								   "╠═»»» 3.  IMPRIMIR DATOS                ║\n"
								   "╠═»»» 4.  FILTRAR POR DIFICULTAD        ║\n"
								   "╠═»»» 5.  GENERAR FILTRADO.CSV          ║\n"
								   "╠═»»» 6.  SALIR                         ║\n"
								   "╚═══════════════════════════════════════╝\n");

		switch(opcion)
		{
		case 1:
			utn_getString(archivo, "ingrese el nombre del archivo [datos.csv]: ", "Hubo un Error, vuelva a ingresar el nombre del archivo [datos.csv]: ");
			strcat(auxArchivo, archivo);

			if(controller_cargarParticipantesDesdeTexto(auxArchivo, listaParticipantes)==0)
			{
				printf("\nSe cargo correctamente\n");
			}
			else
			{
				printf("\nNo se pudo cargar el archivo...\n");
			}
		break;
		case 2:
			if(ll_isEmpty(listaParticipantes) == 0)
			{
				if(ll_sort(listaParticipantes, part_sortByName, 0) == 0)
				{
					printf("\nSe ordeno por nombre de manera descendente\n");
				}
				else
				{
					printf("\nNo se pudo ordenar las computadoras\n");
				}
			}
			else
			{
				printf("\nNo hay participantes cargadas en la lista\n");
			}
		break;
		case 3:
			if(ll_isEmpty(listaParticipantes) == 0)
			{
				if(controller_listarParticipantes(listaParticipantes)==0)
				{
					printf("\nParticipantes listados correctamente\n");
				}
				else
				{
					printf("\nHubo un error, no se pudo listar\n");
				}
			}
			else
			{
				printf("\nNo hay participantes cargadas en la lista\n");
			}
		break;
		case 4:
			if(ll_isEmpty(listaParticipantes) == 0)
			{
				utn_getInt(&opcionFilter, "\nIngrese el nivel de dificultad [1. FACIL] - [2. NORMAL] - [3. DIFICIL]: ", "Hubo un error, vuelva a intentar ", 1, 3, 3);
				switch(opcionFilter)
				{
					case 1:
						listaFilter = ll_filter(listaParticipantes, part_filterDificultadUno);
					break;
					case 2:
						listaFilter = ll_filter(listaParticipantes, part_filterDificultadDos);
					break;
					case 3:
						listaFilter = ll_filter(listaParticipantes, part_filterDificultadTres);
					break;
				}
			}
			else
			{
				printf("\nNo hay Participantes cargadas en la lista\n");
			}
		break;
		case 5:
			if(ll_isEmpty(listaParticipantes)==0)
			{
				if(controller_guardarComoTexto("src/filtrado.csv", listaFilter)==0)
				{
					printf("\nArchivo filtrado.csv Guardado correctamente\n");
				}
				else
				{
					printf("\nNo se pudo Guardar el Archivo filtrado.csv\n");
				}
			}
		break;
		case 6:
			printf("\nHas salido\n");
		break;
		default:
			printf("\nOpcion incorrecta\n");
		break;
		}

	}while(opcion != 6);

	ll_deleteLinkedList(listaParticipantes);

	return 0;
}
