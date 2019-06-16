#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>

using namespace std;
void loge();
void ingresolog();
char apellido[30],nombre[30];
int codigo;
ifstream consultal;
ofstream log;
struct login{
  	int edad,codigo,auxedad,auxcodigo;
  	char nombre[30],user[30],iuser[30],contr[30],icontr[30],apellidos[30],auxnombre[30],auxuser[30],auxiuser[30],auxcontr[30],auxicontr[30],auxapellidos[30];
};	
login login;


int main()
{
    log.open("Login.txt",ios::app);
  	int opcion;
  	while(opcion!=3)
  	{
  		system("cls");
  		cout<<"***********************************"<<endl;
  		cout<<"*	                                *"<<endl;
  		cout<<"*	        1....Ingreso            *"<<endl;
  		cout<<"*	        2....Creacion           *"<<endl;
  		cout<<"*	        3....Salir              *"<<endl;
  		cout<<"*	                                *"<<endl;
  		cout<<"***********************************"<<endl;
        log.close();
  		cin>>opcion;
  		switch(opcion){
  			case 1:
  				loge();
  	    		break;
  			case 2:
  				ingresolog();
  				break;
	        case 3:
	          	break;
  		}
  	}
  	return 0;
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
  	consultal>>login.codigo;
  	while(!consultal.eof())
  	{
  	  	consultal>>login.apellidos>>login.nombre>>login.user>>login.contr;
  	  	if((strcmp(login.user, login.iuser) == 0)&&(strcmp(login.contr, login.icontr)==0))
  	  	{
  	    	si=true;
  	    	system("cls");
  	    	cout<<"Bienvenido "<<login.nombre<<"!!"<<endl;
        	strcpy(nombre,login.nombre);
        	strcpy(apellido,login.apellidos);
  	    	codigo=login.codigo;
        	getch();
//  	    	menu();
  	  	}
  	  	consultal>>login.codigo;
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
void ingresolog()
{
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
    cout<<"                   Ingrese Codigo de Usuario....: ";cin>>login.auxcodigo;
    cout<<"                   Ingrese Usuario (Nick).......: ";cin >>login.auxuser;
    consultal>>login.codigo;
    while(!consultal.eof())
    {
      	consultal>>login.apellidos>>login.nombre>>login.user>>login.contr;
      	if((login.codigo==login.auxcodigo)|(strcmp(login.user, login.auxuser) == 0))
      	{
        	system("cls");
			printf("Lo sentimos, Codigo o Usuario ya en Uso");
        	repetido=true;
        	log.close();
        	consultal.close();
        	break;
      	}
      	consultal>>login.codigo;
    }	

    if(repetido==false)
    {
      	cout<<"                   Ingrese Apellidos............: ";cin>>login.apellidos;
      	cout<<"                   Ingrese Nombre...............: ";cin>>login.nombre;
      	cout<<"                   Ingrese Contrasena...........: ";cin>>login.contr;
      	cout<<endl<<endl;
      	cout<<"                            Guardado Correctamente"<<endl;
      	cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
      	log<<login.auxcodigo<<" "<<login.apellidos<<" "<<login.nombre<<" "<<login.auxuser<<" "<<login.contr<<endl;
    }

    log.close();
    consultal.close();
    getch();
}
