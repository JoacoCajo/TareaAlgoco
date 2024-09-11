#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include "bubblesort.h"
#include <string>
#include "mergesort.h"
#include "quicksort.h"
#include <cstdlib>
/*Función 'generar_ordenamiento', recibe como parametros un entero 'tipo_datos'
que simboliza si se trata de datos desordenados(1) o parcialmente ordenados(2).
El entero 'cant_datos' indica la cantidad de datos a generar, generalmente en potencias de 10.
La función retorna vacio, pero en su interior genera un archivo .txt que nos servirá para probar
los algoritmos de ordenamiento.
*/
void generar_ordenamiento(int tipo_datos, int cant_datos)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1,1000);

    //GENERAR UN VECTOR DE DATOS DESORDENADOS.
    if(tipo_datos== 1)
    {
        ofstream archivo ("datos_desordenados" + to_string(cant_datos) + ".txt");
        vector<int> datos_desordenados;
        for (int i = 0; i<=cant_datos; i++)
        {
        
        datos_desordenados.push_back(distr(gen));

        }

        if (archivo.is_open())
        {
        archivo.write(reinterpret_cast<const char*>(datos_desordenados.data()), datos_desordenados.size() * sizeof(int));
        archivo.close();
        }
    
    }
       //GENERAR UN VECTOR DE DATOS PARCIALMENTE ORDENADOS
    else if(tipo_datos == 2)
    {
        ofstream archivo ("datos_parcialmente_ordenados" + to_string(cant_datos) + ".txt");
        vector<int> datos_parcialmente_ordenados;
        int potencia = cant_datos;

        for(int i = 0; i<=(potencia/2); i++)
        {
            datos_parcialmente_ordenados.push_back(i+1);
        }

        uniform_int_distribution<> distr((potencia/2),potencia);
        for(int i = 50; i<=potencia; i++)
        {
            datos_parcialmente_ordenados.push_back(distr(gen));
        }


        if (archivo.is_open())
        {
        archivo.write(reinterpret_cast<const char*>(datos_parcialmente_ordenados.data()), datos_parcialmente_ordenados.size() * sizeof(int));
        archivo.close();
        }
    }

}
//Función "generar_matriz"
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>

