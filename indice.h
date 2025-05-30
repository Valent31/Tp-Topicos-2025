#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED
typedef struct{
    long dni;
    unsigned nro_reg;
}t_reg_indice;
typedef struct{
    t_reg_indice *r_indice;
}t_indice;
#include "general.h"
void indice_crear(t_indice *);
int indice_insertar(t_indice *, const t_reg_indice*);
int indice_eliminar(t_indice *, t_reg_indice *);
int indice_vacio(const t_indice*);
int indice_lleno(const t_indice *, unsigned tamDato);
int indice_buscar(const t_indice *, t_reg_indice * reg_indice);
int indice_cargar(t_indice *, const char *path);
void indice_vaciar(t_indice*);


#endif // INDICE_H_INCLUDED
