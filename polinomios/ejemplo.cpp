#include <iostream>
using namespace std;

// Definición de la estructura del nodo
struct Nodo {
    int coeficiente;
    int exponente;
    Nodo* siguiente;
};

// Función para insertar un término al polinomio
void insertarTermino(Nodo** cabeza, int coeficiente, int exponente) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->coeficiente = coeficiente;
    nuevoNodo->exponente = exponente;
    nuevoNodo->siguiente = nullptr;

    if (*cabeza == nullptr) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para mostrar el polinomio
void mostrarPolinomio(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        cout << temp->coeficiente << "x^" << temp->exponente;
        temp = temp->siguiente;
        if (temp != nullptr) {
            cout << " + ";
        }
    }
    cout << endl;
}

// Función para sumar dos polinomios
Nodo* sumarPolinomios(Nodo* polinomio1, Nodo* polinomio2) {
    Nodo* resultado = nullptr;

    while (polinomio1 != nullptr && polinomio2 != nullptr) {
        if (polinomio1->exponente > polinomio2->exponente) {
            insertarTermino(&resultado, polinomio1->coeficiente, polinomio1->exponente);
            polinomio1 = polinomio1->siguiente;
        } else if (polinomio1->exponente < polinomio2->exponente) {
            insertarTermino(&resultado, polinomio2->coeficiente, polinomio2->exponente);
            polinomio2 = polinomio2->siguiente;
        } else {
            int coeficienteSuma = polinomio1->coeficiente + polinomio2->coeficiente;
            if (coeficienteSuma != 0) {
                insertarTermino(&resultado, coeficienteSuma, polinomio1->exponente);
            }
            polinomio1 = polinomio1->siguiente;
            polinomio2 = polinomio2->siguiente;
        }
    }

    // Agregar los términos restantes del polinomio1
    while (polinomio1 != nullptr) {
        insertarTermino(&resultado, polinomio1->coeficiente, polinomio1->exponente);
        polinomio1 = polinomio1->siguiente;
    }

    // Agregar los términos restantes del polinomio2
    while (polinomio2 != nullptr) {
        insertarTermino(&resultado, polinomio2->coeficiente, polinomio2->exponente);
        polinomio2 = polinomio2->siguiente;
    }

    return resultado
}

// Función principal
int main() {
    Nodo* polinomio1 = nullptr;
    Nodo* polinomio2 = nullptr;
    Nodo* resultado = nullptr;

    // Insertar términos en el primer polinomio
    insertarTermino(&polinomio1, 3, 4);
    insertarTermino(&polinomio1, 2, 2);
    insertarTermino(&polinomio1, 5, 0);

    // Insertar términos en el segundo polinomio
    insertarTermino(&polinomio2, 1, 3);
    insertarTermino(&polinomio2, -2, 2);
    insertarTermino(&polinomio2, 4, 1);

    cout << "Polinomio 1: ";
    mostrarPolinomio(polinomio1);

    cout << "Polinomio 2: ";
    mostrarPolinomio(polinomio2);

    resultado = sumarPolinomios(polinomio1, polinomio2);

    cout << "Resultado de la suma: ";
    mostrarPolinomio(resultado);

    // Liberar memoria
    Nodo* temp;
    while (polinomio1 != nullptr) {
        temp = polinomio1;
        polinomio1 = polinomio1->siguiente;
        delete temp;
    }

    while (polinomio2 != nullptr) {
        temp = polinomio2;
        polinomio2 = polinomio2->siguiente;
        delete temp;
    }

    while (resultado != nullptr) {
        temp = resultado;
        resultado = resultado->siguiente;
        delete temp;
    }

    return 0;
}