using namespace std;
//MATRIZ NO IMPLEMENTADA.
int main()
{
    string flag;
    cout << "¿Quieres generar los datos? (true/false)" << endl;
    cin>>flag;
    if(flag=="true"){
        int es_matriz;
        cout << "1. Multiplicacion de matrices 2. Algoritmos de ordenamiento"<<endl;
        cin>>es_matriz;
        if(es_matriz==1)
        {
            int filas;
            int columnas;
            int filas2;
            int columnas2;
            cout<< "Indique n° filas (matriz 1)";
            cin >>filas;
            cout<< "Indique n° columnas (matriz 1)";
            cin >> columnas;
            cout<< "Indique n° filas (matriz 2)";
            cin >>filas2;
            cout<< "Indique n° columnas (matriz 2)";
            cin >> columnas2;
        }
        else if(es_matriz==2)
        {
            int tipo_datos;
            int cant_datos;
            cout<<"Elige el tipo de datos\n1. Desordenados 2. Parcialmente Ordenados."<<endl;
            cin >> tipo_datos ;
        
            cout << "Cantidad de datos: " <<endl;
            cin >> cant_datos ;
            generar_ordenamiento(tipo_datos, cant_datos);
            exit(1);
        }
    }
    else
    {  
        int accion;
        cout<< "1. Multiplicacion de matrices 2. Algoritmos de ordenamiento"<<endl;
        cin>>accion;
        if(accion==1)
        { //MATRIZ NO IMPLEMENTADA
        }
        else if(accion==2)
        {
            int tipo_ordenamiento;
            int tipo_datos;
            int cant_datos;

            cout << "Elige el tipo de ordenamiento: \n1. Bubble sort 2. Mergesort 3. Quicksort 4. Sorting nativo"<< endl;
            cin >> tipo_ordenamiento ;
            cout<<"Elige el tipo de datos\n1. Desordenados 2. Parcialmente Ordenados."<<endl;
            cin >> tipo_datos ;
            cout << "Cantidad de datos: " <<endl;
            cin >> cant_datos ;

            //bubblesort
            if(tipo_ordenamiento == 1)
            {
                //Desordenados
                string datos;
                if(tipo_datos == 1)
                {
                    datos= "datos_desordenados";
                } 
                //parcialmente ordenados
                else if(tipo_datos == 2)
                {
                    datos= "datos_parcialmente_ordenados";
                }
                ifstream archivo (datos + to_string(cant_datos) + ".txt");
                if(archivo.is_open())
                {
                    vector <int> vector(cant_datos);
                    archivo.read(reinterpret_cast<char*>(vector.data()), vector.size() * sizeof(int));
                    auto start = chrono::high_resolution_clock::now();
                    bubbleSort(vector, cant_datos);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
                    if(tipo_datos == 1)
                    {
                        cout << "Bubble Sort, tiempo de ejecución: " << duration.count() << " microsegundos" << " con "<< cant_datos << " datos desordenados." << endl;
                        archivo.close();
                    }
                    else
                    {
                        cout << "Bubble Sort, tiempo de ejecución: " << duration.count() << " microsegundos" << " con "<< cant_datos << " datos parcialmente ordenados." << endl;
                        archivo.close();
                    }
                }

            }
            
            else if(tipo_ordenamiento == 2)
            {
                string datos;
                if(tipo_datos == 1)
                {
                    datos = "datos_desordenados";
                }
                else if (tipo_datos == 2)
                {
                    datos = "datos_parcialmente_ordenados";
                }

                    ifstream archivo (datos+to_string(cant_datos)+".txt");
                    if(archivo.is_open())
                        {
                            vector <int> vector(cant_datos);
                            archivo.read(reinterpret_cast<char*>(vector.data()), vector.size() * sizeof(int));
                            auto start = chrono::high_resolution_clock::now();
                            mergeSort(vector, 0 , cant_datos-1);
                            auto end = chrono::high_resolution_clock::now();
                            auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
                            if(tipo_datos == 1)
                            {   
                                cout << "mergeSort, tiempo de ejecución: " << duration.count() << " microsegundos" << " con "<< cant_datos << " datos desordenados." << endl;
                                archivo.close();
                            }
                            else
                            {
                                cout << "mergeSort, tiempo de ejecución: " << duration.count() << " microsegundos" << " con "<< cant_datos << " datos parcialmente ordenados." << endl;
                                archivo.close();
                            }
                        }
            }
            else if(tipo_ordenamiento == 3)
            {
                string datos;
                if(tipo_datos == 1)
                {
                    datos = "datos_desordenados";
                }
                else if (tipo_datos == 2)
                {
                    datos = "datos_parcialmente_ordenados";
                }

                ifstream archivo (datos+to_string(cant_datos)+".txt");
                if(archivo.is_open())
                {
                    vector <int> vector(cant_datos);
                    archivo.read(reinterpret_cast<char*>(vector.data()), vector.size() * sizeof(int));
                    //printvectoray(vector, cant_datos); //para buscar bugs

                    auto start = chrono::high_resolution_clock::now();
                    quickSort(vector, 0 , cant_datos-1);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);

                    if(tipo_datos == 1)
                    {
                        cout << "Quicksort, tiempo de ejecución: " << duration.count() << " microsegundos" << " con "<< cant_datos << " datos desordenados." << endl;
                        archivo.close();
                    }
                    else
                    {
                        cout << "Quicksort, tiempo de ejecución: " << duration.count() << " microsegundos" << " con "<< cant_datos << " datos parcialmente ordenados." << endl;
                        archivo.close();
                    }
                }
            }
            //Sorting Nativo.
            else if(tipo_ordenamiento == 4)
            {
                string datos;
                if(tipo_datos == 1)
                {
                    datos = "datos_desordenados";
                }
                else if (tipo_datos == 2)
                {
                    datos = "datos_parcialmente_ordenados";
                }

                ifstream archivo (datos+to_string(cant_datos)+".txt");
                if(archivo.is_open())
                {
                    vector <int> vector(cant_datos);
                    archivo.read(reinterpret_cast<char*>(vector.data()), vector.size() * sizeof(int));
                    auto start = chrono::high_resolution_clock::now();

                    sort(vector.begin(), vector.end());

                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);

                    if(tipo_datos == 1)
                    {
                        cout << "Sort nativo, tiempo de ejecución: " << duration.count() << " microsegundos" << " con "<< cant_datos << " datos desordenados." << endl;
                        archivo.close();
                    }
                    else
                    {
                        cout << "Sort nativo, tiempo de ejecución: " << duration.count() << " microsegundos" << " con "<< cant_datos << " datos parcialmente ordenados." << endl;
                        archivo.close();
                    }
                }
            }
        }
    }

 return 0;

}