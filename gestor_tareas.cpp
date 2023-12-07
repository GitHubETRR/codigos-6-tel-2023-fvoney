#include <iostream>
using namespace std;
#define SALIR 3
#define CANTIDAD 10
class tarea{
    private:
        string nombre, desc, estado;
    public:
        void modificar(string, string, string);
        void listar();
}tareas[CANTIDAD];

void tarea::modificar(string _nombre, string _desc, string _estado){
    nombre = _nombre;
    desc = _desc;
    estado = _estado;
};
void tarea::listar()
{
    cout<<"Nombre: "<< nombre;
    cout<<"\nDescripción: "<<desc;
    cout<<"\nEstado: "<<estado<<"\n";
};

void feditar(int);

void flistar();
void flistar(int);

int main(){
    int opcion=0;
    int ntarea;
    bool flag=false;
    cout<<"Bienvenido al Gestor de Tareas!!\n\n";
    while(opcion!=SALIR){
        cout<<"--Seleccione una opción--\n";
        cout<<"1.Editar tareas\n";
        cout<<"2.Listar tareas\n";
        cout<<"3.Salir\n\n";
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"Ingrese un numero del 1 al 10\n";
                cin>>ntarea;
                ntarea--;
                feditar(ntarea);
                break;
            case 2:
                do{
                    cout<<"Ingrese el numero de la tarea a mostrar (0 listar todas)\n";
                    cin>>ntarea;
                    if(ntarea==0){
                        flag=false;
                        flistar();
                    }else if((ntarea>=1) && (ntarea<=10)){
                        flag=false;
                        ntarea--;
                        flistar(ntarea);
                    }else{
                        cout<<"Por favor, ingrese un valor valido";
                        flag=true; 
                    }
                }while(flag);     
                break;
            case 3:
                cout<<"¡Hasta pronto!";
                break;
            default:
                cout<<"Por favor, introduzca una opción válida\n";
                break;
        }
    }
}

void feditar(int n){
    string nombre, desc, estado;
    cout<<"La tarea seleccionada es la N°"<<n+1<<"\n";
    cout<<"\nNombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout<<"\nDescripción: ";
    getline(cin, desc);
    cout<<"\nEstado: ";
    getline(cin, estado);
    tareas[n].modificar(nombre, desc, estado);
}

void flistar(void){
    for(int i=0; i<CANTIDAD; i++){
        cout<<"Tarea "<< i+1 <<" :\n";
        tareas[i].listar();
    }
}
void flistar(int n){
    cout<<"Tarea "<< n+1 <<" :\n";
    tareas[n].listar();
}

