/*
Función 'partition', recibe como parámetros un vector de enteros 'arr' y dos enteros 'low' y 'high', 
que representan los índices del subarreglo de 'arr' que se está procesando. 

La función selecciona el último elemento del subarreglo como pivote y reordena el subarreglo para que 
todos los elementos menores que el pivote estén a su izquierda y los mayores a su derecha. 
Devuelve la posición correcta del pivote después de la reordenación.

Función 'quickSort', recibe como parámetros un vector de enteros 'arr' y dos enteros 'low' y 'high', 
que representan los índices del subarreglo de 'arr' que se desea ordenar. 

La función implementa el algoritmo de ordenamiento rápido (QuickSort), dividiendo recursivamente el 
subarreglo en dos partes según el pivote proporcionado por la función 'partition': una parte con elementos 
menores y otra con elementos mayores o iguales al pivote. La función se llama recursivamente para ordenar 
ambas partes.

Ambas funciones no retornan valores ya que modifican el vector 'arr' directamente.
*/

int partition(vector<int>& arr, int low, int high) {
  

    int pivot = arr[high];
  
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}


void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
