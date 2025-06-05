#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "validacion.h"
#include "indice.h"

#define ARCH_SOCIOS "Archivos/socios.dat"


int main(){
    t_indice* pi = malloc(sizeof(t_indice));
    t_reg_indice regABM;

    t_fecha fProceso;
    printf("INGRESE FECHA DE PROCESO:");
    scanf("%d/%d/%d",&fProceso.dia, &fProceso.mes, &fProceso.anio);

    crearBinario(fProceso);
    indice_crear(pi);

    int flag;
    do{
        flag =indice_cargar(pi, "socios.dat");
    }while(!flag);
    for(int i = 0; i <pi->cantidad; i++){
        printf("DNI: %-8ld\tPOS:%-5i\n", pi->registro[i].dni, pi->registro[i].nro_reg);
    }

    const char opciones [][TAM_MENU] = {"ABMSLE",
                                        "Alta de Socio",
                                        "Baja de Socio",
                                        "Modificar Socio",
                                        "Buscar Socio",
                                        "Listar Socios Activos (por DNI)",
                                        "Salir"
                                        };

    char opc;
    long dniABM;

    do
    {
        opc=menu(opciones, "Menu Principal");
        switch (opc)
            {
                case 'A':
                   /* /// si el DNI es valido y no existe, darlo de alta en el sistema
                        printf("Ingresar DNI para el Alta:\n");
                        scanf("%ld", &dniABM);

                        if (ValidarDni(dniABM))
                            {
                                t_reg_indice regIdx;
                                regIdx.dni = dniABM;

                            if (indice_buscar(&pi, &regIdx))
                                {
                                    printf("El DNI ya existe en el archivo.\n");
                                }else
                                    {
                                        generarAlta(dniABM, &indice, ARCH_SOCIOS);  /// DNI validado y listo para dar de alta
                                    }
                            }else{
                                    printf("El DNI no es válido.\n");
                                 }*/
                    system("PAUSE");
                    break;

                case 'B':
                    ///si el DNI esta en el sistema cambiar el estado a B
                    system("PAUSE");
                    break;

                case 'M':
                    ///si el DNI existe en el sistema realizar la modificacion deseada
                    system("PAUSE");
                    break;

                case 'S':
                    ///si el DNI existe en el indice mostrar la informacion correspondiente
                    system("PAUSE");
                    break;

                case 'L':
                    ///Listar todos los socios ACTIVOS
                    system("PAUSE");
                    break;
            }
    }while(opc!='E');

    return 0;


}




