#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "UTN.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int rto=-1;
	if(path != NULL && pArrayListJugador != NULL)
	{
		FILE* pFile = fopen(path, "r");
		if(pFile != NULL){
			if( parser_JugadorFromText(pFile, pArrayListJugador) ==0 ){
				rto=0;
			}
			fclose(pFile);
		}
	}
    return rto;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int rto=-1;
	if(path != NULL && pArrayListJugador != NULL)
	{
		FILE* pFile = fopen(path, "rb");
		if(pFile != NULL){
			if( parser_JugadorFromBinary(pFile, pArrayListJugador) ==0 ){

				rto=0;
			}
			fclose(pFile);
		}
	}
	return rto;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int rto= -1;

	if(pArrayListJugador != NULL) {
		if(jug_alta(pArrayListJugador)==0){
			rto=0;
		}
	}

    return rto;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int rto= -1;

	if(pArrayListJugador != NULL) {
		jug_modificar(pArrayListJugador);
		rto=0;
	}

	return rto;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rto=-1;

	if(pArrayListJugador != NULL)
	{
		jug_baja(pArrayListJugador, pArrayListSeleccion);
		rto=0;
	}

    return rto;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	Jugador* unJugador;
	int cant, rto=-1;

	if(pArrayListJugador != NULL)
	{
		cant = ll_len(pArrayListJugador);
		printf("\n════════════════════════════════════════════════════════════════════════════════════════════\n");
		printf(" ID  Nombre\t\t\tEdad\tPosicion\t\tNacionalidad\tIdSeleccion");
		printf("\n════════════════════════════════════════════════════════════════════════════════════════════\n\n");
		for(int i=0; i<cant; i++)
		{
			unJugador = (Jugador*)ll_get(pArrayListJugador, i);
			jug_printOne(unJugador);
			rto = 0;
		}
	}

    return rto;
}


/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			if(parser_guardarJugadorModoTexto(pFile, pArrayListJugador)==0){
				retorno =0;
			}

			fclose(pFile);
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int rto=-1;
	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			parser_guardarJugadoresModoBinario(pFile, pArrayListJugador);
			fclose(pFile);
		}
		rto=0;
	}

    return rto;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int rto=-1;
	if(path != NULL && pArrayListSeleccion != NULL)
	{
		FILE* pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if( parser_SeleccionFromText(pFile, pArrayListSeleccion) ==0 )
			{
				rto=0;
			}
			fclose(pFile);
		}
	}
    return rto;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	Seleccion* unaSeleccion;
	int cant, rto=-1;

	if(pArrayListSeleccion != NULL)
	{
		cant = ll_len(pArrayListSeleccion);
		printf("\n════════════════════════════════════════════════════\n");
		printf("ID\tPais\t\tConfederacion\t Convocados");
		printf("\n════════════════════════════════════════════════════\n\n");
		for(int i=0; i<cant; i++)
		{
			unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			if(unaSeleccion != NULL)
			{
				selec_printOne(unaSeleccion);
				rto = 0;
			}
		}
	}
    return rto;
}


/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			if(parser_guardarSeleccionModoTexto(pFile, pArrayListSeleccion)==0)
			{
				retorno=0;
			}
			fclose(pFile);
		}
	}
    return retorno;
}


int controller_listar(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int rto=-1,auxConvocados;
	char aux;

	do{
		printf("\n╔══════ MENU ════════\n"
				"╠═»»» A. Jugadores\n"
				"╠═»»» B. Selecciones\n"
				"╠═»»» C. Convocados\n"
				"╠═»»» D. Salir\n"
				"╚════════════════════\n");

		utn_getChar(&aux, "Ingrese una opcion >>> ", "Error, ", 'A', 'z', 2);
		aux = toupper(aux);

		switch(aux)
		{
			case 'A':
				controller_listarJugadores(pArrayListJugador);
				break;
			case 'B':
				controller_listarSelecciones(pArrayListSeleccion);
				break;
			case 'C':
				auxConvocados = controller_filtrarConvocados(pArrayListJugador, pArrayListSeleccion);
				if(auxConvocados == -1)
				{
					printf("\n\nNo hay jugadores Convocados\n\n");
				}
				break;
			case 'D':
				printf("\nSaliendo...\n");
				break;
			default:
				break;
		}
	}while(aux != 'D');

	return rto;
}

