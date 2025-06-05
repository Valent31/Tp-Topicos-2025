#include "indice.h"

void indice_crear(t_indice * indice)
{
    indice->registro = malloc(sizeof(t_reg_indice)*100);
    if(!indice)
    {
        printf("\nERROR AL CREAR INDICE...");
        return;
    }
    indice->cantidad = 0;
    indice->capacidad = 100;
    indice->tamElem = sizeof(t_reg_indice);
}

int indice_lleno(const t_indice * pi)
{
    return pi->cantidad==pi->capacidad;
}

void indice_vaciar(t_indice* pi)
{
    free(pi);
    pi->registro=NULL;
    pi->capacidad=0;
    pi->cantidad=0;
    pi->tamElem=0;
}
int indice_cargar (t_indice* pi, const char* path)
{
    FILE * arch;
    t_socio socio;
    int i = 0;
    arch = fopen(path, "rb");
    if(!arch)
    {
        printf("\nERROR AL LEER EL ARCHIVO...");
        return 0;
    }
    fread(&socio, sizeof(t_socio), 1, arch );
    while(!feof(arch))
    {
        if(i>=pi->capacidad)
        {
            aumentarCap(pi);
        }
        pi->registro[i].dni = socio.DNI;
        pi->registro[i].nro_reg = i;
        i++;
        pi->cantidad++;
        fread(&socio, sizeof(t_socio), 1, arch);
    }

    Bubble_Sort_Gen(pi->registro, pi->cantidad,sizeof(t_reg_indice), compara_socio_indice);
    fclose(arch);
    return 1;
}
void aumentarCap(t_indice *pi)
{
    t_reg_indice *temp;
    int per = (int)(pi->capacidad *1.3);
    temp = realloc(pi->registro, sizeof(t_reg_indice)*per);
    if(temp == NULL)
    {
        printf("\n\nERROR AL AUMENTAR CAPACIDAD...");
        exit(1);
    }
    pi->registro = temp;
    pi->capacidad = per;
}
void Bubble_Sort_Gen (void *v, size_t ce, size_t tam, int (*cmp)(const void*,const void*))
{
    int i, j;
    for(i=0; i<ce-1; i++)
    {
        for(j=0; j<ce-1-i; j++)
        {
            if(cmp(v+(j*tam),v+((j+1)*tam))>0)
                IntercambioDinamicoGenerico(v+(j*tam),v+((j+1)*tam),tam);
        }
    }
}

void IntercambioDinamicoGenerico (void *a, void *b, size_t tam)
{
    char *aux = (char*)malloc(tam);
    if(aux==NULL)
    {
        printf("Error.");
        return;
    }
    memcpy(aux,a,tam);
    memcpy(a,b,tam);
    memcpy(b,aux,tam);

    free(aux);
}

int compara_socio_indice(const void* a,const void* b)
{
    t_reg_indice* idx1 = (t_reg_indice*) a;
    t_reg_indice* idx2 = (t_reg_indice*) b;

    return idx1->dni - idx2->dni;
}


int indice_vacio(const t_indice * pi)
{
    return pi->cantidad == 0;
}


int indice_insertar(t_indice* pi, t_reg_indice* preg){

    int i;

    if(indice_buscar(pi, preg) == TRUE)
        return TRUE;

    if(pi->cantidad == pi->capacidad)
        aumentarCap(pi);

    for(i= (pi->cantidad -1); i>=0; i--)
    {
        if(pi->registro[i].dni > preg->dni)
        {
            pi->registro[i+1] = pi->registro[i];
        }
        else
        {
            pi->registro[i+1] = pi->registro[i];
            pi->registro[i] = *preg;
            break;
        }
    }

    return TRUE;
}

int indice_eliminar (t_indice* pi, t_reg_indice* preg){
    int i;
    if(indice_buscar(pi, preg) == FALSE)
        return FALSE;

    for(i=0; i< pi->cantidad; i++)
    {
        if(pi->registro[i].dni >= preg->dni){
            pi->registro[i] = pi->registro[i+1];
        }

    }

    return TRUE;
}

int indice_buscar (const t_indice* pi, t_reg_indice* preg){
    int i;
    for(i=0; i < pi->cantidad; i++){
        if (pi->registro[i].dni == preg->dni) {
            *preg = pi->registro[i];
            return TRUE;
        }
    }
    return FALSE;
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
