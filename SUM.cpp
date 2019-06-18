#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<cstdlib>
#include<conio.h>

using namespace std;

//fichero
ifstream leer;
ofstream temp;
ofstream guardar;
ifstream consultal;
ofstream log;

//variables globales
int clave,opc,cl,edad,nota,nota1,nota2,codigo;
char nombre[30],Nnombre[30],apellido1[30],nombre2[30];
bool encontrado;

//funciones
void menu1();
void menu2();
void newIngre();
void mostrar();
void buscar();
void borrar();
void modificar();
void loge();
void ingresolog();
int tomarInt();
bool tipoIntValido (string);

//estructuras
struct login{
	int codigo1,auxcodigo;
  	char nombre1[30],user[30],iuser[30],contr[30],icontr[30],apellidos[30],auxnombre[30],auxuser[30],auxiuser[30],auxcontr[30],auxicontr[30],auxapellidos[30];
}login;	

int main(){
	cout<<"______________"<<endl;
	cout<<"______________"<<endl;
	cout<<"__Bienvenido__"<<endl;
	cout<<"______________"<<endl;
	cout<<"______________"<<endl;
	system("pause");
	guardar.open("ejemplo4.txt",ios::app);
	menu2();

	return 0;
}

void menu1(){
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
		fflush(stdin);
		opc = tomarInt();	
		Sleep(300);
		switch(opc){
			case 1: newIngre(); break;
			case 2: mostrar(); break;
			case 3: buscar(); break;
			case 4: borrar(); break;
			case 5: modificar(); break;
			default:
				if(opc != 0){
					system("cls"); 
				}
		}
		if(opc == 0){
			cout<<"\n\nHasta pronto....\n\n";
		}
	}while(opc != 0);
}
void newIngre(){
	system("cls");
	cout<<"_____________________"<<endl;
	cout<<"    INGRESAR DATOS   "<<endl;
	cout<<"_____________________"<<endl;
	cout<<"Ingrese nombre: ";
	fflush(stdin);
	cin.getline(nombre,30,'\n');
	cout<<"Ingrese codigo: ";
	clave = tomarInt();
	cout<<"Ingrese edad: ";
	edad = tomarInt();
	cout<<"Ingrese nota 1: ";
	nota1 = tomarInt();
	guardar<<nombre<<" "<<clave<<" "<<edad<<" "<<nota1<<endl;
	cout<<"\n";
	leer.close();
	system("pause");
	system("cls");
}
void mostrar(){
	system("cls");
	leer.open("ejemplo4.txt");
	leer>>nombre;
	cout<<"_____________________"<<endl;
	cout<<"    MOSTRAR DATOS    "<<endl;
	cout<<"_____________________"<<endl;
	while(!leer.eof()){
		leer>>clave>>edad>>nota1;
		cout<<"_____________________"<<endl;
		cout<<"Nombre  :\t "<<nombre<<endl;
		cout<<"Apellido:\t "<<nombre<<endl;
		cout<<"Codigo  :\t "<<clave<<endl;
		cout<<"Edad    :\t "<<edad<<endl;
		cout<<"Nota 1  :\t "<<nota1<<endl;
		cout<<"Nota 2  :\t "<<nota1<<endl;
		cout<<"Nota 3  :\t "<<nota1<<endl;
		cout<<"Promedio:\t "<<nota1<<endl;
		cout<<"Nota faltante:\t "<<nota1<<endl;
		cout<<"_____________________"<<endl;
		leer>>nombre;
	}
	leer.close();
	system("pause");
	system("cls");
}
void buscar(){
	system("cls");
	leer.open("ejemplo4.txt");
	leer>>nombre;
	encontrado = false;
	cout<<"_____________________"<<endl;
	cout<<"  BUSQUEDA DE DATOS  "<<endl;
	cout<<"_____________________"<<endl;
	cout<<"Ingrese codigo a buscar: ";
	cl = tomarInt();
	while(!leer.eof()){
		leer>>clave>>edad>>nota1;
		if(clave == cl){
			encontrado = true;
			cout<<"_____________________"<<endl;
			cout<<"Nonbre: "<<nombre<<endl;
			cout<<"Codigo: "<<clave<<endl;
			cout<<"Edad: "<<edad<<endl;
			cout<<"Nota 1: "<<nota1<<endl;
			cout<<"_____________________"<<endl;
		}
		leer>>nombre;
	}
	if(encontrado == false){
		cout<<"\nCodigo no encontrado..."<<endl;
	}
	cout<<"\n";
	leer.close();
	system("pause");
	system("cls");
}
void borrar(){
	system("cls");
	leer.open("ejemplo4.txt");
	temp.open("temp1.txt");
	leer>>nombre;
	encontrado = false;
	cout<<"_____________________"<<endl;
	cout<<"    ELIMINAR DATOS   "<<endl;
	cout<<"_____________________"<<endl;
	cout<<"Ingrese codigo a eliminar: ";
	cl = tomarInt();
	while(!leer.eof()){
		leer>>clave>>edad>>nota1;
		if(clave == cl){
			encontrado = true;
			cout<<"_____________________"<<endl;
			cout<<"Nonbre: "<<nombre<<endl;
			cout<<"Codigo: "<<clave<<endl;
			cout<<"Edad: "<<edad<<endl;
			cout<<"Nota 1: "<<nota1<<endl;
			cout<<"_____________________"<<endl;
			cout<<"\nELIMINADO\n\n";
		}else{
			temp<<nombre<<" "<<clave<<" "<<edad<<" "<<nota1<<endl;
		}
		leer>>nombre;
	}
	if(encontrado == false){
		cout<<"\nCodigo no encontrada..."<<endl;
	}
	cout<<"\n";
	leer.close();
	guardar.close();
	temp.close();
	remove("ejemplo4.txt");
	rename("temp1.txt","ejemplo4.txt");
	system("pause");
	system("cls");
}
void modificar(){
	system("cls");
	leer.open("ejemplo4.txt");
	temp.open("temp1.txt");
	leer>>nombre;
	encontrado = false;
	cout<<"_____________________"<<endl;
	cout<<"   MODIFICAR DATOS   "<<endl;
	cout<<"_____________________"<<endl;
	cout<<"Ingrese codigo a modificar: ";
	cl = tomarInt();
	while(!leer.eof()){
		leer>>clave>>edad>>nota1;
		if(clave == cl){
			encontrado = true;
			cout<<"_____________________"<<endl;
			cout<<"Nonbre: "<<nombre<<endl;
			cout<<"Codigo: "<<clave<<endl;
			cout<<"Edad: "<<edad<<endl;
			cout<<"Nota 1: "<<nota1<<endl;
			cout<<"_____________________"<<endl;
			cout<<"Ingrese nuevo nombre: ";
			cin>>Nnombre;
			temp<<Nnombre<<" "<<clave<<" "<<edad<<" "<<nota1<<endl;
			cout<<"\nMODIFICADO"<<endl;
		}else{
			temp<<nombre<<" "<<clave<<" "<<edad<<" "<<nota1<<endl;
		}
		leer>>nombre;
	}
	if(encontrado == false){
		cout<<"\nCodigo no encontrada..."<<endl;
	}
	cout<<"\n";
	leer.close();
	guardar.close();
	temp.close();
	remove("ejemplo4.txt");
	rename("temp1.txt","ejemplo4.txt");
	system("pause");
	system("cls");
}
int tomarInt(){
	string num;
	bool valido = false;
	
	while (!valido){
		try{
//			system("cls");
//			cout<<"ingrese numero: ";
			getline(cin,num);
			valido = tipoIntValido(num);
			if(!valido){
				throw num;
			}
		}
		catch (string e){
			cout<<e<<" no valido "<<endl;
//			Sleep(500);
			getch();
//			system("cls");
		}
	}
	return atoi(num.c_str());
	
}
bool tipoIntValido (string nume){
	int inicio = 0,i;
	if(nume.length() == 0){
		return 0;
	}
	if(nume[0] == '+' || nume[0] == '-'){
		inicio = 1;
		if(nume.length() == 1){
			return 0;
		}
	}
	for(i=inicio;i<nume.length();i++){
		if(!isdigit(nume[i])){
			return 0;
		}
	}
	return 1;
}
void menu2(){
	log.open("Login.txt",ios::app);
  	int opcion;
  	while(opcion!=3){
  		system("cls");
  		cout<<"*****************"<<endl;
  		cout<<"*     LOGIN     *"<<endl;
  		cout<<"*1.Ingreso      *"<<endl;
  		cout<<"*2.Creacion     *"<<endl;
  		cout<<"*3.Salir        *"<<endl;
  		cout<<"*               *"<<endl;
  		cout<<"*****************"<<endl;
        log.close();
  		cout<<"Opcion -> ";
		opcion = tomarInt();
		Sleep(500);
  		switch(opcion){
  			case 1: loge(); break;
  			case 2: ingresolog(); break;
	        case 3: break;
//	        default: menu2();
  		}
  	}
}
void loge(){
  	system("cls");
  	consultal.close();
    log.close();
    log.open("Login.txt",ios::app);
  	consultal.open("Login.txt",ios::in);
  	bool si=false;
  	cout<<"Ingrese Usuario....: ";
  	cin>>login.iuser;
    cout<<"Ingrese Contrasena.: ";
  	cin>>login.icontr;
  	consultal>>login.codigo1;
  	while(!consultal.eof())
  	{
  	  	consultal>>login.apellidos>>login.nombre1>>login.user>>login.contr;
  	  	if((strcmp(login.user, login.iuser) == 0)&&(strcmp(login.contr, login.icontr)==0))
  	  	{
  	    	si=true;
  	    	system("cls");
  	    	cout<<"Bienvenido "<<login.nombre1<<"!!"<<endl;
        	strcpy(nombre2,login.nombre1);
        	strcpy(apellido1,login.apellidos);
  	    	codigo = login.codigo1;
//  	    	Sleep(1500);
  	    	system("cls");
//        	getch();
  	    	menu1();
  	  	}
  	  	consultal>>login.codigo1;
  	}
  	if(si==false)
    {
      	system("cls");
  		cout<<"Incorrecto Intentelo de Nuevo"<<endl;
  		getch();
  	}
  	consultal.close();
    log.close();
}
void ingresolog(){
  	system("cls");
  	log.close();
    consultal.close();
    cout<<"Creacion de Usuarios"<<endl;
    cout<<endl<<endl;
    bool repetido=false;
    log.open("Login.txt",ios::app);
    consultal.open("Login.txt");
    cout<<endl<<endl;
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
	printf("NOTA: el Codigo y el Usuario No se podran modificar en un futuro");
    cout<<endl<<endl;
    cout<<"Ingrese Codigo de Usuario....: ";cin>>login.auxcodigo;
    cout<<"Ingrese Usuario .............: ";cin >>login.auxuser;
    consultal>>login.codigo1;
    while(!consultal.eof())
    {
      	consultal>>login.apellidos>>login.nombre1>>login.user>>login.contr;
      	if((login.codigo1==login.auxcodigo)|(strcmp(login.user, login.auxuser) == 0))
      	{
        	system("cls");
			printf("Lo sentimos, Codigo o Usuario ya en Uso");
        	repetido=true;
        	log.close();
        	consultal.close();
        	break;
      	}
      	consultal>>login.codigo1;
    }	

    if(repetido==false)
    {
      	cout<<"Ingrese Apellidos............: ";cin>>login.apellidos;
      	cout<<"Ingrese Nombre...............: ";cin>>login.nombre1;
      	cout<<"Ingrese Contrasena...........: ";cin>>login.contr;
      	cout<<endl<<endl;
      	cout<<"\nGuardado Correctamente"<<endl;
      	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
      	log<<login.auxcodigo<<" "<<login.apellidos<<" "<<login.nombre1<<" "<<login.auxuser<<" "<<login.contr<<endl;
    }

    log.close();
    consultal.close();
    getch();
}

