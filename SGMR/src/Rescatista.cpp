#include "Rescatista.h"
#include <iostream>



Rescatista::Rescatista(const std::string& codigo, const std::string& nombre, const std::string& especialidad)
    : Personal(codigo, nombre, especialidad) {
}

Rescatista::~Rescatista() {
}

void Rescatista::ejecutarAccion() const {
    std::cout << "[Rescatista " << codigo << "] Buscando sobrevivientes en escombros\n";
}
