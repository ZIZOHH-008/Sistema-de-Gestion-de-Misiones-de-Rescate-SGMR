#include "Personal.h"
#include <iostream>



Personal::Personal(const std::string& codigo, const std::string& nombre, const std::string& especialidad)
    : Recurso(codigo, nombre) {
    this->especialidad = especialidad;
}

Personal::~Personal() {
}

std::string Personal::getEspecialidad() const {
    return especialidad;
}

void Personal::mostrarInfo() const {
    Recurso::mostrarInfo();
    std::cout << " | Especialidad: " << especialidad;
}
