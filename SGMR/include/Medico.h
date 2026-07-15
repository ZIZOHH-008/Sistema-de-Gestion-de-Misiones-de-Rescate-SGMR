#ifndef MEDICO_H
#define MEDICO_H

#include "Personal.h"



class Medico : public Personal {
public:
    Medico(const std::string& codigo, const std::string& nombre, const std::string& especialidad);
    ~Medico() override;

    void ejecutarAccion() const override;
};

#endif
