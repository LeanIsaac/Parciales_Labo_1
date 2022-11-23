/*
 * computadoras.h
 *
 *  Created on: 20 nov. 2022
 *      Author: Marec
 */

#ifndef COMPUTADORAS_H_
#define COMPUTADORAS_H_

typedef struct
{
	int id;
	char descripcion[100];
	int precio;
	int idTipo;
	int cuotas;
	float precioCuotas;
}eComputer;

/**
 * \fn eComputer compu_new*()
 * \brief constructor
 *
 * \return eComputer*
 */
eComputer* compu_new();

/**
 * \fn eComputer compu_newParametros*(char*, char*, char*, char*, char*)
 * \brief constructor con parametros
 *
 * \param idStr char*
 * \param descripcionStr char*
 * \param precioStr char*
 * \param idTipoStr char*
 * \param cuotasStr char*
 * \return eComputer
 */
eComputer* compu_newParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr, char* cuotasStr);

/**
 * \fn void compu_delete(eComputer*)
 * \brief destructor
 *
 * \param this eComputer*
 */
void compu_delete(eComputer* this);

/**
 * \fn int compu_setId(eComputer*, int)
 * \brief setea el id por parmetro
 *
 * \param this eComputer*
 * \param id int
 * \return int
 */
int compu_setId(eComputer* this,int id);

/**
 * \fn int compu_getId(eComputer*, int*)
 * \brief obtengo el id
 *
 * \param this eComputer*
 * \param id *int
 * \return int
 */
int compu_getId(eComputer* this, int* id);

/**
 * \fn int compu_setDescripcion(eComputer*, char*)
 * \brief setea la descripcion
 *
 * \param this eComputer*
 * \param descripcion
 * \return int
 */
int compu_setDescripcion(eComputer* this,char* descripcion);

/**
 * \fn int compu_getDescripcion(eComputer*, char*)
 * \brief obtengo la descripcion
 *
 * \param this eComputer*
 * \param descripcion char*
 * \return int
 */
int compu_getDescripcion(eComputer* this,char* descripcion);

/**
 * \fn int compu_setPrecio(eComputer*, int)
 * \brief setea el precio
 *
 * \param this eComputer*
 * \param precio int
 * \return int
 */
int compu_setPrecio(eComputer* this,int precio);

/**
 * \fn int compu_getPrecio(eComputer*, int*)
 * \brief itobtengo el precio
 *
 * \param this eComputer*
 * \param precio int*
 * \return int
 */
int compu_getPrecio(eComputer* this,int* precio);

/**
 * \fn int compu_setIdTipo(eComputer*, int)
 * \brief seteo el idTipo
 *
 * \param this eComputer*
 * \param idTipo int
 * \return int
 */
int compu_setIdTipo(eComputer* this,int idTipo);

/**
 * \fn int compu_getIdTipo(eComputer*, int*)
 * \brief obtengo el idTipo
 *
 * \param this eComputer*
 * \param idTipo int*
 * \return int
 */
int compu_getIdTipo(eComputer* this,int* idTipo);

/**
 * \fn int compu_setCuotas(eComputer*, int)
 * \brief seteo las coutas
 *
 * \param this eComputer*
 * \param cuotas int
 * \return int
 */
int compu_setCuotas(eComputer* this,int cuotas);

/**
 * \fn int compu_getCuotas(eComputer*, int*)
 * \brief obtengo las cuotas
 *
 * \param this eComputer*
 * \param cuotas int*
 * \return int
 */
int compu_getCuotas(eComputer* this,int* cuotas);

/**
 * \fn void compu_printOne(eComputer*)
 * \brief muestra los datos de una computadora
 *
 * \param unacompu void
 */
void compu_printOne(eComputer* unacompu);

/**
 * \fn int compu_sortByCuotas(void*, void*)
 * \brief funcion criterio
 *
 * \param pCompuUno void*
 * \param pCompuDos void*
 * \return int
 */
int compu_sortByCuotas(void* pCompuUno , void* pCompuDos);

/**
 * \fn int compu_getPrecioCuotas(eComputer*, float*)
 * \brief obtengo el precio por cuota
 *
 * \param this eComputer*
 * \param precioCuotas float*
 * \return
 */
int compu_getPrecioCuotas(eComputer* this,float* precioCuotas);

/**
 * \fn int compu_setPrecioCuotas(eComputer*, float)
 * \brief seteo los precios por cuotas
 *
 * \param this eComputer*
 * \param precioCuotas float
 * \return int
 */
int compu_setPrecioCuotas(eComputer* this,float precioCuotas);

/**
 * \fn int compu_precioPorCuotas(void*)
 * \brief funcion criterio para mapear
 *
 * \param pElement void*
 * \return int
 */
int compu_precioPorCuotas(void* pElement);


#endif /* COMPUTADORAS_H_ */
