#include<iostream>
#include<cstdlib>
using namespace std;
int tomarInt();
bool tipoIntValido (string);
int main(){
	int numero;
	numero = tomarInt();
	cout<<numero<<endl;
	return 0;
}
int tomarInt(){
	string num;
	bool valido = false;
	
	while (!valido){
		try{
			cout<<"ingrese numero: ";
			getline(cin,num);
			valido = tipoIntValido(num);
			if(!valido){
				throw num;
			}
		}
		catch (string e){
			cout<<e<<" no valido"<<endl;
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
