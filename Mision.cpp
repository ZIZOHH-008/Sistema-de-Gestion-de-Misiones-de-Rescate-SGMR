#include "Mision.h"
#include <iostream>



Mision::Mision(const std::string& codigo, const std::string& nombre, const std::string& zonaAfectada) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->zonaAfectada = zonaAfectada;

    // Si se acaban los disponibles, rimensionar lo duplica
    capacidadRecursos = 4;
    cantidadRecursos = 0;
    recursosAsignados = new Recurso*[capacidadRecursos];
}
