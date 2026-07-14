#ifndef PERSONAL_H
#define PERSONAL_H

#include "Recurso.h"

class Personal : public Recurso {
protected:
    string especialidad;

public:
    Personal(const string& codigo, const string& nombre, const string& especialidad);
    virtual ~Personal();

    string getEspecialidad() const;

    void mostrarInfo() const override;  //
};

#endif
