

// 1.Zona para las librerias
#include<iostream>
#include<string.h>
#include <string>
#include<conio.h>
#include<locale.h>
#include<stdio.h>
#include<windows.h>
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
void gotoxy(int x,int y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

//2. Zona para constantes y variables globales
// structs

struct Pelicula{
	
	string nombre;
	
	string clasificacion;
	
	
	Pelicula*ant;
	Pelicula * sig;
};

struct Sesion{
	//Sala * sala_origen;
	int numero;
	string hora;
	string dia;
	
	Sesion * ant;
	Sesion * sig;
};
struct Sala {
    //string Nombre;
    int numero;
    int Sesiones;
    bool Horario1;
    bool Horario2;
    bool Horario3;
    bool Horario4;
    
    Pelicula * PeliSala;
    
    Sesion * pcabSe;
    Sesion * pfinSe;
    
    
    struct Sala *ant;
    struct Sala *sig;
};
struct Cine {
    string Nombre;
    int Salas;
    
    Sala * pcabS;
    Sala * pfinS;
    
    Cine* ant;
    Cine* sig;
};






//3. Zona para definir las funciones


int menu_principal();
void operaciones_pr(int op , Cine *&pcabCine, Cine *& pfinCine,Sesion *& pcabSesion, Sesion *&pfinSesion, Sala*&pcabSala, Sala *&pfinSala,Pelicula *& pcabPelicula,Pelicula * &pfinPelicula);
void Registrar_Sesion(Sala * pcabsala, Sesion *& pcab, Sesion *&pfin, int numero_sala,Cine *&pcabCine, Cine *& pfinCine);
Sala *buscar_sala( Sala *inicio, int num);
void crear_sala(Sala*&pcabsala, Sala*&pfinsala,Cine*pcabcine);
Cine *buscar_cine(string datobuscar,Cine *pcab);
void RegistrarCine(Cine*&pcab, Cine*&pfin);
void fun_listar(Cine *pcabProd);
bool verificar_Cine(string nombre, Cine *pcab);
bool verificar_Sala(int num, Sala *pcab);
void Seleccion_Horario(Sala * salaAct,Sesion * sesionAct);
void Registrar_Pelicula(Pelicula *&pcabP,Pelicula *&pfinP,Cine * pcabCine);
Pelicula *Buscar_Pelicula(string datobuscar,Pelicula *pcab);
bool verificar_Peli(string nombre, Pelicula *pcab);
//4. Zona para la funcion principal




int main() {
	Cine * pcabCine = NULL;
	Cine * pfinCine = NULL;
	Sala * pcabSala = NULL;
	Sala * pfinSala = NULL;
	Sesion * pcabSesion = NULL;
	Sesion * pfinSesion = NULL;
	Pelicula * pcabPelicula = NULL;
	Pelicula * pfinPelicula = NULL;
	//string s = to_string(0)
	//cout<<s
	setlocale(LC_CTYPE,"Spanish");
	int op;
	do{
		system("cls");
		op = menu_principal();
		operaciones_pr(op,pcabCine, pfinCine, pcabSesion, pfinSesion, pcabSala, pfinSala, pcabPelicula, pfinPelicula);
		gotoxy(5, 2);cout<<"Desea realizar otra operacion si(1): ";gotoxy(55,2);cin>>op;  
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

void operaciones_pr(int op , Cine *&pcabCine, Cine *& pfinCine,Sesion *& pcabSesion, Sesion *&pfinSesion, Sala*&pcabSala, Sala *&pfinSala,Pelicula *& pcabPelicula,Pelicula *& pfinPelicula){
	int numb=0;
	string cine;
	Cine * act;
	switch(op){
		case 1: //registrar cine
			RegistrarCine(pcabCine,pfinCine);
			//fun_listar(pcabCine);
			break;
			
		case 2: //Registrar Salas
			crear_sala(pcabSala, pfinSala,pcabCine );
			break;
			
		case 3: // registrar sesiones
			//cout<<"Ingrese el numero de la sala la que pertenece la sesion:"<<endl;
			//cout<<"Sala: ";
			//cin>>numb;
			Registrar_Sesion(pcabSala, pcabSesion, pfinSesion,numb,pcabCine, pfinCine);
			break;
			
		case 4: //registra pelicula
			Registrar_Pelicula(pcabPelicula,pfinPelicula,pcabCine);
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

void RegistrarCine(Cine*&pcab, Cine*&pfin) {
    Cine* NuevoNodo = new(Cine);
    //NuevoNodo->Nombre = nombre;
	bool Verf;
	
	do{
			system("cls");
			fflush(stdin);
			gotoxy(25,8);cout<<"Ingrese el nombre del cine: ";
			gotoxy(55,8);getline(cin, NuevoNodo->Nombre);
			NuevoNodo->Nombre = trim(NuevoNodo->Nombre);
			Verf = verificar_Cine(NuevoNodo->Nombre, pcab);
			if(Verf == true){
				gotoxy(60,20);cout<<"                    ";
			}
	}while(Verf == true);

	NuevoNodo->Salas= 1;	
	NuevoNodo->pcabS = NULL;
    NuevoNodo->pfinS = NULL;
	NuevoNodo->sig = NULL;
	NuevoNodo->ant = NULL;
	
	
	
    if(pcab==NULL){ //significa que es el primero
		pcab=NuevoNodo;
	}else{ //ya existe nodo
		pfin->sig=NuevoNodo;
		NuevoNodo->ant=pfin;
	}
	pfin=NuevoNodo;
}

Cine *buscar_cine(string datobuscar,Cine *pcab){
	Cine *nodoAct=pcab;
	while(nodoAct!=NULL){
		if(nodoAct->Nombre==datobuscar){
			return nodoAct;
		}
	    nodoAct=nodoAct->sig;	
	}
	
   return NULL;	
}

bool verificar_Cine(string nombre, Cine *pcab){
	Cine * dirCine; 
	dirCine = buscar_cine(nombre, pcab);
	
	if(dirCine != NULL){
		return true;	
	}
	return false;
}

void fun_listar(Cine *pcabProd){ //tipo referencia porque cambiara
	Cine *ProdAct=pcabProd;
	
	while(ProdAct!=NULL){
		//Presentar los datos
		cout<<"|>-----------------------------------------------<|"<<endl;
		cout<<"|>Direccion anterior del Nodo: "<<ProdAct->ant<<endl;
		cout<<"|>Direccion del Nodo: "<<ProdAct<<endl;
		cout<<"|>Nombre del cine: "<<ProdAct->Nombre<<endl;
		cout<<"|>Direccion siguiente del Nodo: "<<ProdAct->sig<<endl;
		cout<<"|>-----------------------------------------------<|"<<endl;
		//alterar la condicion o el bucle
		ProdAct=ProdAct->sig;
	} 
}

// ------------------SALA -------------------------------

void crear_sala(Sala*&pcabsala, Sala*&pfinsala, Cine*pcabcine){
	Sala * nuevaSala = new(Sala);
	Cine * cineAct;
	string cine;
	bool Verf;
	nuevaSala->Sesiones = 1;
//	string nombre;
	system("cls");
	fflush(stdin);
	
	//pregunta a que cine pertenece y verifica si existe
	do{
		gotoxy(35, 5);cout<<("                              ");
		gotoxy(5, 5);cout<<("Ingrese a que Cine pertenece: ");gotoxy(35, 5);getline(cin,cine);
		Verf = verificar_Cine(cine, pcabcine);
	}while(Verf == false);
	cineAct = buscar_cine(cine,pcabcine);
	gotoxy(5, 7);cout<<("Numero de Sala: ");gotoxy(35, 7);cout<<cineAct->Salas;
	//------- Ingresar demas detos

	nuevaSala->numero = cineAct->Salas;
	nuevaSala->pcabSe = NULL;
    nuevaSala->pcabSe = NULL;
	nuevaSala -> ant = NULL;
	nuevaSala -> sig = NULL;
	nuevaSala -> Horario1 = false;
	nuevaSala -> Horario2 = false;
	nuevaSala -> Horario3 = false;
	nuevaSala -> Horario4 = false;
    
	cineAct->Salas += 1;
	
	
	
	
	


	if (cineAct->pcabS == NULL){
	
		cineAct->pcabS = nuevaSala;
	}else{
		nuevaSala->ant = cineAct->pfinS;
		cineAct->pfinS->sig = nuevaSala;
	}
	cineAct->pfinS = nuevaSala;

}


Sala *buscar_sala(Sala *inicio, int num) {
	Sala *actual = inicio;
    while (actual != NULL) {// de no existir un sala existente se continua y registra
        if (actual->numero == num) {
            return actual;
        }
        actual = actual->sig;
    }
    return NULL;
}
bool verificar_Sala(int num, Sala *pcab){
	Sala * dirSala; 
	dirSala = buscar_sala(pcab,num);
	
	if(dirSala != NULL){
		return true;	
	}
	return false;
}


// --------------- SESION ----------------------------


void Registrar_Sesion(Sala * pcabsala, Sesion *& pcab, Sesion *&pfin, int numero_sala,Cine *&pcabCine, Cine *& pfinCine){

	Sala * salaAct;
	Cine * cineAct;
	string cine;
	int sala;
	bool Verf;
//	string nombre;
	system("cls");
	fflush(stdin);
	
	//pregunta a que cine pertenece y verifica si existe
	do{
		gotoxy(35, 5);cout<<("                              ");
		gotoxy(5, 5);cout<<("Ingrese a que Cine pertenece: ");gotoxy(35, 5);getline(cin,cine);
		Verf = verificar_Cine(cine, pcabCine);
	}while(Verf == false);
	cineAct = buscar_cine(cine,pcabCine);
	
	do{
		gotoxy(35, 7);cout<<("                              ");
		gotoxy(5, 7);cout<<("Ingrese a que Sala pertenece: ");gotoxy(35, 7);cin>>sala;
		Verf = verificar_Sala(sala, cineAct->pcabS);
	}while(Verf == false);
	salaAct = buscar_sala(cineAct->pcabS, sala);
	
	if(salaAct->Horario1 == false || salaAct->Horario2 == false||salaAct->Horario3 == false||salaAct->Horario4 == false){
		Sesion * nuevaSesion = new(Sesion);
	
	nuevaSesion->numero = salaAct->Sesiones;
	gotoxy(5, 9);cout<<("Numero de Sesion: ");gotoxy(35, 9);cout<<salaAct->Sesiones;
	salaAct->Sesiones +=1;
	
	
	if (salaAct->pcabSe == NULL){
	
		salaAct->pcabSe = nuevaSesion;
	}else{
		nuevaSesion->ant = salaAct->pfinSe;
		salaAct->pfinSe->sig = nuevaSesion;
	}
	salaAct->pfinSe = nuevaSesion;
	
	
	Seleccion_Horario(salaAct, nuevaSesion);
	
	}else{
		if(salaAct->Horario1 == true && salaAct->Horario2 == true&&salaAct->Horario3 == true&&salaAct->Horario4 == true){
			gotoxy(5, 9);cout<<(" No hay Horarios Disponibles ");
		}
	}	
}

void Seleccion_Horario(Sala * salaAct, Sesion * sesionAct){
	int op;
	bool verf;
	do{
		verf = false;
		do{
				fflush(stdin);
				gotoxy(5, 14);cout<<("1.- Horario 1: 10:30am ");
				gotoxy(5, 16);cout<<("2.- Horario 2: 12:30pm ");
				gotoxy(5, 18);cout<<("3.- Horario 3: 15:00pm ");
				gotoxy(5, 20);cout<<("4.- Horario 4: 20:00pm ");
				gotoxy(5, 22);cout<<("Ingrese el horario de la sala: ");gotoxy(35, 22);cin>>op;
		}while(op<0 || op>4);
	
		switch(op){
			case 1:
				if(salaAct->Horario1 != true){
					sesionAct->hora = "10:30am";
					salaAct->Horario1 = true;
					
					break;
				}else{
					verf= true;
					break;
				}
				
	
				
			case 2:
				if(salaAct->Horario2 != true){
					sesionAct->hora = "12:30am";
					salaAct->Horario2 = true;
					break;
				}else{
					verf= true;
					break;
				}
				
			case 3:
				if(salaAct->Horario3 != true){
					sesionAct->hora = "15:00pm";
					salaAct->Horario3 = true;
					break;
				}else{
					verf= true;
					break;
				}
				
			case 4:
				if(salaAct->Horario4 != true){
					sesionAct->hora = "20:00pm";
					salaAct->Horario4 = true;
					break;
				}else{
					verf= true;
					break;
				}
				
			}
	}while(verf==true);

}

// ------------- PELICULA ---------------------------

void Registrar_Pelicula(Pelicula *&pcabP,Pelicula *&pfinP, Cine * pcabCine){
	int op;
	string nombre;
	
	system("cls");
	fflush(stdin);
	do{
		gotoxy(5,5); cout<<"1.- Registrar Película";
		gotoxy(5,7); cout<<"2.- Asignar Película a Sala";
		gotoxy(5,10); cout<<"Ingrese opcion a elegir |1 - 2|: ";gotoxy(40,10);cin>>op;
	}while(op<0 || op>2);
	
	if (op==1){
		Pelicula *NuevoNodo=new(Pelicula); //ab001
		do{
			fflush(stdin);
			gotoxy(5, 12);cout<<"Ingrese el Nombre: ";gotoxy(40, 12);getline(cin, NuevoNodo->nombre);	
		}while(Buscar_Pelicula(NuevoNodo->nombre,pcabP) != NULL);
		
		NuevoNodo->ant=NULL;
		NuevoNodo->sig=NULL;
		
		if(pcabP==NULL){ //significa que es el primero
			pcabP=NuevoNodo;
		}else{ //ya existe nodo
			pfinP->sig=NuevoNodo;
			NuevoNodo->ant=pfinP;
		}
		pfinP=NuevoNodo;
	}else{
		Sala * salaAct;
		Cine * cineAct;
		Pelicula * peliAct;
		string cine;
		string peli;
		int sala;
		bool Verf;
	//	string nombre;
		fflush(stdin);
		
		do{
			gotoxy(35, 14);cout<<("                              ");
			gotoxy(5, 14);cout<<("Ingrese la Pelicula a asignar: ");gotoxy(35, 14);getline(cin,peli);
			Verf = verificar_Peli(peli, pcabP);
		}while(Verf == false);
		peliAct = Buscar_Pelicula(peli,pcabP);	
		
		
		//pregunta a que cine pertenece y verifica si existe
		do{
			gotoxy(35, 16);cout<<("                              ");
			gotoxy(5, 16);cout<<("Ingrese a que Cine pertenece: ");gotoxy(35, 16);getline(cin,cine);
			Verf = verificar_Cine(cine, pcabCine);
		}while(Verf == false);
		cineAct = buscar_cine(cine,pcabCine);
		
		do{
			gotoxy(35, 18);cout<<("                              ");
			gotoxy(5, 18);cout<<("Ingrese a que Sala pertenece: ");gotoxy(35, 18);cin>>sala;
			Verf = verificar_Sala(sala, cineAct->pcabS);
		}while(Verf == false);
		salaAct = buscar_sala(cineAct->pcabS, sala);
		
		salaAct-> PeliSala = peliAct;
	}
}
	
Pelicula *Buscar_Pelicula(string datobuscar,Pelicula *pcab){
	Pelicula *nodoAct=pcab;
	while(nodoAct!=NULL){
		if(nodoAct->nombre ==datobuscar){
			return nodoAct;
		}
	    nodoAct=nodoAct->sig;	
	}
	
   return NULL;	
}

bool verificar_Peli(string nombre, Pelicula *pcab){
	Pelicula * dirPeli; 
	dirPeli = Buscar_Pelicula(nombre, pcab);
	
	if(dirPeli != NULL){
		return true;	
	}
	return false;
}








