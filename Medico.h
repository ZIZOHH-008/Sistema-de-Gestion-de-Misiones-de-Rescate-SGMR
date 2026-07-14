#ifndef MEDICO_H
#define MEDICO_H

#include "Personal.h"



class Medico : public Personal {
public:
    Medico(const string& codigo, const string& nombre, const string& especialidad);
    ~Medico();

    void ejecutarAccion() const override;
};

#endif
