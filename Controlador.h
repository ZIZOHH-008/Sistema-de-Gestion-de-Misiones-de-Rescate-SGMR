#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Recurso.h"
#include "Mision.h"

class Controlador {
private:
    Recurso** inventarioRecursos; //puntero a un arreglo de punteros
    int cantidadRecursos;
    int capacidadRecursos;

    Mision** misiones;  //puntero a un arreglo de punteros
    int cantidadMisiones;
    int capacidadMisiones;

    //Manejo de los recursos
    void redimensionarRecursos();
    void redimensionarMisiones();
    void agregarRecursoInventario(Recurso* recurso);
    void agregarMisionSistema(Mision* mision);

    //opciones del menú
    void verRecursos() const;
    void registrarRecurso();
    void crearMision();
    void asignarRecursoAMision();
    void ejecutarMisionMenu();

    void cargarDatosPrueba();

    void mostrarMenu() const;

    Recurso* buscarRecursoPorIndice(int indice) const;
    Mision* buscarMisionPorIndice(int indice) const;

    
public:
    Controlador();
    ~Controlador();

    void iniciar();
};

#endif
