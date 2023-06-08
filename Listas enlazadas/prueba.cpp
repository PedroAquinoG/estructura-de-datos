/*Crear un programa que almacene en un array, nombre, dni y telefono. Ordenados de manera ascendente por el dni.
Y luego pasarlo a una lista simplemente enlazada ordenados por numero de telefono descendente.*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct humano {
    string nombre;
    int dni;
    int telefono;
};

struct nodo {
    humano inf;
    nodo* sig;
};

void insertar_o(humano*, int&, int);
nodo* trasladar_o(humano*, int, nodo*);
void mostrar_array(humano*, int);
void mostrar_lista(nodo*);

int main() {
    int max = 20;
    nodo* p = NULL;
    int n_alumnos = 0;
    humano alumnos[max];
    insertar_o(alumnos, n_alumnos, max);
    mostrar_array(alumnos, n_alumnos);
    p = trasladar_o(alumnos, n_alumnos, p);
    mostrar_lista(p);
    return 0;
}

void insertar_o(humano* x, int& n, int max) {
    char s;
    int i = 0;
    humano aux;
    do {
        if (n < max) {
            n++;
            cout << "\nNUEVO ALUMNO: " << endl;
            cout << "\nDNI: ";
            cin >> x[i].dni;
            cout << "\nNombre y apellido: ";
            cin.ignore();
            getline(cin, x[i].nombre);
            cout << "\nTelefono: ";
            cin >> x[i].telefono;
            if (n > 1) {
                int m = n - 1;
                while (m > 0 && x[m].dni < x[m - 1].dni) {
                    aux = x[m - 1];
                    x[m - 1] = x[m];
                    x[m] = aux;
                    m--;
                }
            }
            i++;
        }
        else {
            cout << "No hay espacio en el Array.." << endl << endl;
            system("pause");
            break;
        }
        cout << "MAS DATOS? (s/n): ";
        cin >> s;
    } while (s == 's' || s == 'S');
}

nodo* trasladar_o(humano* x, int n, nodo* p) {
    for (int i = 0; i < n; i++) {
        nodo* q = new nodo;
        q->inf = x[i];
        q->sig = NULL;
        if (p == NULL || x[i].telefono < p->inf.telefono) {
            q->sig = p;
            p = q;
        }
        else {
            nodo* r = p;
            while (r->sig != NULL && x[i].telefono > r->sig->inf.telefono) {
                r = r->sig;
            }
            q->sig = r->sig;
            r->sig = q;
        }
    }
    return p;
}

void mostrar_array(humano* x, int n) {
    if (n > 0) {
        cout << "\nR    E   G   I   S   T   R   O   : " << endl << endl;
        cout << setw(20) << "NOMBRE Y APELLIDO" << setw(20);
        cout << "DNI" << setw(20);
        cout << "Telefono" << endl << endl;
        for (int i = 0; i < n; i++) {
            cout << setw(20) << x[i].nombre << setw(20);
            cout << x[i].dni << setw(20);
            cout << x[i].telefono << endl;
        }
        cout << endl;
    }
}

void mostrar_lista(nodo* p) {
    nodo* q = p;
    cout << "\nR    E   G   I   S   T   R   O   : " << endl << endl;
    cout << setw(20) << "NOMBRE Y APELLIDO" << setw(20);
    cout << "DNI" << setw(20);
    cout << "Telefono" << endl << endl;
    while (q != NULL) {
        cout << setw(20) << q->inf.nombre << setw(20);
        cout << q->inf.dni << setw(20);
        cout << q->inf.telefono << endl;
        q = q->sig;
    }
    cout << endl << endl;
}