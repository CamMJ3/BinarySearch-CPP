# Búsqueda Binaria (C++)

Implementación del algoritmo de búsqueda binaria, tanto en su versión iterativa como recursiva, utilizando la biblioteca std::vector para el almacenamiento dinámico de datos. A través de un menú de interfaz de línea de comandos (CLI) fácil de usar, los usuarios pueden poblar el arreglo de forma dinámica, el cual ordena los elementos automáticamente para garantizar la precisión de la búsqueda.

## Características
 
- Menú interactivo.
- Inicialización de vector con n elementos.
- Inserción de elementos en el vector.
- Visualización de la búsqueda de un número "x" mediante la versión iterativa del algoritmo.
- Visualización de la búsqueda de un número "x" mediante la versión recursiva del algoritmo.

## Estructura del proyecto
- doc/
    - html/
    - latex/
    - images/
        - Imágenes de resultados de pruebas.

- src/
    - busqueda_bin.cpp
    - main.cpp

- headers/
    - busqueda_bin.h

## Documentación
Toda la documentación ha sido generada con Doxygen.

Para visualizar: Diríjase a doc/html/index.html 
Posteriormente, abra con su navegador de preferencia.

Para visualizar todos los comentarios: Vaya a "Class Members", después seleccione "All".

O abra el archivo PDF "refman.pdf".

## Ejecución
- Usando comandos: Abra su terminal, y ejecute el siguiente código...

g++ src/main.cpp -Iheaders -o busqBin
./busqBin

## Autora
Camila Andrea Jaimes Martinez.

## Maestro
Manuel Balderas Victoria.

## Materia y Programa Académico
- Estructura de Datos (Aula).
- Ingeniería en Software y Minería de Datos (1er año).

## Fecha
Martes 12 de Abril, 2026.
