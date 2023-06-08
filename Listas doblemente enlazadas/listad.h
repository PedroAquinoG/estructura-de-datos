#ifndef LISTAD_H
#define LISTAD_H

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
    nodo* ant;
};
void creard_i(nodo*& p, nodo*& f);
void creard_f(nodo*& p, nodo*& f);
void insertard_i(nodo*& p, nodo*& f);
void insertard_f(nodo*& p, nodo*& f);
void insertard_ad(nodo*& p, nodo*& f, int ref);
void insertard_dd(nodo*& p, nodo*& f, int ref);
void eliminard_p(nodo*& p, nodo*& f);
void eliminard_u(nodo*& p, nodo*& f);
void eliminard_x(nodo*& p, nodo*& f, int x);
void eliminard_ad(nodo*& p, int ref);
void eliminard_dd(nodo*& f, int ref);
void recorrer(nodo* p);
void buscar(nodo* p, int x);

void creard_i(nodo*& p, nodo*& f) {
    char op;
    do {
        system("cls");
        nodo* q = new nodo;
        cout << "\nCODIGO: ";
        cin >> q->inf.codigo;
        cout << "NOMBRE: ";
        fflush(stdin);
        getline(cin, q->inf.nombre);
        cout << "NOTA 1: ";
        cin >> q->inf.nota1;
        cout << "NOTA 2: ";
        cin >> q->inf.nota2;
        q->inf.promedio = (q->inf.nota1 + q->inf.nota2) / 2.0;
        q->ant = NULL;
        q->sig = p;
        if (p == NULL) {
            f = q;
        }
        else {
            p->ant = q;
        }
        p = q;
        cout << "\n\n\t\tMAS DATOS? (S/N): ";
        cin >> op;
    } while (op == 's' || op == 'S');
}

void creard_f(nodo*& p, nodo*& f) {
    char op;
    do {
        system("cls");
        nodo* q = new nodo;
        cout << "\nCODIGO: ";
        cin >> q->inf.codigo;
        cout << "NOMBRE: ";
        fflush(stdin);
        getline(cin, q->inf.nombre);
        cout << "NOTA 1: ";
        cin >> q->inf.nota1;
        cout << "NOTA 2: ";
        cin >> q->inf.nota2;
        q->inf.promedio = (q->inf.nota1 + q->inf.nota2) / 2.0;
        q->sig = NULL;
        q->ant = f;
        if (p == NULL) {
            p = q;
        }
        else {
            f->sig = q;
        }
        f = q;
        cout << "\n\tMAS DATOS? (S/N): ";
        cin >> op;
    } while (op == 's' || op == 'S');
}

void insertard_i(nodo*& p, nodo*& f) {
    nodo* q = new nodo;
    cout << "\nCODIGO: ";
    cin >> q->inf.codigo;
    cout << "NOMBRE: ";
    fflush(stdin);
    getline(cin, q->inf.nombre);
    cout << "NOTA 1: ";
    cin >> q->inf.nota1;
    cout << "NOTA 2: ";
    cin >> q->inf.nota2;
    q->inf.promedio = (q->inf.nota1 + q->inf.nota2) / 2.0;
    q->ant = NULL;
    q->sig = p;
    if (p == NULL) {
        f = q;
    }
    else {
        p->ant = q;
    }
    p = q;
}

void insertard_f(nodo*& p, nodo*& f) {
    nodo* q = new nodo;
    cout << "\nCODIGO: ";
    cin >> q->inf.codigo;
    cout << "NOMBRE: ";
    fflush(stdin);
    getline(cin, q->inf.nombre);
    cout << "NOTA 1: ";
    cin >> q->inf.nota1;
    cout << "NOTA 2: ";
    cin >> q->inf.nota2;
    q->inf.promedio = (q->inf.nota1 + q->inf.nota2) / 2.0;
    q->sig = NULL;
    q->ant = f;
    if (p == NULL) {
        p = q;
    }
    else {
        f->sig = q;
    }
    f = q;
}

