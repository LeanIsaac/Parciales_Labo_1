
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "UTN.h"
#include "controler.h"
#include "parser.h"
#include "computadoras.h"

int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListComputer)
{
	int rto= -1;
	char id[10];
	char descripcion[100];
	char precio[100];
	char idTipo[100];
	char cuotas[50];
	int aux;

	eComputer* unaComputadora=NULL;

	if(pFile != NULL && pArrayListComputer != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo,cuotas);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo,cuotas);
			if(aux == 5)
			{
				unaComputadora = compu_newParametros(id, descripcion, precio, idTipo, cuotas);
			}

			if(unaComputadora != NULL)
			{
				ll_add(pArrayListComputer, unaComputadora);
			}
		}
		rto = 0;
	}
    return rto;
}


int parser_guardarTextoMapeado(FILE* pFile , LinkedList* pArrayListComputer)
{
	int retorno = -1, i;
	int id;
	char descripcion[100];
	int precio;
	int idTipo;
	int cuotas;
	float precioCuotas;

	eComputer* aux;
	int len = ll_len(pArrayListComputer);

	if(pFile != NULL && pArrayListComputer != NULL)
	{
		fprintf(pFile,"id,descripcion,precio,idTipo,cuotas,precioPorCuotas\n");

		for(i=0;i<len;i++)
		{
			aux = (eComputer*)ll_get(pArrayListComputer, i);

			if(aux != NULL)
			{
				if(compu_getId(aux, &id)==0)
				{
					if(compu_getDescripcion(aux, descripcion)==0)
					{
						if(compu_getPrecio(aux, &precio)==0)
						{
							if(compu_getIdTipo(aux, &idTipo)==0)
							{
								if(compu_getCuotas(aux, &cuotas)==0)
								{
									if(compu_getPrecioCuotas(aux, &precioCuotas)==0)
									{
										fprintf(pFile,"%d,%s,%d,%d,%d,%.2f\n",id,descripcion,precio,idTipo,cuotas,precioCuotas);
										retorno = 0;
									}
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
