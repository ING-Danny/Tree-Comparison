#include "NodoArbol.h"
#include <list>

// Obtener altura de un nodo
template <typename T>
int altura(NodoArbol<T>* nodo) {
    if (nodo == 0) return 0;
    return nodo->altura;
}

// Obtener máximo entre dos valores
int maximo(int a, int b) {
    return (a > b) ? a : b;
}

// Calcular balance de un nodo
template <typename T>
int balance(NodoArbol<T>* nodo) {
    if (nodo == 0) return 0;
    return altura(nodo->izq) - altura(nodo->der);
}

// Rotación simple a la derecha
template <typename T>
NodoArbol<T>* rotacionDerecha(NodoArbol<T>* y) {
    NodoArbol<T>* x = y->izq;
    NodoArbol<T>* T2 = x->der;

    // Rotar
    x->der = y;
    y->izq = T2;

    // Actualizar alturas
    y->altura = 1 + maximo(altura(y->izq), altura(y->der));
    x->altura = 1 + maximo(altura(x->izq), altura(x->der));

    return x; // Nueva raíz
}

// Rotación simple a la izquierda
template <typename T>
NodoArbol<T>* rotacionIzquierda(NodoArbol<T>* x) {
    NodoArbol<T>* y = x->der;
    NodoArbol<T>* T2 = y->izq;

    // Rotar
    y->izq = x;
    x->der = T2;

    // Actualizar alturas
    x->altura = 1 + maximo(altura(x->izq), altura(x->der));
    y->altura = 1 + maximo(altura(y->izq), altura(y->der));

    return y; // Nueva raíz
}

// Insertar en AVL
template <typename T>
NodoArbol<T>* insertarAVL(NodoArbol<T>* nodo, T valor) {
    // Inserción normal de BST
    if (nodo == 0) {
        return new NodoArbol<T>(valor);
    }
    if (valor < nodo->dato) {
        nodo->izq = insertarAVL(nodo->izq, valor);
    } else if (valor > nodo->dato) {
        nodo->der = insertarAVL(nodo->der, valor);
    } else {
        return nodo; // valores repetidos no se insertan
    }

    // Actualizar altura
    nodo->altura = 1 + maximo(altura(nodo->izq), altura(nodo->der));

    // Obtener balance
    int b = balance(nodo);

    // Caso Izquierda - Izquierda
    if (b > 1 && valor < nodo->izq->dato)
        return rotacionDerecha(nodo);

    // Caso Derecha - Derecha
    if (b < -1 && valor > nodo->der->dato)
        return rotacionIzquierda(nodo);

    // Caso Izquierda - Derecha
    if (b > 1 && valor > nodo->izq->dato) {
        nodo->izq = rotacionIzquierda(nodo->izq);
        return rotacionDerecha(nodo);
    }

    // Caso Derecha - Izquierda
    if (b < -1 && valor < nodo->der->dato) {
        nodo->der = rotacionDerecha(nodo->der);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

// Recorrido inorden (igual que en BST)
template <typename T>
void inordenAVL(NodoArbol<T>* nodo, std::list<T>& lista) {
    if (nodo != 0) {
        inordenAVL(nodo->izq, lista);
        lista.push_back(nodo->dato);
        inordenAVL(nodo->der, lista);
    }
}