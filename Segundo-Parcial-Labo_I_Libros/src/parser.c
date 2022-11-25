
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "UTN.h"
#include "controler.h"
#include "parser.h"
#include "libros.h"

int parser_libroFromText(FILE* pFile , LinkedList* pArrayListLibros)
{
	int rto= -1;
	char id[10];
	char titulo[100];
	char importe[100];
	char idTipo[100];
	int aux;

	eLibros* unLibro=NULL;

	if(pFile != NULL && pArrayListLibros != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,importe,idTipo);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,importe,idTipo);
			if(aux == 4)
			{
				unLibro = libro_newParametros(id, titulo, importe, idTipo);
			}

			if(unLibro != NULL)
			{
				ll_add(pArrayListLibros, unLibro);
			}
		}
		rto = 0;
	}
    return rto;
}


int parser_guardarTextoMapeado(FILE* pFile , LinkedList* pArrayListLibros)
{
	int retorno = -1, i;
	int id;
	char titulo[100];
	int idTipo;
	float importeAumento;

	eLibros* aux;
	int len = ll_len(pArrayListLibros);

	if(pFile != NULL && pArrayListLibros != NULL)
	{
		fprintf(pFile,"id,titulo,importe,idTipo,importeConAumento\n");

		for(i=0;i<len;i++)
		{
			aux = (eLibros*)ll_get(pArrayListLibros, i);

			if(aux != NULL)
			{
				if(libro_getId(aux, &id)==0)
				{
					if(libro_getTitulo(aux, titulo)==0)
					{
						if(libro_getIdTipo(aux, &idTipo)==0)
						{
							if(libro_getImporteAumento(aux, &importeAumento)==0)
							{
								fprintf(pFile,"%d,%s,%.2f,%d\n",id,titulo,importeAumento,idTipo);
								retorno = 0;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

int parser_guardarTexto(FILE* pFile , LinkedList* pArrayListLibros)
{
	int retorno = -1, i;
	int id;
	char titulo[100];
	float importe;
	int idTipo;
	float importeAumento;

	eLibros* aux;
	int len = ll_len(pArrayListLibros);

	if(pFile != NULL && pArrayListLibros != NULL)
	{
		fprintf(pFile,"id,titulo,importe,idTipo\n");

		for(i=0;i<len;i++)
		{
			aux = (eLibros*)ll_get(pArrayListLibros, i);

			if(aux != NULL)
			{
				if(libro_getId(aux, &id)==0)
				{
					if(libro_getTitulo(aux, titulo)==0)
					{
						if(libro_getImporte(aux, &importe)==0)
						{
							if(libro_getIdTipo(aux, &idTipo)==0)
							{
								fprintf(pFile,"%d,%s,%.2f,%d\n",id,titulo,importe,idTipo);
								retorno = 0;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}
