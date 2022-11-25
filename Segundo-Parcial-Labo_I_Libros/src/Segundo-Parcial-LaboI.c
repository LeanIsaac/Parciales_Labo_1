/*
 ============================================================================
 Name        : prueba-segundo-parcial-computadoras.c
 Author      : Marecos Leandro
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "libros.h"
#include "controler.h"
#include "parser.h"
#include "UTN.h"

int main(void) {
	setbuf(stdout, NULL);

	char archivo[100];
	char auxArchivo[100] = "src/";
	int opcion = 0;
	int flag=-1;
	LinkedList* listaLibros = ll_newLinkedList();


	do
	{
		opcion = menuGenericoInt("\n╔═══════════════════════════════════════╗\n"
								   "║     »»»»» MENU DE OPCIONES «««««      ║\n"
								   "╠═══════════════════════════════════════╣\n"
								   "╠═»»» 1.  CARGA DE ARCHIVO              ║\n"
								   "╠═»»» 2.  ORDENAR LA LISTA              ║\n"
								   "╠═»»» 3.  IMPRIMIR DATOS                ║\n"
								   "╠═»»» 4.  GENERAR ARCHIVO ORDENADO.CSV  ║\n"
								   "╠═»»» 5.  MAPEO PRECIO POR IMPORTE      ║\n"
								   "╠═»»» 6.  GUARDAR MAPEO EN ARCHIVO.CSV  ║\n"
								   "╠═»»» 7.  SALIR                         ║\n"
								   "╚═══════════════════════════════════════╝\n");

		switch(opcion)
		{
		case 1:
			utn_getString(archivo, "ingrese el nombre del archivo [datos.csv]: ", "Hubo un Error, vuelva a ingresar el nombre del archivo [datos.csv]: ");
			strcat(auxArchivo, archivo);

			if(controller_cargarLibrosDesdeTexto(auxArchivo, listaLibros)==0)
			{
				printf("\nSe cargo correctamente\n");
			}
			else
			{
				printf("\nNo se pudo cargar el archivo...\n");
			}
		break;
		case 2:
			if(ll_isEmpty(listaLibros) == 0)
			{
				if(ll_sort(listaLibros, libro_sortByImporte, 1) == 0)
				{
					printf("\nSe ordeno correctamente los importe de manera descendente\n");
					flag=0;
				}
				else
				{
					printf("\nNo se pudo ordenar las libros\n");
				}
			}
			else
			{
				printf("\nNo hay libros cargadas en la lista\n");
			}
		break;
		case 3:
			if(ll_isEmpty(listaLibros) == 0)
			{
				if(controller_listarLibros(listaLibros)==0)
				{
					printf("\nLibros listados\n");
				}
				else
				{
					printf("\nHubo un error, no se pudo listar\n");
				}
			}
			else
			{
				printf("\nNo hay libros  cargadas en la lista\n");
			}
		break;
		case 4:
			if(ll_isEmpty(listaLibros) == 0 && flag == 0)
			{
				if(controller_guardarComoTexto("src/ordenado.csv", listaLibros)==0)
				{
					printf("\nArchivo ordenado.csv Generado correctamente\n");
				}
				else
				{
					printf("\nNo se pudo Generar el Archivo ordenado.csv\n");
				}
			}
		break;
		case 5:
			if(ll_isEmpty(listaLibros) == 0)
			{
				if(ll_map(listaLibros, libro_aumentoImporte)==0)
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
				printf("\nNo hay libros  cargadas en la lista\n");
			}
		break;
		case 6:
			if(ll_isEmpty(listaLibros)==0)
			{
				if(controller_guardarComoTextoMapeado("src/mapeado.csv", listaLibros)==0)
				{
					printf("\nArchivo mapeado.csv Guardado correctamente\n");
				}
				else
				{
					printf("\nNo se pudo Guardar el Archivo mapeado.csv\n");
				}
			}
		break;
		case 7:
			printf("\nHas salido\n");
		break;
		default:
			printf("\nOpcion incorrecta\n");
		break;
		}

	}while(opcion != 7);

	ll_deleteLinkedList(listaLibros);

	return 0;
}
