#include "Controlador.h"
#include "Ambulancia.h"
#include "Helicoptero.h"
#include "Medico.h"
#include "Rescatista.h"
#include <iostream>
#include <limits>




Controlador::Controlador() {
    capacidadRecursos = 4;
    cantidadRecursos = 0;
    inventarioRecursos = new Recurso*[capacidadRecursos];

    capacidadMisiones = 4;
    cantidadMisiones = 0;
    misiones = new Mision*[capacidadMisiones];

    cargarDatosPrueba(); // HU05
}




// recorre y libera los objetos creado con new, y luego los arreglos de punteros
Controlador::~Controlador() {
    for (int i = 0; i < cantidadRecursos; i++) {
        delete inventarioRecursos[i];
    }
    delete[] inventarioRecursos;

    for (int i = 0; i < cantidadMisiones; i++) {
        delete misiones[i];
    }
    delete[] misiones;

    std::cout << "\nMemoria liberada" << '\n';
}

