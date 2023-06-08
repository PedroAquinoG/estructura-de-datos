#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include "funciones.h"
#define max 10

using namespace std;

void mostrar(alumno*, int);
void mostrar_uno(alumno*,int);
void mostrarcods(int*, int);
void ordenar(int*, alumno*, int);

int main(){
    int n_estudiantes=9;
    alumno estudiante[max];

    estudiante[0] = {1, 119016, "Carla Flores", 18.6, 19.1, 18.85};
    estudiante[1] = {2, 119002, "Maria Rodriguez", 17.2, 15.5, 16.35};
    estudiante[2] = {3, 119014, "Roberto Castro", 14.3, 12.6, 13.45};
    estudiante[3] = {4, 119000, "Juan Perez", 14.5, 16.8, 15.65};
    estudiante[4] = {5, 119004, "Pedro Gonzalez", 12.8, 13.9, 13.35};
    estudiante[5] = {6, 119006, "Ana Sanchez", 15.6, 14.3, 14.95};
    estudiante[6] = {7, 119010, "Mario Ruiz", 11.7, 14.9, 13.30};
    estudiante[7] = {8, 119012, "Sofia Jimenez", 16.9, 15.8, 16.35};
    estudiante[8] = {9, 119008, "Luisa Torres", 13.4, 16.1, 14.75};
    //estudiante[9] = {10, 119020, "Luis Ramirez", 15.5, 12.3,13.9};
    
    int opcion;

    /*MENU DE ARREGLOS*/
    do {
        system("cls");
        cout << "\nMENU ARREGLOS" << endl;
        cout << "\n1. ARREGLOS DESORDENADOS" << endl;
        cout << "\n2. ARREGLOS ORDENADOS" << endl;
        cout << "\n3. SALIR" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1:{

                /*MENU ARREGLOS DESORDENADOS*/
                int opcion1;
    
                do {
                    cout << "\nMENU ARREGLOS DESORDENADOS" << endl;
                    cout << "\n1. INSERTAR" << endl;
                    cout << "\n2. ELIMINAR" << endl;
                    cout << "\n3. MODIFICAR" << endl;
                    cout << "\n4. MOSTRAR" << endl;
                    cout << "\n5. SALIR" << endl;
                    cout << "\nIngrese una opcion: ";
                    cin >> opcion1;
                    system("cls");
                    switch (opcion1) {
                        case 1:{
                            cout<<"\nAsigne un codigo.....\nDebe tener 6 digitos y empezar en 1190_ _"<<endl;
                            cout <<"Codigo: ";cin >> estudiante[n_estudiantes].codigo;
                            system("cls");
                            insercion_d(cods,n_estudiantes,max,estudiante[n_estudiantes].codigo);
                            if (estudiante[n_estudiantes].codigo==cods[n_estudiantes+1]) {
                                cout<< "\nSe a comprobado que si hay espacio disponible......"<<endl;
                                cout << "\nIngrese los datos del nuevo alumno:" << endl;
                                estudiante[n_estudiantes].orden=estudiante[n_estudiantes-1].orden+1;
                                cout << "Orden asignado: "<<estudiante[n_estudiantes].orden<<endl;
                                cout << "Codigo asignado: "<<estudiante[n_estudiantes].codigo<<endl;
                                cout << "Nombre y apellido: ";fflush(stdin);getline(cin,estudiante[n_estudiantes].nombre);
                                cout << "Nota 1: ";cin >> estudiante[n_estudiantes].nota1;
                                cout << "Nota 2: ";cin >> estudiante[n_estudiantes].nota2;
                                estudiante[n_estudiantes].promedio=(estudiante[n_estudiantes].nota1+estudiante[n_estudiantes].nota2)/2;
                                cout<<"Promedio: "<<estudiante[n_estudiantes].promedio<<endl;
                                n_estudiantes=n_estudiantes+1;
                            }
                            else{
                                cout<<"No hay cupo para mas estudiantes........"<<endl;
                            }
                            system("pause");
                            system("cls");
                            break; 
                        }
                        case 2:{
                            int op;
                            cout<<"\nQUE ALUMNO DESEA ELIMINAR DE LA LISTA?"<<endl<<endl;
                            mostrar(estudiante,n_estudiantes);
                            cout<<"INGRESE EL # DE ORDEN: ";cin>>op;
                            eliminacion_d(cods,n_estudiantes,estudiante[op-1].codigo);
                            for (i = op-1; i < n_estudiantes; i++){
                                estudiante[i] = estudiante[i+1];
                                estudiante[i].orden=estudiante[i].orden-1;
                            }
                            n_estudiantes--;
                            system("cls");
                            cout<<"\nTABLA DE REGISTROS ACTUALIZADA...."<<endl<<endl;
                            mostrar(estudiante,n_estudiantes);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 3:{
                            int op1;
                            int a;
                            char s;
                                do{
                                    system("cls");
                                    mostrar(estudiante,n_estudiantes);
                                    cout << "\nQUE DATO DESEA MODIFICAR?"<<endl<< endl;
                                    cout << "\n1. NOTA 1" << endl;
                                    cout << "\n2. NOTA 2" << endl;                            
                                    cout << "\n3. SALIR" << endl;
                                    cout << "\nIngrese una opcion: ";
                                    cin >> op1;
                                    system("cls");
                                    switch(op1){
                                        case 1:{
                                            mostrar(estudiante,n_estudiantes);
                                            cout<<"INGRESE EL # DE ORDEN DEL ESTUDIANTE \nAL QUE SE LE REALIZARA LA MODIFICACION DE NOTAS: ";cin>>a;
                                            cout<<endl;
                                            system("cls");
                                            mostrar_uno(estudiante,a);
                                            cout<<"ACTUALIZE LA NOTA 1: ";cin>>estudiante[a-1].nota1;
                                            estudiante[a-1].promedio = (estudiante[a-1].nota1 + estudiante[a-1].nota2)/2;
                                            system("cls");
                                            cout<<"NOTAS DE ESTUDIANTE ACTUALIZADAS";                                                        
                                            mostrar_uno(estudiante,a);
                                            system("pause");
                                            system("cls");
                                            break;
                                        }
                                        case 2:{
                                            mostrar(estudiante,n_estudiantes);
                                            cout<<"INGRESE EL # DE ORDEN DEL ESTUDIANTE \nAL QUE SE LE REALIZARA LA MODIFICACION DE NOTAS: ";cin>>a;
                                            cout<<endl;
                                            system("cls");
                                            mostrar_uno(estudiante,a);
                                            cout<<"ACTUALIZE LA NOTA 2: ";cin>>estudiante[a-1].nota2;
                                            estudiante[a-1].promedio = (estudiante[a-1].nota1 + estudiante[a-1].nota2)/2;
                                            system("cls");
                                            cout<<"NOTAS DE ESTUDIANTE ACTUALIZADAS";                                                        
                                            mostrar_uno(estudiante,a);
                                            system("pause");
                                            system("cls");
                                            break;
                                        }
                                        case 3:{
                                            cout << "Volviendo......" << endl;
                                            system("pause");
                                            system("cls");
                                            break;
                                        }
                                        default:{
                                            cout << "Opcion invalida. Intente nuevamente........." <<endl<<endl;
                                            system("pause");
                                            system("cls");
                                            break;
                                        }
                                    }
                                }while (op1 != 3);                           
                            break;
                        }
                        case 4:{
                            mostrar(estudiante,n_estudiantes);
                            /*mostrarcods(cods,n_estudiantes);*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 5:{
                            cout << "Volviendo al menu principal..." << endl;
                            break;
                        }
                        default:{
                            cout << "Opcion invalida. Intente nuevamente." <<endl<<endl;
                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                    cout << endl;
                } while (opcion1 != 5);
                
                system("cls");
                break;
            }
            case 2:{
                /*MENU ARREGLOS ORDENADOS*/
                int opcion2;
                int cod;               
                do {
                    for(i=0;i<n_estudiantes;i++){
                        cods[i]=estudiante[i].codigo;
                    }
                    ordenacion(cods,n_estudiantes);
                    ordenar(cods,estudiante,n_estudiantes);
                    cout << "\nMENU ARREGLOS ORDENADOS" << endl;
                    cout << "\n1. INSERTAR" << endl;
                    cout << "\n2. ELIMINAR" << endl;
                    cout << "\n3. MODIFICAR" << endl;
                    cout << "\n4. MOSTRAR" << endl;
                    cout << "\n5. SALIR" << endl;
                    cout << "\nIngrese una opcion: ";
                    cin >> opcion2;
                    system("cls");
                    switch (opcion2) {
                        case 1:{
                            cout<<"\nAsigne un codigo.....\nDebe tener 6 digitos y empezar en 1190_ _"<<endl;
                            cout <<"Codigo: ";cin >> estudiante[n_estudiantes].codigo;
                            system("cls");
                            insercion_o(cods,n_estudiantes,max,estudiante[n_estudiantes].codigo);
                            ordenacion(cods,n_estudiantes);
                            if (estudiante[n_estudiantes].codigo==cods[n_estudiantes+1]) {
                                cout<< "\nSe a comprobado que si hay espacio disponible......"<<endl;
                                cout << "\nIngrese los datos del nuevo alumno:" << endl;
                                estudiante[n_estudiantes].orden=estudiante[n_estudiantes-1].orden+1;
                                cout << "\nOrden asignado: "<<estudiante[n_estudiantes].orden<<endl;
                                cout << "\nCodigo asignado: "<<estudiante[n_estudiantes].codigo<<endl;
                                cout << "\nNombre y apellido: ";fflush(stdin);getline(cin,estudiante[n_estudiantes].nombre);
                                cout << "\nNota 1: ";cin >> estudiante[n_estudiantes].nota1;
                                cout << "\nNota 2: ";cin >> estudiante[n_estudiantes].nota2;
                                estudiante[n_estudiantes].promedio=(estudiante[n_estudiantes].nota1+estudiante[n_estudiantes].nota2)/2;
                                cout<<"\nPromedio: "<<estudiante[n_estudiantes].promedio<<endl;
                                n_estudiantes=n_estudiantes+1;
                            }
                            else{
                                cout<<"No hay cupo para mas estudiantes........"<<endl;
                            }
                            system("pause");
                            system("cls");
                            break; 
                        }
                        case 2:{
                            int op;
                            cout<<"\nQUE ALUMNO DESEA ELIMINAR DE LA LISTA?"<<endl<<endl;
                            mostrar(estudiante,n_estudiantes);
                            cout<<"INGRESE EL # DE ORDEN: ";cin>>op;
                            eliminacion_o(cods,n_estudiantes,estudiante[op-1].codigo);
                            for (i = op-1; i < n_estudiantes; i++){
                                estudiante[i] = estudiante[i+1];
                                estudiante[i].orden=estudiante[i].orden-1;
                            }
                            n_estudiantes--;
                            system("cls");
                            cout<<"\nTABLA DE REGISTROS ACTUALIZADA...."<<endl<<endl;
                            mostrar(estudiante,n_estudiantes);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 3:{
                            int op1;
                            int a;
                            char s;
                                do{
                                    system("cls");
                                    mostrar(estudiante,n_estudiantes);
                                    cout << "\nQUE DATO DESEA MODIFICAR?"<<endl<< endl;
                                    cout << "\n1. NOTA 1" << endl;
                                    cout << "\n2. NOTA 2" << endl;                            
                                    cout << "\n3. SALIR" << endl;
                                    cout << "\nIngrese una opcion: ";
                                    cin >> op1;
                                    system("cls");
                                    switch(op1){
                                        case 1:{
                                            mostrar(estudiante,n_estudiantes);
                                            cout<<"INGRESE EL # DE ORDEN DEL ESTUDIANTE \nAL QUE SE LE REALIZARA LA MODIFICACION DE NOTAS: ";cin>>a;
                                            cout<<endl;
                                            system("cls");
                                            mostrar_uno(estudiante,a);
                                            cout<<"ACTUALIZE LA NOTA 1: ";cin>>estudiante[a-1].nota1;
                                            estudiante[a-1].promedio = (estudiante[a-1].nota1 + estudiante[a-1].nota2)/2;
                                            system("cls");
                                            cout<<"NOTAS DE ESTUDIANTE ACTUALIZADAS";                                                        
                                            mostrar_uno(estudiante,a);
                                            system("pause");
                                            system("cls");
                                            break;
                                        }
                                        case 2:{
                                            mostrar(estudiante,n_estudiantes);
                                            cout<<"INGRESE EL # DE ORDEN DEL ESTUDIANTE \nAL QUE SE LE REALIZARA LA MODIFICACION DE NOTAS: ";cin>>a;
                                            cout<<endl;
                                            system("cls");
                                            mostrar_uno(estudiante,a);
                                            cout<<"ACTUALIZE LA NOTA 2: ";cin>>estudiante[a-1].nota2;
                                            estudiante[a-1].promedio = (estudiante[a-1].nota1 + estudiante[a-1].nota2)/2;
                                            system("cls");
                                            cout<<"NOTAS DE ESTUDIANTE ACTUALIZADAS";                                                        
                                            mostrar_uno(estudiante,a);
                                            system("pause");
                                            system("cls");
                                            break;
                                        }
                                        case 3:{
                                            cout << "Volviendo......" << endl;
                                            system("pause");
                                            system("cls");
                                            break;
                                        }
                                        default:{
                                            cout << "Opcion invalida. Intente nuevamente........." <<endl<<endl;
                                            system("pause");
                                            system("cls");
                                            break;
                                        }
                                    }
                                }while (op1 != 3);                       
                        break;
                        }
                        case 4:{
                            mostrar(estudiante,n_estudiantes);
                            /*mostrarcods(cods,n_estudiantes);*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 5:{
                            cout << "Volviendo al menu principal..." << endl;
                            break;
                        }
                        default:{
                            cout << "Opcion invalida. Intente nuevamente." <<endl<<endl;
                            system("pause");
                            system("cls");
                            break;
                        }
                    } 
                    cout << endl;
                } while (opcion2 != 5);
                system("cls");
                break;
            }
                break;
            case 3:{
                cout << "Hasta luego!" << endl;
                system("pause");
                break;
            }
            default:{
                cout << "Opcion invalida. Intente nuevamente." << endl;
                system("pause");
                break;
            }
        }
        
        cout << endl;
    } while (opcion != 3);

    return 0;
}