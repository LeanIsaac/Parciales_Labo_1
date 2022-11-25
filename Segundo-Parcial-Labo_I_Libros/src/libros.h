/*
 * computadoras.h
 *
 *  Created on: 20 nov. 2022
 *      Author: Marec
 */

#ifndef LIBROS_H_
#define LIBROS_H_

typedef struct
{
	int id;
	char titulo[100];
	float importe;
	int idTipo;
	float importeConAumento;
}eLibros;

eLibros* libro_new();

eLibros* libro_newParametros(char* idStr, char* tituloStr, char* importeStr, char* idTipoStr);

void libro_delete(eLibros* this);

int libro_setId(eLibros* this,int id);

int libro_getId(eLibros* this, int* id);

int libro_setTitulo(eLibros* this,char* titulo);

int libro_getTitulo(eLibros* this,char* titulo);

int libro_setImporte(eLibros* this,float importe);

int libro_getImporte(eLibros* this,float* importe);

int libro_setIdTipo(eLibros* this,int idTipo);

int libro_getIdTipo(eLibros* this,int* idTipo);

void libro_printOne(eLibros* unLibro);

int libro_sortByImporte(void* pLibroUno , void* pLibroDos);

int libro_getImporteAumento(eLibros* this,float* importeAumento);

int libro_setImporteAumento(eLibros* this,float importeAumento);

int libro_aumentoImporte(void* pElement);

#endif /* LIBROS_H_ */
