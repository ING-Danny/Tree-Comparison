template <typename T>
struct NodoArbol {
    T dato;                 
    NodoArbol<T>* izq;      
    NodoArbol<T>* der;      
    int altura;             // se usará para el AVL que necesita altura (en el binario normal se ignora)

    NodoArbol(T valor) {
        dato = valor;
        izq = 0;
        der = 0;
        altura = 1;
    }
};

