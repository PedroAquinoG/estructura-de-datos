#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include "funciones.h"

using namespace std;

int main() {
    int max = 10;
    int n_estudiantes = 9;
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
            case 1: {

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
                        case 1: {
                            int codigo;
                            cout << "Ingrese el código del estudiante a insertar: ";
                            cin >> codigo;
                            insercion_d(estudiante, n_estudiantes, max, codigo);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 2: {
                            int codigo;
                            cout << "Ingrese el código del estudiante a eliminar: ";
                            cin >> codigo;
                            eliminacion_d(estudiante, n_estudiantes, codigo);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 3: {
                            int op1;
                            int codigo;
                            float nuevaNota;
                            char s;
                            do {
                                system("cls");
                                mostrar(estudiante, n_estudiantes);
                                cout << "\nQUE DATO DESEA MODIFICAR?" << endl
                                     << endl;
                                cout << "\n1. NOTA 1" << endl;
                                cout << "\n2. NOTA 2" << endl;
                                cout << "\n3. SALIR" << endl;
                                cout << "\nIngrese una opcion: ";
                                cin >> op1;
                                system("cls");
                                switch (op1) {
                                    case 1: {
                                        cout << "Ingrese el código del estudiante: ";
                                        cin >> codigo;
                                        cout << "Ingrese la nueva nota 1: ";
                                        cin >> nuevaNota;
                                        modificacion_d(estudiante, n_estudiantes, codigo, nuevaNota, estudiante[busqueda(estudiante, n_estudiantes, codigo)].nota2);
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case 2: {
                                        cout << "Ingrese el código del estudiante: ";
                                        cin >> codigo;
                                        cout << "Ingrese la nueva nota 2: ";
                                        cin >> nuevaNota;
                                        modificacion_d(estudiante, n_estudiantes, codigo, estudiante[busqueda(estudiante, n_estudiantes, codigo)].nota1, nuevaNota);
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case 3: {
                                        cout << "Volviendo......" << endl;
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    default: {
                                        cout << "Opcion invalida. Intente nuevamente........." << endl
                                             << endl;
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                }
                            } while (op1 != 3);
                            break;
                        }
                        case 4: {
                            mostrar(estudiante, n_estudiantes);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 5: {
                            cout << "Volviendo al menu principal..." << endl;
                            break;
                        }
                        default: {
                            cout << "Opcion invalida. Intente nuevamente." << endl
                                 << endl;
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
            case 2: {
                /*MENU ARREGLOS ORDENADOS*/
                int opcion2;
                do {
                    /*ordenar el arreglo alumno por codigos*/
                    ordenar(estudiante, n_estudiantes);

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
                        case 1: {
                            int codigo;
                            cout << "Ingrese el código del estudiante a insertar: ";
                            cin >> codigo;
                            insercion_o(estudiante, n_estudiantes, max, codigo);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 2: {
                            int codigo;
                            cout << "Ingrese el código del estudiante a eliminar: ";
                            cin >> codigo;
                            eliminacion_o(estudiante, n_estudiantes, codigo);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 3: {
                            int op1;
                            int codigo;
                            float nuevaNota;
                            char s;
                            do {
                                system("cls");
                                mostrar(estudiante, n_estudiantes);
                                cout << "\nQUE DATO DESEA MODIFICAR?" << endl
                                     << endl;
                                cout << "\n1. NOTA 1" << endl;
                                cout << "\n2. NOTA 2" << endl;
                                cout << "\n3. SALIR" << endl;
                                cout << "\nIngrese una opcion: ";
                                cin >> op1;
                                system("cls");
                                switch (op1) {
                                    case 1: {
                                        cout << "Ingrese el código del estudiante: ";
                                        cin >> codigo;
                                        cout << "Ingrese la nueva nota 1: ";
                                        cin >> nuevaNota;
                                        modificacion_o(estudiante, n_estudiantes, codigo, nuevaNota, estudiante[busqueda(estudiante, n_estudiantes, codigo)].nota2);
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case 2: {
                                        cout << "Ingrese el código del estudiante: ";
                                        cin >> codigo;
                                        cout << "Ingrese la nueva nota 2: ";
                                        cin >> nuevaNota;
                                        modificacion_o(estudiante, n_estudiantes, codigo, estudiante[busqueda(estudiante, n_estudiantes, codigo)].nota1, nuevaNota);
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case 3: {
                                        cout << "Volviendo......" << endl;
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    default: {
                                        cout << "Opcion invalida. Intente nuevamente........." << endl
                                             << endl;
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                }
                            } while (op1 != 3);
                            break;
                        }
                        case 4: {
                            mostrar(estudiante, n_estudiantes);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 5: {
                            cout << "Volviendo al menu principal..." << endl;
                            break;
                        }
                        default: {
                            cout << "Opcion invalida. Intente nuevamente." << endl
                                 << endl;
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
            case 3: {
                cout << "Hasta luego!" << endl;
                system("pause");
                break;
            }
            default: {
                cout << "Opcion invalida. Intente nuevamente." << endl;
                system("pause");
                break;
            }
        }

        cout << endl;
    } while (opcion != 3);

    return 0;
}