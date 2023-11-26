#include <stdio.h>
union{
    float flotante;
    unsigned char byte[4];
}var;

int main(){
    printf("Bienvenido al programa que convierte un numero en punto flotante a hexadecimal \n");
    printf("Por favor ingrese su valor en punto flotante:\n");
    scanf("%f",&var.flotante);
    printf("Su numero en hexadecimal es: 0x");
     for (int i = 3; i >= 0; i--) {
        printf("%x",var.byte[i]);
    }
}
