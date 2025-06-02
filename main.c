#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "validacion.h"
#include "indice.h"


int main(){
    t_indice* pi;
 //   crearBinario();
    indice_crear(pi);
    int flag;
    do{
        flag =indice_cargar(pi, "socios.dat");
    }while(!flag);
    for(int i = 0; i <pi->cantidad; i++){
        printf("DNI: %-8ld\tPOS:%-5i\n", pi->registro[i].dni, pi->registro[i].nro_reg);
    }
}




