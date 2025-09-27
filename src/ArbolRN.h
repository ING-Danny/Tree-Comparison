#include <set>
#include <iostream>
using namespace std;

struct ArbolRN {
    set<int> datos;
};

// Insertar un código
void insertarRN(ArbolRN &arbol, int valor) {
    arbol.datos.insert(valor);
}

// Eliminar un código
void eliminarRN(ArbolRN &arbol, int valor) {
    arbol.datos.erase(valor);
}

// Mostrar recorrido en orden
void mostrarEnOrdenRN(const ArbolRN &arbol) {
    for (int valor : arbol.datos) {
        cout << valor << " ";
    }
    cout << endl;
}
