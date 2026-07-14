#include "Ambulancia.h"
#include <iostream>



Ambulancia::Ambulancia(const std::string& codigo, const std::string& nombre, int capacidadPacientes)
    : Vehiculo(codigo, nombre, capacidadPacientes) {
}

Ambulancia::~Ambulancia() {
}

void Ambulancia::ejecutarAccion() const {
    std::cout << "[Ambulancia " << codigo << "] Transportando paciente via terrestre\n";
}
