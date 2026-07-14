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



/*
En Mision.cpp hay un Método similar, pero ese borra y crea un arreglo para los "recursosAsignados"
Eso es un atributo privado, no se debe tocar desde otra clase
*/

/*
Duplica la capacidad del arreglo cuando se llena, copiando los punteros existentes 
a un nuevo bloque de memoria en el Heap
*/

void Controlador::redimensionarRecursos() {
    int nuevaCapacidad = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];

    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArreglo[i] = inventarioRecursos[i];
    }

    delete[] inventarioRecursos;
    inventarioRecursos = nuevoArreglo;
    capacidadRecursos = nuevaCapacidad;
}




void Controlador::redimensionarMisiones() {
    int nuevaCapacidad = capacidadMisiones * 2;
    Mision** nuevoArreglo = new Mision*[nuevaCapacidad];

    for (int i = 0; i < cantidadMisiones; i++) {
        nuevoArreglo[i] = misiones[i];
    }

    delete[] misiones;
    misiones = nuevoArreglo;
    capacidadMisiones = nuevaCapacidad;
}



void Controlador::agregarRecursoInventario(Recurso* recurso) {
    if (cantidadRecursos == capacidadRecursos) {
        redimensionarRecursos();
    }
    inventarioRecursos[cantidadRecursos] = recurso;
    cantidadRecursos++;
}



void Controlador::agregarMisionSistema(Mision* mision) {
    if (cantidadMisiones == capacidadMisiones) {
        redimensionarMisiones();
    }
    misiones[cantidadMisiones] = mision;
    cantidadMisiones++;
}
