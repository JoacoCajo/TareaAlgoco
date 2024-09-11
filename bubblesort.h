/*
Función 'bubbleSort', recibe como parámetros un vector de enteros 'vector' y un entero 'n', 
que indica la cantidad de elementos en el vector. 

La función implementa una versión optimizada del algoritmo de ordenamiento burbuja (Bubble Sort), 
donde se ordena el vector comparando y, si es necesario, intercambiando elementos adyacentes. 
El algoritmo incluye una optimización que detiene la ejecución si en una pasada completa no se realizan intercambios, 
indicando que el vector ya está ordenado.

La función no retorna ningún valor ya que modifica el vector 'vector' directamente.
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

void bubbleSort(vector <int> vector, int n)
{
    int i, j;
    bool swapped;
        for (i = 0; i < n - 1; i++) {
            swapped = false;
            for (j = 0; j < n - i - 1; j++) {
                if (vector[j] > vector[j + 1]) {
                    swap(vector[j], vector[j + 1]);
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
        }
}
