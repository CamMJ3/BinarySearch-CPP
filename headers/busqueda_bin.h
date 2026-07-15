#pragma once
#include <vector>

using namespace std;

/** 
 * @file 
 * @brief Se define la estructura de datos para la implementación del algoritmo de búsqueda binaria.
 * @author Camila Andrea Jaimes Martínez.
 * 
 * @details a
 */

template <typename T>
class BusquedaBin 
{
    private:
        vector<T> estruct_datos; ///< Vector ordenado de la estructura de datos a utilizar.

        int busquedaRecursiva(const T& x, int low, int high) const; ///< Realiza la búsqueda binaria de forma recursiva en un subrango del vector.

    public:
        BusquedaBin(const vector<T>& vec_datos); ///< Inicializa un vector, o espacio de búsqueda, de n elementos.

        int buscaIterativa(const T& x) const; ///< Realiza la búsqueda binaria de forma iterativa en todo el vector.
        int buscaRecursiva(const T& x) const; ///< Recibe el elemento a buscar para la búsqueda binaria de forma recursiva.
};

#include "../src/busqueda_bin.cpp"