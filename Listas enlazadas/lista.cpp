#include <iostream>
#include <string>
#include <iomanip>
#include "lista.h"

using namespace std;

void menu(nodo*);

int main() {
    alumno a = {119016, "Carla Flores", 18.6, 19.1, 18.85};
    alumno b = {119002, "Maria Rodriguez", 17.2, 15.5, 16.35};
    alumno c = {119014, "Roberto Castro", 14.3, 12.6, 13.45};

    nodo* p = NULL;
    p = new nodo{a, NULL};
    nodo* q = p;
    q->sig = new nodo{b, NULL};
    q = q->sig;
    q->sig = new nodo{c, NULL};

    menu(p);

    return 0;
}

void menu(nodo* p) {
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
                            p = crear_i(p);
                            system("cls");
                            break;
                        }
                        case 2:{
                            p = crear_f(p);
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
                    cout << "\n\n1. INSERTAR ANTES DE...";
                    cout << "\n\n2. INSERTAR DESPUES DE...";
                    cout << "\n\n3. S A L I R";
                    cout << "\n\n\t\tOPCION: ";
                    cin >> opcion3;
                    system("cls");
                    switch (opcion3) {
                        case 1:{
                            int coda;
                            recorrer(p);
                            cout<<"INSERTAR ANTES DE: "<<endl;
                            cout<<"INGRESE CODIGO DE REFERENCIA: ";cin >> coda;
                            p = insertar_ad(p, coda);
                            system("cls");
                            cout<<"\nINSERTADO CORRECTAMENTE"<<endl<<endl;
                            recorrer(p);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 2:{
                            int codd;
                            recorrer(p);
                            cout<<"INSERTAR DESPUES DE: "<<endl;
                            cout<<"INGRESE CODIGO DE REFERENCIA: ";cin>>codd;
                            p = insertar_dd(p, codd);
                            system("cls");
                            cout<<"\nINSERTADO CORRECTAMENTE"<<endl<<endl;
                            recorrer(p);
                            system("pause");
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
                } while (opcion3 != 3);
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
                            p = eliminar_p(p);
                            system("cls");
                            break;
                        }
                        case 2:{
                            p = eliminar_u(p);
                            system("cls");
                            break;
                        }
                        case 3:{
                            int codx;
                            recorrer(p);
                            cout<<"INGRESE CODIGO DEL NODO A ELIMINAR: ";cin>>codx;
                            p = eliminar_x(p,codx);
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
                            p = eliminar_ad(p,codad);
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
                            p = eliminar_dd(p,coddd);
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