/*
 * listo jugadores *
 * pido el ID del jugador a convocar *
 * listo selecciones *
 * pido el id de seleccion a convocar *
 * valido que la selecion no supere los 22 convocados *
 * si convoca, aumento le cont convocados *
 *
 */
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rto=-1;
	int indice;
	int convocados;
	int indiceSelec, idSeleccion;
	int jugIdSeleccion;

	Jugador* auxJugador=NULL;
	Seleccion* auxSeleccion=NULL;

	controller_listarJugadores(pArrayListJugador);//listo jugadores
	indice = jug_buscarPorId(pArrayListJugador); //PIDO ID A CONVOCAR, RETORNO EL INDICE DEL ID

	controller_listarSelecciones(pArrayListSeleccion);
	indiceSelec = selec_buscarPorId(pArrayListSeleccion);//RETORNA EL INDICE DEL ID SELECCIONADO

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		auxJugador = (Jugador*)ll_get(pArrayListJugador, indice); //OBTENGO EL INDICE DEL JUGADOR DEL ID A CONVOCAR
		auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indiceSelec);

		if(auxJugador != NULL && auxSeleccion != NULL)
		{
			if(jug_getSIdSeleccion(auxJugador, &jugIdSeleccion)==0)
			{
				if(jugIdSeleccion != 0)
				{
					printf("\n\n\nEl jugador ya esta Convocado\n\n\n");
				}
				else
				{
					selec_getConvocados(auxSeleccion, &convocados);//OBTENGO EL NUM DE CONVOCADOS DE LA SELECCION
					if(convocados < 22)
					{
						if(selec_getId(auxSeleccion, &idSeleccion)==0) //OBTENGO EL ID DE LA SELECCION GUARDADA/INGRESADA ANTERIORMENTE
						{
							if(jug_setIdSeleccion(auxJugador, idSeleccion)==0) //A LA LISTA DE JUGADORES, SETEO EL ID DE LA SELECCION
							{
								//printf("\nEl id seleccion se cargo a jugador correctamente\n");
								rto=0;
							}
						}
						convocados++;
						selec_setConvocados(auxSeleccion, convocados);
					}
					else
					{
						printf("\nNo es posible convocar a este jugador, la seleccion supero los 22 Jugadores\n");
					}
				}
			}
		}
	}

	return rto;
}


/*
 * listo los jugadores convocados *
 * pido el id del jugador a quitar *
 * el id de jugador IdSeleccion seteo en 0 *
 * tomo con get el contador de convocados de la seleccion *
 * el contador de convocdos lo decremento *
 */
int controller_quitarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rto=-1;
	int indice, i, lenSelec;
	int idSeleccion, auxIdSeleccion, convocados;

	Jugador* unJugador=NULL;
	Seleccion* unaSeleccion=NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		rto=0;
		controller_filtrarConvocados(pArrayListJugador, pArrayListSeleccion);

		indice = jug_buscarPorId(pArrayListJugador);

		unJugador = (Jugador*)ll_get(pArrayListJugador, indice);

		if(unJugador != NULL)
		{
			jug_getSIdSeleccion(unJugador, &auxIdSeleccion);
			jug_setIdSeleccion(unJugador, 0);
		}

		lenSelec = ll_len(pArrayListSeleccion);

		for(i=0; i<lenSelec; i++)
		{
			unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);

			if(unaSeleccion != NULL)
			{
				selec_getId(unaSeleccion, &idSeleccion);

				selec_getConvocados(unaSeleccion, &convocados);

				if(auxIdSeleccion == idSeleccion)
				{
					convocados = convocados - 1;
					selec_setConvocados(unaSeleccion, convocados);
					rto = 0;
					break;
				}
			}
		}
	}

	return rto;
}


int controller_convocarYQuitarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rto = -1;
	char aux;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		rto=0;
		do{
			printf("\n╔═════════════ MENU ════════════\n"
					"╠═»»» A. Convocar\n"
					"╠═»»» B. Quitar de la seleccion\n"
					"╠═»»» C. Salir\n"
					"╚═══════════════════════════════");

			utn_getChar(&aux, "\nIngrese una opcion: ", "Error, ", 'A', 'z', 3);
			aux = toupper(aux);

			switch(aux)
			{
				case 'A':
					if(controller_convocarJugador(pArrayListJugador, pArrayListSeleccion)==0)
					{
						printf("\n\nSe convoco un jugador correctamente  ✔\n\n");
					}
					break;
				case 'B':
					if(controller_quitarConvocados(pArrayListJugador, pArrayListSeleccion)==0)
					{
						printf("\n\nSe quito un jugador correctamente  ✔\n\n");
					}
					break;
				case 'C':
					printf("\nSaliendo...\n");
					break;
				default:
					break;
			}

		}while(aux != 'C');
	}

	return rto;
}



