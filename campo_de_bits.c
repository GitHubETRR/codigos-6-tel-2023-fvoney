#include <stdio.h>
union flotante{
    struct{
        unsigned int mantisa:23;
        unsigned int exponente:8; 
        unsigned int signo:1;
    };
    float numero;
};

int main() {
    union flotante u;
    printf("Bienvenido al programa para representar numeros en el estandar IEEE 754, ingrese su número flotante: ");
    scanf("%f", &u.numero);
    printf("Su numero es: ");
    if (u.signo & 0x01) printf("1");
    else printf("0");
    for(int n=(8-1);n>=0;n--){
        if ((u.exponente>>n & 0x01)==1) printf("1");
        else printf("0");
    }
    for(int n=(23-1);n>=0;n--){
        if ((u.mantisa>>n & 0x01)==1) printf("1");
        else printf("0");
    }
    return 0;
}
