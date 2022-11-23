
#ifndef CONTROLER_H_
#define CONTROLER_H_

/**
 * \fn int controller_cargarParticipantesDesdeTexto(char*, LinkedList*)
 * \brief Carga los datos de las computadoras desde el archivo.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListParticipante LinkedList*
 * \return int
 */
int controller_cargarParticipantesDesdeTexto(char* path , LinkedList* pArrayListParticipante);

/**
 * \fn int controller_listarParticipantes(LinkedList*)
 * \brief lista todos los datos
 *
 * \param pArrayListParticipante LinkedList*
 * \return int
 */
int controller_listarParticipantes(LinkedList* pArrayListParticipante);

/**
 * \fn int controller_guardarComoTexto(char*, LinkedList*)
 * \brief
 *
 * \param path char*
 * \param pArrayListParticipante LinkedList*
 * \return int
 */
int controller_guardarComoTexto(char* path , LinkedList* pArrayListParticipante);

#endif /* CONTROLER_H_ */
