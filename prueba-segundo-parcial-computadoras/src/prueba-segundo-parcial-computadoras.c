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
#include "computadoras.h"
#include "controler.h"
#include "UTN.h"

int main(void) {
	setbuf(stdout, NULL);

	char archivo[100];
	char auxArchivo[100] = "src/";
	int opcion = 0;

	LinkedList* listaComputadoras = ll_newLinkedList();

	do
	{
		opcion = menuGenericoInt("\n╔═══════════════════════════════════════╗\n"
								   "║     »»»»» MENU DE OPCIONES «««««      ║\n"
								   "╠═══════════════════════════════════════╣\n"
								   "╠═»»» 1.  CARGA DE ARCHIVO              ║\n"
								   "╠═»»» 2.  ORDENAR LA LISTA              ║\n"
								   "╠═»»» 3.  IMPRIMIR DATOS                ║\n"
								   "╠═»»» 4.  MAPEO PRECIO POR CUOTAS       ║\n"
								   "╠═»»» 5.  GUARDAR MAPEO EN ARCHIVO.CSV  ║\n"
								   "╠═»»» 6.  SALIR                         ║\n"
								   "╚═══════════════════════════════════════╝\n");

		switch(opcion)
		{
		case 1:
			utn_getString(archivo, "ingrese el nombre del archivo [datos.csv]: ", "Hubo un Error, vuelva a ingresar el nombre del archivo [datos.csv]: ");
			strcat(auxArchivo, archivo);

			if(controller_cargarJugadoresDesdeTexto(auxArchivo, listaComputadoras)==0)
			{
				printf("\nSe cargo correctamente\n");
			}
			else
			{
				printf("\nNo se pudo cargar el archivo...\n");
			}
		break;
		case 2:
			if(ll_isEmpty(listaComputadoras) == 0)
			{
				if(ll_sort(listaComputadoras, compu_sortByCuotas, 1) == 0)
				{
					printf("\nSe ordeno correctamente las CUOTAS de manera descendente\n");
				}
				else
				{
					printf("\nNo se pudo ordenar las computadoras\n");
				}
			}
			else
			{
				printf("\nNo hay computadoras cargadas en la lista\n");
			}
		break;
		case 3:
			if(ll_isEmpty(listaComputadoras) == 0)
			{
				if(controller_listarComputadoras(listaComputadoras)==0)
				{
					printf("\nComputadoras listadas\n");
				}
				else
				{
					printf("\nHubo un error, no se pudo listar\n");
				}
			}
			else
			{
				printf("\nNo hay computadoras  cargadas en la lista\n");
			}
		break;
		case 4:
			if(ll_isEmpty(listaComputadoras) == 0)
			{
				if(ll_map(listaComputadoras, compu_precioPorCuotas)==0)
				{
					printf("\nMapeado Listo\n");
				}
				else
				{
					printf("\nHubo un fallo, no se mapeo\n");
				}
			}
			else
			{
				printf("\nNo hay computadoras  cargadas en la lista\n");
			}
		break;
		case 5:
			if(ll_isEmpty(listaComputadoras)==0)
			{
				if(controller_guardarComoTexto("src/mapeado.csv", listaComputadoras)==0)
				{
					printf("\nArchivo mapeado.csv Guardado correctamente\n");
				}
				else
				{
					printf("\nNo se pudo Guardar el Archivo mapeado.csv\n");
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

	ll_deleteLinkedList(listaComputadoras);

	return 0;
}
