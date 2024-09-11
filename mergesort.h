#include <bits/stdc++.h>
using namespace std;

/*
Función 'merge', recibe como parámetros un vector de enteros 'arr' y tres enteros: 
'left', 'mid' y 'right', que representan los índices que delimitan los dos subarreglos a fusionar.
La función fusiona estos subarreglos (arr[left..mid] y arr[mid+1..right]) en un único subarreglo ordenado 
dentro de 'arr'.

Función 'mergeSort', recibe como parámetros un vector de enteros 'arr' y dos enteros: 
'left' y 'right', que representan los índices del subarreglo de 'arr' que se desea ordenar.
La función aplica recursivamente el algoritmo de ordenamiento por mezcla (merge sort) 
para ordenar 'arr' dividiendo el arreglo en mitades, ordenando cada mitad y luego fusionándolas 
con la función 'merge'.
*/

void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear vectores temporales
    vector<int> L(n1), R(n2);

    // Copiar los datos a los vectores temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Fusionar los vectores temporales de vuelta en arr[left..right]

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copiar los elementos restantes de L[], si hay alguno

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 'left' es el índice de la izquierda y 'right' es el índice de la derecha 
// del subarreglo de arr que se va a ordenar
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

