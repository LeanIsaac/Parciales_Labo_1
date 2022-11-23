#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "UTN.h"

int main(){
	setbuf(stdout,NULL);

	int option = 0;
	int flag = 0;
	int flagBin = 0;
	int flagText = 0;

	LinkedList* listaJugadores = ll_newLinkedList();
	LinkedList* listaSeleccion = ll_newLinkedList();
	LinkedList* listaJugadoresConvocados = ll_newLinkedList();

    do{
        menuPrincipal();
        utn_getInt(&option, "Ingrese una Opcion >>> ", "Error, ", 1, 11, 3);

    	switch(option)
        {
            case 1://CARGA
            	if(flag == 0)
            	{
					if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)==0 &&
					   controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSeleccion)==0)
					{
						flag=1;
						printf("\nSe cargaron los datos desde jugadores.csv y seleccion.csv  ✔\n\n");
					}
            	}
            	break;
            case 2://ALTA
            	if(controller_agregarJugador(listaJugadores)==0)
            	{
            		printf("\nSe dio de alta un jugador  ✔\n\n");
            	}
            	break;
            case 3://MODIFICACION
            	if(ll_isEmpty(listaJugadores) == 0)
            	{
					if(controller_editarJugador(listaJugadores)==0)
					{
						printf("\nSe Modifico un Jugador Con Exito ✔\n");
					}
            	}
            	else
            	{
					printf("\n\nPrimero debe cargar las listas de jugadores y selecciones\n\n");
				}
            	break;
            case 4://BAJA
            	if(ll_isEmpty(listaJugadores) == 0)
            	{
					if(controller_removerJugador(listaJugadores, listaSeleccion)==0)
					{
						printf("\nSe dio de baja con exito  ✔\n");
					}
            	}
            	else
            	{
					printf("\n\nPrimero debe cargar las listas de jugadores y selecciones\n\n");
				}
            	break;
            case 5://LISTAR
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSeleccion) == 0)
            	{
					controller_listar(listaSeleccion, listaJugadores);
            	}
            	else
            	{
            		printf("\n\nPrimero debe cargar las listas de jugadores y selecciones\n\n");
            	}
            	break;
            case 6:
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSeleccion) == 0)
            	{
            		controller_convocarYQuitarJugadores(listaJugadores, listaSeleccion);
            	}
            	else
            	{
            		printf("\n\nPrimero debe cargar las listas de jugadores y selecciones\n\n");
            	}
            	break;
            case 7:	//ORDENAR Y LISTAR
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSeleccion) == 0)
            	{
            		controller_ordenarYListar(listaJugadores, listaSeleccion);
            	}
            	else
            	{
            		printf("\n\nPrimero debe cargar las listas de jugadores y selecciones\n\n");
            	}
            	break;
            case 8:
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSeleccion) == 0)
            	{
					if(controller_generarBinarioDeConvocados("jugadores.dat", listaJugadores, listaSeleccion)==0)
					{
						flagBin = 1;
					}
					else
					{
						printf("\n\n\n\n\n(!) No hay jugadores convocados (!)\n\n\n\n\n");
					}
            	}
            	else
            	{
            		printf("\nPrimero debe cargar las listas de jugadores y selecciones\n\n");
            	}
            	break;
            case 9:
            	if(flagBin == 1)
            	{
            		if(controller_cargarJugadoresDesdeBinario("jugadores.dat", listaJugadoresConvocados)==0)
            		{
            			controller_listarJugadores(listaJugadoresConvocados);
            			printf("\nJugadores.dat se cargo correctamente  ✔\n\n");
            		}
            		else
            		{
            			printf("\nError, jugadores.dat no se pudo cargar\n\n");
            		}
            	}
            	else{
            		printf("\nPrimero debe generar y guardar el archivo.bin\n\n");
            	}
            	break;
            case 10://GUARDAR JUGADORES MODO TEXTO
            	if(flag == 1)
            	{
					if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores)==0 &&
					   controller_guardarSeleccionesModoTexto("selecciones.csv", listaSeleccion)==0)
					{
						printf("\nLa lista de jugadores y selecciones se guardo correctamente...  ✔\n");
						flagText = 1;
					}
            	}
            	else
            	{
            		printf("\n\nNo se cargaron los datos de jugadores.csv y seleccion.csv  ✔\n\n");
            	}
            	break;
            case 11:
            	if(flagText == 1 || flagBin == 1)
            	{
            		printf("\n\nSaliendo...\n\nAdios!!\n\n");
            	}
            	else
            	{
            		printf("\n\n(!) Antes guarde la lista de jugadores.csv y selecciones.dat... Redirigiendo al Menu principal\n\n");
            	}
            	break;
            default:
            	printf("\n\n(!) ERROR... OPCION NO VALIDA (!)\n\n");
            	break;
        }
    }while(option != 11 || flagText != 1 || flagBin != 1);

    ll_deleteLinkedList(listaJugadores);
    ll_deleteLinkedList(listaSeleccion);
    ll_deleteLinkedList(listaJugadoresConvocados);

    return 0;
}
