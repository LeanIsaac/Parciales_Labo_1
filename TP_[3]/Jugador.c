#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Seleccion.h"
#include "Jugador.h"
#include "parser.h"
#include "Controller.h"
#include "UTN.h"



Jugador* jug_new()
{

	Jugador* unJugador = NULL;
	unJugador = (Jugador*)malloc(sizeof(Jugador));

	return unJugador;
}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* unJugador = NULL;
	unJugador = jug_new();
	int flag = -1;

	if(unJugador != NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL)
	{
		if(jug_setId(unJugador, atoi(idStr))==0)
		{
			if(jug_setNombreCompleto(unJugador, nombreCompletoStr)==0)
			{
				if(jug_setEdad(unJugador, atoi(edadStr))==0)
				{
					if(jug_setPosicion(unJugador, posicionStr)==0)
					{
						if(jug_setNacionalidad(unJugador, nacionalidadStr)==0)
						{
							if(jug_setIdSeleccion(unJugador, atoi(idSeleccionStr))==0)
							{
								flag = 0;
							}
						}
					}
				}
			}
		}
	}

	if(flag == -1)
	{
		jug_delete(unJugador);
		unJugador = NULL;
	}

	return unJugador;
}

void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int jug_setId(Jugador* this,int id)
{
	int rto=-1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rto = 0;
	}

	return rto;
}

int jug_getId(Jugador* this,int* id)
{
	int rto=-1;

	if(this != NULL && id != NULL)
	{
		 *id = this->id;
		rto = 0;
	}


	return rto;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int rto=-1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		rto = 0;
	}

	return rto;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int rto=-1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto, this->nombreCompleto);
		rto = 0;
	}

	return rto;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int rto=-1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(this->posicion, posicion);
		rto = 0;
	}

	return rto;
}


int jug_getPosicion(Jugador* this,char* posicion)
{
	int rto=-1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(posicion, this->posicion);
		rto = 0;
	}

	return rto;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int rto=-1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(this->nacionalidad, nacionalidad);
		rto = 0;
	}

	return rto;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int rto=-1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);
		rto = 0;
	}

	return rto;
}

int jug_setEdad(Jugador* this,int edad)
{
	int rto=-1;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		rto = 0;
	}

	return rto;
}
int jug_getEdad(Jugador* this,int* edad)
{
	int rto=-1;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		rto = 0;
	}

	return rto;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int rto=-1;

	if(this != NULL && idSeleccion >= 0)
	{
		this->idSeleccion = idSeleccion;
		rto = 0;
	}

	return rto;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int rto=-1;

	if(this != NULL && idSeleccion != NULL)
	{
		*idSeleccion = this->idSeleccion;
		rto = 0;
	}

	return rto;
}

void jug_printOne(Jugador* unJugador)
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int idSeleccion;

	jug_getId(unJugador, &id);
	jug_getNombreCompleto(unJugador, nombreCompleto);
	jug_getEdad(unJugador, &edad);
	jug_getPosicion(unJugador, posicion);
	jug_getNacionalidad(unJugador, nacionalidad);
	jug_getSIdSeleccion(unJugador, &idSeleccion);

	printf("%4d %-25s %4d\t%-22s %-18s %4d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
}

void jug_leerId(char* auxId)
{
	FILE* pArchivoId = NULL;

	char idchar[20];
	int id;

	pArchivoId = fopen("archivoId.txt","r");

	if(pArchivoId != NULL)
	{
		fscanf(pArchivoId,"%[^\n]",idchar);

		strcpy(auxId,idchar);

		id = atoi(idchar);

		id++;

		fclose(pArchivoId);

		pArchivoId = fopen("archivoId.txt","w");

		fprintf(pArchivoId,"%d\n",id);

		fclose(pArchivoId);
	}
}

int jug_validarPosiciones(char* strPosicion)
{
	int rto=-1;

	if(stricmp(strPosicion, "Arquero") == 0 )
	{
		rto = 0;
	}
	else
	{
		if(stricmp(strPosicion, "Defensor") == 0 )
		{
			rto= 0;
		}
		else
		{
			if(stricmp(strPosicion, "Mediocampista") == 0 )
			{
				rto=0;
			}
			else
			{
				if(stricmp(strPosicion, "Delantero") == 0 )
				{
					rto=0;
				}
			}
		}
	}
	return rto;
}

void jug_mostrarPosiciones(void)
{
	printf("\n╔═════ POSICIONES ═════\n"
			"╠═»»» Arquero\n"
			"╠═»»» Defensor\n"
			"╠═»»» Mediocampista\n"
			"╠═»»» Delantero\n"
			"╚══════════════════════");
}

