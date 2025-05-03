#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define CHAR_MAY(X) ((X) >= 'a' && (X) <= 'z' ? (X) - 32 :(X))
#define CHAR_MIN(X) ( (X) >= 'a' && (X) <= 'z'? (X): (X)+32

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


char MiTolower(char x);
char MiTouper(char x);
int ValidarDni(int n);
char * Normalizar(const char * cad);
int ValidarFecha(struct t_fecha);
char * ValidarApellyNom(const char * cad);
char * InsertarComa(const char *cad);
char * BorrarComas(const char *cad); //Desarrollar
char * InsertarComa(const char *cad);//Desarrollar
int ValidarSexo(char S);
int ValidarCat(char cat[10]);
int ValidarEstado(char est);
int validarFecha(t_fecha fecha);
int cantDias(int mes, int anio);
int anioBisiesto(int anio);


#endif // VALIDACION_H_INCLUDED
