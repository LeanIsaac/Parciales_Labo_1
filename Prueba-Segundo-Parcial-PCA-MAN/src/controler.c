
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "participante.h"
#include "UTN.h"
#include "parser.h"

int controller_cargarParticipantesDesdeTexto(char* path , LinkedList* pArrayListParticipante)
{
	int rto=-1;
	if(path != NULL && pArrayListParticipante != NULL)
	{
		FILE* pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if( parser_participanteFromText(pFile, pArrayListParticipante) ==0 )
			{
				rto=0;
			}
			fclose(pFile);
		}
		else
		{
			printf("\nARCHIVO NULO\n");
		}
	}
    return rto;
}



int controller_listarParticipantes(LinkedList* pArrayListParticipante)
{
	eParticipante* unPart;
	int cant, rto=-1;

	if(pArrayListParticipante != NULL)
	{
		cant = ll_len(pArrayListParticipante);
		printf("\n═══════════════════════════════════════════════════════════════════════\n");
		printf(" ID\tNombre\t\t\tEdad\t\tDificultad\tScore");
		printf("\n═══════════════════════════════════════════════════════════════════════\n\n");
		for(int i=0; i<cant; i++)
		{
			unPart = (eParticipante*)ll_get(pArrayListParticipante, i);
			part_printOne(unPart);
			rto = 0;
		}
	}

    return rto;
}



int controller_guardarComoTexto(char* path , LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListParticipante != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTextoFiltrado(pFile, pArrayListParticipante);
			retorno=0;
		}
		else
		{
			retorno=-2;
		}

		fclose(pFile);
	}
	return retorno;
}

