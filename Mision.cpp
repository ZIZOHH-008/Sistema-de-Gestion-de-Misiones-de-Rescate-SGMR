#include "Mision.h"
#include <iostream>



Mision::Mision(const std::string& codigo, const std::string& nombre, const std::string& zonaAfectada) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->zonaAfectada = zonaAfectada;

    // Si se acaban los disponibles, rimensionar lo duplica
    capacidadRecursos = 4;
    cantidadRecursos = 0;
    recursosAsignados = new Recurso*[capacidadRecursos];
}


// Solo se destruye el arreglo de punteros, los objetos apuntados no
// Esos se destruyen en Controlador
Mision::~Mision() {
    delete[] recursosAsignados;
}




/*
En Controlador.cpp hay un Método similar, pero ese borra y crea un arreglo para el inventario de recursos y misiones
Eso es un atributo privado, no se debe tocar desde otra clase
*/

/*
Duplica la capacidad del arreglo cuando se llena, copiando los punteros existentes 
a un nuevo bloque de memoria en el Heap
*/

void Mision::redimensionar() {
    int nuevaCapacidad = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];

    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArreglo[i] = recursosAsignados[i];
    }

    delete[] recursosAsignados; //Borra el arreglo anterior
    recursosAsignados = nuevoArreglo;   //Los elementos del arreglo borrado quedan en el nuevo
    capacidadRecursos = nuevaCapacidad;
}





bool Mision::asignarRecurso(Recurso* recurso) {
    if (recurso == nullptr) {
        return false;
    }

    if (cantidadRecursos == capacidadRecursos) {
        redimensionar();
    }

    recursosAsignados[cantidadRecursos] = recurso;
    cantidadRecursos++;

    recurso->setEstado(true);  // Aquí vuelve ocupado == True del objeto punteado
    return true;
}




void Mision::ejecutarMision() const {
    std::cout << "\n=== Ejecutando mision [" << codigo << "] " << nombre << " ===\n";

    if (cantidadRecursos == 0) {
        std::cout << "No hay recursos asignados a esta mision\n";
        return;
    }

    for (int i = 0; i < cantidadRecursos; i++) {
        recursosAsignados[i]->ejecutarAccion(); //Dependiendo del recurso, ejecuta el método con su modificación
    }
}



void Mision::mostrarInfo() const {
    std::cout << "Mision [" << codigo << "] " << nombre << " | Zona: " << zonaAfectada << " | Recursos asignados: " << cantidadRecursos << '\n';

    for (int i = 0; i < cantidadRecursos; i++) {
        std::cout << "   - ";
        recursosAsignados[i]->mostrarInfo();
        std::cout << "\n";
    }
}




std::string Mision::getCodigo() const {
    return codigo;
}



std::string Mision::getNombre() const {
    return nombre;
}



int Mision::getCantidadRecursos() const {
    return cantidadRecursos;
}
