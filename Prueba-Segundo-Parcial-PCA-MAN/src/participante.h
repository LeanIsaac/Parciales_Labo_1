/*
 * participante.h
 *
 *  Created on: 22 nov. 2022
 *      Author: Marec
 */

#ifndef PARTICIPANTE_H_
#define PARTICIPANTE_H_

#define MAX_CHAR 1024

typedef struct
{
	int id;
	char nombre[MAX_CHAR];
	int edad;
	int idDificultad;
	int score;

}eParticipante;

eParticipante* part_new(void);
eParticipante* part_newParametros(char* idStr, char* nombreStr, char* edadStr, char* idDificultadStr, char* scoreStr);
void part_delete(eParticipante* this);
int part_setId(eParticipante* this, int id);
int part_getId(eParticipante* this, int* id);
int part_setNombre(eParticipante* this, char* nombre);
int part_getNombre(eParticipante* this, char* nombre);
int part_setEdad(eParticipante* this, int edad);
int part_getEdad(eParticipante* this, int* edad);
int part_setIdDificultad(eParticipante* this, int idDificultad);
int part_getIdDificultad(eParticipante* this, int* idDificultad);
int part_setScore(eParticipante* this, int score);
int part_getScore(eParticipante* this, int* score);
void part_printOne(eParticipante* unParticipante);
int part_sortByName(void* pNombreUno, void* pNombreDos);
int part_filterDificultadUno(void* pElement);
int part_filterDificultadDos(void* pElement);
int part_filterDificultadTres(void* pElement);

#endif /* PARTICIPANTE_H_ */
