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
#include "controler.h"
#include "libros.h"
#include "UTN.h"
#include "parser.h"


eLibros* libro_new()
{
	eLibros* unLibro=NULL;
	unLibro = (eLibros*)malloc(sizeof(eLibros));

	return unLibro;
}

eLibros* libro_newParametros(char* idStr, char* tituloStr, char* importeStr, char* idTipoStr)
{
	eLibros* unLibro = libro_new();
	int flag=-1;

	if(unLibro != NULL && idStr != NULL && tituloStr != NULL && importeStr != NULL && idTipoStr != NULL)
	{
		if(libro_setId(unLibro, atoi(idStr))==0)
		{
			if(libro_setTitulo(unLibro, tituloStr)==0)
			{
				if(libro_setImporte(unLibro, atof(importeStr))==0)
				{
					if(libro_setIdTipo(unLibro, atoi(idTipoStr))==0)
					{
						flag = 0;
					}
				}
			}
		}
	}

	if(flag == -1)
	{
		libro_delete(unLibro);
		unLibro = NULL;
	}

	return unLibro;
}




void libro_delete(eLibros* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int libro_setId(eLibros* this,int id)
{
	int rto=-1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rto = 0;
	}

	return rto;
}

int libro_getId(eLibros* this, int* id)
{
	int rto=-1;

	if(this != NULL && id != NULL)
	{
		 *id = this->id;
		rto = 0;
	}


	return rto;
}

int libro_setTitulo(eLibros* this,char* titulo)
{
	int rto=-1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo, titulo);
		rto = 0;
	}

	return rto;
}

int libro_getTitulo(eLibros* this,char* titulo)
{
	int rto=-1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo, this->titulo);
		rto = 0;
	}

	return rto;
}

int libro_setImporte(eLibros* this,float importe)
{
	int rto=-1;

	if(this != NULL && importe > 0)
	{
		this->importe = importe;
		rto = 0;
	}

	return rto;
}

int libro_getImporte(eLibros* this,float* importe)
{
	int rto=-1;

	if(this != NULL && importe != NULL)
	{
		*importe = this->importe;
		rto = 0;
	}

	return rto;
}


int libro_setIdTipo(eLibros* this,int idTipo)
{
	int rto=-1;

	if(this != NULL && idTipo > 0)
	{
		this->idTipo = idTipo;
		rto = 0;
	}

	return rto;
}

int libro_getIdTipo(eLibros* this,int* idTipo)
{
	int rto=-1;

	if(this != NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;
		rto = 0;
	}

	return rto;
}



int libro_getImporteAumento(eLibros* this,float* importeAumento)
{
	int rto=-1;

	if(this != NULL && importeAumento != NULL)
	{
		*importeAumento = this->importeConAumento;
		rto = 0;
	}

	return rto;
}

int libro_setImporteAumento(eLibros* this,float importeAumento)
{
	int rto=-1;

	if(this != NULL && importeAumento > 0)
	{
		this->importeConAumento = importeAumento;
		rto = 0;
	}

	return rto;
}


void libro_printOne(eLibros* unLibro)
{
	int id;
	char titulo[100];
	float importe;
	int idTipo;
	char idTipoStr[100];

	libro_getId(unLibro, &id);
	libro_getTitulo(unLibro, titulo);
	libro_getImporte(unLibro, &importe);
	libro_getIdTipo(unLibro, &idTipo);

	if(idTipo == 1)
	{
		strcpy(idTipoStr, "PAPEL");
		printf("%4d  %-35s %12.2f  %-14s\n",id,titulo,importe,idTipoStr);
	}
	else
	{
		strcpy(idTipoStr, "EBOOK");
		printf("%4d  %-35s %12.2f  %-14s\n",id,titulo,importe,idTipoStr);
	}
}

int libro_sortByImporte(void* pLibroUno , void* pLibroDos)
{
	int retorno = -1;
	float importeLibroUno;
	float importeLibroDos;
	eLibros* libroUno = NULL;
	eLibros* libroDos = NULL;

	if(pLibroUno != NULL && pLibroDos != NULL)
	{
		libroUno = (eLibros*)pLibroUno;
		libroDos =  (eLibros*)pLibroDos;

		if(libroUno != NULL && libroDos != NULL)
		{
			libro_getImporte(libroUno, &importeLibroUno);
			libro_getImporte(libroDos, &importeLibroDos);

			if(importeLibroUno < importeLibroDos)
			{
				retorno = 0;
			}
			else
			{
				if(importeLibroUno > importeLibroDos)
				{
					retorno = 1;
				}
			}
		}
	}

	return retorno;

}


int libro_aumentoImporte(void* pElement)
{
	int retorno = -1;
	eLibros* unlibro=NULL;
	float importe;
	int idTipo;
	float resultado;

	if(pElement != NULL)
	{
		unlibro = (eLibros*)pElement;

		if(unlibro != NULL)
		{
			libro_getImporte(unlibro, &importe);
			libro_getIdTipo(unlibro, &idTipo);


			if(idTipo == 1)
			{
				resultado = (importe * 0.10) + importe;
			}
			else
			{
				resultado = (importe * 0.20) + importe;
			}


			if(libro_setImporteAumento(unlibro, resultado)==0)

			{
				retorno=0;
			}
		}
	}

	return retorno;
}

