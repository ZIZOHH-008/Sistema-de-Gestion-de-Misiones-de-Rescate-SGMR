#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Vehiculo.h"


class Helicoptero : public Vehiculo {
public:
    Helicoptero(const string& codigo, const string& nombre, int capacidadPacientes);
    ~Helicoptero();

    void ejecutarAccion() const override;
};

#endif
