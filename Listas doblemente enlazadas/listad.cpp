#include <iostream>
#include <string>
#include <iomanip>
#include "listad.h"

using namespace std;

void menu(nodo*,nodo*);

int main() {
    alumno a = {119016, "Carla Flores", 18.6, 19.1, 18.85};
    alumno b = {119002, "Maria Rodriguez", 17.2, 15.5, 16.35};
    alumno c = {119014, "Roberto Castro", 14.3, 12.6, 13.45};

    nodo* p = NULL;
    nodo* f = NULL;
    p = new nodo{a, NULL, NULL};
    nodo* q = p;
    q->sig = new nodo{b, NULL, NULL};
    q = q->sig;
    q->sig = new nodo{c, NULL, NULL};

    menu(p,f);

    return 0;
}

void menu(nodo* p,nodo* f) {
    int opcion1,opcion2,opcion3,opcion4;
    system("cls");
    do {
        cout << "\nM\tE\tN\tU";
        cout << "\n==========================";
        cout << "\n\n1. CREACION NEW NODO";
        cout << "\n\n2. INSERTAR NODOS";
        cout << "\n\n3. ELIMINAR NODOS";
        cout << "\n\n4. BUSCAR";
        cout << "\n\n5. MOSTRAR - RECORRER";
        cout << "\n\n6. S A L I R";
        cout << "\n\n\t\tOPCION: ";
        cin >> opcion1;
        system("cls");
        switch (opcion1) {
            case 1:{
                do {
                    cout << "\nM\tE\tN\tU";
                    cout << "\n==========================";
                    cout << "\n\n1. CREACION EN EL INICIO";
                    cout << "\n\n2. CREAR POR EL FINAL";
                    cout << "\n\n3. S A L I R";
                    cout << "\n\n\t\tOPCION: ";
                    cin >> opcion2;
                    system("cls");
                    switch (opcion2) {
                        case 1:{
                            creard_i(p,f);
                            system("cls");
                            break;
                        }
                        case 2:{
                            creard_f(p,f);
                            system("cls");
                            break;
                        }
                        case 3:{
                            cout<<"\tREGRESANDO....."<<endl<<endl;
                            system("pause");
                            system("cls");
                            break;
                        }
                        default:{
                            cout<<"\tOPCION INVALIDA"<<endl;
                            cout<<"\tINTENTE NUEVAMENTE....."<<endl<<endl;
                            system("pause");
                            system("cls");
                        }
                    }
                    system("cls");
                } while (opcion2 != 3);
                system("cls");
                break;
            }
            case 2:{
                do {
                    cout << "\nM\tE\tN\tU";
                    cout << "\n==========================";
                    cout << "\n\n1. INSERTAR AL INICIO";
                    cout << "\n\n2. INSERTAR AL FINAL";
                    cout << "\n\n3. INSERTAR ANTES DE...";
                    cout << "\n\n4. INSERTAR DESPUES DE...";
                    cout << "\n\n5. S A L I R";
                    cout << "\n\n\t\tOPCION: ";
                    cin >> opcion3;
                    system("cls");
                    switch (opcion3) {
                        case 1:{
                            insertard_i(p,f);
                            system("cls");
                            break;
                        }
                        case 2:{
                            insertard_f(p,f);
                            system("cls");
                            break;
                        }
                        case 3:{
                            int coda;
                            recorrer(p);
                            cout<<"INSERTAR ANTES DE: "<<endl;
                            cout<<"INGRESE CODIGO DE REFERENCIA: ";cin >> coda;
                            insertard_ad(p,f,coda);
                            system("cls");
                            cout<<"\nINSERTADO CORRECTAMENTE"<<endl<<endl;
                            recorrer(p);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 4:{
                            int codd;
                            recorrer(p);
                            cout<<"INSERTAR DESPUES DE: "<<endl;
                            cout<<"INGRESE CODIGO DE REFERENCIA: ";cin>>codd;
                            insertard_dd(p,f,codd);
                            system("cls");
                            cout<<"\nINSERTADO CORRECTAMENTE"<<endl<<endl;
                            recorrer(p);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 5:{
                            cout<<"\tREGRESANDO....."<<endl<<endl;
                            system("pause");
                            system("cls");
                            break;
                        }
                        default:{
                            cout<<"\tOPCION INVALIDA"<<endl;
                            cout<<"\tINTENTE NUEVAMENTE....."<<endl<<endl;
                            system("pause");
                            system("cls");
                        }
                    }
                    system("cls");
                } while (opcion3 != 5);
                system("cls");
                break;
            }
            case 3:{
                do {
                    recorrer(p);
                    cout << "\nM\tE\tN\tU";
                    cout << "\n==========================";
                    cout << "\n\n1. ELIMINAR PRIMER NODO";
                    cout << "\n\n2. ELIMINAR ULTIMO NODO";
                    cout << "\n\n3. ELIMINAR NODO X";
                    cout << "\n\n4. ELIMINAR ANTES DE...";
                    cout << "\n\n5. ELIMINAR DESPUES DE...";
                    cout << "\n\n6. S A L I R";
                    cout << "\n\n\t\tOPCION: ";
                    cin >> opcion4;
                    system("cls");
                    switch (opcion4) {
                        case 1:{
                            eliminard_p(p,f);
                            system("cls");
                            break;
                        }
                        case 2:{
                            eliminard_u(p,f);
                            system("cls");
                            break;
                        }
                        case 3:{
                            int codx;
                            recorrer(p);
                            cout<<"INGRESE CODIGO DEL NODO A ELIMINAR: ";cin>>codx;
                            eliminard_x(p,f,codx);
                            system("cls");
                            cout<<"\nELIMINADO CORRECTAMENTE"<<endl<<endl;
                            recorrer(p);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 4:{
                            int codad;
                            recorrer(p);
                            cout<<"INGRESE CODIGO DE REFERENCIA: ";cin>>codad;
                            eliminard_ad(p,codad);
                            system("cls");
                            cout<<"\nELIMINADO CORRECTAMENTE"<<endl<<endl;
                            recorrer(p);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 5:{
                            int coddd;
                            recorrer(p);
                            cout<<"INGRESE CODIGO DE REFERENCIA: ";cin>>coddd;
                            eliminard_dd(f,coddd);
                            system("cls");
                            cout<<"\nELIMINADO CORRECTAMENTE"<<endl<<endl;
                            recorrer(p);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 6:{
                            cout<<"\tREGRESANDO....."<<endl<<endl;
                            system("pause");
                            system("cls");
                            break;
                        }
                        default:{
                            cout<<"\tOPCION INVALIDA"<<endl;
                            cout<<"\tINTENTE NUEVAMENTE....."<<endl<<endl;
                            system("pause");
                            system("cls");
                        }
                    }
                    system("cls");
                } while (opcion4 != 6);
                system("cls");
                break;
            }
            case 4:{
                int codb;
                cout<<"\nINGRESE CODIGO DE REFERENCIA: ";cin>>codb;
                system("cls");
                buscar(p,codb);
                system("pause");
                system("cls");
                break;
            }
            case 5:{
                recorrer(p);
                system("pause");
                system("cls");
                break;
            }
            case 6:{
                cout<<"\tHASTA LUEGO....."<<endl<<endl;
                system("pause");
                system("cls");
                break;
            }
            default:{
                cout<<"\tOPCION INVALIDA"<<endl;
                cout<<"\tINTENTE NUEVAMENTE....."<<endl<<endl;
                system("pause");
                system("cls");
            }
        }
        system("cls");
    } while (opcion1 != 6);
}