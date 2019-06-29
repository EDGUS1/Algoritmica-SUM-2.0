#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<cstdlib>
#include<conio.h>

using namespace std;

//ficheros
ifstream leer;
ofstream temp;
ofstream guardar;
ifstream consultal;
ofstream log;
ifstream consultal2;
ofstream log2;

//variables globales
int clave,opc,cl,codigo,edad,codigo10,x1,y1;
double prom,falta,nota1,nota2,nota3;
char nombre[30],Nnombre[30],apellido1[30],nombre2[30],nombre10[30],Nnombre10[30],apellido10[30],nombre20[30],apel[40];
bool encontrado;

//funciones
void menu1();
void menu2();
void menuAlumn();
void newIngre();
void mostrar();
void buscar();
void borrar();
void modificar();
void loge();
void ingresolog();
void ingresolog2();
int tomarInt();
bool tipoIntValido (string);
void gotoxy(int,int);

//estructuras
struct login{
	int codigo1,auxcodigo;
  	char nombre1[30],user[30],iuser[30],contr[30],icontr[30],apellidos[30],auxnombre[30],auxuser[30],auxiuser[30],auxcontr[30],auxicontr[30],auxapellidos[30];
}login;	
struct login2{
	int codigo10,auxcodigo10;
  	char nombre10[30],user10[30],iuser10[30],contr10[30],icontr10[30],apellidos10[30],auxnombre10[30],auxuser10[30],auxiuser10[30],auxcontr10[30],auxicontr10[30],auxapellidos10[30];
}login2;	

