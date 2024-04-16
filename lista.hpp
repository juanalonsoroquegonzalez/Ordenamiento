#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>

using namespace std;

template<typename T, int MAX>

class lista {
private:
    T Datos[MAX];
    int Tam;
    int ultimo;

    void Inicializa(T dato, int ultimo);
    void Inserta(T dato, int posicion);
    void Agrega(T dato);
    void Busca(string dato);
    void Elimina(int posicion);
    T recupera(int posicion);
    
    void Muestra();

    int ultimo_() const;

    void quicksort(int extizq, int extder);
public:
    lista();

    bool Vacia() const;
    bool Llena() const;
    void enlistar(T element);

    void busquedaLineal(string elemento);
    void busquedaBinaria(string elemento);
    T bot();

    void ordenamiento();
};

template<typename T, int MAX>
lista<T, MAX>::lista() : Tam(MAX), ultimo(-1) {
}

template<typename T, int MAX>
void lista<T, MAX>::Inicializa(T dato, int ultimo_actualizado) {
    if (ultimo_actualizado >= 0 && ultimo_actualizado < MAX) {
        Datos[ultimo_actualizado] = dato;
        ultimo = ultimo_actualizado;
    } else {
        cout << "Error: Índice de último inválido." << endl;
    }
}

template<typename T, int MAX>
void lista<T, MAX>::enlistar(T element) {
    Agrega(element);
}

template<typename T, int MAX>
void lista<T, MAX>::ordenamiento() {
    quicksort(0, ultimo);
}

template<typename T, int MAX>
void lista<T, MAX>::quicksort(int extizq, int extder) {
    if (extizq >= extder) {
        return;
    }

    int medio = (extizq + extder) / 2;
    swap(Datos[medio], Datos[extder]);

    int i = extizq;
    int j = extder - 1;

    while (i <= j) {
        while (i <= j && stof(Datos[i].getNombre()) > stof(Datos[extder].getNombre())) {
            i++;
        }
        while (i <= j && stof(Datos[j].getNombre()) <= stof(Datos[extder].getNombre())) {
            j--;
        }
        if (i < j) {
            swap(Datos[i], Datos[j]);
        }
    }
    if (i != extder) {
        swap(Datos[i], Datos[extder]);
    }
    quicksort(extizq, i - 1);
    quicksort(i + 1, extder);
}

template<typename T, int MAX>
void lista<T, MAX>::Agrega(T dato) {
    if (Llena()) {
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tNo se pudo agregar la cita porque la lista esta llena." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
    } else {
        Datos[++ultimo] = dato;
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tCita agregada a la lista..." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
    }
}

template<typename T, int MAX>
void lista<T, MAX>::Inserta(T dato, int posicion)
{
    posicion = ultimo+1;
    if(Llena() || posicion < 0 || posicion > ultimo + 1) {
        std::cout << "\nError de insercion";
    } else {
        int i = ultimo + 1;
        while(i > posicion) {
            Datos[i] = Datos[i - 1];
            i--;
        }
        Datos[posicion] = dato;
        ultimo++;
        std::cout << "\nElemento insertado";
    }
}

template<typename T, int MAX>
void lista<T, MAX>::Elimina(int posicion)
{
    if(Vacia() || posicion < 0 || posicion > ultimo) {
        cout << "Error de eliminacion";
    } else {
        int i = posicion;
        while(i < ultimo) {
            Datos[i] = Datos[i + 1];
            i++;
        }
        ultimo--;
        cout << "Elemento eliminado";
    }
}

template<typename T, int MAX>
T lista<T, MAX>::recupera(int posicion)
{
    if(Vacia() || posicion < 0 || posicion > ultimo) {
        cout << "\nInsuficiencia datos";
        return T(); // Return default value for type T
    } else {
        return Datos[posicion];
    }
}

template<typename T, int MAX>
bool lista<T, MAX>::Vacia() const
{
    return (ultimo == -1);
}

template<typename T, int MAX>
bool lista<T, MAX>::Llena() const
{
    return (ultimo == Tam - 1);
}

template<typename T, int MAX>
void lista<T, MAX>::Muestra()
{
    if (Vacia()) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    std::cout << "Elementos de la lista:" << std::endl;
    for (int i = 0; i <= ultimo; ++i) {
        cout << Datos[i] << " ";
    }
    cout << endl;
}

template<typename T, int MAX>
int lista<T, MAX>::ultimo_() const
{
    return ultimo;
}

template<typename T, int MAX>
void lista<T, MAX>::busquedaLineal(string elemento) {
    if (Vacia()) {
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tLa lista esta vacia. No hay elementos." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        return;
    }
    for (int i = 0; i <= ultimo; i++) {
        if (Datos[i].getNombre() == elemento) {
            cout << "\t\t\t---------------------------------------" << endl;
            cout << "\t\t\tDatos: "<< endl << endl << Datos[i] << endl;
            cout << "\t\t\tEs el numero " << i + 1 << " en la lista" << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            return;
        }
    }
    cout << "\t\t\t---------------------------------------" << endl;
    cout << "\t\t\tNo se encontraron constancias para " << elemento << endl;
    cout << "\t\t\t---------------------------------------" << endl;
}

template<typename T, int MAX>
void lista<T, MAX>::busquedaBinaria(string elemento) {

    ordenamiento();

    int primero = 0;
    int ult = ultimo;
    int medio;

    while (primero <= ult) { 
        medio = (primero + ult) / 2;

        if (Datos[medio].getPromedio() < stof(elemento)) {
            ult = medio - 1;
        } else if (Datos[medio].getPromedio() == stof(elemento)) {
            cout << "\t\t\t---------------------------------------" << endl;

            cout << "\t\t\tDatos < " << endl << Datos[medio] << "\t\t\t>" << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            cout << "\t\t\t< " << elemento << " >  encontrado en la posicion " << medio + 1 << "..." << endl;
            cout << "\t\t\t---------------------------------------" << endl;
            return;
        } else {
            primero = medio + 1;
        }
    }

    cout << "\t\t\t---------------------------------------" << endl;
    cout << "\t\t\t< " << elemento << " >  no encontrado. Porfavor da de alta" << endl;
    cout << "\t\t\t---------------------------------------" << endl;

}


template<typename T, int MAX>
T lista<T, MAX>::bot() {
    if (Vacia()) {
        cout << "\t\t\t---------------------------------------" << endl;
        cout << "\t\t\tLa lista esta vacia. No hay elementos en el fondo." << endl;
        cout << "\t\t\t---------------------------------------" << endl;
        return Datos[0].getNombre();
    }
    cout << "\t\t\t---------------------------------------" << endl;
    cout << "\t\t\tLlena la constancia del alumno < " << Datos[0].getNombre() << " >" << endl;
    cout << "\t\t\t---------------------------------------" << endl;
    Datos[0].llenar();
    return Datos[0].getNombre();
}
#endif // __LISTA_H__