#ifndef VEHICULO_H
#define VEHICULO_H

#include "Recurso.h"


class Vehiculo : public Recurso {
protected:
    int capacidadPacientes;

public:
    Vehiculo(const std::string& codigo, const std::string& nombre, int capacidadPacientes);
    ~Vehiculo() override;

    int getCapacidadPacientes() const;

    void mostrarInfo() const override;
};

#endif
