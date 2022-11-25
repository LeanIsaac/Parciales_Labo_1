
#ifndef CONTROLER_H_
#define CONTROLER_H_

/**
 * \fn int controller_cargarLibrosDesdeTexto(char*, LinkedList*)
 * \brief
 *
 * \param path
 * \param pArrayListLibros
 * \return
 */
int controller_cargarLibrosDesdeTexto(char* path , LinkedList* pArrayListLibros);

/**
 * \fn int controller_listarLibros(LinkedList*)
 * \brief
 *
 * \param pArrayListLibro
 * \return
 */
int controller_listarLibros(LinkedList* pArrayListLibro);

/**
 * \fn int controller_guardarComoTexto(char*, LinkedList*)
 * \brief
 *
 * \param path char*
 * \param pArrayListLibros LinkedList*
 * \return int
 */
int controller_guardarComoTextoMapeado(char* path , LinkedList* pArrayListLibros);

/**
 * \fn int controller_guardarComoTexto(char*, LinkedList*)
 * \brief
 *
 * \param path
 * \param pArrayListLibros
 * \return
 */
int controller_guardarComoTexto(char* path , LinkedList* pArrayListLibros);

#endif /* CONTROLER_H_ */
