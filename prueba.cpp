#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main(int argc, char** argv) {
	fstream archivo("registro.txt");
	string nombre, apellido, direccion, linea, cadena, lin, lin2, lin3, lin4;
	int telefono, op, op2, res = 0;
	do{
		cout<<"1. Nuevo registro\n2. leer registro\n3.buscar\n4. Salir\n";
		cin>>op;
		cin.ignore();
		if(op == 1){
			if(!archivo.is_open()){
				archivo.open("registro.txt",ios::out);
			}
			cout<<"nombre: ";
			getline(cin,nombre);
			cout<<"apellido: ";
			getline(cin, apellido);
			cout<<"Direccion: ";
			getline(cin,direccion);
			cout<<"telefono: ";
			cin>>telefono;
			
			cout<<"1. Guardar\n2. Regresar\n";
			cin>>op2;
			if(op2 == 1){
				archivo<<"nombre: "<<nombre<<endl;
				archivo<<"apellido: "<<apellido<<endl;
				archivo<<"direccion: "<<direccion<<endl;
				archivo<<"telefono: "<<telefono<<endl;
				system("cls");
				cout<<"registro guardado con exito...\n";
				system("pause");
				system("cls");
			}
			archivo.close();
		}
		if(op == 2){
			if(!archivo.is_open()){
				archivo.open("registro.txt",ios::in);
			}
			while(getline(archivo, linea)){
				cout<<linea<<"\n";
			}
			archivo.close();
			system("pause");
		}
		if(op == 3){
			cout<<"nombre: ";
			cin>>cadena;
			if(!archivo.is_open()){
				archivo.open("registro.txt",ios::in);
			}
			while(getline(archivo, lin)){
				if(lin.find(cadena) != string::npos){
					cout<<lin<<endl;
					getline(archivo,lin2);
					cout<<lin2<<endl;
					getline(archivo,lin3);
					cout<<lin3<<endl;
					getline(archivo,lin4);
					cout<<lin4<<endl;
					res = 1;
				}
			}
			if (res == 0){
				cout<<cadena<< " no encontrado..."<<endl;
			}
			system("pause");
		}
	}while(op != 4);
	return 0;
}
