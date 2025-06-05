#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#include "indice.h"

#define TRUE 1
#define FALSE 0
#define toUpper(X) (((X) >= 'a' && (X) <= 'z') ? (X) - 32 :(X))
#define toLower(X) ( ((X) >= 'a' && (X) <= 'z')? (X): (X)+32)
#define ES_LETRA(X) (( (X) >= 'a' && (X) <= 'z' || (X)>= 'A' && (X) <= 'Z'))
#define ES_NUMERO(X) ((X)>='0' && (X) <='9')
#define ES_LMIN(X) (( (X) >= 'a' && (X) <= 'z'))
#define TAM_MENU 40


int str_lenght(char * str);
int  str_cmp(char* a, char *b);
void strtoupper(char *str);
void eliminate_str(char *str, size_t i, size_t cant);
void returnDir(void * vec, void *el, size_t tam, size_t tamV);
int binarySearch (void *vec, void *target, size_t ce, size_t tam, int (*cmp) (void*, void*));

char elegir_opcion(const char m[][TAM_MENU], const char *txt, const char *msj);
char menu(const char m[][TAM_MENU], const char *txt);



#endif // GENERAL_H_INCLUDED
