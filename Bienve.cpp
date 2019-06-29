#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
void gotoxy(int,int);
void perm();
int main(){
	int a=0,b=20,x=0,e;
	srand(time(NULL));
	do{
		e=rand()%10;
		switch(e){
			case 1:system("color 0");break;
			case 2:system("color 2");break;
			case 3:system("color 3");break;
			case 4:system("color 4");break;
			case 5:system("color 5");break;
			case 6:system("color 6A");break;
			case 7:system("color 70");break;
			case 8:system("color C7");break;
			case 9:system("color 8F");break;
			case 10:system("color 21");break;
			default:system("color 24");
		}		
		system("cls");
		gotoxy(35,11);
		cout<<"BIENVENIDO"<<endl;
		a=6;
		b=50;
		x=30;
		for(int i=0;i<20;i++){
			gotoxy(x,6);
			cout<<"+";
			Sleep(50);
			x++;
		}
		for(int i=0;i<10;i++){
			gotoxy(50,a);
			cout<<"+";
			Sleep(40);
			a++;
		}
		for(int i=0;i<20;i++){
			gotoxy(b,a);
			cout<<"+";
			Sleep(30);
			b--;
		}
		for(int i=0;i<10;i++){
			gotoxy(b,a);
			cout<<"+";
			Sleep(20);
			a--;	
		}
//		system("cls");
		
//		void perm();
//		Sleep(1000);
//		system("pause");
//		system("cls");
		
//		void perm();
//		Sleep(1000);
	}while(!kbhit());
	gotoxy(0,20);
	return 0;
}
void gotoxy(int a,int b){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = a;
    dwPos.Y= b;
    SetConsoleCursorPosition(hcon,dwPos);  
}
void perm(){
		int a=6,x=30,b=50;
		for(int i=0;i<20;i++){
			gotoxy(x,6);
			cout<<"+";
//			Sleep(50);
			x++;
		}
		for(int i=0;i<10;i++){
			gotoxy(50,a);
			cout<<"+";
//			Sleep(40);
			a++;
		}
		for(int i=0;i<20;i++){
			gotoxy(b,a);
			cout<<"+";
//			Sleep(30);
			b--;
		}
		for(int i=0;i<10;i++){
			gotoxy(b,a);
			cout<<"+";
//			Sleep(20);
			a--;	
		}	
}
