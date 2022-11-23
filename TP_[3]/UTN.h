/*
 * UTN.h
 *
 *  Created on: 28 abr. 2022
 *      Author: equipo
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * @brief Funcion menuGenerico
 *
 * @param opciones ingresamos las opciones de nuentro menu
 * @return retorna un entero, de la opcion elejida
 */
int menuGenerico( char opciones[]  );

/**
 * @fn int utn_getShort(short*, char*, char*, int, int, int)
 * @brief funcion short
 *
 * @param pResultado short
 * @param mensaje char*
 * @param msjError char*
 * @param min int
 * @param max int
 * @param tries int
 * @return int
 */
int utn_getShort(short* pResultado,char* mensaje, char* msjError, int min, int max, int tries);

/**
 * @fn int utn_getInt(int*, char*, char*, int, int, int)
 * @brief peide el ingrese de un numero y lo valida
 *
 * @param pResultado float
 * @param mensaje char*
 * @param msjError char*
 * @param min int
 * @param max int
 * @param tries int
 * @return int
 */
int utn_getInt(int* pResultado,char* mensaje, char* msjError, int min, int max, int tries);


/**
 * \fn void getString(char[], char[], int)
 * \brief
 *
 * \param palabra char
 * \param mensaje char
 * \param tamanio int
 */
void getString(char palabra[],char mensaje[],int tamanio);

/**
 * @fn int getInt(char[])
 * @brief getter Int Generico, sin muchos citerios de validacion (SOLO QUE NO SEA LETRA)
 *
 * @param mensaje char[]
 * @return int
 */
int getInt(char mensaje[]);

/**
 * @fn int esNumerica(char[])
 * @brief Valida que lo ingresado mediante cadena de caracteres sea un numero
 *
 * @param auxiliar char[]
 * @return int
 */
int esNumerica(char auxiliar[]);

/**
 * @brief Solicita un caracter  al usuario, luego de verificarlo devuelve el resultado
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mensaje de Error a ser mostrado
 * @param minimo Es la letra maximo a ser aceptado
 * @param maximo Es la letra minimo a ser aceptado
 * @return Retorna 0 si se obtuvo el caracter y -1 si no
 */
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char min, char max, int reintentos);

/**
 * @fn int validar_Cadena(char[])
 * @brief Valida que no sea una cadena e caracteres, y no un numero
 *
 * @param string char[]
 * @return int
 */
int validar_Cadena(char string[]);

/**
 * @fn int utn_getString(char[], char[], char[])
 * @brief Pide el ingreso de una cadena e caracteres con criterios
 *
 * @param cadena char[]
 * @param mensaje char[]
 * @param msjError char[]
 * @return int
 */
int utn_getString(char cadena[], char mensaje[],char msjError[]);

/**
 * @fn int utn_getFloat(float*, char*, char*, int, int, int)
 * @brief Pide el ingrese de un flotante, y valida criterios segun se le ordene por parametros
 *
 * @param pResultado float*
 * @param mensaje char*
 * @param msjError char*
 * @param min int
 * @param max int
 * @param tries int
 * @return Float
 */
int utn_getFloat(float* pResultado,char* mensaje, char* msjError, int min, int max, int tries);

/**
 * @fn float getFloat(char[])
 * @brief Getter float Generico - Valida que no lo ingresado sea un numero y no sea negativo
 *
 * @param mensaje char[]
 * @return Float
 */
float getFloat(char mensaje[]);

/**
 * @fn int Validate_OnlyNumberFloat(char*)
 * @brief valida que solo sea numeros Flotantes
 *
 * @param pData char*
 * @return int
 */
int Validate_OnlyNumberFloat(char* pData);

/**
 * @fn void pressKey(void)
 * @brief hasta que no se ingrese una tecla el programa no sigue
 *
 */
void pressKey(void);


//int esAlfaNumerico(char str[]);


#endif /* UTN_H_ */
