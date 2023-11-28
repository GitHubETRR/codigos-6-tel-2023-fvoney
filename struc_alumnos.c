#include <stdio.h>
#define MAX 20
int cant=0;
struct alumnos {
    char nombre[MAX];
    char apellido[MAX];
    short int edad;
    char curso [6];
};
int main() {
    printf("Hola, ¿cuantos alumnos va a ingresar?");
    scanf("%d", &cant);
    
    struct alumnos alumno[cant];
    for (int i = 0; i < cant; i++) {
        printf("Ingrese el nombre del alumno %d: ", i+1);
        scanf("%s", alumno[i].nombre);
        printf("Ingrese el apellido del alumno %d: ", i+1);
        scanf("%s", alumno[i].apellido);
        printf("Ingrese la edad del alumno %d: ", i+1);
        scanf("%hd", &alumno[i].edad);
        printf("Ingrese el curso del alumno %d: ", i+1);
        scanf("%s", alumno[i].curso);
    }

    printf("\n\nLos datos de los alumnos son:\n\n");

    for (int i = 0; i < cant; i++) {
        printf("Nombre del alumno %d: %s\n", i+1, alumno[i].nombre);
        printf("Apellido del alumno %d: %s\n", i+1, alumno[i].apellido);
        printf("Edad del alumno %d: %d\n", i+1, alumno[i].edad);
        printf("Curso del alumno %d: %s\n", i+1, alumno[i].curso);
    }
    return 0;
}



