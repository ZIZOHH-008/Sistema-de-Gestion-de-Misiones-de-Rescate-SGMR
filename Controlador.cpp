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



void Controlador::cargarDatosPrueba() {
    //Ambulancias
    agregarRecursoInventario(new Ambulancia("AMB-01", "Ambulancia Alfa", 2));
    agregarRecursoInventario(new Ambulancia("AMB-02", "Ambulancia Beta", 2));

    //Helicopteros
    agregarRecursoInventario(new Helicoptero("HEL-01", "Helicoptero Condor", 4));

    //Medicos
    agregarRecursoInventario(new Medico("MED-01", "Dra. Camila Rios", "Trauma"));
    agregarRecursoInventario(new Medico("MED-02", "Dr. Andres Lopez", "Urgencias"));

    //Rescatistas
    agregarRecursoInventario(new Rescatista("RES-01", "Juan Herrera", "Estructuras colapsadas"));
    agregarRecursoInventario(new Rescatista("RES-02", "Laura Gomez", "Rescate acuatico"));

    //Misiones
    agregarMisionSistema(new Mision("MIS-01", "Deslizamiento Cali Sur", "Cali - Valle del Cauca"));
    agregarMisionSistema(new Mision("MIS-02", "Inundacion Palmira", "Palmira - Valle del Cauca"));
}



//Al ser índice, retorna un puntero
Recurso* Controlador::buscarRecursoPorIndice(int indice) const {
    if (indice < 0 || indice >= cantidadRecursos) {
        return nullptr;
    }
    return inventarioRecursos[indice];
}



//Al ser índice, retorna un puntero
Mision* Controlador::buscarMisionPorIndice(int indice) const {
    if (indice < 0 || indice >= cantidadMisiones) {
        return nullptr;
    }
    return misiones[indice];
}


