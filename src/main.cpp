#include <iostream> 
#include <algorithm>
#include "busqueda_bin.h"

/** 
 * @file 
 * @brief busqueda binaria
 *
 * @details Las opciones son las siguientes:
 * - 1) Crear un vector con tamaño de n elementos.
 * - 2) Buscar un número a partir de la versión iterativa del algoritmo de búsqueda binaria.
 * - 3) Buscar un número a partir de la versión recursiva del algoritmo de búsqueda binaria.
 * - 4) Salir del programa.
 */

int menu();

using namespace std;

int main()
{
    BusquedaBin<int>* busqueda = nullptr; ///< Puntero a la instancia de la clase BusquedaBin.

    while (true)
	{
		switch (menu())
		{
        case 1:
        {
            int tam; ///< Número de elementos en el vector ordenado a utilizar.
            cout << "\n¿De cuántos números desea que sea el vector a utilizar? ";
            cin >> tam;

            vector<int> elementos(tam);

            cout << "\n---> ¿Qué números desea agregar al vector?\n";

            for (int i = 0; i < tam; i++)
            {
                cout << "[Índice " << i << "] " << "Número: ";
                cin >> elementos[i];
            }

            sort(elementos.begin(), elementos.end()); ///< Ordena automáticamente el vector en forma ascendente.

            if (busqueda != nullptr)
            {
                delete busqueda; ///< Elimina el vector anterior si fue creado previamente.
            }
           
            busqueda = new BusquedaBin<int>(elementos);
            break;
        }
		case 2:
        {
            if (busqueda == nullptr)
            {
                cout << "\nNo se ha creado un vector aún.";
                break;
            }; 

            int num; ///< Número a buscar en el vector ordenado.
            cout <<  "\nIngrese el número a buscar mediante la versión iterativa: ";
            cin >> num;

            int indice = busqueda->buscaIterativa(num);
            
            if (indice == -1)
            {
                cout << "\nNo se ha encontrado el número en el vector.";
            }
            else
            {
                cout << "\n¡Se ha encontrado el número!";
                cout << "\n---> Índice del número " << num << " : " << indice;
            }
			break;
        }
		case 3:
        {
            if (busqueda == nullptr)
            {
                cout << "\nNo se ha creado un vector aún.";
                break;
            }; 

            int num; ///< Número a buscar en el vector ordenado.
            cout <<  "\nIngrese el número a buscar mediante la versión recursiva: ";
            cin >> num;

            int indice = busqueda->buscaRecursiva(num);
            
            if (indice == -1)
            {
                cout << "\nNo se ha encontrado el número en el vector.";
            }
            else
            {
                cout << "\n¡Se ha encontrado el número!";
                cout << "\n---> Índice del número " << num << " : " << indice;
            }
            break;
        }
        case 4:
        {
			cout << "\nSaliendo del programa...";
			exit(0);
			break;
        }
        }
    }

    delete busqueda; ///< Libera la memoria del vector antes de salir del programa.
}

/***********************************************************************/

/** 
 * @brief Menú del programa que maneja el input (aportación) del usuario.
 *
 * @details Devuelve una opción a la función main().
 */

