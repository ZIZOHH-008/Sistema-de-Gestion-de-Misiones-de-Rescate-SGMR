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




void Controlador::verRecursos() const {
    std::cout << "\n\n=== Inventario de recursos (" << cantidadRecursos << ") ===" << '\n';
    if (cantidadRecursos == 0) {
        std::cout << "No hay recursos registrados." << '\n';
        return;
    }
    for (int i = 0; i < cantidadRecursos; i++) {
        std::cout << "[" << i << "] ";
        inventarioRecursos[i]->mostrarInfo();
        std::cout << '\n';
    }
}





void Controlador::registrarRecurso() {
    std::cout << "\n\n=== Registrar nuevo recurso ===" << '\n';
    std::cout << "1. Ambulancia\n2. Helicoptero\n3. Medico\n4. Rescatista\nOpcion: ";

    int tipo;
    std::cin >> tipo;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opcion invalida." << '\n';
        return;
    }

    std::string codigo, nombre, dato;
    std::cout << "Codigo (placa o ID unico): ";
    std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);


    //La variable puntero que se almacenará en el arreglo de punteros
    Recurso* nuevo = nullptr;

    switch (tipo) {
        case 1: {
            int capacidad;
            std::cout << "Capacidad de pacientes: ";
            std::cin >> capacidad;
            nuevo = new Ambulancia(codigo, nombre, capacidad);
            break;
        }
        case 2: {
            int capacidad;
            std::cout << "Capacidad de pacientes: ";
            std::cin >> capacidad;
            nuevo = new Helicoptero(codigo, nombre, capacidad);
            break;
        }
        case 3: {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Especialidad: ";
            std::getline(std::cin, dato);
            nuevo = new Medico(codigo, nombre, dato);
            break;
        }
        case 4: {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Especialidad / tipo de rescate: ";
            std::getline(std::cin, dato);
            nuevo = new Rescatista(codigo, nombre, dato);
            break;
        }
        default:
            std::cout << "Tipo de recurso invalido" << '\n';
            return;
    }

    agregarRecursoInventario(nuevo); //El objeto "nuevo" se guarda con esta funcion
    std::cout << "Recurso registrado con exito" << '\n';
}





void Controlador::crearMision() {
    std::cout << "\n\n=== Crear nueva mision ===" << '\n';

    std::string codigo, nombre, zona;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Codigo de la mision: ";
    std::getline(std::cin, codigo);
    std::cout << "Nombre de la mision: ";
    std::getline(std::cin, nombre);
    std::cout << "Zona afectada: ";
    std::getline(std::cin, zona);

    Mision* nueva = new Mision(codigo, nombre, zona);
    agregarMisionSistema(nueva);

    std::cout << "Mision creada con exito" << '\n';
}





void Controlador::asignarRecursoAMision() {
    if (cantidadMisiones == 0) {
        std::cout << "\nNo hay misiones creadas. Cree una mision primero" << '\n';
        return;
    }
    if (cantidadRecursos == 0) {
        std::cout << "\nNo hay recursos en el inventario. Registre uno primero" << '\n';
        return;
    }

    std::cout << "\n\n=== Misiones disponibles ===" << '\n';
    for (int i = 0; i < cantidadMisiones; i++) {
        std::cout << "[" << i << "] ";
        misiones[i]->mostrarInfo();
    }

    int indiceMision;
    std::cout << "Seleccione el indice de la mision: ";
    std::cin >> indiceMision;

    Mision* mision = buscarMisionPorIndice(indiceMision);
    if (mision == nullptr) {
        std::cout << "Indice de mision invalido." << '\n';
        return;
    }

    verRecursos();
    int indiceRecurso;
    std::cout << "Seleccione el indice del recurso a asignar: ";
    std::cin >> indiceRecurso;

    Recurso* recurso = buscarRecursoPorIndice(indiceRecurso);
    if (recurso == nullptr) {
        std::cout << "Indice de recurso invalido." << '\n';
        return;
    }

    
    // se usa el método por medio del puntero y se pasa el mismo puntero
    bool exito = mision->asignarRecurso(recurso);

    if (exito) {
        std::cout << "Recurso asignado con exito a la mision\n";
    } else {
        std::cout << "Este recurso ya esta ocupado en otra mision. No se puede asignar\n";
    }
}





void Controlador::ejecutarMisionMenu() {
    if (cantidadMisiones == 0) {
        std::cout << "\nNo hay misiones creadas." << '\n';
        return;
    }

    std::cout << "\n\n=== Misiones disponibles ===" << '\n';
    for (int i = 0; i < cantidadMisiones; i++) {
        std::cout << "[" << i << "] ";
        misiones[i]->mostrarInfo();
    }

    int indice;
    std::cout << "Seleccione el indice de la mision a ejecutar: ";
    std::cin >> indice;

    Mision* mision = buscarMisionPorIndice(indice);
    if (mision == nullptr) {
        std::cout << "Indice invalido." << '\n';
        return;
    }

    // El polimorfmos, en donde Mision.h recorre Recurso* y usa ejecutarAccion()
    // Luego, según la clase y el método definido, sale en consola el resultado
    mision->ejecutarMision();
}





//  Menú del sistema en general
void Controlador::mostrarMenu() const {
    std::cout << "\n\n\n========== SGMR - Sistema de Gestion de Misiones de Rescate ==========" << '\n';
    std::cout << "1. Ver recursos" << '\n';
    std::cout << "2. Registrar recurso" << '\n';
    std::cout << "3. Crear mision" << '\n';
    std::cout << "4. Asignar recurso a mision" << '\n';
    std::cout << "5. Ejecutar mision" << '\n';
    std::cout << "6. Salir" << '\n';
    std::cout << "Seleccione una opcion: ";
}





void Controlador::iniciar() {
    int opcion = 0;

    do {
        mostrarMenu();
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida, intente de nuevo." << '\n';
            continue;
        }

        switch (opcion) {
            case 1:
                verRecursos();
                break;
            case 2:
                registrarRecurso();
                break;
            case 3:
                crearMision();
                break;
            case 4:
                asignarRecursoAMision();
                break;
            case 5:
                ejecutarMisionMenu();
                break;
            case 6:
                std::cout << "Cerrando el sistema..." << '\n';
                break;
            default:
                std::cout << "Opcion no valida." << '\n';
        }

    } while (opcion != 6);
}
