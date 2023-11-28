#include <stdio.h>
#include <string.h>
char SN[1];
char S[]="S";
int comparar(char*, char*);

int main(){
    printf("Bienvenid@ al programa que comparara si dos palabras ingresadas son iguales entre si\n");
    char pal1[25], pal2[25];
    reinicio:
    printf("Por favor introduzca su primera palabra:\n");
    scanf("%s", pal1);
    printf("Por favor introduzca su segunda palabra:\n");
    scanf("%s", pal2);
    
    if (comparar(pal1, pal2)==0) printf("Las palabras son iguales\n");
    else printf("Las palabras son diferentes\n");
    printf("Desea realizar otra comparación? S/N\n");
    scanf("%s", SN); if(strcmp(SN, S) == 0){goto reinicio;} else return 0;
}

int comparar(char *p1, char *p2){
    for(int n=0;n<=25;n++){
        if ((*p1++)!=(*p2++)){
            return 1;
        }
    }
    return 0;
}




