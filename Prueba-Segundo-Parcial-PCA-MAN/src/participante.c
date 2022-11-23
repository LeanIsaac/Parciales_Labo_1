/*
 * participante.c
 *
 *  Created on: 22 nov. 2022
 *      Author: Marec
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "participante.h"
#include "UTN.h"
#include "parser.h"

eParticipante* part_new(void)
{
	eParticipante* unPart=NULL;
	unPart =(eParticipante*)malloc(sizeof(eParticipante));

	return unPart;
}

eParticipante* part_newParametros(char* idStr, char* nombreStr, char* edadStr, char* idDificultadStr, char* scoreStr )
{
	eParticipante* unPart=NULL;
	unPart = part_new();
	int flag=-1;

	if(unPart != NULL && idStr != NULL && nombreStr != NULL && edadStr != NULL && idDificultadStr != NULL && scoreStr != NULL)
	{
		if(part_setId(unPart, atoi(idStr))==0)
		{
			if(part_setNombre(unPart, nombreStr)==0)
			{
				if(part_setEdad(unPart, atoi(edadStr))==0)
				{
					if(part_setIdDificultad(unPart, atoi(idDificultadStr))==0)
					{
						if(part_setScore(unPart, atoi(scoreStr))==0)
						{
							flag = 0;
						}
					}
				}
			}
		}
	}

	if(flag == -1)
	{
		part_delete(unPart);
		unPart = NULL;
	}
	return unPart;
}

void part_delete(eParticipante* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int part_setId(eParticipante* this, int id)
{
	int rto=-1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rto = 0;
	}

	return rto;
}

int part_getId(eParticipante* this, int* id)
{
	int rto=-1;

	if(this != NULL && id != NULL)
	{
		 *id = this->id;
		rto = 0;
	}


	return rto;
}

int part_setNombre(eParticipante* this, char* nombre)
{
	int rto=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		rto=0;
	}
	return rto;
}

int part_getNombre(eParticipante* this, char* nombre)
{
	int rto=-1;

	if(this != NULL  && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		rto=0;
	}
	return rto;
}

int part_setEdad(eParticipante* this, int edad)
{
	int rto=-1;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		rto = 0;
	}

	return rto;
}

int part_getEdad(eParticipante* this, int* edad)
{
	int rto=-1;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		rto = 0;
	}

	return rto;
}


int part_setIdDificultad(eParticipante* this, int idDificultad)
{
	int rto=-1;

	if(this != NULL && idDificultad > 0)
	{
		this->idDificultad = idDificultad;
		rto = 0;
	}

	return rto;
}

int part_getIdDificultad(eParticipante* this, int* idDificultad)
{
	int rto=-1;

	if(this != NULL && idDificultad != NULL)
	{
		 *idDificultad = this->idDificultad;
		rto = 0;
	}


	return rto;
}


int part_setScore(eParticipante* this, int score)
{
	int rto=-1;

	if(this != NULL && score > 0)
	{
		this->score = score;
		rto = 0;
	}

	return rto;
}

int part_getScore(eParticipante* this, int* score)
{
	int rto=-1;

	if(this != NULL && score != NULL)
	{
		*score = this->score;
		rto = 0;
	}

	return rto;
}


void part_printOne(eParticipante* unParticipante)
{
	int id;
	char nombre[100];
	int edad;
	int idDificultas;
	int score;
	char idTipoStr[100];

	part_getId(unParticipante, &id);
	part_getNombre(unParticipante, nombre);
	part_getEdad(unParticipante, &edad);
	part_getIdDificultad(unParticipante, &idDificultas);
	part_getScore(unParticipante, &score);

	if(idDificultas == 1)
	{
		strcpy(idTipoStr, "FACIL");
		printf("%4d\t%-20s\t%4d\t\t%-10s\t%4d\n",id,nombre,edad,idTipoStr,score);
	}
	else
	{
		if(idDificultas == 2)
		{
			strcpy(idTipoStr, "NORMAL");
			printf("%4d\t%-20s\t%4d\t\t%-10s\t%4d\n",id,nombre,edad,idTipoStr,score);
		}
		else
		{
			strcpy(idTipoStr, "DIFICIL");
			printf("%4d\t%-20s\t%4d\t\t%-10s\t%4d\n",id,nombre,edad,idTipoStr,score);
		}
	}
}


int part_sortByName(void* pNombreUno, void* pNombreDos)
{
	int rto=-1;
	char nombreParticipanteUno[500];
	char nombreParticipanteDos[500];
	eParticipante* partUno=NULL;
	eParticipante* partDos=NULL;

	if(partUno != NULL && partDos != NULL)
	{
		partUno = (eParticipante*)pNombreUno;
		partDos = (eParticipante*)pNombreDos;

		if(partUno != NULL && partDos != NULL)
		{
			part_getNombre(partUno, nombreParticipanteUno);
			part_getNombre(partDos, nombreParticipanteDos);

			rto = strcmp(nombreParticipanteUno, nombreParticipanteDos);
		}
	}


	return rto;
}


int part_filterDificultadUno(void* pElement)
{
	int retorno = -1;
	int dificultad;
	eParticipante* unParticipante = NULL;

	if(pElement != NULL)
	{
		unParticipante = (eParticipante*)pElement;
		if(unParticipante != NULL)
		{
			part_getIdDificultad(unParticipante, &dificultad);

			if(dificultad == 1)
			{
				retorno = 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}
	return retorno;
}


int part_filterDificultadDos(void* pElement)
{
	int retorno = -1;
	int dificultad;
	eParticipante* unParticipante = NULL;

	if(pElement != NULL)
	{
		unParticipante = (eParticipante*)pElement;
		if(unParticipante != NULL)
		{
			part_getIdDificultad(unParticipante, &dificultad);

			if(dificultad == 2)
			{
				retorno = 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}
	return retorno;
}

int part_filterDificultadTres(void* pElement)
{
	int retorno = -1;
	int dificultad;
	eParticipante* unParticipante = NULL;

	if(pElement != NULL)
	{
		unParticipante = (eParticipante*)pElement;
		if(unParticipante != NULL)
		{
			part_getIdDificultad(unParticipante, &dificultad);
			if(dificultad == 3)
			{
				retorno = 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}
	return retorno;
}


