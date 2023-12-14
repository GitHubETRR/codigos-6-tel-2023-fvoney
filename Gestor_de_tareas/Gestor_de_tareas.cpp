#include <iostream>
#include <fstream>
using namespace std;
#define SALIR 5

class tarea{
	private:
		string nombre, desc, estado;    // atributos
		tarea *siguiente;
	public:
		void apuntarobj(tarea*);        // para cambiar a donde apunta el objeto (setear puntero)
		tarea *sabersiguiente();        // obtener donde apunta el objeto
		void modificar(string, string, string);	    //cambiar valores de los atributos del obejeto
		void modificar(string);         //cambiar solo el estado
		string sabernombre(void);
		string saberdesc(void);
		string saberestado(void);
}tareas;

typedef tarea *ptarea;	// ahorrar escribir **

void tarea::apuntarobj(tarea *_siguiente){
	siguiente = _siguiente;
};

tarea *tarea::sabersiguiente(){
	return siguiente;
};

void tarea::modificar(string _nombre, string _desc, string _estado){
	nombre = _nombre;
	desc = _desc;
	estado = _estado;
};

void tarea::modificar(string _estado){
	estado = _estado;
};

string tarea::sabernombre(void){
	return nombre;
};

string tarea::saberdesc(void){
	return desc;
};

string tarea::saberestado(void){
	return estado;
};

/*
	Las funciones que cambien el conjunto de mi lista, tienen que ser doble puntero
	Las que modifiquen solo 1 objeto de la lista, no
*/

void fcrear(ptarea*);
void feditar(ptarea, string);
void flistar(ptarea);
void flistar(ptarea, string);
void feliminar(ptarea*, string);
void ffleer(ptarea*);
void ffescribir(ptarea);

int main(){
	int opcion=0;
	int ntarea;
	bool flag=false;
	string nombre;
	ptarea comienzo = NULL;
	cout<<"Recuperando archivo...\n";
	ffleer(&comienzo);
	cout<<"Archivo recuperado\n";
	cout<<"\nBienvenido al Gestor de Tareas!!\n";
	while(opcion!=SALIR){
		cout<<"\n--Por favor, seleccione una opción--\n";
		cout<<"\t1.Crear tarea\n";
		cout<<"\t2.Editar estado\n";
		cout<<"\t3.Listar tareas\n";
		cout<<"\t4.Eliminar tarea\n";
		cout<<"\t5.Salir\n\n";
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Creación tarea\n";
				fcrear(&comienzo);
				break;
			case 2:
				cout<<"Edición tarea\n";
				cout<<"Ingrese el nombre de la tarea a editar: ";
				cin.ignore();	
				getline(cin, nombre);
				feditar(comienzo, nombre);
				
				break;
			case 3:
				cout<<"Listar tarea\n";
				cout<<"Ingrese el nombre de la tarea a mostrar (0 listar todas): ";
				cin.ignore();
				getline(cin, nombre);
				if(nombre=="0") flistar(comienzo);
				else flistar(comienzo, nombre);
				break;
			case 4:
				cout<<"Eliminacion de tarea\n";
				cout<<"Ingrese el nombre de la tarea a eliminar: ";
				cin.ignore();
				getline(cin, nombre);
				feliminar(&comienzo, nombre);
				break;
			case 5:
				ffescribir(comienzo);
				cout<<"¡Hasta pronto!";
				break;
			default:
				cout<<"Por favor, introduzca una opción válida\n";
				break;
		}
	}
	return 0;
}

void fcrear(ptarea* comienzo){
	ptarea objetonuevo = new tarea;
	string nombre, desc, estado;
	cout<<"\nNombre: ";
	cin.ignore();
	getline(cin, nombre);
	cout<<"\nDescripción: ";
	getline(cin, desc);
	cout<<"\nEstado: ";
	getline(cin, estado);
	objetonuevo->modificar (nombre, desc, estado);      //uso el operador flecha para apuntar al objeto
	objetonuevo->apuntarobj(*comienzo);     	//definitle su suguiente
	*comienzo = objetonuevo;           	//como ingreso objetos al principio de la lista, actualizo el comienzo con el objeto mas reciente
}

