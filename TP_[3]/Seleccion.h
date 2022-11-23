#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

/**
 * \fn Seleccion selec_new*()
 * \brief contructor
 *
 * \return Seleccion*
 */
Seleccion* selec_new();

/**
 * \fn Seleccion selec_newParametros*(char*, char*, char*, char*)
 * \brief contructor parametrizado
 *
 * \param idStr char*
 * \param paisStr char*
 * \param confederacionStr char*
 * \param convocadosStr char*
 * \return int
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/**
 * \fn void selec_delete(Seleccion*)
 * \brief destructor
 *
 * \param this Seleccion
 */
void selec_delete(Seleccion* this);

/**
 * \fn int selec_getId(Seleccion*, int*)
 * \brief obtiene un id
 *
 * \param this Seleccion*
 * \param id int*
 * \return int
 */
int selec_getId(Seleccion* this,int* id);

/**
 * \fn int selec_getPais(Seleccion*, char*)
 * \brief obtiene un pais
 *
 * \param this Seleccion*
 * \param pais char*
 * \return int
 */
int selec_getPais(Seleccion* this,char* pais);

/**
 * \fn int selec_getConfederacion(Seleccion*, char*)
 * \brief obtiene una confederacion
 *
 * \param this Seleccion*
 * \param confederacion char*
 * \return int
 */
int selec_getConfederacion(Seleccion* this,char* confederacion);

/**
 * \fn int selec_setConvocados(Seleccion*, int)
 * \brief setea los convocados
 *
 * \param this Seleccion*
 * \param convocados int
 * \return int
 */
int selec_setConvocados(Seleccion* this,int convocados);

/**
 * \fn int selec_getConvocados(Seleccion*, int*)
 * \brief obtiene los convocados
 *
 * \param this Seleccion*
 * \param convocados int*
 * \return int
 */
int selec_getConvocados(Seleccion* this,int* convocados);

/**
 * \fn void selec_printOne(Seleccion*)
 * \brief muestra una seleccion
 *
 * \param unaSeleccion Seleccion
 */
void selec_printOne(Seleccion* unaSeleccion);

/**
 * \fn int selec_buscarPorId(LinkedList*)
 * \brief pide un id y retorna el indice en el que se encuentra
 *
 * \param pArrayListSeleccion LindedList*
 * \return int
 */
int selec_buscarPorId(LinkedList* pArrayListSeleccion);


/**
 * \fn int selec_ordenarPorConfederacion(void*, void*)
 * \brief ordena por confederacion
 *
 * \param pSeleccionUno void*
 * \param pSeleccionDos void*
 * \return int
 */
int selec_ordenarPorConfederacion(void* pSeleccionUno , void* pSeleccionDos);

/**
 * \fn int selec_validarConfederaciones(char*)
 * \brief valida las confederaciones
 *
 * \param strPosicion char*
 * \return int
 */
int selec_validarConfederaciones(char* strPosicion);

#endif // selec_H_INCLUDED
