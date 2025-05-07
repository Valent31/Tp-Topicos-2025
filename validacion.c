#include "validacion.h"
int ValidarDni(int n){
    return (n<10000 || n>10000000)? FALSE : TRUE;
}

void eliminate_tab(char *str){
    while(*str){
        if(*str != '\t'){
            str++;
        }
        else{
            *str = ' ';
            str++;
        }
    }
 }
void capitalize_str(char * str){
    int space = 1;
    while(*str){
        if(*str == ' ' || *str ==9 || *str == '.' || *str == ','){
            space =1;
        }
        else{
            *str = space ? toUpper(*str) : toLower(*str);
            space = 0;
        }
        str++;
    }
}
int eliminate_spaces(char *str){
    int space = 0, cant=0, el =0;
    char *ini = str;
    while(*str){
        if(*str != ' ' ){
            if(space){
                eliminate_str(ini, 1, cant);
                str = ini;
                space = 0;
                cant = 0;
            }
        }
        else{
            if(space){
                cant++;
                el++;
            }
            else{
                ini = str;
                space = 1;
            }
        }
        str++;
    }
    return el;
}
void check(char *str, int c){
    if(*(str+1)!= ' ' && c>0){
        memmove(str+2, str+1, str_lenght(str));
        *(str+1)= ' ';
    }
    if(!ES_LMIN(*(str-1))){
        memmove(str-1, str, str_lenght(str)+1);
    }
}
char * ValidarNyA(char * cad, int max){
    char *lec, *com1;
    int espacio =0;
    int checked = 0;
    eliminate_tab(cad);
    /*Avanza hasta la primer letra*/
    while(*cad ==' '|| *cad== ','){
        cad++;
        max--;
    }
    espacio+= max - str_lenght(cad);
    lec = cad;
    capitalize_str(cad);
    espacio+=eliminate_spaces(cad);
    while(*lec && checked ==0){
        if(*lec!=','){
            lec++;
        }
        else{
            /*Al llegar a la primer coma verifica que este bien formateado, y si no lo esta, en la funcion check lo arregala*/
            /*El parametro espacio es importante para saber si podemos agregar un caracter sin violar memoria*/
            check(lec, espacio);
            checked =1;
            lec++;
        }
    }
    /*Se le asgina  a com1 la direccion de el caracter siguiente a la coma para poder despues cambiar las siguientes comas por espacios y al final borrar los espacios sobrantes*/
    com1 = lec;
    if(checked){
        while(*lec){
                if(*(lec)!=','){
                lec++;
            }
            else{
                *(lec)=' ';
                lec++;
            }
        }
        /*Se llega al final de la cadena y ahora se busca eliminar todo espacio innecesario  hasta llegar a la primera letra*/
        /*Como ya se elminan espacios repetitivos anteriormente deberia quedar solo un espacio ya que la funcion  eliminate_spaces deja solo un espacio no permite 2 o mas juntos*/
        lec--;
        while(!ES_LMIN(*lec)){
            lec--;
        }
        *(lec+1) = '\0';
        /*Usamos nuevamente la funcion porque si habia comas y dsp espacio quedarian dos espacios por ej:
        "Hola, como , andas"
        quedaria dsp de todo el proceso anterior
        "Hola, como   andas"
        Entonces una vez cambiados las ',' por  ' ' podemos eliminar los espacios redundantes*/
        eliminate_spaces(com1-1);
    }
    else{
        /*En caso de no haber cadena
        1.Al estar al final de la cadena va eliminar los espacios innecesarios si es que hay*/
        lec--;
        while(!ES_LMIN(*lec)){
            lec--;
        }
        *(lec+1)= '\0';/*
        2.se va a insertar dsp de la primera la palabra la ','*/
        lec =cad;
        while(*lec!=' '){
            lec++;
        }
        memmove(lec+1, lec, str_lenght(lec)+1);
        *lec = ',';
    }
    return cad;
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
        return TRUE;
    else
        return FALSE;
}
int validarFecha(t_fecha fecha)
{
    if(fecha.anio >= 1900)
        if(fecha.mes >= 1 && fecha.mes <=12 && fecha.dia <= cantDias(fecha.mes, fecha.anio) && fecha.dia>=1)
            return TRUE;
    return FALSE;
}
int ValidarSexo(char s){
    s = toUpper(s);
    return (s=='F' || s=='M')? TRUE:FALSE;
}
int ValidarCat(char cat[10]){
    const char *opc[]={"MENOR","ADULTO","VITALICIO","HONORARIO"};
    int i;
    strtoupper(cat);
    for(i=0; i<4; i++){
        if(str_cmp(cat,opc[i]) == 0)
            return TRUE;
    }
    return FALSE;
}
int ValidarEstado(char e){
    e= toUpper(e);
    return (e=='A' || e=='B')? TRUE:FALSE;
}
/*
char * ValidarApellyNom(const char *cad){
    //PePe GALLeta, Raul
    cad = Normalizar(*cad);
    //Pepe Galleta, Raul
    char * lec = cad;
    while(*lec ){
        if(*lec == ','){
            //*cad = BorrarComas(*cad);
            return cad;
        }
        lec++;
    }
    cad = InsertarComa(*cad);
}
void  insertarComa(char *cad){
}
Galleta Pepe, Raul Diego Benja Valen


int ValidarSexo(char s){
    /*CHAR_MAY(s);
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
   /* CHAR_MAY(e);
    return (e=='A' || e=='B')? TRUE:FALSE;
}

int validarFecha(t_fecha fecha)
{
    if(fecha.anio >= 1900)
        if(fecha.mes >= 1 && fecha.mes <=12 && fecha.dia <= cantDias(fecha.mes, fecha.anio) && fecha.dia>=1)
            return TRUE;
    return FALSE;
}
*/


