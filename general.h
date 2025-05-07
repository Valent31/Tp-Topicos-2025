#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED
#include <stddef.h>
#define TRUE 1
#define FALSE 0
#define toUpper(X) (((X) >= 'a' && (X) <= 'z') ? (X) - 32 :(X))
#define toLower(X) ( ((X) >= 'a' && (X) <= 'z')? (X): (X)+32)
#define ES_LETRA(X) (( (X) >= 'a' && (X) <= 'z' || (X)>= 'A' && (X) <= 'Z'))
#define ES_NUMERO(X) ((X)>='0' && (X) <='9')
#define ES_LMIN(X) (( (X) >= 'a' && (X) <= 'z'))
int str_lenght(char * str);
int  str_cmp(char* a, char *b);
void strtoupper(char *str);
void eliminate_str(char *str, size_t i, size_t cant);


#endif // GENERAL_H_INCLUDED