int controller_filtrarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rto=-1;
	int lenJug,lenSelec, i, j;
	int idSeleccion, auxIdSeleccion, convocados;

	Jugador* unJugador=NULL;
	Seleccion* unaSeleccion=NULL;

	lenJug = ll_len(pArrayListJugador);
	lenSelec = ll_len(pArrayListSeleccion);

	if(pArrayListJugador != NULL && lenJug > 0 && lenSelec > 0)
	{
		for(i=0; i<lenJug; i++)
		{
			for(j=0; j<lenSelec; j++)
			{
				unJugador = (Jugador*)ll_get(pArrayListJugador, i);
				unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, j);

				if(unJugador != NULL && unaSeleccion != NULL)
				{
					jug_getSIdSeleccion(unJugador, &idSeleccion);
					selec_getId(unaSeleccion, &auxIdSeleccion);
					selec_getConvocados(unaSeleccion, &convocados);

					if(idSeleccion == auxIdSeleccion && convocados > 0)
					{
						jug_printOne(unJugador);
						rto=0;
					}
				}
			}
		}
	}

	return rto;
}

int controller_ordenarYListar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rto = -1;
	char aux;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		do{
			printf("\n╔═════════════ ORDENAR Y LISTAR ════════════\n"
				     "╠═»»» B. Selecciones por confederacion\n"
				     "╠═»»» C. Jugadores por edad\n"
				     "╠═»»» D. Jugadores por nombre\n"
				     "╠═»»» E. Salir\n"
				     "╚═══════════════════════════════════════════");

			utn_getChar(&aux, "\nIngrese una opcion: ", "Error, ", 'A', 'z', 3);
			aux = toupper(aux);

			switch(aux)
			{
				case 'A':
					if(ll_sort(pArrayListJugador, jug_ordenarPorNacionalidad, 1)==0)
					{
						controller_listarJugadores(pArrayListJugador);
					}
					break;
				case 'B':
					if(ll_sort(pArrayListSeleccion, selec_ordenarPorConfederacion, 1)==0)
					{
						controller_listarSelecciones(pArrayListSeleccion);
					}
					break;
				case 'C':
					if(ll_sort(pArrayListJugador, jug_ordenarPorEdad, 1)==0)
					{
						controller_listarJugadores(pArrayListJugador);
					}
					break;
				case 'D':
					if(ll_sort(pArrayListJugador, jug_ordenarPorNombre, 1)==0)
					{
						controller_listarJugadores(pArrayListJugador);
					}
					break;
				case 'E':
					printf("\nSaliendo...\n");
					break;
				default:
					break;
			}
		}while(aux != 'E');
	}

	return rto;
}

int controller_generarBinarioDeConvocados(char* path, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rto=-1, aux;
	int lenSelec, lenJug;
	int i, j;
	char confederacion[100];
	char auxConfederacion[100];
	int idSeleccion, auxIdSeleccion, convocados;

	Seleccion* auxSeleccion =NULL;
	Jugador* auxJugador = NULL;
	FILE* pFileBinary = NULL;

	lenSelec = ll_len(pArrayListSeleccion);
	lenJug = ll_len(pArrayListJugador);

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_filtrarConvocados(pArrayListJugador, pArrayListSeleccion);

		printf("\n╔════════ CONFEDERACIONES ════════\n"
				 "╠═»»» CONMEBOL\n"
				 "╠═»»» UEFA\n"
				 "╠═»»» AFC\n"
				 "╠═»»» CAF\n"
				 "╠═»»» CONCACAF\n"
				 "╚═════════════════════════════════\n");//no paso a funciones porque ningun menu es reutilizable

		utn_getString(auxConfederacion, "Ingrese el nombre de la confederacion: ", "Error, ");
		aux = selec_validarConfederaciones(auxConfederacion);
		while(aux != 0)
		{
			printf("\nError vuelva a ingresar la confederacion\n\n");
			utn_getString(auxConfederacion, "Ingrese el nombre de la confederacion: ", "Error, ");
			aux = selec_validarConfederaciones(auxConfederacion);
		}
		strupr(auxConfederacion);

		pFileBinary = fopen(path, "wb");

		for(i=0; i<lenJug; i++)
		{
			for(j=0; j<lenSelec; j++)
			{
				auxJugador = (Jugador*)ll_get(pArrayListJugador, i);
				auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, j);

				if(auxJugador != NULL && auxSeleccion != NULL)
				{
					jug_getSIdSeleccion(auxJugador, &auxIdSeleccion);
					selec_getId(auxSeleccion, &idSeleccion);
					selec_getConfederacion(auxSeleccion, confederacion);
					selec_getConvocados(auxSeleccion, &convocados);

					if(strcmp(confederacion, auxConfederacion) == 0 && idSeleccion == auxIdSeleccion && convocados > 0)
					{
						jug_printOne(auxJugador);//imprimo para ver que si es el jugador correcto

						if(pFileBinary != NULL)
						{
							fwrite(auxJugador, sizeof(Jugador), 1, pFileBinary);
						}
						rto = 0;
					}
				}
			}
		}

		fclose(pFileBinary);
	}

	return rto;
}

