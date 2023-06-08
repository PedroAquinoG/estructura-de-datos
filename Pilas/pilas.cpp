#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void apilar(int*, int&, int, int);
void desapilar(int*, int&);

int main() {
    int max = 30;
    int pila[max];
    int tope = -1;
    apilar(pila, tope, max, 1);
    apilar(pila, tope, max, 2);
    apilar(pila, tope, max, 3);

    // Imprimir elementos de la pila
    for (int i = tope; i >= 0; i--) {
        cout << pila[i] << " ";
    }
    cout << endl;

    desapilar(pila, tope);

    // Imprimir elementos de la pila después de desapilar
    for (int i = tope; i >= 0; i--) {
        cout << pila[i] << " ";
    }
    cout << endl;
    return 0;
}

void apilar(int* pila, int& tope, int max, int dato) {
    if (tope < max - 1) {
        tope++;
        pila[tope] = dato;
    }
    else {
        cout << "Error: La pila esta llena." << endl;
    }
}

void desapilar(int* pila, int& tope) {
    if (tope >= 0) {
        tope--;
    }
    else {
        cout << "Error: La pila esta vacia." << endl;
    }
}
