#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct alumno {
    int codigo;
    string nombre;
    float nota1;
    float nota2;
    float promedio;
};

struct nodo {
    alumno inf;
    nodo* sig;
};

nodo* crear_i(nodo* p);
nodo* crear_f(nodo* p);
nodo* insertar_ad(nodo* p, int ref);
nodo* insertar_dd(nodo* p, int ref);
nodo* eliminar_p(nodo* p);
nodo* eliminar_u(nodo* p);
nodo* eliminar_x(nodo* p, int x);
nodo* eliminar_ad(nodo* p, int ref);
nodo* eliminar_dd(nodo* p, int ref);
void recorrer(nodo* p);
void buscar(nodo* p, int x);

nodo* crear_i(nodo* p) {
    nodo* q;
    char op;
    do {
        system("cls");
        q = new nodo;
        cout << "\nCodigo: ";
        cin >> q->inf.codigo;
        cout << "Nombre: ";
        fflush(stdin);
        getline(cin, q->inf.nombre);
        cout << "Nota 1: ";
        cin >> q->inf.nota1;
        cout << "Nota 2: ";
        cin >> q->inf.nota2;
        q->inf.promedio = (q->inf.nota1 + q->inf.nota2) / 2.0;
        q->sig = p;
        p = q;
        cout << "\n\n\t\tMAS DATOS? (S/N): ";
        cin >> op;
    } while (op == 's' || op == 'S');

    return p;
}

nodo* crear_f(nodo* p) {
    nodo* q, * r;
    char op;
    do {
        system("cls");
        q = new nodo;
        cout << "\nCodigo: ";
        cin >> q->inf.codigo;
        cout << "Nombre: ";
        fflush(stdin);
        getline(cin, q->inf.nombre);
        cout << "Nota 1: ";
        cin >> q->inf.nota1;
        cout << "Nota 2: ";
        cin >> q->inf.nota2;
        q->inf.promedio = (q->inf.nota1 + q->inf.nota2) / 2;
        q->sig = NULL;
        if (p == NULL) {
            p = q;
        }
        else {
            r->sig = q;
        }
        r = q;
        cout << "\n\tMAS DATOS? (S/N): ";
        cin >> op;
    } while (op == 's' || op == 'S');
    return p;
}

nodo* insertar_ad(nodo* p, int ref) {
    nodo* q, * r, *x;
    int cen;
    if (p != NULL) {
        q = p;
        cen = 0;
        while ((q->inf.codigo != ref) && (cen == 0)){
            if (q->sig != NULL){
                r = q;
                q = q->sig;
            }
            else {
                cen++;
            }
        }
        if (cen == 0) {
            x = new (nodo);
            cout << "\nCodigo: ";
            cin >> x->inf.codigo;
            cout << "Nombre: ";
            fflush(stdin);
            getline(cin, x->inf.nombre);
            cout << "Nota 1: ";
            cin >> x->inf.nota1;
            cout << "Nota 2: ";
            cin >> x->inf.nota2;
            x->inf.promedio = (x->inf.nota1 + x->inf.nota2)/2;
            x->sig = q;
            if (p == q) {
                p = x;
            }
            else {
                r->sig = x;
            }
        }
        else {
            cout << "El dato de referencia no existe...." << endl << endl;
        }
    }
    else {
        cout << "No hay datos..." << endl;
    }
    return p;
}

nodo* insertar_dd(nodo* p, int ref) {
    nodo* q, * r, * x;
    int cen;
    if (p != NULL) {
        q = p;
        cen = 0;
        while ((q->inf.codigo != ref) && (cen == 0)) {
            if (q->sig != NULL) {
                q = q->sig;
            }
            else {
                cen++;
            }
        }
        if (cen == 0) {
            x = new nodo;
            cout << "\nCodigo: ";
            cin >> x->inf.codigo;
            cout << "Nombre: ";
            fflush(stdin);
            getline(cin, x->inf.nombre);
            cout << "Nota 1: ";
            cin >> x->inf.nota1;
            cout << "Nota 2: ";
            cin >> x->inf.nota2;
            x->inf.promedio = (x->inf.nota1 + x->inf.nota2) / 2;
            x->sig = q->sig;
            q->sig = x;
        }
        else {
            cout << "El dato de referencia no existe...." << endl << endl;
        }
    }
    else {
        cout << "No hay datos..." << endl;
    }
    return p;
}

nodo* eliminar_p(nodo* p) {
    nodo* q;
    if (p != NULL) {
        q = p;
        p = p->sig;
        delete (q);
    }
    else {
        cout << "No hay datos..." << endl << endl;
    }
    return p;
}

