#ifndef MISION_H
#define MISION_H

#include <string>
#include "Recurso.h"



class Mision {
private:
    std::string codigo;
    std::string nombre;
    std::string zonaAfectada;

    Recurso** recursosAsignados; // arreglo dinámico de punteros
    int cantidadRecursos;
    int capacidadRecursos;

    void redimensionar(); // duplica el tamaño del arreglo cuando se llena

public:
    Mision(const std::string& codigo, const std::string& nombre, const std::string& zonaAfectada);
    ~Mision(); // Solo libera el arreglo de punteros, no los objetos apuntados (pq no es dueña de los recursos)
 
    void asignarRecurso(Recurso* recurso);

    void ejecutarMision() const;

    void mostrarInfo() const;

    std::string getCodigo() const;
    std::string getNombre() const;
    int getCantidadRecursos() const;
};

#endif
