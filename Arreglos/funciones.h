#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include "busqueda.h"
#include "ordenacion.h"

using namespace std;

void insercion_o(int*, int, int, int);
void eliminacion_o(int*, int, int);
void modificacion_o(int*, int, int, int);

void insercion_d(int*, int, int, int);
void eliminacion_d(int*, int, int);
void modificacion_d(int*, int, float, float);


void insercion_o(int *x, int n, int max, int dato){
    int pos;
    if(n==max){
        cout<<"El arreglo esta lleno"<<endl;
    }
    else{
        pos = busqueda(x, n, dato);
        if(pos<0){
            x[n+1]=dato;
            n=n+1;
        }
        else{
            cout<<"\nEl dato se repite"<<endl;
        }
    }
}

void eliminacion_o(int *x, int n, int dato){
    int pos;
    if(n>0){
        pos=busqueda(x,n,dato);
        if(pos>0){
            n--;
            for(int i=pos; i<n; i++){
                x[i]=x[i+1];
            }
        }
        else{
            cout<<"No se encontro el dato"<<endl;
        }
    }
    else{
        cout<<"El array no tiene datos"<<endl;
    }
}

void modificacion_o(int *x, int n, int dato1, int dato2){
    int pos;
    if(n>0){
        pos=busqueda(x,n,dato1);
        if(pos>0){
            x[pos]=dato2;
            ordenacion(x,n);
        }
        else{
            cout<<"No se encontro el dato"<<endl;
        }
    }
    else{
        cout<<"El array no tiene datos";
    }
}

void insercion_d(int *x, int n, int max, int dato){
    int pos;
    if(n==max){
        cout<<"El arreglo esta lleno"<<endl;
    }
    else{
        pos = busqueda(x, n, dato);
        if(pos<0){
            x[n+1]=dato;
        }
        else{
            cout<<"\nEl dato se repite"<<endl;
        }
    }
}

void eliminacion_d(int *x, int n,int dato) {
    if(n>0){
        for (int i = 0; i < n; i++){
            if (x[i] == dato) {
                for (int j = i; j < n-1; j++) {
                    x[j] = x[j+1];
                }
            n=n-1;
            break;
            }
        }

        cout<<"El dato no fue encontrado"<<endl;
    } 
    else{
        cout<<"No hay datos"<<endl;
    }
}

void modificacion_d(int *x, int n, float dato1, float dato2){
    if(n>0){
        int i=0;
        int cen=0;
        while((i<=n) && (cen=0)){
            if(x[i]==dato1){
                cen=1;
                x[i]=dato2;
            }
            else{
                i++;
            }
        }
        if(cen==0){
            cout<<"El dato no existe"<<endl;
        }
        else{}
    }
    else{
        cout<<"El array no tiene datos";
    }
}

#endif