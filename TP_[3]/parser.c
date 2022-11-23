#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int rto= -1;
	char id[10];
	char nombreCompleto[100];
	char edad[10];
	char posicion[50];
	char nacionalidad[50];
	char idSeleccion[10];
	int aux;

	Jugador* unJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
			if(aux == 6)
			{
				unJugador = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			}

			if(unJugador != NULL)
			{
				ll_add(pArrayListJugador, unJugador);
			}
		}
		rto = 0;
	}
    return rto;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int rto=-1;
	Jugador* unJugador=NULL;
	int aux;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		while(!feof(pFile))
		{
			unJugador = jug_new();
			aux = fread(unJugador, sizeof(Jugador), 1, pFile);
			if( unJugador != NULL && aux == 1 )
			{
				ll_add(pArrayListJugador, unJugador);
			}
		}
		rto = 0;
	}

    return rto;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int rto= -1;
	char id[10];
	char pais[50];
	char confederacion[50];
	char convocados[10];
	int aux;

	Seleccion* unaSeleccion=NULL;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
			if(aux == 4)
			{
				unaSeleccion = selec_newParametros(id, pais, confederacion, convocados);
			}

			if(unaSeleccion != NULL)
			{
				ll_add(pArrayListSeleccion, unaSeleccion);
			}
		}
		rto = 0;
	}
	return rto;;
}

int parser_guardarJugadorModoTexto(FILE* pFile ,LinkedList* pArrayListJugador)
{
	int rto=-1, i;
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad;
	char auxPosicion[100];
	char auxNacionalidad[100];
	int auxIdSeleccion;

	Jugador* auxJugador;

	int len = ll_len(pArrayListJugador);

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fprintf(pFile,"Id,NombreCompleto,Edad,Posicion,Nacionalidad,IdSeleccion\n");

		for(i=0; i<len; i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i);
			if(auxJugador != NULL)
			{
				jug_getId(auxJugador, &auxId);
				jug_getNombreCompleto(auxJugador, auxNombreCompleto);
				jug_getEdad(auxJugador, &auxEdad);
				jug_getPosicion(auxJugador, auxPosicion);
				jug_getNacionalidad(auxJugador, auxNacionalidad);
				jug_getSIdSeleccion(auxJugador, &auxIdSeleccion);

				fprintf(pFile, "%d,%s,%d,%s,%s,%d\n",auxId,auxNombreCompleto,auxEdad, auxPosicion,auxNacionalidad,auxIdSeleccion);
			}
		}
		rto=0;
	}

	return rto;
}

int parser_guardarSeleccionModoTexto(FILE* pFile, LinkedList* pArrayListSeleccion)
{
	int rto=-1, i;
	int auxId;
	char auxPais[100];
	char auxConfederacion[100];
	int auxConvocados;
	int len;

	Seleccion* unaSeleccion=NULL;
	len = ll_len(pArrayListSeleccion);

	if(pArrayListSeleccion != NULL && pFile != NULL)
	{
		fprintf(pFile,"Id,Pais,Confederacion,Convocados\n");

		for(i=0; i<len; i++)
		{
			unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
			if(unaSeleccion != NULL)
			{
				selec_getId(unaSeleccion, &auxId);
				selec_getPais(unaSeleccion, auxPais);
				selec_getConfederacion(unaSeleccion, auxConfederacion);
				selec_getConvocados(unaSeleccion, &auxConvocados);

				fprintf(pFile, "%d,%s,%s,%d\n",auxId,auxPais,auxConfederacion, auxConvocados);
			}
		}
		rto=0;
	}

	return rto;
}


int parser_guardarJugadoresModoBinario(FILE* pFile, LinkedList* pArrayListJugador)
{
	int rto=-1;
	int i, len;

	Jugador* auxJugador=NULL;
	len = ll_len(pArrayListJugador);

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		for(i=0;i<len;i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i);

			if(auxJugador != NULL)
			{
				fwrite(auxJugador, sizeof(Jugador), 1, pFile);
			}
		}
		rto=0;
	}

	return rto;
}
