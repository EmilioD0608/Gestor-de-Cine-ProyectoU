// 1.Zona para las librerias
#include<iostream>
#include<string.h>
#include<conio.h>
#include<locale.h>
#include<stdio.h>
using namespace std;

//2. Zona para constantes y variables globales




//3. Zona para definir las funciones


int menu_principal();
//4. Zona para la funcion principal

int main() {
	setlocale(LC_CTYPE,"Spanish");
	int op;
	do{
		system("cls");
		op = menu_principal();
		//operaciones(op);
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
















