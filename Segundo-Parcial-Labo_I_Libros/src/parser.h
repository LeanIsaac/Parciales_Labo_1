
#ifndef PARSER_H_
#define PARSER_H_

/**
 * \fn int parser_LibroFromText(FILE*, LinkedList*)
 * \brief pasa los campos del archivo, del tipo "sring" a la estructura, a tipos de dato nativos
 *
 * \param pFile FILE*
 * \param pArrayListLibros LinkedList*
 * \return int
 */
int parser_libroFromText(FILE* pFile , LinkedList* pArrayListLibros);

/**
 * \fn int parser_guardarTextoMapeado(FILE*, LinkedList*)
 * \brief pasa los datos de la la estructura guardada en la lista a un archivo
 *
 * \param pFile FILE*
 * \param pArrayListLibros LinkedList*
 * \return int
 */
int parser_guardarTextoMapeado(FILE* pFile , LinkedList* pArrayListLibros);

/**
 * \fn int parser_guardarTexto(FILE*, LinkedList*)
 * \brief
 *
 * \param pFile
 * \param pArrayListLibros
 * \return
 */
int parser_guardarTexto(FILE* pFile , LinkedList* pArrayListLibros);

#endif /* PARSER_H_ */
