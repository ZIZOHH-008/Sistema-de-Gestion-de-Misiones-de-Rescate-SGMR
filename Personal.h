#ifndef PERSONAL_H
#define PERSONAL_H

#include "Recurso.h"

class Personal : public Recurso {
protected:
    std::string especialidad;

public:
    Personal(const std::string& codigo, const std::string& nombre, const std::string& especialidad);
    virtual ~Personal();

    std::string getEspecialidad() const;

    void mostrarInfo() const override;
};

#endif