int main(){
	cout<<"\n\n\n\n\n\n\t\t\t\t__________________"<<endl;
	cout<<"\t\t\t\t__________________"<<endl;
	cout<<"\t\t\t\t___ Bienvenido ___"<<endl;
	cout<<"\t\t\t\t__________________"<<endl;
	cout<<"\t\t\t\t__________________\n\n\n\n\n\n"<<endl;
	cout.precision(2);
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
		x1 = 10;
		y1 = 11;
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
	cout<<"    _____________________"<<endl;
	cout<<"        INGRESAR DATOS   "<<endl;
	cout<<"    _____________________"<<endl;
	cout<<"Ingrese nombre.......................: ";
	fflush(stdin);
	cin.getline(nombre,30,'\n');
	cout<<"Ingrese apellido.....................: ";
	fflush(stdin);
	cin.getline(apel,30,'\n');
	cout<<"Ingrese codigo.......................: ";
	fflush(stdin);
	x1 = 39;
	y1 = 5;
	clave = tomarInt();
	cout<<"Ingrese edad.........................: ";
	x1 = 39;
	y1 = 6;
	edad = tomarInt();
	cout<<"Ingrese nota del examen parcial......: ";
	x1 = 39;
	y1 = 7;
	nota1 = tomarInt();
	cout<<"Ingrese nota del examen final........: ";
	x1 = 39;
	y1 = 8;
	nota2 = tomarInt();
	cout<<"Ingrese nota de evaluacion continua..: ";
	x1 = 39;
	y1 = 9;
	nota3 = tomarInt();
	prom = (nota1+nota2+nota3)/3;
	if(prom > 10.5){
		falta = 0;
	}else{
		falta = 10.5 - prom;
	}
	guardar<<nombre<<" "<<apel<<" "<<clave<<" "<<edad<<" "<<nota1<<" "<<nota2<<" "<<nota3<<" "<<prom<<" "<<falta<<endl;
	cout<<"\n";
	leer.close();
	system("pause");
	system("cls");
}
void mostrar(){
	system("cls");
	leer.open("ejemplo4.txt");
	leer>>nombre;
	cout<<"    _____________________"<<endl;
	cout<<"        MOSTRAR DATOS    "<<endl;
	cout<<"    _____________________"<<endl;
	while(!leer.eof()){
		leer>>apel>>clave>>edad>>nota1>>nota2>>nota3>>prom>>falta;
		cout<<"______________________________________"<<endl;
		cout<<"Nombre.........................: "<<nombre<<endl;
		cout<<"Apellido.......................: "<<apel<<endl;
		cout<<"Codigo.........................: "<<clave<<endl;
		cout<<"Edad...........................: "<<edad<<endl;
		cout<<"Nota del parcial...............: "<<nota1<<endl;
		cout<<"Nota del final.................: "<<nota2<<endl;
		cout<<"Nota de la evaluacion continua.: "<<nota3<<endl;
		cout<<"Promedio.......................: "<<prom<<endl;
		cout<<"Nota faltante para aprobar.....: "<<falta<<endl;
		cout<<"______________________________________"<<endl;
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
	cout<<"    _____________________"<<endl;
	cout<<"      BUSQUEDA DE DATOS  "<<endl;
	cout<<"    _____________________"<<endl<<endl;
	cout<<"Ingrese codigo a buscar: ";
	x1 = 25;
	y1 = 4; 
	cl = tomarInt();
	while(!leer.eof()){
		leer>>apel>>clave>>edad>>nota1>>nota2>>nota3>>prom>>falta;
		if(clave == cl){
			encontrado = true;
			cout<<"______________________________________"<<endl;
			cout<<"Nombre.........................: "<<nombre<<endl;
			cout<<"Apellido.......................: "<<apel<<endl;
			cout<<"Codigo.........................: "<<clave<<endl;
			cout<<"Edad...........................: "<<edad<<endl;
			cout<<"Nota del parcial...............: "<<nota1<<endl;
			cout<<"Nota del final.................: "<<nota2<<endl;
			cout<<"Nota de la evaluacion continua.: "<<nota3<<endl;
			cout<<"Promedio.......................: "<<prom<<endl;
			cout<<"Nota faltante para aprobar.....: "<<falta<<endl;
			cout<<"______________________________________"<<endl;
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
	cout<<"    _____________________"<<endl;
	cout<<"        ELIMINAR DATOS   "<<endl;
	cout<<"    _____________________"<<endl<<endl;
	cout<<"Ingrese codigo a eliminar: ";
	x1 = 25;
	y1 = 4;
	cl = tomarInt();
	while(!leer.eof()){
		leer>>apel>>clave>>edad>>nota1>>nota2>>nota3>>prom>>falta;
		if(clave == cl){
			encontrado = true;
			cout<<"______________________________________"<<endl;
			cout<<"Nombre.........................: "<<nombre<<endl;
			cout<<"Apellido.......................: "<<apel<<endl;
			cout<<"Codigo.........................: "<<clave<<endl;
			cout<<"Edad...........................: "<<edad<<endl;
			cout<<"Nota del parcial...............: "<<nota1<<endl;
			cout<<"Nota del final.................: "<<nota2<<endl;
			cout<<"Nota de la evaluacion continua.: "<<nota3<<endl;
			cout<<"Promedio.......................: "<<prom<<endl;
			cout<<"Nota faltante para aprobar.....: "<<falta<<endl;
			cout<<"______________________________________"<<endl;
			cout<<"\nELIMINADO\n\n";
		}else{
			temp<<nombre<<" "<<apel<<" "<<clave<<" "<<edad<<" "<<nota1<<" "<<nota2<<" "<<nota3<<" "<<prom<<" "<<falta<<endl;
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
	cout<<"_____________________"<<endl<<endl;
	cout<<"Ingrese codigo a modificar: ";
	x1 = 25;
	y1 = 4;
	cl = tomarInt();
	while(!leer.eof()){
		leer>>apel>>clave>>edad>>nota1>>nota2>>nota3>>prom>>falta;
		if(clave == cl){
			encontrado = true;
			cout<<"______________________________________"<<endl;
			cout<<"Nombre.........................: "<<nombre<<endl;
			cout<<"Apellido.......................: "<<apel<<endl;
			cout<<"Codigo.........................: "<<clave<<endl;
			cout<<"Edad...........................: "<<edad<<endl;
			cout<<"Nota del parcial...............: "<<nota1<<endl;
			cout<<"Nota del final.................: "<<nota2<<endl;
			cout<<"Nota de la evaluacion continua.: "<<nota3<<endl;
			cout<<"Promedio.......................: "<<prom<<endl;
			cout<<"Nota faltante para aprobar.....: "<<falta<<endl;
			cout<<"______________________________________"<<endl;
			cout<<"Ingrese nuevo nombre: ";
			cin>>Nnombre;
			temp<<Nnombre<<" "<<apel<<" "<<clave<<" "<<edad<<" "<<nota1<<" "<<nota2<<" "<<nota3<<" "<<prom<<" "<<falta<<endl;
			cout<<"\nMODIFICADO"<<endl;
		}else{
			temp<<nombre<<" "<<apel<<" "<<clave<<" "<<edad<<" "<<nota1<<" "<<nota2<<" "<<nota3<<" "<<prom<<" "<<falta<<endl;
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
			cout<<"    *** "<<e<<" no valido ***"<<endl;
			Sleep(1000);
			gotoxy(x1,y1);
			cout<<"                                               "<<endl;
			gotoxy(0,y1+1);
			cout<<"                                               "<<endl;
			gotoxy(x1,y1);
//			getch();
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
	log2.open("Login2.txt",ios::app);
  	int opcion;
  	while(opcion!=3){
  		system("cls");
  		cout<<"*****************"<<endl;
  		cout<<"*     LOGIN     *"<<endl;
  		cout<<"*1. Ingreso     *"<<endl;
  		cout<<"*2. Creacion    *"<<endl;
  		cout<<"*3. Salir       *"<<endl;
  		cout<<"*               *"<<endl;
  		cout<<"*****************"<<endl;
        log.close();
        log2.close();
  		cout<<"Opcion -> ";
  		fflush(stdin);
  		x1 = 10;
  		y1 = 7;
		opcion = tomarInt();
		Sleep(500);
  		switch(opcion){
  			case 1: loge(); break;
  			case 2: ingresolog2(); break;
	        case 3: break;
	        case 13: ingresolog();break;
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
  	consultal2.close();
    log2.close();
    log2.open("Login2.txt",ios::app);
  	consultal2.open("Login2.txt",ios::in);
  	bool si=false;
  	cout<<"___________________________________"<<endl;
  	cout<<"Ingrese Usuario....: ";
  	cin>>login.iuser;
//  	login2.iuser10 = login.iuser;
    cout<<"Ingrese Contrasena.: ";
	cin>>login.icontr;
	cout<<"___________________________________"<<endl;
//  	login2.icontr10 = login.icontr;
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
  	    	Sleep(1000);
  	    	system("cls");
//        	getch();
  	    	menu1();
  	  	}
  	  	consultal>>login.codigo1;
  	}
  	consultal2>>login2.codigo10;
  	while(!consultal2.eof())
  	{
  	  	consultal2>>login2.apellidos10>>login2.nombre10>>login2.user10>>login2.contr10;
  	  	consultal>>login.apellidos>>login.nombre1>>login.user>>login.contr;
  	  	if((strcmp(login2.user10, login.iuser) == 0)&&(strcmp(login2.contr10, login.icontr)==0))
  	  	{
  	    	si=true;
  	    	system("cls");
  	    	cout<<"Bienvenido "<<login2.nombre10<<"!!"<<endl;
        	strcpy(nombre20,login2.nombre10);
        	strcpy(apellido10,login2.apellidos10);
  	    	codigo10 = login2.codigo10;
  	    	Sleep(1000);
  	    	system("cls");
//        	getch();
  	    	menuAlumn();
  	  	}
  	  	consultal>>login.codigo1;
  	  	consultal2>>login2.codigo10;
  	}
  	if(si==false)
    {
      	system("cls");
  		cout<<"Incorrecto Intentelo de Nuevo"<<endl;
  		Sleep(1000);
//  		getch();
  	}
  	consultal.close();
    log.close();
    consultal2.close();
    log2.close();
}
void ingresolog(){
  	system("cls");
  	log.close();
    consultal.close();
    cout<<"                       Creacion de Usuarios"<<endl;
    cout<<endl<<endl;
    bool repetido=false;
    log.open("Login.txt",ios::app);
    consultal.open("Login.txt");
    cout<<endl<<endl;
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
	printf("     NOTA: el Codigo y el Usuario No se podran modificar en un futuro");
    cout<<endl<<endl;
    x1 = 31;
	y1 = 8;
    cout<<"Ingrese Codigo de Usuario....: ";login.auxcodigo = tomarInt();
    cout<<"Ingrese Usuario .............: ";cin >>login.auxuser;
    consultal>>login.codigo1;
    while(!consultal.eof()){
      	consultal>>login.apellidos>>login.nombre1>>login.user>>login.contr;
      	if((login.codigo1==login.auxcodigo)|(strcmp(login.user, login.auxuser) == 0)){
        	system("cls");
			printf("Lo sentimos, Codigo o Usuario ya en Uso");
        	repetido=true;
        	log.close();
        	consultal.close();
        	break;
      	}
      	consultal>>login.codigo1;
    }	

    if(repetido==false){
    	fflush(stdin);
      	cout<<"Ingrese Apellidos............: ";cin.getline(login.apellidos,50,'\n');
      	fflush(stdin);
      	cout<<"Ingrese Nombre...............: ";cin.getline(login.nombre1,50,'\n');
      	fflush(stdin);
      	cout<<"Ingrese Contrasena...........: ";cin.getline(login.contr,50,'\n');
      	cout<<endl<<endl;
      	cout<<"\nGuardado Correctamente"<<endl;
      	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
      	log<<login.auxcodigo<<" "<<login.apellidos<<" "<<login.nombre1<<" "<<login.auxuser<<" "<<login.contr<<endl;
    }

    log.close();
    consultal.close();
    Sleep(500);
//    getch();
}
void menuAlumn(){
	int aux;
	
	do{
		system("cls");
		cout<<"****************"<<endl;
		cout<<"*MENU DE ALUMNO*"<<endl;
		cout<<"*              *"<<endl;
		cout<<"*1. Buscar     *"<<endl;
		cout<<"*2. Mostrar    *"<<endl;
		cout<<"*0. Salir      *"<<endl;
		cout<<"*              *"<<endl;
		cout<<"****************"<<endl;
		cout<<"Opcion -> ";
		fflush(stdin);
		x1 = 10;
		y1 = 8;
		aux = tomarInt();
		switch (aux){
			case 1:buscar();break;
			case 2:mostrar();break;
			case 0:break;
		}
		
	}while(aux != 0);
}
void ingresolog2(){
  	system("cls");
  	log2.close();
    consultal2.close();
    cout<<"                       Creacion de Usuarios"<<endl;
    cout<<endl<<endl;
    bool repetido=false;
    log2.open("Login2.txt",ios::app);
    consultal2.open("Login2.txt");
    cout<<endl<<endl;
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
	printf("     NOTA: el Codigo y el Usuario No se podran modificar en un futuro");
    cout<<endl<<endl;
    x1 = 31;
	y1 = 8;
    cout<<"Ingrese Codigo de Usuario....: ";login2.auxcodigo10 = tomarInt();
    cout<<"Ingrese Usuario .............: ";cin >>login2.auxuser10;
    consultal2>>login2.codigo10;
    while(!consultal2.eof()){
      	consultal2>>login2.apellidos10>>login2.nombre10>>login2.user10>>login2.contr10;
      	if((login2.codigo10==login2.auxcodigo10)|(strcmp(login2.user10, login2.auxuser10) == 0)){
        	system("cls");
			printf("Lo sentimos, Codigo o Usuario ya en Uso");
        	repetido=true;
        	log2.close();
        	consultal2.close();
        	break;
      	}
      	consultal2>>login2.codigo10;
    }	

    if(repetido==false){
    	fflush(stdin);
      	cout<<"Ingrese Apellidos............: ";cin>>login2.apellidos10;
      	fflush(stdin);
		cout<<"Ingrese Nombre...............: ";cin>>login2.nombre10;
      	cout<<"Ingrese Contrasena...........: ";cin>>login2.contr10;
      	cout<<endl<<endl;
      	cout<<"\nGuardado Correctamente"<<endl;
      	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
      	log2<<login2.auxcodigo10<<" "<<login2.apellidos10<<" "<<login2.nombre10<<" "<<login2.auxuser10<<" "<<login2.contr10<<endl;
    }

    log2.close();
    consultal2.close();
    Sleep(500);
//    getch();
}
void gotoxy(int a,int b){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = a;
    dwPos.Y= b;
    SetConsoleCursorPosition(hcon,dwPos);  
}
