#include "Helicoptero.h"
#include <iostream>



Helicoptero::Helicoptero(const std::string& codigo, const std::string& nombre, int capacidadPacientes)
    : Vehiculo(codigo, nombre, capacidadPacientes) {
}

Helicoptero::~Helicoptero() {
}

void Helicoptero::ejecutarAccion() const {
    std::cout << "[Helicoptero " << codigo << "] Realizando extracción aérea\n";
}
