

// 1.Zona para las librerias
#include<iostream>
#include<string.h>
#include <string>
#include<conio.h>
#include<locale.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
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
	
	string protagonistas;
	
	Pelicula*ant;
	Pelicula * sig;
};

struct Sesion{
	//Sala * sala_origen;
	int numero;
	string hora;

	
	Sesion * ant;
	Sesion * sig;
};
struct Sala {
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
void operaciones_pr(int op , Cine *&pcabCine, Cine *& pfinCine,Pelicula *& pcabPelicula,Pelicula * &pfinPelicula);
void Registrar_Sesion( int numero_sala,Cine *&pcabCine, Cine *& pfinCine);
Sala *buscar_sala( Sala *inicio, int num);
void crear_sala(Cine*pcabcine);
Cine *buscar_cine(string datobuscar,Cine *pcab);
void RegistrarCine(Cine*&pcab, Cine*&pfin);
void fun_listar(Cine *pcabProd);
bool verificar_Cine(string nombre, Cine *pcab);
bool verificar_Sala(int num, Sala *pcab);
void Seleccion_Horario(Sala * salaAct,Sesion * sesionAct);
void Registrar_Pelicula(Pelicula *&pcabP,Pelicula *&pfinP,Cine * pcabCine);
Pelicula *Buscar_Pelicula(string datobuscar,Pelicula *pcab);
bool verificar_Peli(string nombre, Pelicula *pcab);
string Registrar_Clasificcion();
void info_Sala(Cine*pcabCine);
void listar_sesiones(Sesion * pcab,int Y, int &ref);
void busqueda_pelicula(Cine * pcabCine, Pelicula * pcabP);
void Cartelera(Cine * pcabCine, Pelicula * pcabP);
void pelis_edades(Pelicula * pcab,Cine * pcabCine);
void menu_pelis();

//4. Zona para la funcion principal




int main() {
	Cine * pcabCine = NULL;
	Cine * pfinCine = NULL;
	Pelicula * pcabPelicula = NULL;
	Pelicula * pfinPelicula = NULL;
	void busqueda_pelicula(Cine * pcabCine);

	setlocale(LC_CTYPE,"Spanish");
	int op;
	do{
		system("cls");
		op = menu_principal();
		operaciones_pr(op,pcabCine, pfinCine, pcabPelicula, pfinPelicula);
		fflush(stdin);
		gotoxy(55, 1);cout<<"Desea realizar otra operacion si(1): ";gotoxy(93,1);cin>>op;  
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
		cout<<"> 4. Registrar y Asignar Peliculas"<<endl;
		cout<<"> 5. Visualizar información de Sala Concreta"<<endl;
		cout<<"> 6. Buscar pelicula"<<endl;
		cout<<"> 7. Listar peliculas por edades"<<endl;
		cout<<"> 8. Listar carteleras de todos los cines"<<endl;
		cout<<"> 9. Salir del programa"<<endl;
		cout<<"------------------||||||||||||||------------------"<<endl<<endl;
		cout<<"Elije una opcion [1--9]: ";
		cin>>resp;
	}while(resp<1 || resp>10 );
	
}

void operaciones_pr(int op , Cine *&pcabCine, Cine *& pfinCine,Pelicula *& pcabPelicula,Pelicula *& pfinPelicula){
	int numb=0;
	string cine;
	Cine * act;
	switch(op){
		case 1: //registrar cine
		
			RegistrarCine(pcabCine,pfinCine);
			//fun_listar(pcabCine);
			break;
			
		case 2: //Registrar Salas
			if(pcabCine!=NULL){
				crear_sala(pcabCine );
				break;
			}else{
				cout<<"No existen cines,Registra uno";
				break;
			}
			
			
		case 3: // registrar sesiones
			
			Registrar_Sesion(numb,pcabCine, pfinCine);
			break;
			
		case 4: //registra pelicula
			Registrar_Pelicula(pcabPelicula,pfinPelicula,pcabCine);
			break;
		case 5: //visualizar informacion de una sala concreta
			if (pcabCine!=NULL and pcabCine->pcabS!=NULL){
				info_Sala(pcabCine);
				break;
			}else{
				cout<<"No es posible ver la informacion de una sala, ";
				break;
			}
			
			
		case 6: //Buscar película
			if(pcabPelicula!=NULL){
				busqueda_pelicula(pcabCine, pcabPelicula);
				break;
			}else{
				cout<<"No existen peliculas";
				break;
			}
			
			
		case 7: //Listar las peliculas por edades
			pelis_edades(pcabPelicula, pcabCine);
			break;
		case 8: // listar carteleras de todos los cines
			Cartelera(pcabCine, pcabPelicula);
			break;
		case 9: //salir del programa
			char conf;
                cout << "¿Está seguro de salir (S/N)? ";cin >> conf;
                if (conf == 'S' || conf == 's') {

                    cout << "Saliendo del programa..." << endl;
                    exit(0);
                }else{
                	break;
				}
			
			
	}
}


// -------------------- CINE --------------------------

void RegistrarCine(Cine*&pcab, Cine*&pfin) {
    Cine* NuevoNodo = new(Cine);
    //NuevoNodo->Nombre = nombre;
	bool Verf;
	system("cls");
	do{
			
			fflush(stdin);
			gotoxy(25,6);cout<<"Ingrese el nombre del cine: ";
			gotoxy(55,6);getline(cin, NuevoNodo->Nombre);
			NuevoNodo->Nombre = trim(NuevoNodo->Nombre);
			
			Verf = verificar_Cine(NuevoNodo->Nombre, pcab);
			if(Verf == true){
				gotoxy(55,6);cout<<"                    ";
				gotoxy(25,8);cout<<"** Cine Ya Existente **";
			}
	}while(Verf == true);
	gotoxy(25,8);cout<<"** Cine Registrado con Exito **";
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


// ------------------SALA -------------------------------

void crear_sala(Cine*pcabcine){
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
	nuevaSala->PeliSala = NULL;
    nuevaSala->pfinSe = NULL;
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


void Registrar_Sesion( int numero_sala,Cine *&pcabCine, Cine *& pfinCine){

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
	
	nuevaSesion->sig = NULL;
	nuevaSesion->ant = NULL;
	
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
				
				gotoxy(45, 5);cout<<("|");gotoxy(50, 5);cout<<("1.- Horario 1: 10:30am ");
				gotoxy(45, 7);cout<<("|");gotoxy(50, 7);cout<<("2.- Horario 2: 12:30pm ");
				gotoxy(45, 9);cout<<("|");gotoxy(50, 9);cout<<("3.- Horario 3: 15:00pm ");
				gotoxy(45, 11);cout<<("|");gotoxy(50, 11);cout<<("4.- Horario 4: 20:00pm ");
				gotoxy(50, 13);cout<<("Ingrese el horario de la sala: ");gotoxy(82, 13);cin>>op;
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
	string clasificacion;
	string Protas;
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
		
		//registrar clasificacion
		clasificacion = Registrar_Clasificcion();
		NuevoNodo->clasificacion = clasificacion;
		
		fflush(stdin);
		gotoxy (5,24);cout<<"Ingrese el nombre de los protagonistas: "; gotoxy(45, 24);getline(cin, Protas);
		NuevoNodo->protagonistas = Protas;
		
	
		
		
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

string Registrar_Clasificcion(){
	int op;



	do{
		fflush(stdin);
		gotoxy(5, 14);cout<<("1.- Todo Publico > TP ");
		gotoxy(5, 16);cout<<("2.- Mayores de 15 > M15 ");
		gotoxy(5, 18);cout<<("3.- Mayores de 18 > N18 ");
		gotoxy(5, 20);cout<<("4.- Infantil > IFN");
		gotoxy(5, 22);cout<<("Ingrese la clasificacion de la Pelicula |1 - 4|: ");gotoxy(55, 22);cin>>op;
	}while(op<0 || op>4);
	
		switch(op){
			case 1:
				return "TP";
				break;
	
			case 2:
				return "M15";
				break;
				
				
			case 3:
				return "M18";
				break;
				
				
			case 4:
				return "IFN";
				break;			
		}
	}

// -------------- Visualizacion de datos -----------------

void info_Sala(Cine*pcabCine){
	
	//identificacion de la sala --------------------------
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
		gotoxy(5, 7);cout<<("Ingrese la Sala: ");gotoxy(35, 7);cin>>sala;
		Verf = verificar_Sala(sala, cineAct->pcabS);
	}while(Verf == false);
	salaAct = buscar_sala(cineAct->pcabS, sala);
	
	// ----------------------------------------
	
	//Mostrar Info-------
	
	gotoxy(5, 10);cout<<"Cine: ";gotoxy(20, 10);cout<<cineAct->Nombre;
	gotoxy(5, 12);cout<<"Sala: ";gotoxy(20, 12);cout<<salaAct->numero;	
	if(salaAct->PeliSala !=NULL){
		gotoxy(5, 16);cout<<"Pelicula: ";gotoxy(20, 16);cout<<salaAct->PeliSala->nombre;
		gotoxy(5, 18);cout<<"Protagonistas: ";gotoxy(20, 18);cout<<salaAct->PeliSala->protagonistas;
		gotoxy(5, 20);cout<<"Clasificacion: ";gotoxy(20, 20);cout<<salaAct->PeliSala->clasificacion;
		
	}else{
		gotoxy(5, 16);cout<<"Pelicula: ";gotoxy(20, 16);cout<<"Sin Pelicula Asignada";
		gotoxy(5, 18);cout<<"Protagonistas: ";gotoxy(20, 18);cout<<"Sin Pelicula Asignada";
		gotoxy(5, 20);cout<<"Clasificacion: ";gotoxy(20, 20);cout<<"Sin Pelicula Asignada";
	}
	
	
	int e = 0;
	
	listar_sesiones(salaAct->pcabSe,23,e);
	fflush(stdin);
}

void listar_sesiones(Sesion * pcab, int Y, int &ref){
	Sesion *nodoAct=pcab;
	int y = Y;//23;
	
	while(nodoAct!=NULL){
		//Presentar los datos
		gotoxy(5, y);cout<<"|>-----------------------------------------------<|";
		gotoxy(5, y+2);cout<<"|>Numero de Sesion: ";gotoxy(30,y+2);cout<<nodoAct->numero;
		gotoxy(5, y+4);cout<<"|>Horario de la sesion: ";gotoxy(30,y+4);cout<<nodoAct->hora;
		gotoxy(5,y+6);cout<<"|>-----------------------------------------------<|";
		//alterar la condicion o el bucle
		y+=6;
		ref += 8;
		nodoAct=nodoAct->sig;
		//gotoxy(5,30);cout<<"SIguienteeee";
		
	} 
}


void busqueda_pelicula(Cine * pcabCine, Pelicula * pcabP){
	system("cls");
	Pelicula * peliAct;
	string cine;
	string peli;
	int sala;
	bool Verf;
	//	string nombre;
	fflush(stdin);
	
	do{
		gotoxy(35, 10);cout<<("                              ");
		gotoxy(5, 10);cout<<("Ingrese la Pelicula a asignar: ");gotoxy(35, 10);getline(cin,peli);
		Verf = verificar_Peli(peli, pcabP);
	}while(Verf == false);
	peliAct = Buscar_Pelicula(peli,pcabP);	
	gotoxy(5,11);cout<<"Nombre: ";gotoxy(35,11);cout<<peliAct->nombre; 
	gotoxy(5,12);cout<<"Clasificacion: ";gotoxy(35,12);cout<<peliAct->clasificacion;
	gotoxy(5,13);cout<<"Protagonistas: ";gotoxy(35,13);cout<<peliAct->protagonistas;


	Cine *cineAct=pcabCine;
	Sala * salaAct;
	int y= 16;
	//int y2=18;
	
	while(cineAct!=NULL){
		//Presentar los datos
		gotoxy(5, y);cout<<"Cine: ";gotoxy(15, y);cout<<cineAct->Nombre;
		salaAct = cineAct->pcabS;
		
		if(salaAct->PeliSala == peliAct){
			while(salaAct!=NULL){
			
			
			
			gotoxy(5, y+2);cout<<"Sala:";gotoxy(15, y+2 );cout<<salaAct->numero;
			
			
			listar_sesiones(salaAct->pcabSe, y+3, y);

			salaAct = salaAct->sig;
			y+=4;
			}
		}
		
		
		y +=4 ;
		cineAct=cineAct->sig;
	} 
}

void Cartelera(Cine * pcabCine, Pelicula * pcabP){
	system("cls");
	Pelicula * peliAct;
	string cine;
	string peli;
	int sala;
	bool Verf;
	//	string nombre;
	fflush(stdin);
	Cine *cineAct=pcabCine;
	Sala * salaAct;
	int y= 8;
	//int y2=18;
	
	while(cineAct!=NULL){
		//Presentar los datos
		gotoxy(5, y);cout<<"Cine >>> ";gotoxy(25, y);cout<<cineAct->Nombre;
		salaAct = cineAct->pcabS;
		
		while(salaAct!=NULL){
			gotoxy(5, y+2);cout<<"Sala >>>";gotoxy(25, y+2 );cout<<salaAct->numero;
			if(salaAct->PeliSala){
				gotoxy(5,y+4);cout<<"Nombre >>> ";gotoxy(25,y+4);cout<<salaAct->PeliSala->nombre; 
				gotoxy(5,y+6);cout<<"Clasificacion >>> ";gotoxy(25,y+6);cout<<salaAct->PeliSala->clasificacion;
				gotoxy(5,y+8);cout<<"Protagonistas >>> ";gotoxy(25,y+8);cout<<salaAct->PeliSala->protagonistas;
			}else{
				gotoxy(5,y+4);cout<<"Nombre >>> ";gotoxy(25,y+4);cout<<"    "; 
				gotoxy(5,y+6);cout<<"Clasificacion >>> ";gotoxy(25,y+6);cout<<"    "; 
				gotoxy(5,y+8);cout<<"Protagonistas >>> ";gotoxy(25,y+8);cout<<"    "; 
			}
			
			
			
			
			
			listar_sesiones(salaAct->pcabSe, y+10, y);
			//gotoxy(5, y2+y2);cout<<"sexooooooooooooooooooooooooooooo";
			//y2+ = 
			salaAct = salaAct->sig;
			y+=8;
		}
		
		
		y +=5 ;
		cineAct=cineAct->sig;
	} 
}


void pelis_edades(Pelicula * pcab, Cine * pcabCine){
	Pelicula * peliAct = pcab;
	system("cls");
	string clasi;
	Cine *cineAct=pcabCine;
	Sala * salaAct;
	menu_pelis();
	gotoxy(5, 5);cout<<"Ingrese la clasificacion a buscar: ";gotoxy(40, 5);cin>>clasi;
	int y = 8;
	clasi= trim(clasi);
	
	if(clasi!="TP" and clasi!="M15" and clasi!="M18" and clasi!="IFN"){
		gotoxy(5, 17);cout<<"No existe esta clasificacion";
	}else{
		system("cls");
		Pelicula *nodoAct=pcab;
		while(nodoAct!=NULL){
			if(nodoAct->clasificacion == clasi){
				gotoxy(5,y+2);cout<<"Nombre >>> ";gotoxy(35,y+2);cout<<peliAct->nombre; 
				gotoxy(5,y+4);cout<<"Clasificacion >>> ";gotoxy(35,y+4);cout<<peliAct->clasificacion;
				gotoxy(5,y+6);cout<<"Protagonistas >>> ";gotoxy(35,y+6);cout<<peliAct->protagonistas;
				//return nodoAct;
				while(cineAct!=NULL){
				//Presentar los datos
				gotoxy(5, y);cout<<"Cine >>> ";gotoxy(15, y);cout<<cineAct->Nombre;
				salaAct = cineAct->pcabS;
					
					while(salaAct!=NULL){
						
						
						
						gotoxy(5, y+8);cout<<"Sala >>>";gotoxy(15, y+8 );cout<<salaAct->numero;
						
						
						listar_sesiones(salaAct->pcabSe, y+10, y);
						
						//y2+ = 
						salaAct = salaAct->sig;
						y+=8;
					}
				
				
				y +=5 ;
				cineAct=cineAct->sig;
			} 
				
				
				
			}
		    nodoAct=nodoAct->sig;	
		}
		
	   //return NULL;	
	}
	}	
	
void menu_pelis(){
	
	gotoxy(50,5);cout<<" -------- Elija una Clasificacion: ---------";
	gotoxy(50,7);cout<<">> Si busca para Todo Publico Escriba   | TP  | ";
	gotoxy(50,9);cout<<">> Si busca para Mayores de 15 Escriba  | M15 | ";
	gotoxy(50,11);cout<<">> Si busca para Mayores de 18 Escriba  | M18 |";
	gotoxy(50,13);cout<<">> Si busca Infantiles Escriba          | IFN |";
	
}



