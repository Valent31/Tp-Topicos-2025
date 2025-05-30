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
