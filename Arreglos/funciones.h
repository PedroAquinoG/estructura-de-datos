#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string>
using namespace std;

struct alumno {
    int orden;
    int codigo;
    string nombre;
    float nota1, nota2;
    float promedio;
};

int busqueda(alumno*, int, int);
void ordenacion(alumno*, int);

void mostrar(alumno*,int);
void mostrar_uno(alumno*,int);

void insercion_o(alumno*, int, int, int);
void eliminacion_o(alumno*, int, int);
void modificacion_o(alumno*, int, int, int);

void insercion_d(alumno*, int, int, int);
void eliminacion_d(alumno*, int, int);
void modificacion_d(alumno*, int, float, float);


int busqueda(alumno *x, int n, int codigo){
    int i=0;
    int pos;
    while (i < n && x[i].codigo < codigo) {
        i++;
    }
    if(i>n || x[i].codigo>codigo){
        pos=-i;
        return pos;
    }
    else{
        pos=i;
        return pos;
    }
}

void ordenacion(alumno *x, int n){
    alumno aux;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[j].codigo>x[j+1].codigo){
                aux=x[j];
                x[j]=x[j+1];
                x[j+1]=aux;
            }
        }
    }
    for(int i=0;i<n;i++){
        x[i].orden=i+1;
    }
}

void mostrar(alumno *x,int n){
    cout << "\n<<<<<<<<<<<<<<<<  R    E   G   I   S   T   R   O   :  >>>>>>>>>>>>>>>>" << endl<<endl;
    cout << setw(10)<<"#ORDEN" <<setw(10);
    cout << "CODIGO"<<setw(20);
    cout << "NOMBRE Y APELLIDO" <<setw(10);
    cout << "NOTA 1"<<setw(10);
    cout << "NOTA 2"<<setw(10);
    cout << "PROMEDIO"<<endl<<endl;
    for (int i = 0; i < n; i++) {
        cout <<setw(10)<<x[i].orden << setw(10);
        cout <<x[i].codigo << setw(20);
        cout <<x[i].nombre <<setw(10);
        cout <<x[i].nota1 << setw(10);
        cout <<x[i].nota2 << setw(10);
        cout <<x[i].promedio <<endl;
    }
    cout<<endl;
}

void mostrar_uno(alumno *x, int n){
    int i=n-1;
    cout << "\n<<<<<<<<<<<<<<<<  R    E   G   I   S   T   R   O   :  >>>>>>>>>>>>>>>>" << endl<<endl;
    cout << setw(10)<<"#ORDEN" <<setw(10);
    cout << "CODIGO"<<setw(20);
    cout << "NOMBRE Y APELLIDO" <<setw(10);
    cout << "NOTA 1"<<setw(10);
    cout << "NOTA 2"<<setw(10);
    cout << "PROMEDIO"<<endl<<endl;
    cout <<setw(10)<<x[i].orden << setw(10);
    cout <<x[i].codigo << setw(20);
    cout <<x[i].nombre <<setw(10);
    cout <<x[i].nota1 << setw(10);
    cout <<x[i].nota2 << setw(10);
    cout <<x[i].promedio <<endl;
    cout<<endl;
}

void insercion_o(alumno* x, int& n, int max, int dato) {
    int pos;
    if (n == max) {
        cout << "El arreglo está lleno" << endl;
    }
    else {
        pos = busqueda(x, n, dato);
        if (pos < 0) {
            x[n].codigo = dato;
            n = n + 1;
        }
        else {
            cout << "\nEl dato se repite" << endl;
        }
    }
}

void eliminacion_o(alumno* x, int& n, int dato) {
    int pos;
    if (n > 0) {
        pos = busqueda(x, n, dato);
        if (pos >= 0) {
            n--;
            for (int i = pos; i < n; i++) {
                x[i] = x[i + 1];
            }
        }
        else {
            cout << "No se encontró el dato" << endl;
        }
    }
    else {
        cout << "El array no tiene datos" << endl;
    }
}

void modificacion_o(alumno* x, int n, int dato1, int dato2) {
    int pos;
    if (n > 0) {
        pos = busqueda(x, n, dato1);
        if (pos >= 0) {
            x[pos].codigo = dato2;
            ordenacion(x, n);
        }
        else {
            cout << "No se encontró el dato" << endl;
        }
    }
    else {
        cout << "El array no tiene datos" << endl;
    }
}

void insercion_d(alumno* x, int& n, int max, int dato) {
    int pos;
    if (n == max) {
        cout << "El arreglo está lleno" << endl;
    }
    else {
        pos = busqueda(x, n, dato);
        if (pos < 0) {
            x[n].codigo = dato;
            n++;
        }
        else {
            cout << "\nEl dato se repite" << endl;
        }
    }
}

void eliminacion_d(alumno* x, int& n, int dato) {
    if (n > 0) {
        int i = 0;
        while (i < n) {
            if (x[i].codigo == dato) {
                for (int j = i; j < n - 1; j++) {
                    x[j] = x[j + 1];
                }
                n--;
                break;
            }
            i++;
        }
        if (i == n) {
            cout << "El dato no fue encontrado" << endl;
        }
    }
    else {
        cout << "No hay datos" << endl;
    }
}

void modificacion_d(alumno* x, int n, float dato1, float dato2) {
    if (n > 0) {
        int i = 0;
        int cen = 0;
        while (i < n) {
            if (x[i].codigo == dato1) {
                cen = 1;
                x[i].codigo = dato2;
                break;
            }
            i++;
        }
        if (cen == 0) {
            cout << "El dato no existe" << endl;
        }
    }
    else {
        cout << "El array no tiene datos" << endl;
    }
}
#endif