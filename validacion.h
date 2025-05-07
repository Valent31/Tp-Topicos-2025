#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include "general.h"
#define TRUE 1
#define FALSE 0
#define toUpper(X) (((X) >= 'a' && (X) <= 'z') ? (X) - 32 :(X))
#define toLower(X) ( ((X) >= 'a' && (X) <= 'z')? (X): (X)+32)
#define ES_LETRA(X) (( (X) >= 'a' && (X) <= 'z' || (X)>= 'A' && (X) <= 'Z'))
#define ES_NUMERO(X) ((X)>='0' && (X) <='9')
#define ES_LMIN(X) (( (X) >= 'a' && (X) <= 'z'))
 typedef struct{
    int dia;
    int mes;
    int anio;
 }t_fecha;

 typedef struct {
    long DNI;
    char ApellYNom[60];
    t_fecha FechNacimiento;
    char sex;
    t_fecha FechAfil;
    char Cat[10];
    t_fecha FechUltCuota;
    char estado;
 }t_socios;


/*char MiTolower(char x);   USAR CHAR_MAY(X)
 char MiTouper(char x);    USAR CHAR_MIN(X)*/
int ValidarDni(int n);
void eliminate_tab(char *str);
void capitalize_str(char * str);
int eliminate_spaces(char *str);
void check(char *str, int c);
char * ValidarNyA(char * cad, int max);
int ValidarFecha(struct t_fecha);
int cantDias(int mes, int anio);
int anioBisiesto(int anio);
int ValidarSexo(char S);
int ValidarCat(char cat[10]);
int ValidarEstado(char est);


#endif // VALIDACION_H_INCLUDED
