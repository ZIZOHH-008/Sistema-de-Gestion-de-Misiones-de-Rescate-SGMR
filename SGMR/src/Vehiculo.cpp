#include "Vehiculo.h"
#include <iostream>



Vehiculo::Vehiculo(const std::string& codigo, const std::string& nombre, int capacidadPacientes)
    : Recurso(codigo, nombre) {
    this->capacidadPacientes = capacidadPacientes;
}

Vehiculo::~Vehiculo() {
}

int Vehiculo::getCapacidadPacientes() const {
    return capacidadPacientes;
}

void Vehiculo::mostrarInfo() const {
    Recurso::mostrarInfo();
    std::cout << " | Capacidad pacientes: " << capacidadPacientes;
}
