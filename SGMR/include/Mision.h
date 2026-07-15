#ifndef MISION_H
#define MISION_H

#include <string>
#include "Recurso.h"


class Mision {
private:
    std::string codigo;
    std::string nombre;
    std::string zonaAfectada;

    Recurso** recursosAsignados; // arreglo dinámico de punteros (heap, sin std::vector)
    int cantidadRecursos;
    int capacidadRecursos;

    void redimensionar(); // duplica la capacidad del arreglo cuando se llena

public:
    Mision(const std::string& codigo, const std::string& nombre, const std::string& zonaAfectada);
    ~Mision();

    bool asignarRecurso(Recurso* recurso);

    void ejecutarMision() const;

    void mostrarInfo() const;

    std::string getCodigo() const;
    std::string getNombre() const;
    int getCantidadRecursos() const;
};

#endif
