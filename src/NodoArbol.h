#ifndef _NODOBINARIO_H__
#define _NODOBINARIO_H__

#include <iostream>



using namespace std;

template <class T>
class NodoArbol {
    public:
        T dato;                 
        NodoArbol<T> *izq;      
        NodoArbol<T> *der;      
        int altura;     
    
        NodoArbol(T valor);

};

#include "NodoArbol.hxx"
#endif