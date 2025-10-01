#include "ArbolAVL.h"

template< class T >
ArbolAVL<T>::ArbolAVL(){
    this->raiz=NULL;
}

// Obtener altura de un nodo
template <class T>
int ArbolAVL<T>::altura(NodoArbol<T>* nodo) {
    if (nodo == 0) 
        return 0;
    return nodo->altura;
}

// Obtener máximo entre dos valores
int maximo(int a, int b) {
    return (a > b) ? a : b;
}
//Obtener Minimo del nodo
template < class T >
NodoArbol<T>* ArbolAVL<T>::minValueNode(NodoArbol<T>* nodo) {
    NodoArbol<T>* current = nodo;

    // loop down to find the leftmost leaf
    while (current->izq != nullptr)
        current = current->izq;

    return current;
}

// Calcular balance de un nodo
template <typename T>
int ArbolAVL<T>::balance(NodoArbol<T>* nodo) {
    if (nodo == 0) 
        return 0;
    return altura(nodo->izq) - altura(nodo->der);
}

// Rotación simple a la derecha
template <typename T>
NodoArbol<T>* ArbolAVL<T>::rotacionDerecha(NodoArbol<T>* y) {
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
NodoArbol<T>* ArbolAVL<T>::rotacionIzquierda(NodoArbol<T>* x) {
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
NodoArbol<T>* ArbolAVL<T>::insertarAVL(NodoArbol<T>* nodo, T valor) {
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

//eliminar nodo
template < class T > 
NodoArbol<T>* ArbolAVL<T>::eliminarAVL(NodoArbol<T>* nodo, T valor) {
    if (nodo == NULL)
        return nodo;
    if(valor < nodo->dato)
        nodo->izq = eliminarAVL(nodo->izq,valor);
    else if(valor > nodo->dato)
        nodo->der = eliminarAVL(nodo->der,valor);
    else{
        // un solo hijo o ninguno 
        if((nodo->izq == NULL) || (nodo->der == NULL)){
            NodoArbol<T>* aux = nodo->izq ? 
                         nodo->izq : nodo->der;
            // Ningun hijo
            if(aux == NULL){
                aux = nodo;
                nodo = NULL;
            }else //Un solo hijo
                *nodo = *aux;
            
            free(aux);
        }else{
            NodoArbol<T>* aux = minValueNode(nodo->der);
            nodo->dato = aux->dato;
            nodo->der = eliminarAVL(nodo->der, aux->dato);
        }

    }

    if(nodo == NULL)
        return nodo;

    nodo->altura = 1 + maximo(altura(nodo->izq), altura(nodo->der));

    int bal = balance(nodo);
    // Caso izquierdo Izquierdo
    if (bal > 1 && balance(nodo->izq) >= 0)
        return rotacionDerecha(nodo);


    //Caso izquierdo derecho
    if(bal > 1 && balance(nodo->izq) < 0){
        nodo->izq = rotacionIzquierda(nodo->izq);
        return rotacionDerecha(nodo);
    }

    // Caso derecho 
    if (bal < -1 && balance(nodo->der) <= 0)
        return rotacionIzquierda(nodo);

    // Derecho - Izquierdo Caso
    if (bal < -1 && balance(nodo->der) > 0) {
        nodo->der = rotacionDerecha(nodo->der);
        return rotacionIzquierda(nodo);
    }

    return nodo;
    
}


// Recorrido inorden (igual que en BST)
template <class T>
void ArbolAVL<T>::inOrden(NodoArbol<T>* nodo) {
    if (nodo != nullptr) {
        inOrden(nodo->izq);
        cout << nodo->dato << " ";
        inOrden(nodo->der);
    }
}