int jug_alta(LinkedList* pArrayListJugador)
{
	int rto= -1,aux;
	char auxId[10];
	char nombreCompleto[100];
	char edad[30];
	char posicion[50];
	char auxPosicion[50];
	char nacionalidad[50];
	char idSeleccion[10];
	Jugador* auxJugador=NULL;

	if(pArrayListJugador != NULL) {
		printf("\n---------------------------------------------------------\n");

		utn_getString(nombreCompleto, "\nIngrese nombre completo: ", "Error, ");

		printf("\n---------------------------------------------------------\n");
		getString(edad, "\nIngrese edad: ", 60);

		printf("\n---------------------------------------------------------\n");
		jug_mostrarPosiciones();
		utn_getString(auxPosicion, "\nIngrese la posicion: ", "Error, ");
		aux = jug_validarPosiciones(auxPosicion);
		while(aux != 0)
		{
			printf("\nError vuelva a ingresar la posicion\n");
			utn_getString(auxPosicion, "\nIngrese la posicion: ", "Error, ");
			aux = jug_validarPosiciones(auxPosicion);
		}
		strcpy(posicion, auxPosicion);
		printf("\n---------------------------------------------------------\n");

		utn_getString(nacionalidad, "\nIngrese nacionalidad: ", "Error, ");

		printf("\n---------------------------------------------------------\n");

		jug_leerId(auxId);

		auxJugador = jug_newParametros(auxId, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);

		if(auxJugador != NULL)
		{
			ll_add(pArrayListJugador, auxJugador);
			rto=0;
		}
	}

	return rto;
}

int jug_modificar(LinkedList* pArrayListJugador)
{
	Jugador* auxJugador=NULL;
	int rto=-1,aux;
	int opcion;
	int indice;

	char auxNombreCompleto[100];
	int auxEdad;
	char auxPosicion[100];
	char auxNacionalidad[100];

	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);

		indice = jug_buscarPorId(pArrayListJugador);

		rto=0;

		if(indice > -1)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, indice);

			do{
				opcion = menuGenerico("\n╔════════════ MENU ═════════════\n"
									  "╠═»»» 1. Modificar Nombre\n"
									  "╠═»»» 2. Modificar Edad\n"
									  "╠═»»» 3. Modificar Posicion\n"
									  "╠═»»» 4. Modificar Nacionalidad\n"
									  "╠═»»» 5. Salir\n"
									  "╚═══════════════════════════════");
				switch(opcion) {
				case 1:
					utn_getString(auxNombreCompleto, "Ingrese el nombre completo: ", "Error, ");
					jug_setNombreCompleto(auxJugador, auxNombreCompleto);
					break;
				case 2:
					utn_getInt(&auxEdad, "Ingrese la edad: ", "Error, ", 1,100, 2);
					jug_setEdad(auxJugador, auxEdad);
					break;
				case 3:
					jug_mostrarPosiciones();
					utn_getString(auxPosicion, "\nIngrese la posicion: ", "Error, ");
					aux = jug_validarPosiciones(auxPosicion);
					while(aux != 0)
					{
						printf("\nError vuelva a ingresar la posicion\n");
						utn_getString(auxPosicion, "\nIngrese la posicion: ", "Error, ");
						aux = jug_validarPosiciones(auxPosicion);
					}
					jug_setPosicion(auxJugador, auxPosicion);
					break;
				case 4:
					utn_getString(auxNacionalidad, "Ingrese la nacionalidad: ", "Error, ");
					jug_setNacionalidad(auxJugador, auxNacionalidad);
					break;
				case 5:
					printf("\n\nSaliendo...\n\n\n\nAdios!!!");
					break;
				}

			}while(opcion != 5);
		}
	}

	return rto;
}

int jug_buscarPorId(LinkedList* pArrayListJugador)
{
	Jugador* auxJugador;

	int idJugador;
	int id, i, rto, len;
	rto = -1;

	len = ll_len(pArrayListJugador); //GUARDO TAMAÑO DE LA LISTA

	if(pArrayListJugador != NULL)
	{
		utn_getInt(&id, "\nIngrese el ID del jugador: ", "Error, ", 0, 9999999, 3); //PIDO ID

		for(i=0;i<len;i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i); //OBTENGO EL INDICE //Retorno un puntero al elemento que se encuentra en el índice i
			if(auxJugador != NULL)
			{
				jug_getId(auxJugador, &idJugador);// OBTENGO EL ID DE X POSICION
				if(id == idJugador) // SI EL ID X ES IGUAL
				{
					rto = i; //LO RETORNO Y SALGO
					break;
				}
			}
		}
	}

	return rto;
}


