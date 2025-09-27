#include "NodoArbol.h"
#include <list>

// Insertar en Árbol Binario
template <typename T>
NodoArbol<T>* insertarNodo(NodoArbol<T>* nodo, T valor) {
    if (nodo == 0) {
        return new NodoArbol<T>(valor);
    }
    if (valor < nodo->dato) {
        nodo->izq = insertarNodo(nodo->izq, valor);
    } else if (valor > nodo->dato) {
        nodo->der = insertarNodo(nodo->der, valor);
    }
    return nodo;
}

// Recorrido inorden
template <typename T>
void inorden(NodoArbol<T>* nodo, std::list<T>& lista) {
    if (nodo != 0) {
        inorden(nodo->izq, lista);
        lista.push_back(nodo->dato);
        inorden(nodo->der, lista);
    }
}

// Eliminar nodo
template <typename T>
NodoArbol<T>* eliminarNodo(NodoArbol<T>* nodo, T valor) {
    if (nodo == 0) return nodo;

    if (valor < nodo->dato) {
        nodo->izq = eliminarNodo(nodo->izq, valor);
    } else if (valor > nodo->dato) {
        nodo->der = eliminarNodo(nodo->der, valor);
    } else {
        // Caso 1: sin hijos
        if (nodo->izq == 0 && nodo->der == 0) {
            delete nodo;
            return 0;
        }
        // Caso 2: un hijo
        else if (nodo->izq == 0) {
            NodoArbol<T>* temp = nodo->der;
            delete nodo;
            return temp;
        } else if (nodo->der == 0) {
            NodoArbol<T>* temp = nodo->izq;
            delete nodo;
            return temp;
        }
        // Caso 3: dos hijos
        else {
            NodoArbol<T>* sucesor = nodo->der;
            while (sucesor->izq != 0) {
                sucesor = sucesor->izq;
            }
            nodo->dato = sucesor->dato;
            nodo->der = eliminarNodo(nodo->der, sucesor->dato);
        }
    }
    return nodo;
}
