#include "Medico.h"
#include <iostream>



Medico::Medico(const std::string& codigo, const std::string& nombre, const std::string& especialidad)
    : Personal(codigo, nombre, especialidad) {
}

Medico::~Medico() {
}

void Medico::ejecutarAccion() const {
    std::cout << "[Medico " << codigo << "] Estabilizando signos vitales\n";
}
