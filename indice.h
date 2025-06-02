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
} t_indice;

void indice_crear(t_indice *);
int indice_insertar(t_indice *, const t_reg_indice*);
int indice_eliminar(t_indice *, t_reg_indice *);
int indice_vacio(const t_indice*);
int indice_lleno(const t_indice *, unsigned tamDato);
int indice_buscar(const t_indice *, t_reg_indice * reg_indice);
int indice_cargar(t_indice *, const char *path);
void indice_vaciar(t_indice*);
void aumentarCap(t_indice *pi);
/**
GENERICAS
*/

int compara_socio_indice(void* a,void* b);


#endif // INDICE_H_INCLUDED
