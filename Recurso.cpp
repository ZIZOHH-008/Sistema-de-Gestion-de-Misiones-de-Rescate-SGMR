#include "Recurso.h"
#include <iostream>



Recurso::Recurso(const std::string& codigo, const std::string& nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
}

//El destructor virtual daña las hijas y despues a ella misma
Recurso::~Recurso() {
}

void Recurso::mostrarInfo() const {
    std::cout << "Codigo: " << codigo << "  | Nombre: " << nombre;
}

std::string Recurso::getCodigo() const {
    return codigo;
}

std::string Recurso::getNombre() const {
    return nombre;
}
