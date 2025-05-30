#include "validacion.h"
/**************************************************
*                                                 *
*          FUNCIONES PARA LA NORMALIZACION        *
*                                                 *
***************************************************/

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
int validarString(char *str, int tam){
    int i= 0;
    while(i < tam){
        if(*(str+i) !='\0'){
            i++;
        }
        else{
            return 1;
        }
    }
    return 0;
}
int validarStringAndTwo(char *str, int tam){
    int i = 0;
    int found = 0;
    int first = 0;
    int second = 0;
    int isspace = 1;
    while(i < tam && found!= 1){
        if(second== 0 && ES_LETRA(str[i])){
            if(first ==0){
                isspace = 0;
                first = 1;
            }
            else{
                if(isspace == 1){
                    second =1;
                }
            }
        }
        else{
            if(str[i] == '\0'){
                found = 1;
            }
            else{
                isspace =1;
            }
        }
        i++;
    }
    return (second ==1 && found ==1)?TRUE:FALSE;
}
char * normalizar(char * cad, int max){
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
/**********************************************************
*                VALIDACION   FECHA                       *
***********************************************************/
int cantDias(int mes, int anio)
{
    static int meses[12] = {31,28,31,30,31,31,30,31,30,31,30,31};

    if(mes == 2 && anioBisiesto(anio))
        return 29;

    return meses[mes-1];
}

int anioBisiesto(int anio)
{
    return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)?TRUE:FALSE;
}
int validarFecha(t_fecha fecha)
{
    if(fecha.anio >= 1900){
        if(fecha.mes >= 1 && fecha.mes <=12 && fecha.dia <= cantDias(fecha.mes, fecha.anio) && fecha.dia>=1){
            return TRUE;
        }
    }
    return FALSE;
}
int cmpFecha(const t_fecha f1, const t_fecha f2){
    if(f1.anio != f2.anio){
        return (f1.anio>f2.anio)?1:-1;
    }
    if(f1.mes != f2.mes){
        return (f1.mes>f2.mes)?1:-1;
    }
    if(f1.dia != f2.dia){
        return (f1.dia > f2.dia)?1:-1;
    }
    return 0;
}
t_fecha difFechas(const t_fecha *fecIni, const t_fecha *fecFin){
    static const char dias[2][13] = {
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};
    t_fecha edad;
    edad = *fecFin;
    if((edad.dia -= fecIni->dia)<0){
        edad.mes--;
        edad.dia += dias[anioBisiesto(edad.anio)][edad.mes];
    }
    if((edad.mes -= fecIni->mes)<0){
        edad.mes +=12;
        edad.anio--;
    }
    edad.anio -= fecIni->anio;
    return edad;
}

/**********************************************************
//               VALIDACION   DATOS                       *
/**********************************************************/
int ValidarDni(long dni){
    return (dni>10000 && dni<100000000)?TRUE:FALSE;
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
int validar(t_socio socio, t_fecha fProceso){
    if(ValidarDni(socio.DNI) == FALSE){
        printf("DNI");
        return FALSE;
    }
    if(validarStringAndTwo(&socio.ApellYNom, 60)==0){
        printf("CADENA");
        return FALSE;
    }
    t_fecha aux;
    aux = difFechas(&socio.FechNacimiento, &fProceso);
    if(validarFecha(socio.FechNacimiento)==FALSE || aux.anio<10){
        printf("NACIMIENTO");
        return FALSE;
    }
    if(ValidarSexo(socio.sex)==FALSE){
        printf("SEXO");
        return FALSE;
    }
    if(validarFecha(socio.FechAfil)==FALSE){
        printf("FECHA AFILIACION");
        return FALSE;
    }
    if(!(cmpFecha(socio.FechAfil, fProceso)<=0 && cmpFecha(socio.FechAfil, socio.FechNacimiento)>0)){
        printf("FECHA AFILIACION, 2ndo bucle");
        return FALSE;
    }
    if(ValidarCat(socio.Cat)==FALSE){
        printf("CATEGORIA");
        return FALSE;
    }
    if(validarFecha(socio.FechUltCuota)==FALSE){
        printf("ULTIMA CUOTA, 1ER BUCLE");
        return FALSE;
    }
    if(cmpFecha(socio.FechUltCuota, socio.FechAfil)<=0||cmpFecha(socio.FechUltCuota, fProceso)>0){
        printf("ULTIMA CUOTA, 2DO BUCLE");
        return FALSE;
    }
    if(ValidarEstado(socio.estado)==0){
        printf("ESTADO");
    }
    return ValidarEstado(socio.estado);
}

/**********************************************************
//               FUNCIONES PRINCIPALES                    *
/**********************************************************/
void crearBinario(){
    char linea[BUFFER];
    t_socio socio;
    t_fecha fProceso;
    printf("INGRESE FECHA DE PROCESO:");
    scanf("%i %i %i",&fProceso.dia, &fProceso.mes, &fProceso.anio);
    FILE *pt = fopen("socios.txt", "rt");
    FILE *pb = fopen("socios.dat","wb");
    FILE *pError = fopen("error.txt","wt");
    char aux[60];
    if(pt==NULL || pb ==NULL || pError == NULL){
        printf("ERROR AL CREAR BINARIO");
        exit(1);
    }
    while(fgets(linea, sizeof(linea),pt)){
        cargarSocio(linea, &socio);
        if(validar(socio,fProceso)!=TRUE){
            cargarError(pError, linea);
        }
        else{
            strcpy(aux, normalizar(socio.ApellYNom, 60));
            strcpy(socio.ApellYNom,aux);
            mostrarSocio(&socio);
            fwrite(&socio, sizeof(t_socio), 1,pb);
        }
    }
    fclose(pt);
    fclose(pb);
    fclose(pError);
}
void cargarSocio(char *pt, t_socio *socio){
    sscanf(pt, "%d;%59[^;];%d;%d;%d;%c;%d;%d;%d;%9[^;];%d;%d;%d;%c",
           &socio->DNI, socio->ApellYNom, &socio->FechNacimiento.dia,
           &socio->FechNacimiento.mes, &socio->FechNacimiento.anio,
           &socio->sex, &socio->FechAfil.dia, &socio->FechAfil.mes,
           &socio->FechAfil.anio, socio->Cat, &socio->FechUltCuota.dia,
           &socio->FechUltCuota.mes, &socio->FechUltCuota.anio,
           &socio->estado);
}

void cargarError(FILE *pError, char *linea){
    fprintf(pError,"%s",linea);
}
void mostrarSocio(t_socio * socio){
    printf("%d;%s;%d;%d;%d;%c;%d;%d;%d;%s;%d;%d;%d;%c\n",
           socio->DNI, socio->ApellYNom, socio->FechNacimiento.dia,
           socio->FechNacimiento.mes, socio->FechNacimiento.anio,
           socio->sex, socio->FechAfil.dia, socio->FechAfil.mes,
           socio->FechAfil.anio, socio->Cat, socio->FechUltCuota.dia,
           socio->FechUltCuota.mes, socio->FechUltCuota.anio,
           socio->estado);
}
//Primera Parte, validacion completa

/*
char * ValidarApellyNom(const char *cad){
    PePe GALLeta, Raul
    cad = Normalizar(*cad);
    Pepe Galleta, Raul
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


