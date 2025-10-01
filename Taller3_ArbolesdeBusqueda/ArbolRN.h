#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <set>
#include <iostream>

class ArbolRN {
private:
    std::set<int> datos;  // Usamos std::set para simular el árbol rojo-negro

public:
    void insertarRN(int valor);
    void eliminarRN(int valor);
    void mostrarEnOrdenRN() const;
};
#include "ArbolRN.cxx"
#endif 
