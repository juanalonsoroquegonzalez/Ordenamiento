#ifndef __CONSTANCIA_H__
#define __CONSTANCIA_H__

#include <string>
#include <iostream>

using namespace std;

class constancia {
private:
    string nombre;
    string carrera;
    string prepa;
    float promedio;

public:
    constancia();
    constancia(const constancia& a);

    void llenar();

    string getNombre() const;
    string getCarrera() const;
    string getPrepa() const;
    float getPromedio() const;

    void setNombre(const string&);
    void setCarrera(const string&);
    void setPrepa(const string&);
    void setPromedio(const float&);
    
    constancia &operator=(const constancia &);
 
    bool operator==(const constancia &) const;
    bool operator!=(const constancia &) const;
    bool operator<(const constancia &) const;
    bool operator<=(const constancia &) const;
    bool operator>(const constancia &) const;
    bool operator>=(const constancia &) const;

    friend istream &operator>>(istream &, constancia &);
    friend ostream &operator<<(ostream &, const constancia &);
};
constancia::constancia() {}

constancia::constancia(const constancia& a) : 
                        nombre(a.nombre), 
                        carrera(a.carrera), 
                        prepa(a.prepa), 
                        promedio(a.promedio) {}

string constancia::getNombre() const
{
    return nombre;
}

string constancia::getCarrera() const
{
    return carrera;
}

string constancia::getPrepa() const
{
    return prepa;
}

float constancia::getPromedio() const
{
    return promedio;
}

void constancia::setNombre(const string& n)
{
    nombre = n;
}

void constancia::setCarrera(const string& c)
{
    carrera = c;
}

void constancia::setPrepa(const string& p)
{
    prepa = p;
}

void constancia::setPromedio(const float& r)
{
    promedio = r;
}

void constancia::llenar()
{
    cout << "Ingrese carrera: ";
    cin >> carrera;
    cout << "Ingrese la preparatoria de procedencia: ";
    cin >> prepa;
    cout << "Ingrese promedio: ";
    cin >> promedio;
}

constancia& constancia::operator=(const constancia &other)
{
    if (this != &other) {
        this->nombre = other.nombre;
        this->carrera = other.carrera;
        this->prepa = other.prepa;
        this->promedio = other.promedio;
    }
    return *this;
}

bool constancia::operator==(const constancia &other) const
{
    return (nombre == other.nombre &&
            carrera == other.carrera &&
            prepa == other.prepa &&
            promedio == other.promedio);
}

bool constancia::operator!=(const constancia &other) const
{
    return !(promedio == other.promedio);
}

bool constancia::operator<(const constancia &other) const
{
    return promedio < other.promedio;
}

bool constancia::operator<=(const constancia &other) const
{
    return promedio <= other.promedio;
}

bool constancia::operator>(const constancia &other) const
{
    return promedio > other.promedio;
}

bool constancia::operator>=(const constancia &other) const
{
    return promedio >= other.promedio;
}

ostream& operator<<(ostream &out, const constancia &e)
{
    out << "\t\t\tNombre: " << e.nombre << endl;
    out << "\t\t\tCarrera: " << e.carrera << endl;
    out << "\t\t\tPreparatoria de procedencia: " << e.prepa << endl;
    out << "\t\t\tPromedio: " << e.promedio << endl;
    return out;
}

istream& operator>>(istream &in, constancia &e)
{
    cout << "\t\t\tIngrese el nombre: ";
    in >> e.nombre;
    cout << "\t\t\tIngrese carrera: ";
    in >> e.carrera;
    cout << "\t\t\tIngrese la preparatoria de procedencia: ";
    in >> e.prepa;
    cout << "\t\t\tIngrese promedio: ";
    in >> e.promedio;
    
    return in;
}


#endif // __CONSTANCIA_H__
