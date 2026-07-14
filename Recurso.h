#ifndef RECURSO_H
#define RECURSO_H

#include <string>


class Recurso {
protected:
    std::string codigo;  // Identificador único (placa para vehículos, cédula/ID para personal)
    std::string nombre;

public:
    Recurso(const std::string& codigo, const std::string& nombre);
    virtual ~Recurso();

    // Este método todos los deben tener, es como un contrato
    virtual void ejecutarAccion() const = 0;

    // Cada clase modifica como quiera este método
    virtual void mostrarInfo() const;

    string getCodigo() const;
    string getNombre() const;
};

#endif
