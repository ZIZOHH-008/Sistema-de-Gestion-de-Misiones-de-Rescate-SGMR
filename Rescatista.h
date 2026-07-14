#ifndef RESCATISTA_H
#define RESCATISTA_H

#include "Personal.h"



class Rescatista : public Personal {
public:
    Rescatista(const std::string& codigo, const std::string& nombre, const std::string& especialidad);
    ~Rescatista();

    void ejecutarAccion() const override;
};

#endif
