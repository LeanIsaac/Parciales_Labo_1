/*
 * UTN.c
 *
 *  Created on: 28 abr. 2022
 *      Author: equipo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"

///////////// MENU ///////////////////////////////////////////////

int menuGenericoInt( char opciones[] )
{
	int opcion;

	printf( "%s", opciones );

	opcion = getInt("\nOpcion >>> ");

	return opcion;
}


char menuGenericoChar( char opciones[] )
{
	char opcionChar;

	printf( "%s", opciones );

	utn_getChar(&opcionChar, "\nOpcion >>> ", "\nHubo un Error, Vuelva a intentar \n", "A", "z", 3);

	return opcionChar;
}
//////////////// CADENA DE CARACTERES ////////////////////////

int utn_getString(char cadena[], char mensaje[],char msjError[])
{
    int rto = -1;
    char aux[300];

    if( cadena != NULL && mensaje != NULL && msjError != NULL )
    {
        rto = 0;

        getString(aux, mensaje, 300);

        while(validar_Cadena(aux)==-1 || validaNoEspaciosContinuos(aux) != 0)
        {
        	getString(aux, msjError, 30);
        }
    }
    strcpy(cadena,aux);
    return rto;
}

// SOLO VALIDA NO PASAR EL LIMITE DE UN ARRAY DE CARACTERES
void getString(char palabra[],char mensaje[],int tamanio)
{
	char auxilar[1024];
	int cantidadLetras;

	printf("%s",mensaje);
	setbuf(stdin,NULL);
	gets(auxilar);

	cantidadLetras = strlen(auxilar);

	while(cantidadLetras > tamanio)
	{
		printf("%s",mensaje);
		setbuf(stdin,NULL);
		gets(auxilar);
	}
	strcpy(palabra,auxilar);
}


int validar_Cadena(char string[])
{
    int i=0;
    int rto=0;
    int j;

    j = strlen(string);

    while(i<j && rto == 0)
    {
        if(isalpha(string[i])!=0 || string[i] == ' ' || string[i] == '.'|| string[i] == '_')
        {
            i++;
        }
        else
        {
            rto = -1;
        }
    }
    return rto;
}

int validaNoEspaciosContinuos(char str[])
{
    int i, rto, espaciosContinuos=0;
    int len = strlen(str);

    for(i=0;i<len;i++)
    {
        if(str[i] == ' ' && str[i+1] == ' ')
        {
            espaciosContinuos = -1;
        }
    }
    if(espaciosContinuos == -1 || str[0] == ' ')
    {
        rto =-1;
    }
    else
    {
        rto=0;
    }
    return rto;
}



/////////// SHORT / INT //////////////////////////////////////////////////////////////////////

int utn_getShort(short* pResultado,char* mensaje, char* msjError, int min, int max, int tries)
{
	short num;
	int rto;

	while( tries > 0)
	{
		num = getInt(mensaje);
		if(num<=max && num>=min)
		{
			break;
		}
		tries--;
		printf("%s",msjError);
	}

	if(tries == 0)
	{
		rto= -1;
	}
	else
	{
		rto=0;
		*pResultado = num;
	}
	return rto;
}
/////////// ENTERO / INT //////////////////////////////////////////////////////////////////////

int utn_getInt(int* pResultado,char* mensaje, char* msjError, int min, int max, int tries)
{

	int num;
	int rto;

	while( tries > 0){
		num = getInt(mensaje);
		if(num<=max && num>=min){
			break;
		}
		tries--;
		printf(msjError);
	}

	if(tries == 0)
	{
		rto= -1;
	}
	else
	{
		rto=0;
		*pResultado = num;
	}
	return rto;
}

//FUNCION GET INT GENERICA, SIN RANGO Y ALGUNOS CRITERIOS DE MAS
int getInt(char mensaje[])
{
	int retorno = -1;
	int esNumero;
	char auxiliar[30];

	getString(auxiliar,mensaje,30); // donde se va a guardar, ingresa un numero,limite de la cadena

	while(esNumerica(auxiliar) < 1)
	{
	  getString(auxiliar,mensaje,30);
	}

	esNumero = atoi(auxiliar);

	retorno = esNumero;

 return retorno;
}



int esNumerica(char auxiliar[])
{
	int i;
	int largo;
	int retorno =-1;

	if(auxiliar != NULL)
	{
		retorno = 1;

		largo = strlen(auxiliar);

		for(i=0;i<largo;i++)
		{
			if(isdigit(auxiliar[i])==0)
			{
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}
/////////////////////////////////// CARACTER //////////////////////////////

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char min, char max, int reintentos)
{
	int rto=-1;
	char bufferChar;

	if( pResultado !=NULL && mensaje !=NULL && mensajeError != NULL && min <= max && reintentos >= 0 )
	{
		do{
			printf("%s",mensaje);
			setbuf(stdin, NULL);
			scanf("%c",&bufferChar);

			if( bufferChar >= min && bufferChar <= max )
			{
				*pResultado = bufferChar; // guardo el puntero a resultado
				rto=0;
				break;
			}
			else { //salio mal
				printf("%s", mensajeError);
				reintentos--;
			}
		}while( reintentos >= 0 );
	}
	return rto;
}

//////////// ALFANUMERICO ////////////////////////////////

int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0'){
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && ( str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        return 0;
        i++;
    }
    return 1;
}

/////////// FLOAT / FLOTANTE //////////////////////////////////////

int utn_getFloat(float* pResultado,char* mensaje, char* msjError, int min, int max, int tries)
{

	float num;
	int rto;

	while( tries > 0)
	{
		num  = getFloat(mensaje);
		if( num <= max && num >= min )
		{
			break;
		}
		tries--;
		printf(msjError);
	}

	if(tries == 0)
	{
		rto= -1;
	}
	else
	{
		rto=0;
		*pResultado = num;
	}
	return rto;
}


//FUNCION GET FLOAT GENERICA
float getFloat(char mensaje[])//que sea un numero
{
	float retorno = -1;
	float esNumero;
	char auxiliar[30];

	getString(auxiliar, mensaje, 30);

	while(Validate_OnlyNumberFloat(auxiliar) < 1)
	{
		getString(auxiliar, mensaje, 30);
	}

	esNumero = atof(auxiliar);

	retorno = esNumero;

 return retorno;
}

int Validate_OnlyNumberFloat(char* pData)
{
	int countSigno = 0;
	int rto = 1;

	if( strlen(pData) > 0 )
	{
		for(int i=0; i < strlen(pData); i++)
		{
			if(pData[i] == '.' || pData[i] == ',')
			{
				countSigno++;
			}
			else
			{
				if (isdigit(pData[i] ) == 0)
				{
					if ( i == 0 )
					{
						if( pData[0] != '-' )
						{
							rto = 0;
							break;
						}
					}
					else
					{
						rto = 0;
						break;
					}
				}
			}
		}

		if( countSigno > 1 )
		{
			rto = 0;
		}
	}
	else
	{
		rto =0;
	}
	return rto;
}

///////// PRESIONAR UNA TECLA PARA CONTINUAR ///////////////
void pressKey(void)
{
	char tecla;

	printf("Presione [Enter] para continuar...\n\n>>>> ");
    while ((tecla = getchar()) != '\n' && tecla != EOF);
}
