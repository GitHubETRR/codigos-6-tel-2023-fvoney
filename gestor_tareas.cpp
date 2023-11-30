#include <iostream>
using namespace std;
#define Salir 4

class tarea{
    private:
        string nombre, desc, estado;
    public:
        void Agregar(){}
        void Listar(){}
        void Editar(){}
};

int main(){
    cout<<"Bienvenido al Gestor de Tareas!!\n\n";
    int opcion=0;
    while(opcion!=Salir){
        cout<<"--Seleccione una opción--\n";
        cout<<"1.Agregar Tarea\n";
        cout<<"2.Listar\n";
        cout<<"3.Editar\n";
        cout<<"4.Salir\n\n";
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"Agregar Tarea\n\n";
                break;
            case 2:
                cout<<"Listar Tarea\n\n";
                break;
            case 3:
                cout<<"Editar Tarea\n\n";
                break;
            case 4:
                cout<<"¡Hasta pronto!";
                break;
            default:
                cout<<"Por favor, introduzca una opción válida\n";
                break;
        }
    }
}