nodo* eliminar_u(nodo* p) {
    nodo* q, * r;
    if (p != NULL) {
        q = p;
        while (q->sig != NULL) {
            r = q;
            q = q->sig;
        }
        if (p == q) {
            p = NULL;
        }
        else {
            r->sig = NULL;
        }
        delete (q);
    }
    else {
        cout << "No hay datos..." << endl << endl;
    }
    return p;
}

nodo* eliminar_x(nodo* p, int x) {
    nodo* q, * r;
    int cen;
    if (p != NULL) {
        q = p;
        cen = 0;
        while ((q->inf.codigo != x) && (cen == 0)) {
            if (q->sig != NULL) {
                r = q;
                q = q->sig;
            }
            else {
                cen++;
            }
        }
        if (cen == 0) {
            if (q == p) {
                p = p->sig;
            }
            else {
                r->sig = q->sig;
            }
            delete (q);
        }
        else {
            cout << "No existe el dato..." << endl << endl;
        }
    }
    else {
        cout << "No hay datos..." << endl << endl;
    }
    return p;
}

nodo* eliminar_ad(nodo* p, int ref) {
    nodo* q, * r, * s;
    int cen;
    if (p != NULL) {
        q = p;
        r = q;
        cen = 0;
        while ((q->inf.codigo != ref) && (cen == 0)) {
            if (q->sig != NULL) {
                s = r;
                r = q;
                q = q->sig;
            }
            else {
                cen++;
            }
        }
        if (cen == 0) {
            if (p != q) {
                if (p == r) {
                    p = q;
                }
                else {
                    s->sig = q;
                }
                delete (r);
            }
            else {
                cout << "No hay anterior..." << endl << endl;
            }
        }
        else {
            cout << "No se encontró el dato de referencia..." << endl << endl;
        }
    }
    else {
        cout << "Lista vacía..." << endl << endl;
    }
    return p;
}

nodo* eliminar_dd(nodo* p, int ref) {
    nodo* q, * r;
    int cen;
    if (p != NULL) {
        q = p;
        cen = 0;
        while ((q->inf.codigo != ref) && (cen == 0)) {
            if (q->sig != NULL) {
                q = q->sig;
            }
            else {
                cen++;
            }
        }
        if (cen == 0) {
            r = r->sig;
            if (r != NULL) {
                q->sig = r->sig;
                delete (r);
            }
            else {
                cout << "No hay siguiente dato..." << endl << endl;
            }
        }
        else {
            cout << "El dato de referencia no existe..." << endl << endl;
        }
    }
    else {
        cout << "No hay datos..." << endl << endl;
    }
    return p;
}

void recorrer(nodo* p) {
    nodo* q;
    q = p;
    cout << "\n<<<<<<<<<<<<<<  R    E   G   I   S   T   R   O   :  >>>>>>>>>>>>>>" << endl<<endl;
    cout << setw(10)<<"CODIGO"<<setw(20);
    cout << "NOMBRE Y APELLIDO" <<setw(10);
    cout << "NOTA 1"<<setw(10);
    cout << "NOTA 2"<<setw(10);
    cout << "PROMEDIO"<<endl<<endl;
    while (q != NULL) {
        cout <<setw(10)<<q->inf.codigo << setw(20);
        cout <<q->inf.nombre <<setw(10);
        cout <<q->inf.nota1 << setw(10);
        cout <<q->inf.nota2 << setw(10);
        cout <<q->inf.promedio <<endl;
        q=q->sig;
    }
    cout << endl << endl;
}

void buscar(nodo* p, int x) {
    nodo* q;
    q = p;
    while (q!= NULL) {
        if (q->inf.codigo == x) {
            cout<<endl;
            cout<<"EL ALUMNO CON CODIGO "<<q->inf.codigo<<" SE ENCUENTRA EN EL REGISTRO"<<endl<<endl;
            cout << setw(10)<<"CODIGO"<<setw(20);
            cout << "NOMBRE Y APELLIDO" <<setw(10);
            cout << "NOTA 1"<<setw(10);
            cout << "NOTA 2"<<setw(10);
            cout << "PROMEDIO"<<endl<<endl;
            cout <<setw(10)<<q->inf.codigo << setw(20);
            cout <<q->inf.nombre <<setw(10);
            cout <<q->inf.nota1 << setw(10);
            cout <<q->inf.nota2 << setw(10);
            cout <<q->inf.promedio <<endl<<endl;
            break;
        }
        q = q->sig;
    }
    if (q==NULL) {
        cout << "NO SE ENCONTRO EL DATO DE REFERENCIA.." << endl << endl;
    }
}

#endif
