#include <iostream>
#include <fstream>
#include <list>
#include <utility>
#include <ctime> 
#include <iomanip>


#include "NodoArbol.h"    
#include "ArbolBinario.h" 
#include "ArbolAVL.h"     
#include "ArbolRN.h"      

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <archivo_entrada.txt>" << endl;
        return 1;
    }

    string nombreArchivo = argv[1];
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "ERROR: No se pudo abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    // Inicializar puntero raíz
    NodoArbol<int> *raiz = nullptr;

    // Crear instancia del árbol
    ArbolBinario<int> arbolBinario;
    ArbolAVL<int> arbolAVL;
    ArbolRN arbolRN;
    // Cambiar a string
    string operacion;
    int codigo;     
    //variables de tiempo
    double tiempoBinarioInsert = 0.0, tiempoAVLInsert = 0.0, tiempoRNInsert = 0.0;
    double tiempoBinarioEliminar = 0.0, tiempoAVLEliminar = 0.0, tiempoRNEliminar = 0.0;
    // Leer archivo
    while (archivo >> operacion >> codigo) {
        if (operacion == "A") {
            clock_t start;
            //Evaluar el tiempo de cada ejecucion
            start = clock();
            raiz = arbolBinario.insertarNodo(raiz, codigo);
            tiempoBinarioInsert += (std::clock() - start) / (double) CLOCKS_PER_SEC;

            start = clock();
            raiz = arbolAVL.insertarAVL(raiz,codigo);
            tiempoAVLInsert += (clock() - start) / (double) CLOCKS_PER_SEC;

            start = clock();
            arbolRN.insertarRN(codigo);
            tiempoRNInsert += (clock() - start) / (double) CLOCKS_PER_SEC;

        } else if (operacion == "E") {
            clock_t start;
            start = clock();
            raiz = arbolBinario.eliminarNodo(raiz, codigo);
            tiempoBinarioEliminar += (clock() - start) / (double) CLOCKS_PER_SEC;

            start = clock();
            raiz = arbolAVL.eliminarAVL(raiz,codigo);
            tiempoAVLEliminar += (clock() - start) / (double) CLOCKS_PER_SEC;

            start = clock();
            arbolRN.eliminarRN(codigo);
            tiempoRNEliminar += (clock() - start) / (double) CLOCKS_PER_SEC;

        } else {
            cerr << "Operación desconocida: " << operacion << endl;
        }
    }

    archivo.close(); 

    cout << "Archivo '" << nombreArchivo << "' procesado." << endl;
    cout << "Tiempos acumulados (segundos):\n";
    cout << "Inserción:\n";
    cout << "  Árbol Binario: " << tiempoBinarioInsert << "\n";
    cout << "  Árbol AVL:     " << tiempoAVLInsert << "\n";
    cout << "  Árbol RN:      " << tiempoRNInsert << "\n";

    cout << "Eliminación:\n";
    cout << "  Árbol Binario: " << tiempoBinarioEliminar << "\n";
    cout << "  Árbol AVL:     " << tiempoAVLEliminar << "\n";
    cout << "  Árbol RN:      " << tiempoRNEliminar << "\n";

    return 0;
}
