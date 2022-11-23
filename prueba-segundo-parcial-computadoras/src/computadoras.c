/*
 * computadoras.c
 *
 *  Created on: 20 nov. 2022
 *      Author: Marec
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "computadoras.h"
#include "UTN.h"
#include "parser.h"


eComputer* compu_new()
{
	eComputer* unaCompu=NULL;
	unaCompu = (eComputer*)malloc(sizeof(eComputer));

	return unaCompu;
}

eComputer* compu_newParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr, char* cuotasStr)
{
	eComputer* unaCompu = NULL;
	unaCompu = compu_new();
	int flag = -1;

	if(unaCompu != NULL &&  idStr != NULL && descripcionStr != NULL &&  precioStr != NULL && idTipoStr != NULL && cuotasStr != NULL)
	{
		if(compu_setId(unaCompu, atoi(idStr))==0)
		{
			if(compu_setDescripcion(unaCompu, descripcionStr)==0)
			{
				if(compu_setPrecio(unaCompu, atof(precioStr))==0)
				{
					if(compu_setIdTipo(unaCompu, atoi(idTipoStr))==0)
					{
						if(compu_setCuotas(unaCompu, atoi(cuotasStr))==0)
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
		compu_delete(unaCompu);
		unaCompu = NULL;
	}

	return unaCompu;
}

void compu_delete(eComputer* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int compu_setId(eComputer* this,int id)
{
	int rto=-1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rto = 0;
	}

	return rto;
}

int compu_getId(eComputer* this, int* id)
{
	int rto=-1;

	if(this != NULL && id != NULL)
	{
		 *id = this->id;
		rto = 0;
	}


	return rto;
}

int compu_setDescripcion(eComputer* this,char* descripcion)
{
	int rto=-1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion, descripcion);
		rto = 0;
	}

	return rto;
}

int compu_getDescripcion(eComputer* this,char* descripcion)
{
	int rto=-1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion, this->descripcion);
		rto = 0;
	}

	return rto;
}

int compu_setPrecio(eComputer* this,int precio)
{
	int rto=-1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		rto = 0;
	}

	return rto;
}

int compu_getPrecio(eComputer* this,int* precio)
{
	int rto=-1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		rto = 0;
	}

	return rto;
}


int compu_setIdTipo(eComputer* this,int idTipo)
{
	int rto=-1;

	if(this != NULL && idTipo > 0)
	{
		this->idTipo = idTipo;
		rto = 0;
	}

	return rto;
}

int compu_getIdTipo(eComputer* this,int* idTipo)
{
	int rto=-1;

	if(this != NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;
		rto = 0;
	}

	return rto;
}


int compu_setCuotas(eComputer* this,int cuotas)
{
	int rto=-1;

	if(this != NULL && cuotas > 0)
	{
		this->cuotas = cuotas;
		rto = 0;
	}

	return rto;
}

int compu_getCuotas(eComputer* this,int* cuotas)
{
	int rto=-1;

	if(this != NULL && cuotas != NULL)
	{
		*cuotas = this->cuotas;
		rto = 0;
	}

	return rto;
}

int compu_getPrecioCuotas(eComputer* this,float* precioCuotas)
{
	int rto=-1;

	if(this != NULL && precioCuotas != NULL)
	{
		*precioCuotas = this->precioCuotas;
		rto = 0;
	}

	return rto;
}

int compu_setPrecioCuotas(eComputer* this,float precioCuotas)
{
	int rto=-1;

	if(this != NULL && precioCuotas > 0)
	{
		this->precioCuotas = precioCuotas;
		rto = 0;
	}

	return rto;
}

void compu_printOne(eComputer* unacompu)
{
	int id;
	char descripcion[100];
	int precio;
	int idTipo;
	int cuotas;
	char idTipoStr[100];

	compu_getId(unacompu, &id);
	compu_getDescripcion(unacompu, descripcion);
	compu_getPrecio(unacompu, &precio);
	compu_getIdTipo(unacompu, &idTipo);
	compu_getCuotas(unacompu, &cuotas);

	if(idTipo == 1)
	{
		strcpy(idTipoStr, "DESKTOP");
		printf("%4d  %-102s %12d  %-12s %4d\n",id,descripcion,precio,idTipoStr,cuotas);
	}
	else
	{
		strcpy(idTipoStr, "LAPTOP");
		printf("%4d  %-102s %12d  %-12s %4d\n",id,descripcion,precio,idTipoStr,cuotas);
	}
}

int compu_sortByCuotas(void* pCompuUno , void* pCompuDos)
{
	int retorno = -1;
	int cuotaCompuUno;
	int cuotaCompuDos;
	eComputer* compuUno = NULL;
	eComputer* compuDos = NULL;

	if(pCompuUno != NULL && pCompuDos != NULL)
	{
		compuUno = (eComputer*)pCompuUno;
		compuDos =  (eComputer*)pCompuDos;

		if(compuUno != NULL && compuDos != NULL)
		{
			compu_getCuotas(compuUno, &cuotaCompuUno);
			compu_getCuotas(compuDos, &cuotaCompuDos);

			if(cuotaCompuUno < cuotaCompuDos)
			{
				retorno = 0;
			}
			else
			{
				if(cuotaCompuUno > cuotaCompuDos)
				{
					retorno = 1;
				}
			}
		}
	}

	return retorno;

}

int compu_precioPorCuotas(void* pElement)
{
	int retorno = -1;
	eComputer* unaCompu=NULL;
	int cuotas, precio;
	float resultado;

	if(pElement != NULL)
	{
		unaCompu = (eComputer*)pElement;

		if(unaCompu != NULL)
		{
			compu_getCuotas(unaCompu, &cuotas);
			compu_getPrecio(unaCompu, &precio);

			resultado = (float) precio / cuotas;

			if(compu_setPrecioCuotas(unaCompu, resultado)==0)
			{
				retorno=0;
			}
		}
	}



	return retorno;
}

