#include <iostream>
#include "lista.hpp"
#include "constancia.hpp"

int main() {
    lista<constancia, 20> Lista;

    int opcion;
    do {
        system("cls");
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\t            MENU                     " << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\t1. Enlistar" << endl;
        cout << "\t\t\t2. Buscar" << endl;
        cout << "\t\t\t3. Salir" << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tIngrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                if (Lista.Llena()) {
                    cout << "\t\t\t---------------------------------------" << endl;
                    cout << "\t\t\tLa lista esta llena." << endl;
                    cout << "\t\t\t---------------------------------------" << endl;
                    break;
                } else {
                    cin.ignore();
                    constancia nueva;
                    cin >> nueva;
                    //cout << nueva;
                    Lista.enlistar(nueva);
                }
            }
                break;
            case 2: 
                {
                    if (Lista.Vacia()) {
                    cout << "\t\t\t---------------------------------------" << endl;
                    cout << "\t\t\tNo hay mas constancias en la lista." << endl;
                    cout << "\t\t\t---------------------------------------" << endl;
                    break;
                    } else {
                        cout << "\t\t\tBuscar su constancia en la lista: ";
                        string nombre;
                        cin.ignore();
                        getline(cin, nombre);
                        Lista.busquedaBinaria(nombre);
                    }
                }
                break;
            case 3: {
                cout << "\t\t\tSaliendo del programa..." << endl;
            }
                break;
            default:
                cout << "\t\t\t---------------------------------------" << endl;
                cout << "\t\t\tOpcion no valida. Por favor, ingrese una opcion valida." << endl;
                cout << "\t\t\t---------------------------------------" << endl;
                break;
        }
        system("PAUSE");
    } while (opcion != 3);

    return 0;
}