#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Seleccion.h"
#include "parser.h"
#include "UTN.h"

Seleccion* selec_new(){
	Seleccion* unaSeleccion;
	unaSeleccion = (Seleccion*)malloc(sizeof(Seleccion));

	return unaSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion* unaSeleccion=NULL;
	unaSeleccion = selec_new();
	int flag=-1;

	if(unaSeleccion != NULL && idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr)
	{
		unaSeleccion->id = atoi(idStr);
		strcpy(unaSeleccion->pais, paisStr);
		strcpy(unaSeleccion->confederacion, confederacionStr);
		selec_setConvocados(unaSeleccion, atoi(convocadosStr));
		flag = 0;
	}

	if(flag == -1) {
		selec_delete(unaSeleccion);
		unaSeleccion = NULL;
	}

	return unaSeleccion;
}


void selec_delete(Seleccion* this){
	if(this != NULL)
	{
		free(this);
	}
}

int selec_getId(Seleccion* this,int* id){
	int rto=-1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		rto = 0;
	}
	return rto;
}

int selec_getPais(Seleccion* this,char* pais){
	int rto=-1;

	if(this != NULL && pais != NULL)
	{
		strcpy(pais, this->pais);
		rto = 0;
	}
	return rto;
}


int selec_getConfederacion(Seleccion* this,char* confederacion){
	int rto=-1;

	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion, this->confederacion);
		rto = 0;
	}
	return rto;
}


int selec_setConvocados(Seleccion* this,int convocados){
	int rto=-1;

	if(this != NULL && convocados >= 0)
	{
		this->convocados = convocados;
		rto = 0;
	}
	return rto;
}

int selec_getConvocados(Seleccion* this,int* convocados){
	int rto=-1;

	if(this != NULL && convocados != NULL)
	{
		*convocados = this->convocados;
		rto = 0;
	}
	return rto;
}


void selec_printOne(Seleccion* unaSeleccion){
	int id;
	char pais[100];
	char confederacion[100];
	int convocados;

	selec_getId(unaSeleccion, &id);
	selec_getPais(unaSeleccion, pais);
	selec_getConfederacion(unaSeleccion, confederacion);
	selec_getConvocados(unaSeleccion, &convocados);

	if(unaSeleccion != NULL){
		printf("%-4d\t%-15s\t %-10s\t %2d\n",id,pais,confederacion,convocados);
	}
}


int selec_buscarPorId(LinkedList* pArrayListSeleccion)
{
	Seleccion* auxSeleccion = NULL;

	int idSeleccion;
	int id, i, rto, len;
	rto = -1;

	len = ll_len(pArrayListSeleccion); //GUARDO TAMAÑO DE LA LISTA

	if(pArrayListSeleccion != NULL && id >= 0)
	{
		utn_getInt(&id, "\nIngrese el ID de la seleccion: ", "Error, ", 0, 9999999, 3); //PIDO ID

		for(i=0;i<len;i++)
		{
			auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i); //OBTENGO EL INDICE //Retorno un puntero al elemento que se encuentra en el índice de i
			if(auxSeleccion != NULL)
			{
				selec_getId(auxSeleccion, &idSeleccion);// OBTENGO EL ID DE X POSICION
				if(id == idSeleccion) // SI EL ID INGRESADO ES IGUAL A X ID EN X POSICION
				{
					rto = i; //LO RETORNO Y ROMPO
					break;
				}
			}
		}
	}

	return rto;
}


int selec_ordenarPorConfederacion(void* pSeleccionUno , void* pSeleccionDos)
{
	int retorno = -1;
	char confederacionSeleccionUno[100];
	char confederacionSeleccionDos[100];
	Seleccion* seleccionUno = NULL;
	Seleccion* seleccionDos = NULL;

	if(pSeleccionUno != NULL && pSeleccionDos != NULL)
	{
		seleccionUno = (Seleccion*)pSeleccionUno;
		seleccionDos =  (Seleccion*)pSeleccionDos;

		if(seleccionUno != NULL && seleccionDos != NULL)
		{
			selec_getConfederacion(seleccionUno, confederacionSeleccionUno);
			selec_getConfederacion(seleccionDos, confederacionSeleccionDos);

			retorno = strcmp(confederacionSeleccionUno, confederacionSeleccionDos);
		}
	}

	return retorno;
}

int selec_validarConfederaciones(char* strPosicion)
{
	int rto=-1;

	if(stricmp(strPosicion, "CONMEBOL") == 0 )
	{
		rto = 0;
	}
	else
	{
		if(stricmp(strPosicion, "UEFA") == 0 )
		{
			rto= 0;
		}
		else
		{
			if(stricmp(strPosicion, "CAF") == 0 )
			{
				rto=0;
			}
			else
			{
				if(stricmp(strPosicion, "CONCACAF") == 0 )
				{
					rto=0;
				}
				else
				{
					if(stricmp(strPosicion, "AFC") == 0)
					{
						rto=0;
					}
				}
			}
		}
	}
	return rto;
}
