#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

/**
 * \fn Jugador jug_new*()
 * \brief constructor
 *
 * \return Jugador*
 */
Jugador* jug_new();

/**
 * \fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
 * \brief  constructor parametrizados
 *
 * \param idStr char*
 * \param nombreCompletoStr char*
 * \param edadStr char*
 * \param posicionStr char*
 * \param nacionalidadStr char*
 * \param idSeleccionStr char*
 * \return Jugador*
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);

/**
 * \fn void jug_delete(Jugador*)
 * \brief Destructor
 *
 * \param this Jugador*
 */
void jug_delete(Jugador* this);

/**
 * \fn int jug_setId(Jugador*, int)
 * \brief setea el id
 *
 * \param this Jugador*
 * \param id int
 * \return int
 */
int jug_setId(Jugador* this,int id);

/**
 * \fn int jug_getId(Jugador*, int*)
 * \brief obtiene el id
 *
 * \param this Jugador*
 * \param id int*
 * \return int
 */
int jug_getId(Jugador* this,int* id);

/**
 * \fn int jug_setNombreCompleto(Jugador*, char*)
 * \brief setea el nombre del Jugador
 *
 * \param this Jugador*
 * \param nombreCompleto char*
 * \return int
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/**
 * \fn int jug_getNombreCompleto(Jugador*, char*)
 * \brief  Obtiene el nombre del jugador
 *
 * \param this Jugador*
 * \param nombreCompleto char*
 * \return int
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/**
 * \fn int jug_setPosicion(Jugador*, char*)
 * \brief setea la posiciom
 *
 * \param this 	Jugador
 * \param posicion char*
 * \return int
 */
int jug_setPosicion(Jugador* this,char* posicion);

/**
 * \fn int jug_getPosicion(Jugador*, char*)
 * \brief obtetiene la posicion
 *
 * \param this Jugador*
 * \param posicion char*
 * \return int
 */
int jug_getPosicion(Jugador* this,char* posicion);

/**
 * \fn int jug_setNacionalidad(Jugador*, char*)
 * \brief  setea la nacionalidad
 *
 * \param this Jugador*
 * \param nacionalidad char*
 * \return int
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/**
 * \fn int jug_getNacionalidad(Jugador*, char*)
 * \brief obtiene la nacionalidad
 *
 * \param this Jugador*
 * \param nacionalidad char*
 * \return int
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/**
 * \fn int jug_setEdad(Jugador*, int)
 * \brief setea la eda
 *
 * \param this Jugador*
 * \param edad int
 * \return int
 */
int jug_setEdad(Jugador* this,int edad);

/**
 * \fn int jug_getEdad(Jugador*, int*)
 * \brief obtiene la edad
 *
 * \param this Jugador*
 * \param edad int*
 * \return int
 */
int jug_getEdad(Jugador* this,int* edad);

/**
 * \fn int jug_setIdSeleccion(Jugador*, int)
 * \brief  setea el IdSeleccion
 *
 * \param this Jugador*
 * \param idSeleccion int
 * \return int
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/**
 * \fn int jug_getSIdSeleccion(Jugador*, int*)
 * \brief obtiene el idSeleccion
 *
 * \param this Jugador*
 * \param idSeleccion int*
 * \return int
 */
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

/**
 * \fn void jug_printOne(Jugador*)
 * \brief muestra un jugador
 *
 * \param unJugador Jugador*
 */
void jug_printOne(Jugador* unJugador);

/**
 * \fn void jug_leerId(char*)
 * \brief Lee un ID
 *
 * \param auxId char*
 */
void jug_leerId(char* auxId);

/**
 * \fn int jug_alta(LinkedList*)
 * \brief agrega un jugador
 *
 * \param pArrayListJugador Jugador*
 * \return int
 */
int jug_alta(LinkedList* pArrayListJugador);

/**
 * \fn int jug_buscarPorId(LinkedList*)
 * \brief pide un id y retorna el indice en el que se encuentra
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int jug_buscarPorId(LinkedList* pArrayListJugador);

/**
 * \fn int jug_modificar(LinkedList*)
 * \brief modifica los campos de un jugador
 *
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int jug_modificar(LinkedList* pArrayListJugador);


void menuPrincipal(void); ////////////	/MOVER

/**
 * \fn int jug_baja(LinkedList*)
 * \brief da de baja un jugador
 *
 * \param pArrayListJugador LinkedList*
 * \return INT
 */
int jug_baja(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
/**
 * \fn void jug_mostrarPosiciones(void)
 * \brief muestra las posiciones disponibles para elegir
 *
 */
void jug_mostrarPosiciones(void);

/**
 * \fn int jug_validarPosiciones(char*)
 * \brief
 *
 * \param strPosicion
 * \return
 */
int jug_validarPosiciones(char* strPosicion);


/**
 * \fn int jug_ordenarPorNacionalidad(void*, void*)
 * \brief ordena por Nacionalidad
 *
 * \param pJugadorUno void*
 * \param pJugadorDos void*
 * \return int
 */
int jug_ordenarPorNacionalidad(void* pJugadorUno , void* pJugadorDos);


/**
 * \fn int jug_ordenarPorNombre(void*, void*)
 * \brief ordena por nombre
 *
 * \param pJugadorUno void*
 * \param pJugadorDos void*
 * \return int
 */
int jug_ordenarPorNombre(void* pJugadorUno , void* pJugadorDos);


/**
 * \fn int jug_ordenarPorEdad(void*, void*)
 * \brief ordena por edad
 *
 * \param pJugadorUno void*
 * \param pJugadorDos void*
 * \return int
 */
int jug_ordenarPorEdad(void* pJugadorUno , void* pJugadorDos);

#endif // jug_H_INCLUDED
