// 1.Zona para las librerias
#include<iostream>
#include<string.h>
#include<conio.h>
#include<locale.h>
#include<stdio.h>
using namespace std;

// ---------- IMPLEMENTACIONES EXTRA ---------
string trim(string str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


//2. Zona para constantes y variables globales
// structs

struct Cine {
    string Nombre;
    int Salas;
    Cine* ant;
    Cine* sig;
};

struct Sala {
    string Nombre;
    int Sesiones;
    struct Sala *ant;
    struct Sala *sig;
};

struct Sesion{
	
	int numero;
	string hora;
	string dia;
	
	Sesion * ant;
	Sesion * sig;
};


//3. Zona para definir las funciones


int menu_principal();
void operaciones_pr(int op ,Sesion *& pcabSesion, Sesion *&pfinSesion, Sala*&pcabSala, Sala *&pfinSala);
void Registrar_Sesion(Sala * pcabsala, Sesion *& pcab, Sesion *&pfin, string nombre_sala);
Sala *buscar_sala( Sala *inicio, string nombre);
void crear_sala(Sala*&pcabsala, Sala*&pfinsala);
//4. Zona para la funcion principal




int main() {
	
	Sala * pcabSala = NULL;
	Sala * pfinSala = NULL;
	Sesion * pcabSesion = NULL;
	Sesion * pfinSesion = NULL;
	
	
	
	setlocale(LC_CTYPE,"Spanish");
	int op;
	do{
		system("cls");
		op = menu_principal();
		operaciones_pr(op, pcabSesion, pfinSesion, pcabSala, pfinSala);
		cout<<"Desea realizar otra operacion si(1): ";
		cin>>op;  
	}while(op==1);
	
	
	
	
	
	getch();
	return 0;
}

//5. Implementar las funciones

int menu_principal(){
	int resp;
	do{
		system("cls");
		cout<<"------------------MENU PRINCIPAL------------------"<<endl;
		cout<<"> 1. Registrar Cine"<<endl;
		cout<<"> 2. Registrar Salas"<<endl;
		cout<<"> 3. Registrar Sesiones"<<endl;
		cout<<"> 4. Registrar Pelicula"<<endl;
		cout<<"> 5. Visualizar información de Sala Concreta"<<endl;
		cout<<"> 6. Buscar pelicula"<<endl;
		cout<<"> 7. Modificar una película de una sala concreta"<<endl;
		cout<<"> 8. Listar peliculas por edades"<<endl;
		cout<<"> 9. Listar carteleras de todos los cines"<<endl;
		cout<<"> 10. Salir del programa"<<endl;
		cout<<"------------------||||||||||||||------------------"<<endl<<endl;
		cout<<"Elije una opcion [1--10]: ";
		cin>>resp;
	}while(resp<1 || resp>10 );
	
}

void operaciones_pr(int op ,Sesion *& pcabSesion, Sesion *&pfinSesion, Sala*&pcabSala, Sala *&pfinSala){
	string nombre;
	switch(op){
		case 1: //registrar cine
			
			break;
		case 2: //Registrar Salas
		crear_sala(pcabSala, pfinSala);
			break;
		case 3: // registrar sesiones
			cout<<"Inggrese el nombre de la sala la que pertenece la sesion";;
			cin>>nombre;
			Registrar_Sesion(pcabSala, pcabSesion, pfinSesion,nombre);
			break;
		case 4: //registra pelicula
			break;
		case 5: //visualizar informacion de una sala concreta
			break;
		case 6: //Buscar película
			break;
		case 7: //Modificar una pelicula de una sala concreta
			break;
		case 8: //Listar las peliculas por edades
			break;
		case 9: // listar carteleras de todos los cines
			break;
		case 10: //salir del programa
			break;
	}
}


// -------------------- CINE --------------------------

// ------------------SALA -------------------------------

void crear_sala(Sala*&pcabsala, Sala*&pfinsala){
	Sala * nuevaSala = new(Sala);
	nuevaSala->Sesiones = 0;
	string nombre;
    printf("Ingrese el nombre de la nueva sala:\n");
    cin.ignore(); // Ignorar el salto de línea anterior
    getline(cin, nombre); // Leer el nombre completo de la sala
    string nombre_trim = trim(nombre); // Eliminar los espacios en blanco al principio y al final
	nuevaSala->Nombre = nombre_trim;
	
	nuevaSala -> ant = NULL;
	nuevaSala -> sig = NULL;
	
	if (pcabsala == NULL){
		pcabsala = nuevaSala;
	}else{
		nuevaSala -> ant = pfinsala;
		pfinsala ->sig = nuevaSala;
	}
	
	pfinsala= nuevaSala;
	
	cout<<nuevaSala<<endl;
	cout<<nuevaSala->Nombre<<endl;
	cout<<nuevaSala->ant<<endl;
	cout<<nuevaSala->sig<<endl;
	
	
}


Sala *buscar_sala(Sala *inicio, string nombre) {
	Sala *actual = inicio;
    while (actual != NULL) {// de no existir un sala existente se continua y registra
        if (actual->Nombre.compare(nombre) == 0) {
            return actual;
        }
        actual = actual->sig;
    }
    return NULL;
}


// --------------- SESION ----------------------------


void Registrar_Sesion(Sala * pcabsala, Sesion *& pcab, Sesion *&pfin, string nombre_sala){
	
	Sala * salaAct = buscar_sala(pcabsala, nombre_sala);
	if(salaAct != NULL){
		Sesion * nuevaSesion = new(Sesion);
		cout<<"Ingrese el número de sesion: "; cin>> nuevaSesion->numero;
		cout<<"Ingrese la hora de la sesion: "; 
		cin.ignore();
		getline(cin, nuevaSesion->dia);
	
		cout<<"Ingrese el dia de la sesion: "; cin>> nuevaSesion->dia;
		
		nuevaSesion -> ant = NULL;
		nuevaSesion -> sig = NULL;
		
		if (pcab == NULL){
			pcab = nuevaSesion;
		}else{
			nuevaSesion -> ant = pfin;
			pfin->sig = nuevaSesion;
		}
		
		pfin= nuevaSesion;
		cout<<nuevaSesion<<endl;
		cout<<nuevaSesion->numero<<endl;
		cout<<nuevaSesion->ant<<endl;
		cout<<nuevaSesion->sig<<endl;
	}else{
		cout<<"Esta sala no existe";
	}

}


/*
int numero;
	string hora;
	string dia;
	
	Sesion * ant;
	Sesion * sig;
*/









