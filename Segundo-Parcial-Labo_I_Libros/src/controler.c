
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "controler.h"
#include "libros.h"
#include "UTN.h"
#include "parser.h"

int controller_cargarLibrosDesdeTexto(char* path , LinkedList* pArrayListLibros)
{
	int rto=-1;
	if(path != NULL && pArrayListLibros != NULL)
	{
		FILE* pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			if( parser_libroFromText(pFile, pArrayListLibros) ==0 )
			{
				rto=0;
				printf("\nARCHIVO NO-NULO\n");
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



int controller_listarLibros(LinkedList* pArrayListLibro)
{
	eLibros* unLibro;
	int cant, rto=-1;

	if(pArrayListLibro != NULL)
	{
		cant = ll_len(pArrayListLibro);
		printf("\n══════════════════════════════════════════════════════════════════════════\n");
		printf(" ID    Titulo\t\t\tImporte\t\tTipo");
		printf("\n══════════════════════════════════════════════════════════════════════════\n\n");
		for(int i=0; i<cant; i++)
		{
			unLibro = (eLibros*)ll_get(pArrayListLibro, i);
			libro_printOne(unLibro);
			rto = 0;
		}
	}

    return rto;
}

int controller_guardarComoTexto(char* path , LinkedList* pArrayListLibros)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListLibros != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTexto(pFile, pArrayListLibros);
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


int controller_guardarComoTextoMapeado(char* path , LinkedList* pArrayListLibros)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListLibros != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTextoMapeado(pFile, pArrayListLibros);
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

