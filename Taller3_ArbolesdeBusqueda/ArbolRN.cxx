#include "ArbolRN.h"

void ArbolRN::insertarRN(int valor) {
    datos.insert(valor);
}

void ArbolRN::eliminarRN(int valor) {
    datos.erase(valor);
}

void ArbolRN::mostrarEnOrdenRN() const {
    for (int valor : datos) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
}
