#ifndef VEHICULO_H
#define VEHICULO_H

#include "Recurso.h"


class Vehiculo : public Recurso {
protected:
    int capacidadPacientes;

public:
    Vehiculo(const string& codigo, const string& nombre, int capacidadPacientes);
    virtual ~Vehiculo();

    int getCapacidadPacientes() const;

    void mostrarInfo() const override;
};

#endif
