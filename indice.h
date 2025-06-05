#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "validacion.h"
#include "general.h"
typedef struct{
    long dni;
    unsigned nro_reg;
}t_reg_indice;

typedef struct {
    t_reg_indice *registro;    // puntero genérico a los datos (tipo void)
    unsigned cantidad;  // cantidad actual de registros
    unsigned capacidad; // cantidad máxima posible antes de realloc
    unsigned tamElem;   // tamaño de cada elemento
}t_indice;

void indice_crear(t_indice *indice);
int indice_eliminar (t_indice* pi, t_reg_indice* preg);
int indice_vacio(const t_indice*);
int indice_lleno(const t_indice * pi);
int indice_insertar(t_indice* pi, t_reg_indice* preg);
int indice_cargar(t_indice *, const char *path);
int indice_buscar (const t_indice* pi, t_reg_indice* preg);
void indice_vaciar(t_indice*);
void aumentarCap(t_indice *pi);
/**
GENERICAS
*/

int compara_socio_indice(const void* a, const void* b);
void Bubble_Sort_Gen (void *v, size_t ce, size_t tam, int (*cmp)(const void*,const void*));
void IntercambioDinamicoGenerico (void *a, void *b, size_t tam);

void generarAlta(long dniABM, t_indice *pi, FILE *pf);


#endif // INDICE_H_INCLUDED
