
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "computadoras.h"
#include "UTN.h"
#include "parser.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListComputer)
{
	int rto=-1;
	if(path != NULL && pArrayListComputer != NULL)
	{
		FILE* pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if( parser_JugadorFromText(pFile, pArrayListComputer) ==0 )
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



int controller_listarComputadoras(LinkedList* pArrayListComputer)
{
	eComputer* unaCompu;
	int cant, rto=-1;

	if(pArrayListComputer != NULL)
	{
		cant = ll_len(pArrayListComputer);
		printf("\n═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
		printf(" ID    Descripcion\t\t\t\t\t\t\t\t\t\t\t\t    Precio  Tipo\tCuotas");
		printf("\n═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n\n");
		for(int i=0; i<cant; i++)
		{
			unaCompu = (eComputer*)ll_get(pArrayListComputer, i);
			compu_printOne(unaCompu);
			rto = 0;
		}
	}

    return rto;
}



int controller_guardarComoTexto(char* path , LinkedList* pArrayListComputer)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListComputer != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTextoMapeado(pFile, pArrayListComputer);
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
