#ifndef _ARBOLBINARIO_H__
#define _ARBOLBINARIO_H__

#include "NodoArbol.h"


template < class T > 
class ArbolBinario {
    protected:
        NodoArbol<T>* raiz;
    public: 
        ArbolBinario();
        NodoArbol<T>* insertarNodo(NodoArbol<T>* nodo, T valor);
        NodoArbol<T>* eliminarNodo(NodoArbol<T>* nodo, T valor);
        void inOrden(NodoArbol<T>* nodo);
};


#include "ArbolBinario.hxx"
#endif
