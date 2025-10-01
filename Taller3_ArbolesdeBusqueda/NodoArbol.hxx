#include "NodoArbol.h"

template <class T>
NodoArbol<T>::NodoArbol(T valor) {
    dato = valor;
    izq = nullptr;
    der = nullptr;
    altura = 0;
}