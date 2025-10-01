#ifndef _ARBOLAVL_H__
#define _ARBOLAVL_H__

#include "NodoArbol.h"


template < class T > 
class ArbolAVL {
    protected:
        NodoArbol<T>* raiz;
    public: 
        ArbolAVL();
        int altura(NodoArbol<T>* nodo); //Altura de un nodo
        int balance(NodoArbol<T>* nodo);
        NodoArbol<T>* rotacionDerecha(NodoArbol<T>* y);
        NodoArbol<T>* rotacionIzquierda(NodoArbol<T>* x);
        NodoArbol<T>* insertarAVL(NodoArbol<T>* nodo, T valor);
        NodoArbol<T>* eliminarAVL(NodoArbol<T>* nodo, T valor);
        NodoArbol<T> * minValueNode(NodoArbol<T>* nodo);
        void inOrden(NodoArbol<T>* nodo);
};

#include "ArbolAVL.hxx"
#endif