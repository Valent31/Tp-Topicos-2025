#include "validacion.h"
char MiTolower(char x){
    return x>='A'&&x<='Z'?x+32:x;
}
char MiTouper(char x){
    return x>='a'&&x<='z'?x-32:x;
}

int ValidarDni(int n){
    int result =(n<10000 || n>10000000)? 1 : 0;
}

char * Normalizar(const char * cad){
    char * lec = cad, * esc = cad;
    int primetaLetraPalabra;
    while(*lec){
        while(isspace(*lec))
            lec++;
        if(*lec){
            primetaLetraPalabra = 1;
            while(*lec && !isspace(*lec)){
                *esc = primetaLetraPalabra? MiTouper(*lec):MiTolower(*lec);
                primetaLetraPalabra = 0;
                esc++;
                lec++;
            }
            *esc=' ';
            esc++;
        }
    }
    *(esc-1) = '\0';
    return cad;
}


char * ValidarApellyNom(const char *cad){
    //PePe GALLeta, Raul
    *cad = Normalizar(*cad);
    //Pepe Galleta, Raul
    char * lec = cad;
    while(*lec ){
        if(*lec == ','){
            //*cad = BorrarComas(*cad);
            return cad;
        }
        lec++;
    }
    *cad = InsertarComa(*cad);
}

//Galleta Pepe, Raul Diego Benja Valen


int ValidarSexo(char s){
    CHAR_MAY(s);
    return (s=='F' || s=='M')? TRUE:FALSE;
}

int ValidarCat(char cat[10]){
    const char *opc[]={'MENOR','ADULTO','VITALICIO','HONORARIO'};
    int i;
    for(i=0; i<4; i++){
        if(strcmpi(cat,opc[i]) == 0)
            return TRUE;
    }
    return FALSE;
}

int ValidarEstado(char e){
    CHAR_MAY(e);
    return (e=='A' || e=='B')? TRUE:FALSE;
}

int validarFecha(t_fecha fecha)
{
    if(fecha.anio >= 1900)
        if(fecha.mes >= 1 && fecha.mes <=12 && fecha.dia <= cantDias(fecha.mes, fecha.anio) && fecha.dia>=1)
            return TRUE;
    return FALSE;
}

int cantDias(int mes, int anio)
{
    static int meses[12] = {31,28,31,30,31,31,30,31,30,31,30,31};

    if(mes == 2 && anioBisiesto(anio))
        return 29;

    return meses[mes-1];
}

int anioBisiesto(int anio)
{
    if((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
    {
        return TRUE;
    }

    return FALSE;
}
