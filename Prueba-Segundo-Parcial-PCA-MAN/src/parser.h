
#ifndef PARSER_H_
#define PARSER_H_

/**
 * \fn int parser_participanteFromText(FILE*, LinkedList*)
 * \brief pasa los campos del archivo, del tipo "sring" a la estructura, a tipos de dato nativos
 *
 * \param pFile FILE*
 * \param pArrayListParticipante LinkedList*
 * \return int
 */
int parser_participanteFromText(FILE* pFile , LinkedList* pArrayListParticipante);

/**
 * \fn int parser_guardarTextoMapeado(FILE*, LinkedList*)
 * \brief pasa los datos de la la estructura guardada en la lista a un archivo
 *
 * \param pFile FILE*
 * \param pArrayListComputer LinkedList*
 * \return int
 */
int parser_guardarTextoFiltrado(FILE* pFile , LinkedList* pArrayListComputer);

#endif /* PARSER_H_ */
