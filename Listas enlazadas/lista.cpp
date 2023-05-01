#include<iostream>
#include "lista.h"
using namespace std;

void menu(nodo*);

int main(){
    nodo *p=NULL;
    menu(p);
    return 0;
}

void menu(nodo *p){
    int opcion;
    do{
        system("cls");
        cout<<"\n M\tE\tN\tU";
        cout<<"\n==========================";
        cout<<"\n\n1. CREACION POR EL INICIO";
        cout<<"\n\n2. CREACION POR EL FINAL";
        cout<<"\n\n3. RECORRIDO";
        cout<<"\n\n4. S A L I R";
        cout<<"\n\n\t\t\t\tOPCION: ";cin>>opcion;
        switch(opcion){
            case 1:{
                system("cls");
                p = crear_i(p);
                break;
            }
            case 2:{
                system("cls");
                p = crear_f(p);
                break;
            }
            case 3:{
                system("cls");
                mostrar(p);
                system("pause");
                break;
            }
        }
    }while(opcion!=4);
}