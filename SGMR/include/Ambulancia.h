#ifndef AMBULANCIA_H
#define AMBULANCIA_H

#include "Vehiculo.h"

class Ambulancia : public Vehiculo {
public:
    Ambulancia(const std::string& codigo, const std::string& nombre, int capacidadPacientes);  //Paso por referencias para evitar duplicar datos
    ~Ambulancia() override;

    void ejecutarAccion() const override;
};

#endif
