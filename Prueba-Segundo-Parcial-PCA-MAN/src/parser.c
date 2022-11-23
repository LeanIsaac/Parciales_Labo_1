
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "UTN.h"
#include "controler.h"
#include "parser.h"
#include "participante.h"

int parser_participanteFromText(FILE* pFile , LinkedList* pArrayListParticipante)
{
	int rto= -1;
	char id[10];
	char nombre[100];
	char edad[100];
	char idDificultad[100];
	char score[50];
	int aux;

	eParticipante* unParticipante=NULL;

	if(pFile != NULL && pArrayListParticipante != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,idDificultad,score);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,idDificultad,score);
			if(aux == 5)
			{
				unParticipante = part_newParametros(id, nombre, edad, idDificultad, score);
			}

			if(unParticipante != NULL)
			{
				ll_add(pArrayListParticipante, unParticipante);
			}
		}
		rto = 0;
	}
    return rto;
}


int parser_guardarTextoFiltrado(FILE* pFile , LinkedList* pArrayListParticipante)
{
	int retorno = -1, i;
	int id;
	char nombre[100];
	int edad;
	int idDificultad;
	int score;

	eParticipante* aux;
	int len = ll_len(pArrayListParticipante);

	if(pFile != NULL && pArrayListParticipante != NULL)
	{
		fprintf(pFile,"id,nombre,edad,idDificultad,score\n");
		for(i=0;i<len;i++)
		{
			aux = (eParticipante*)ll_get(pArrayListParticipante, i);
			if(aux != NULL)
			{
				if(part_getId(aux, &id)==0)
				{
					if(part_getNombre(aux, nombre)==0)
					{
						if(part_getEdad(aux, &edad)==0)
						{
							if(part_getIdDificultad(aux, &idDificultad)==0)
							{
								if(part_getScore(aux, &score)==0)
								{
									fprintf(pFile,"%d,%s,%d,%d,%d\n",id,nombre,edad,idDificultad,score);
									retorno = 0;
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}
