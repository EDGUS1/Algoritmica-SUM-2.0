#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int main(){
	int clave,opc,cl,edad;
	char nombre[30];
	bool encontrado;
	ofstream guardar;
	ifstream leer;
	ofstream temp;
	guardar.open("ejemplo3.txt",ios::app);
	do{
		cout<<"*************************"<<endl;
		cout<<"********* MENU **********"<<endl;
		cout<<"*************************"<<endl;
		cout<<"* 1. Guardar fichero    *"<<endl;
		cout<<"* 2. Leer fichero       *"<<endl;
		cout<<"* 3. Buscar fichero     *"<<endl;
		cout<<"* 4. Eliminar fichero   *"<<endl;
		cout<<"* 5. Modificar fichero  *"<<endl;
		cout<<"* 0. Salir              *"<<endl;
		cout<<"*************************"<<endl;
		cout<<"*************************"<<endl;
		cout<<"Opcion -> ";
		cin>>opc;
		Sleep(200);
		system("cls");
		switch(opc){
			case 1:
				cout<<"_____________________"<<endl;
				cout<<"    INGRESAR DATOS   "<<endl;
				cout<<"_____________________"<<endl;
				cout<<"Ingrese nombre: ";
				fflush(stdin);
				cin.getline(nombre,30,'\n');
				cout<<"Ingrese clave: ";
				cin>>clave;
				cout<<"Ingrese edad: ";
				cin>>edad;
				guardar<<nombre<<" "<<clave<<" "<<edad<<endl;
				break;
			case 2:
				leer.open("ejemplo3.txt");
				leer>>nombre;
				cout<<"_____________________"<<endl;
				cout<<"    MOSTRAR DATOS    "<<endl;
				cout<<"_____________________"<<endl;
				while(!leer.eof()){
					leer>>clave>>edad;
					cout<<"_____________________"<<endl;
					cout<<"Nombre: "<<nombre<<endl;
					cout<<"Clave: "<<clave<<endl;
					cout<<"Edad: "<<edad<<endl;
					cout<<"_____________________"<<endl;
					leer>>nombre;
				}
				system("pause");
				system("cls");
				leer.close();
				break;
			case 3:
				leer.open("ejemplo3.txt");
				leer>>nombre;
				encontrado = false;
				cout<<"_____________________"<<endl;
				cout<<"  BUSQUEDA DE DATOS  "<<endl;
				cout<<"_____________________"<<endl;
				cout<<"Ingrese clave a buscar: ";
				cin>>cl;
				while(!leer.eof()){
					leer>>clave>>edad;
					if(clave == cl){
						encontrado = true;
						cout<<"_____________________"<<endl;
						cout<<"Nonbre: "<<nombre<<endl;
						cout<<"Clave: "<<clave<<endl;
						cout<<"Edad: "<<edad<<endl;
						cout<<"_____________________"<<endl;
					}
					leer>>nombre;
				}
				if(encontrado == false){
					cout<<"\nClave no encontrada..."<<endl;
				}
				system("pause");
				system("cls");
				leer.close();
				break;
			case 4:
				leer.open("ejemplo3.txt");
				temp.open("temp.txt");
				leer>>nombre;
				encontrado = false;
				cout<<"Ingrese clave a buscar: ";
				cin>>cl;
				while(!leer.eof()){
					leer>>clave>>edad;
					if(clave == cl){
						encontrado == true;
						cout<<"_____________________"<<endl;
						cout<<"Nonbre: "<<nombre<<endl;
						cout<<"Clave: "<<clave<<endl;
						cout<<"Edad: "<<edad<<endl;
						cout<<"_____________________"<<endl;
						cout<<"ELIMINADO"<<endl;
					}else{
						temp<<nombre<<" "<<clave<<" "<<edad<<endl;
					}
					leer>>nombre;
				}
				if(encontrado == false){
					cout<<"\nClave no encontrada..."<<endl;
				}
				system("pause");
				system("cls");
				leer.close();
				break;
		}
	}while(opc != 0);
	return 0;
}