void menuPrincipal(void)
{
	printf("╔═══════════════════════════════════════╗\n"
	       "║                                       ║\n"
	       "║ »»»»» FIFA WORLD CUP QATAR 2022 ««««« ║\n"
		   "║                                       ║\n"
		   "╠═══════════════════════════════════════╣\n"
		   "╠═»»» 1.  CARGA DE ARCHIVO              ║\n"
		   "╠═»»» 2.  ALTA DE JUGADORES             ║\n"
		   "╠═»»» 3.  MODIFICACION DE JUGADORES     ║\n"
		   "╠═»»» 4.  BAJA DE JUGADORES             ║\n"
		   "╠═»»» 5.  LISTADO                       ║\n"
		   "╠═»»» 6.  CONVOCAR O QUITAR JUGADORES   ║\n"
		   "╠═»»» 7.  ORDENAR Y LISTAR              ║\n"
		   "╠═»»» 8.  GENERAR ARCHIVO BINARIO       ║\n"
		   "╠═»»» 9.  CARGAR ARCHIVO BINARIO        ║\n"
		   "╠═»»» 10. GUARDAR ARCHIVO .CSV          ║\n"
		   "╠═»»» 11. SALIR                         ║\n"
		   "╚═══════════════════════════════════════╝\n");
}

int jug_baja(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rto=-1;
	int indice;
	char aux;
	int idSeleccion;
	int convocados;
	int lenSelec;
	int auxId;
	Jugador* auxJugador= NULL;
	Seleccion* auxSeleccion=NULL;

	lenSelec = ll_len(pArrayListSeleccion);

	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);

		indice = jug_buscarPorId(pArrayListJugador);

		if(indice != -1)
		{
			auxJugador = (Jugador*) ll_get(pArrayListJugador, indice);
			jug_getSIdSeleccion(auxJugador, &idSeleccion);

			if(auxJugador != NULL)
			{

				jug_printOne(auxJugador);

				utn_getChar(&aux, "\nDesea dar de baja este jugador? [S|N] ", "Error, ", 'A', 'z', 3);
				aux = tolower(aux);

				if(aux == 's')
				{
					for(int i=0;i<lenSelec;i++)
					{
						auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
						selec_getId(auxSeleccion, &auxId);
						selec_getConvocados(auxSeleccion, &convocados);
						if(auxId == idSeleccion)
						{
							convocados--;
							selec_setConvocados(auxSeleccion, convocados);
						}
					}

					ll_remove(pArrayListJugador, indice);
					rto=0;
				}
				else
				{
					printf("\nEl jugador no se dio de Baja\n");
				}
			}
		}
		else
		{
			printf("\nEl ID no coincide con el ingresado\n\n");
		}
	}

	return rto;
}

int jug_ordenarPorNacionalidad(void* pJugadorUno , void* pJugadorDos)
{
	int retorno = -1;
	char nacionalidadJugadorUno[100];
	char nacionalidadJugadorDos[100];
	Jugador* jugadorUno = NULL;
	Jugador* jugadorDos = NULL;

	if(pJugadorUno != NULL && pJugadorDos != NULL)
	{
		jugadorUno = (Jugador*)pJugadorUno;
		jugadorDos =  (Jugador*)pJugadorDos;

		if(jugadorUno != NULL && jugadorDos != NULL)
		{
			jug_getNacionalidad(jugadorUno, nacionalidadJugadorUno);
			jug_getNacionalidad(jugadorDos, nacionalidadJugadorDos);
			retorno = strcmp(nacionalidadJugadorUno,nacionalidadJugadorDos);
		}
	}

	return retorno;
}

int jug_ordenarPorNombre(void* pJugadorUno , void* pJugadorDos)
{
	int retorno = -1;
	char nombreJugadorUno[100];
	char nombreJugadorDos[100];
	Jugador* jugadorUno = NULL;
	Jugador* jugadorDos = NULL;

	if(pJugadorUno != NULL && pJugadorDos != NULL)
	{
		jugadorUno = (Jugador*)pJugadorUno;
		jugadorDos =  (Jugador*)pJugadorDos;

		if(jugadorUno != NULL && jugadorDos != NULL)
		{
			jug_getNombreCompleto(jugadorUno, nombreJugadorUno);
			jug_getNombreCompleto(jugadorDos, nombreJugadorDos);
			retorno = strcmp(nombreJugadorUno,nombreJugadorDos);
		}
	}

	return retorno;
}

int jug_ordenarPorEdad(void* pJugadorUno , void* pJugadorDos)
{
	int retorno = -1;
	int edadJugadorUno;
	int edadJugadorDos;
	Jugador* jugadorUno = NULL;
	Jugador* jugadorDos = NULL;

	if(pJugadorUno != NULL && pJugadorDos != NULL)
	{
		jugadorUno = (Jugador*)pJugadorUno;
		jugadorDos =  (Jugador*)pJugadorDos;

		if(jugadorUno != NULL && jugadorDos != NULL)
		{
			jug_getEdad(jugadorUno, &edadJugadorUno);
			jug_getEdad(jugadorDos, &edadJugadorDos);

			if(edadJugadorUno > edadJugadorDos)
			{
				retorno = 1;
			}
			else
			{
				if(edadJugadorUno < edadJugadorDos)
				{
					retorno = 2;
				}
			}
		}
	}

	return retorno;
}