void feditar(ptarea comienzo, string nombre){
	bool flag = false;
	string estado;
	ptarea buscador = comienzo;
	while(buscador != NULL){
		if(buscador->sabernombre()==nombre){
			cout<<"Ingrese el nuevo estado: ";
			getline(cin, estado);
			buscador->modificar(estado);
			flag = true;
			break;
		}
		buscador = buscador->sabersiguiente();
	}
	if(!flag) cout<<"La tarea "<<nombre<<" no se encontró\n";
}

void flistar(ptarea comienzo){
	ptarea aux = comienzo;
	int orden=1;
	while(aux != NULL){
		cout<<orden<<". "<<aux->sabernombre()<<":\n";
		cout<<"\t- "<<aux->saberdesc()<<"\n";
		cout<<"\t- "<<aux->saberestado()<<"\n";
		aux = aux->sabersiguiente();
		orden++;
	}
}

void flistar(ptarea comienzo, string nombre){		//logica de encontrar es la misma que feditar, solo cambia el if
	bool flag = false;
	ptarea buscador = comienzo;
	while(buscador != NULL){
		if(buscador->sabernombre()==nombre){
			cout<<buscador->sabernombre()<<":\n";
			cout<<"\t- "<<buscador->saberdesc()<<"\n";
			cout<<"\t- "<<buscador->saberestado()<<"\n";
			flag = true;
			break;
		}
		buscador = buscador->sabersiguiente();
	}
	if(!flag) cout<<"La tarea "<<nombre<<" no se encontró\n";
}

void feliminar(ptarea* comienzo, string nombre){
	ptarea eliminador = *comienzo, anterior = NULL;
	bool flag = false;
	while(eliminador != NULL){
		if(eliminador->sabernombre()==nombre){
			if (anterior != NULL) anterior->apuntarobj(eliminador->sabersiguiente());
			else *comienzo = eliminador->sabersiguiente();	//solo entra si hay que eliminar el primero de la lista
			delete(eliminador);
			cout<<"La tarea "<<nombre<<" se elimino exitosamente\n";
			flag = true;
			break;
		}
		anterior = eliminador;
		eliminador = eliminador->sabersiguiente();
	}
	if(!flag) cout<<"La tarea "<<nombre<<" no se encontró\n";
}

void ffleer(ptarea* comienzo){
	ifstream archivo ("tareas.txt", ios::in);
	string nombre, desc, estado;
	if (!(archivo.is_open()))
	{
		cout << "No se logro abrir el archivo\n";
		exit(1);
	}
	/*
	if(!archivo.eof()){
		while
	}
	*/
	//if(!flag){
		//while(!archivo.eof()){ // mientras que NO sea el final de archivo, entro al bucle
		
	while (getline(archivo, nombre) && getline(archivo, desc) && getline(archivo, estado)){
		/*
			lee las 3 lineas, si un getline() no pudo leer nada, devuelve un false
			con que exista un false en el while (debido a las AND) la condicion se hace falsa (0), y no entra al while
			mientras que si leyo todo, (todo 1 o true) la condicion es verdadera y sigue con la creacion del objeto y su asignacion de atributos
		*/
		ptarea objetonuevo = new tarea;	// crea el objeto
		objetonuevo->modificar (nombre, desc, estado); // asigna valor
		objetonuevo->apuntarobj(*comienzo); //mete el objeto a la lista
		*comienzo = objetonuevo;
	}
	archivo.close();
}

void ffescribir(ptarea comienzo){
	ofstream archivo ("tareas.txt", ios::out);
	ptarea aux = comienzo;
	if(!(archivo.is_open())){
		cout << "No se logro abrir el archivo\n";
		exit(1);
	}
	while(aux != NULL){
		archivo<<aux->sabernombre()<<"\n";
		archivo<<aux->saberdesc()<<"\n";
		archivo<<aux->saberestado()<<"\n";
		aux = aux->sabersiguiente();
	}
	archivo.close();
}