int menu()
{
    int opcion;
	do
	{
		cout << "\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ ¡ MENÚ ! -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_";
        cout << "\n\n-------> ¡Búsqueda binaria!\n";
        cout << "1) Crear un vector de n elementos.\n";
		cout << "2) Buscar un número a partir de la versión iterativa del algoritmo.\n";
		cout << "3) Buscar un número a partir de la versión recursiva del algoritmo.\n";
        cout << "4) Salir del programa.\n";
		cout << "\n--> Seleccione una opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 4);
	return opcion;
}

/***********************************************************************/

/** 
 * @page Análisis
 * @brief Reflexión teórica y Análisis comparativo del programa 
 * 
 * @section Cuestiones
 * 
 * En este apartado se responden las siguientes cuestiones...
 * 
 * 1) Comparación entre los distintos métodos de ordenamiento vistos en clase.
 * 
 * 2) Complejidad algorítmica (O) de la búsqueda binaria.
 * 
 * 3) Casos de uso: ¿Cuándo es preferible usar búsqueda binaria sobre búsqueda lineal?
 * 
 * @section metodos_orden Análisis comparativo: Métodos de ordenamiento
 * 
 * 1) En clase se discutieron diversos métodos de ordenamiento, entre estos los métodos interativos como los algoritmos de ordenamiento
 * de la burbuja, de selección, etcétera, además de métodos recursivos como el algoritmo de Quicksort y Mergesort.
 * 
 * Los métodos interativos son ideales para estructuras de datos con tamaños desde pequeños a medianos debido al uso de ciclos while en sus algoritmos 
 * que les permite consumir memoria constante (misma cantidad de RAM por ejecución), sin embargo, esta misma característica los convierte en métodos 
 * ineficientes en el caso de grandes estructuras de datos en donde la cantidad de operaciones a realizar puede ser inmensa. Por ejemplo, el algoritmo de
 * la búrbuja utiliza su ciclo while para comparar elementos adyacentes de su estructura de datos hasta alcanzar el orden correcto.
 * 
 * - La complejidad algorítmica de estos métodos suele ser de O(n^2).
 * 
 * Por otra parte, los métodos recursivos son óptimos para estructuras de datos con tamaños desde pequeños a grandes; su recursividad les permite dividir 
 * el espacio de búsqueda fácilmente en subrangos y posteriormente ordenar los elementos de la estructura de datos en forma ascendente. Por ejemplo, el
 * algoritmo de Quicksort divide la estructura de datos mediante la selección de un pivote y ordena los elementos menores a la derecha, mientras que coloca
 * los elementos mayores a su derecha. 
 * 
 *  - La complejidad algorítmica de estos métodos suele ser de O(n log n).
 * 
 * @section complej_alg Complejidad algorítmica: Espacial y temporal
 * 
 * 2) Las complejidades son...
 * 
 * - Búsqueda binaria de forma iterativa.
 * 
 * Su complejidad algorítmica promedio se categoriza como O(log n) en cuestión de tiempo y O(1) en cuestión de memoria, pues crece de forma logarítmica el tiempo de
 * ejecución con respecto al tamaño del vector, y además, usará la misma cantidad de memoria en RAM por ejecución. En el mejor de los casos, su complejidad algorítmica
 * temporal será O(1), lo cual es posible cuando el elemento "x" a buscar se encuentra en el medio del vector, mientras que su complejidad espacial permanecerá como O(1)
 * al consumir memoria constante. 
 * 
 * - Búsqueda binaria de forma recursiva.
 * 
 * Su complejidad algorítmica promedio se categoriza como O(log n) en cuestión de tiempo y O(log n) en cuestión de memoria, pues tanto el tiempo como la memoria utilizada en
 * RAM crece proporcialmente al logaritmo del tamaño del vector: esto se puede comprobar al tener un vector de gran tamaño, donde la cantidad de divisiones aumenta considerablemente
 * y las llamadas a la misma función se quedan congeladas, utilizando aún más memoria. En el mejor de los casos, su complejidad algorítmica temporal será O(1), lo cual es posible
 * cuando el elemento "x" a buscar se encuentra en el medio del vector, y complejidad espacial se convierte en O(1) al consumir memoria constante. 
 * 
 * @section caso_uso Casos de uso: Binaria o linea
 * 
 * 3) Es mejor aplicar el algoritmo de búsqueda binaria en casos donde el espacio de búsqueda tiene demasiados ejemplos, por ejemplo, para un vector de 15,000 elementos, los cuales
 * deben ser ingresados de forma ascendente o ser organizados con una única procedimiento para evitar mayor gasto de memoria en RAM. Dada su complejidad temporal de O(log n), se puede
 * saber la cantidad de operaciones que realizará aplicando un logaritmo base 2 sobre la cantidad de elementos que hay en el espacio de búsqueda: si se sigue el ejemplo, para un vector
 * de 15,000 elementos, la cantidad de operaciones a realizar se aproxima a 13.
 * 
 * Si fuera un espacio de búsqueda pequeña, por ejemplo, de 10 elementos, entonces es más susceptible la búsqueda lineal, dada tiene complejidad espacial de O(1), donde la memoria en RAM
 * que se utiliza por ejecución es constante. Sin embargo, su complejidad temporal es de O(n), lo que implica que el tiempo por ejecución aumenta exactamente igual al tamaño de datos y lo
 * hace un algoritmo ineficiente para grandes cantidades de datos.
 */

/***********************************************************************/

/** 
 * @page Pruebas
 * @brief Ejecución del programa
 * @section pruebas_dijkstra Resultados de Pruebas
 * 
 * Las siguientes imágenes muestran la ejecución exitosa del programa correspondiente
 * al algoritmo de Búsqueda Binaria, el cual tiene las funciones de...
 * 
 * - Inicialización de vector con n elementos.
 * - Inserción de elementos en el vector.
 * - Visualización de la búsqueda de un número "x" mediante la versión iterativa del algoritmo.
 * - Visualización de la búsqueda de un número "x" mediante la versión recursiva del algoritmo.
 * 
 * El primer caso corresponde a un vector cuyos elementos fueron ingresados, en forma ascendente, 
 * por el usuario. A continuación, se muestra la ejecución del programa para este grafo.
 * 
 * \image latex vector1part1.png "Ejecución del programa en un vector inicialmente ordenado (Parte 1)"
 * \image html vector1part1.png
 * 
 * \image latex vector1part2.png "Ejecución del programa en un vector inicialmente ordenado (Part 2 - Final)"
 * \image html vector1part2.png
 * 
 * El segundo caso corresponde a un vector cuyos elementos fueron ingresados, sin orden alguno, 
 * por el usuario. Para ello, se implementa la función sort() de la librería <algorithm>, de tal
 * manera que los elementos del vector sean organizados en forma ascendente correctamente, lo cual
 * sujeta a los elementos del vector a un cambio de índices. A continuación, se muestra la ejecución
 * del programa para este grafo.
 * 
 * \image latex vector2part1.png "Ejecución del programa en un vector inicialmente no ordenado (Parte 1 - Final)"
 * \image html vector2part1.png
 */

/***********************************************************************/

 /** 
 * @page Bibliografía 
 * @brief Fuentes consultadas
 * 
 * Las fuentes consultadas (en formato APA) para la realización de este programa fueron...
 * 
 * 1) Binary search. (2014, enero 28). GeeksforGeeks. https://www.geeksforgeeks.org/dsa/binary-search/
 * 
 * 2) DSA binary search. (s/f). W3schools.com. Recuperado el 12 de mayo de 2026, de https://www.w3schools.com/dsa/dsa_algo_binarysearch.php
 * 
 * 3) C++ algorithm Library Reference (algorithm functions). (s/f). W3schools.com. Recuperado el 12 de mayo de 2026, de https://www.w3schools.com/cpp/cpp_ref_algorithm.asp 
 */