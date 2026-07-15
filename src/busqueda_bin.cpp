#include <iostream>
#include "busqueda_bin.h"

/** 
 * @file 
 * @brief Implementación de de los constructores y métodos de la plantilla BúsquedaBin.
 */

using namespace std;

/***********************************************************************/

/** 
 * @brief Realiza la búsqueda binaria de forma recursiva en un subrango del vector.
 * @details Primero, divide el vector, el cual es el espacio de búsqueda, en dos mitades usando
 * la fórmula "low + (high - low) / 2" para encontrar el índice central sin riesgo de que
 * se presente un desbordamiento (overflow). Posteriormente, pregunta si el número en el índice
 * central es igual al número "x" que se busca.
 * 
 * Si es mayor, se dirige al subrango derecho, y si es menor, al izquierdo.
 * Nuevamente, encuentra la mitad del subrango, y repite el proceso de búsqueda binaria.
 * @param x Elemento en el vector a buscar.
 * @param low índice del límite inferior del subrango actual.
 * @param high índice del límite superior del subrango actual.
 */

template <typename T>
int BusquedaBin<T>::busquedaRecursiva(const T& x, int low, int high) const
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (estruct_datos[mid] == x)
    {
        return mid;
    }
    else if (estruct_datos[mid] < x)
    {
        return busquedaRecursiva(x, mid + 1, high);
    }
    else
    {
        return busquedaRecursiva(x, low, mid - 1);
    }
}

/***********************************************************************/

/** 
 * @brief Inicializa un vector, o espacio de búsqueda, de n elementos.
 * @details Copia los datos recibidos del vector obtenido del usuario en el vector, o espacio de búsqueda, interno.
 * @param vec_datos Apuntador al vector obtenido del usuario.
 */

template <typename T>
BusquedaBin<T>::BusquedaBin(const vector<T>& vec_datos)
{
    estruct_datos = vec_datos;
}

/***********************************************************************/

/** 
 * @brief Realiza la búsqueda binaria de forma iterativa en todo el vector.
 * @details Primero, delimita el espacio de búsqueda en el primer (low) y último
 * (high) elemento del vector, y despúes lo divide en dos mitades usando
 * la fórmula "low + (high - low) / 2" para encontrar el índice central sin riesgo de que
 * se presente un desbordamiento (overflow). Posteriormente, pregunta si el número en el índice
 * central es igual al número "x" que se busca.
 * 
 * Si es mayor, se dirige al subrango derecho, y si es menor, al izquierdo.
 * Nuevamente, encuentra la mitad del subrango, y repite el proceso de búsqueda binaria.
 * @param x Elemento en el vector a buscar.
 */

template <typename T>
int BusquedaBin<T>::buscaIterativa(const T& x) const
{
    int low = 0;
    int high = estruct_datos.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (estruct_datos[mid] == x)
        {
            return mid;
        }
        else if (estruct_datos[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

/***********************************************************************/

/** 
 * @brief Recibe el elemento a buscar para la búsqueda binaria de forma recursiva.
 * @details A partir del número obtenido del usuario, se utiliza la función privada de 
 * búsqueda binaria recursiva para calcular, automáticamente, los índices de low y high.
 * @param x Elemento en el vector a buscar.
 */

template <typename T>
int BusquedaBin<T>::buscaRecursiva(const T& x) const
{
    return busquedaRecursiva(x, 0, estruct_datos.size() - 1);
}

/***********************************************************************/