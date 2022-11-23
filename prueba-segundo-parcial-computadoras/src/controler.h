
#ifndef CONTROLER_H_
#define CONTROLER_H_

/**
 * \fn int controller_cargarJugadoresDesdeTexto(char*, LinkedList*)
 * \brief Carga los datos de las computadoras desde el archivo.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListComputer LinkedList*
 * \return int
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListComputer);

/**
 * \fn int controller_listarComputadoras(LinkedList*)
 * \brief lista todos los datos
 *
 * \param pArrayListComputer LinkedList*
 * \return int
 */
int controller_listarComputadoras(LinkedList* pArrayListComputer);

/**
 * \fn int controller_guardarComoTexto(char*, LinkedList*)
 * \brief
 *
 * \param path char*
 * \param pArrayListComputer LinkedList*
 * \return int
 */
int controller_guardarComoTexto(char* path , LinkedList* pArrayListComputer);

#endif /* CONTROLER_H_ */
