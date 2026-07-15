#include "Recurso.h"
#include <iostream>



Recurso::Recurso(const std::string& codigo, const std::string& nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->ocupado = false;
}

//El destructor virtual daña las hijas y despues a ella misma
Recurso::~Recurso() {
}


void Recurso::mostrarInfo() const {
    std::cout << "Codigo: " << codigo << " | Nombre: " << nombre << " | Estado: " << (ocupado ? "Ocupado" : "Disponible");
    // El "?" es un if-else corto; Si ocupado es true, muestra "Ocupado"; si es false, muestra "Disponible".
}



std::string Recurso::getCodigo() const {
    return codigo;
}



std::string Recurso::getNombre() const {
    return nombre;
}



void Recurso::setEstado(bool ocupado) {
    this->ocupado = ocupado;
}



bool Recurso::getEstado() const {
    return ocupado;
}
