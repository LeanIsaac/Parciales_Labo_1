
#ifndef PARSER_H_
#define PARSER_H_

/**
 * \fn int parser_JugadorFromText(FILE*, LinkedList*)
 *
 * \param pFile FILE*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/**
 * \fn int parser_JugadorFromBinary(FILE*, LinkedList*)
 *
 * \param pFile FILE*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/**
 * \fn int parser_SeleccionFromText(FILE*, LinkedList*)
 *
 * \param pFile FILE*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);

/**
 * \fn int parser_guardarJugadorModoTexto(FILE*, LinkedList*)
 *
 * \param pFile FILE*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_guardarJugadorModoTexto(FILE* pFile ,LinkedList* pArrayListJugador);

/**
 * \fn int parser_guardarSeleccionModoTexto(FILE*, LinkedList*)
 *
 * \param pFile FILE*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 */
int parser_guardarSeleccionModoTexto(FILE* pFile, LinkedList* pArrayListSeleccion);

int parser_guardarJugadoresModoBinario(FILE* pFile, LinkedList* pArrayListJugador);

#endif /* PARSER_H_ */