void insertard_ad(nodo*& p, nodo*& f, int ref) {
    nodo* q = p;
    while (q != NULL && q->inf.codigo != ref) {
        q = q->sig;
    }
    if (q != NULL) {
        nodo* x = new nodo;
        cout << "\nCODIGO: ";
        cin >> x->inf.codigo;
        cout << "NOMBRE: ";
        fflush(stdin);
        getline(cin, x->inf.nombre);
        cout << "NOTA 1: ";
        cin >> x->inf.nota1;
        cout << "NOTA 2: ";
        cin >> x->inf.nota2;
        x->inf.promedio = (x->inf.nota1 + x->inf.nota2) / 2.0;
        x->sig = q;
        x->ant = q->ant;
        if (q->ant != NULL) {
            q->ant->sig = x;
        }
        else {
            p = x;
        }
        q->ant = x;
    }
    else {
        cout << "El dato de referencia no existe." << endl;
    }
}

void insertard_dd(nodo*& p, nodo*& f, int ref) {
    nodo* q = p;
    while (q != NULL && q->inf.codigo != ref) {
        q = q->sig;
    }
    if (q != NULL) {
        nodo* x = new nodo;
        cout << "\nCODIGO: ";
        cin >> x->inf.codigo;
        cout << "NOMBRE: ";
        fflush(stdin);
        getline(cin, x->inf.nombre);
        cout << "NOTA 1: ";
        cin >> x->inf.nota1;
        cout << "NOTA 2: ";
        cin >> x->inf.nota2;
        x->inf.promedio = (x->inf.nota1 + x->inf.nota2) / 2.0;
        x->ant = q;
        x->sig = q->sig;
        if (q->sig != NULL) {
            q->sig->ant = x;
        }
        else {
            f = x;
        }
        q->sig = x;
    }
    else {
        cout << "El dato de referencia no existe." << endl;
    }
}

void eliminard_p(nodo*& p, nodo*& f) {
    if (p != NULL) {
        nodo* q = p;
        p = p->sig;
        if (p != NULL) {
            p->ant = NULL;
        }
        else {
            f = NULL;
        }
        delete q;
    }
    else {
        cout << "No hay datos." << endl;
    }
}

void eliminard_u(nodo*& p, nodo*& f) {
    nodo* q;
    if (p != NULL) {
        q = f;
        f = f->ant;
        if (p == q) {
            p = f;
        }
        else {
            f->sig = NULL;
        }
        delete (q);
    }
    else {
        cout << "No hay datos..." << endl << endl;
    }
}

void eliminard_x(nodo*& p, nodo*& f, int x) {
    nodo* q, * r, * t;
    int cen;
    if (p != NULL) {
        q = p;
        cen = 0;
        while ((q->inf.codigo != x) && (cen == 0)) {
            if (q->sig != NULL) {
                q = q->sig;
            }
            else {
                cen++;
            }
        }
        if (cen == 0) {
            if (p == f) {
                p = NULL;
                f = NULL;
            }
            else {
                if (p == q) {
                    p = p->sig;
                    p->ant = NULL;
                }
                else {
                    if (q == f) {
                        f = f->ant;
                        f->sig = NULL;
                    }
                    else {
                        r = q->ant;
                        t = q->sig;
                        r->sig = t;
                        t->ant = r;
                    }
                }
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
}

void eliminard_ad(nodo*& p, int ref){
    nodo *q, *r, *s;
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
            if (p != q) {
                r=q->ant;
                s=r->ant;
                q->ant=s;
                if(p==r){
                    p=p->sig;
                }
                else{
                    s->sig=q;
                }
                delete(r);
            }
            else {
                cout<<"No hay nodo anterior..."<<endl<<endl;
            }
        }
        else {
            cout << "El dato de referencia no existe...." <<endl<< endl;
        }
    }
    else {
        cout << "No hay datos..." << endl;
    }
}

void eliminard_dd(nodo*& f, int ref) {
    nodo* q, * r, * s;
    int cen;
    if (f != NULL) {
        q = f;
        cen = 0;
        while ((q->inf.codigo != ref) && (cen == 0)) {
            if (q->ant != NULL) {
                q = q->ant;
            }
            else {
                cen++;
            }
        }
        if (cen == 0) {
            if (q != f){
                r=q->sig;
                s=r->sig;
                q->sig=s;
                if(f==r){
                    f=q;
                }
                else{
                    s->ant = q;
                }
                delete(r);
            }
            else {
                cout<<"No hay nodo despues..."<<endl<<endl;
            }
            }
        else {
            cout << "El dato de referencia no existe...." <<endl<< endl;
        }
    }
    else {
        cout << "No hay datos..." << endl;
    }
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