#include "indice.h"
void indice_crear(t_indice * indice){
    indice = malloc(sizeof(t_indice)*100);
    if(!indice){
        printf("\nERROR AL CREAR INDICE...");
        return 0;
    }
}
int indice_lleno(const t_indice * pi, unsigned tamDato){

}


/*int sacar_ult_lista(t_lista * pl, t_info* pi)
{
    t_nodo pelim;
    t_nodo* puntero= (pl)->sig;
    if(!pl)
        return 0;
    while((pl)->sig)
    {
        pl=&(pl)->sig;
    }
    pelim=*pl;
    *pl=pelim->sig;
    pi=pelim->info;
    free(pelim);
    return 1;
}*/
