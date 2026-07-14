#ifndef RESCATISTA_H
#define RESCATISTA_H

#include "Personal.h"



class Rescatista : public Personal {
public:
    Rescatista(const string& codigo, const string& nombre, const string& especialidad);
    ~Rescatista();

    void ejecutarAccion() const override;
};

#endif
