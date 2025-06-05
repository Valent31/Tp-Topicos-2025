#include "general.h"
int str_lenght(char *str){
    int i = 0;
    while(*str != '\0'){
        i++;
        str++;
    }
    return i;
}
int  str_cmp(char* a, char *b){
    int val = 0;
    while(*a && *b){
        if(*a==*b){
            a++;b++;
        }
        else{
            val = a - b;
            return val;
        }
    }
    val = *(a) - *(b);
    return val;
}
void strtoupper(char *str){
    while(*str){
        *(str) = toUpper(*str);
        str++;
    }
}
void eliminate_str(char *str, size_t i, size_t cant){
    int tam = str_lenght(str);
    if(tam < i+ cant || cant == 0 || tam== 0){
        return;
    }
    int cantF= tam-i-cant+1;
    memmove(str+i,str+i+cant,cantF);
}
int binarySearch (void *vec, void *target, size_t ce, size_t tam, int (*cmp) (void*, void*)){
    int low=0, high=ce-1, comp_result, mid;

    while(low <= high){
        mid = (low+high)/2;

        comp_result = cmp(target, vec + mid * tam);

        if(comp_result == 0){
            return mid;
        }

        else if(comp_result < 0){
            high  = mid - 1;
        }

        else{
            low = mid + 1;
        }
    }
    return -1;
}

/**********************************************************
//               FUNCIONES MENU                           *
/**********************************************************/

char menu(const char m[][TAM_MENU], const char *txt)
{
    char opcion;
    opcion = elegir_opcion(m, txt, "Elegir opcion: ");

    while(!strchr(m[0], opcion))
        opcion = elegir_opcion(m, txt, "Opcion erronea. Elegir nuevamente: ");

    return opcion;
}

char elegir_opcion(const char m[][TAM_MENU], const char *txt, const char *msj)
{
    char opcion;
    int i;

    system("CLS");
    printf("\n %s \n", txt);

    for ( i=1 ; i <= strlen(m[0]) ; i++)
        printf("\n %c - %s", m[0][i-1], m[i]);

    printf("\n\n%s: ", msj);
    fflush(stdin);
    scanf(" %c", &opcion);

    return toupper(opcion);
}

/**********************************************************
//               FUNCIONES ABM                            *
/**********************************************************/

void generarAlta(long dniABM, t_indice *pi, FILE *pf)
{

}
