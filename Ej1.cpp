/*
EJERCICIO 1
Crear un programa en C++ que lea la base de datos que el docente indique, y la ordene con el
algoritmo de ordenamiento bubbleSort a partir del dato también indicado por el docente.
Implemente dentro del algoritmo de ordenamiento el conteo de condicionales que requiere para
ordenar y muéstrelo por pantalla.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Función para aplicar Bubble Sort
unsigned long long bubbleSort(vector<int> &arr) {
    unsigned long long contadorComparaciones = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        contadorComparaciones++;

        for (int j = 0; j < n - i - 1; j++) {
            contadorComparaciones++;
            contadorComparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return contadorComparaciones;
}

// Función para mostrar el array
void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    ifstream file("numeros.txt");
    string line;
    vector<int> arr;

    if (file.is_open()) {
        // Leer el archivo y extraer los números
        while (getline(file, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr.push_back(num);
        }
        file.close();

        // Mostrar el array antes de ordenar
//        cout << "Array desordenado: ";
//        printArray(arr);

        // Aplicar Bubble Sort
        unsigned long long cantidadCondicionales  = bubbleSort(arr);
        cout << "Cantidad de comparaciones numeros al Azar: " << cantidadCondicionales << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: "<< endl;
//        printArray(arr);
//
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    ifstream file2("numerosOrdenados.txt");
    if (file2.is_open()) {
        // Leer el archivo y extraer los números
        while (getline(file2, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr.push_back(num);
        }
        file2.close();

        // Mostrar el array antes de ordenar
//        cout << "Array desordenado: ";
//        printArray(arr);

        // Aplicar Bubble Sort
        unsigned long long cantidadCondicionales  = bubbleSort(arr);
        cout << "Cantidad de comparaciones numeros ordenados: " << cantidadCondicionales << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: "<< endl;
//        printArray(arr);
//
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    ifstream file3("numerosInversa.txt");
    if (file3.is_open()) {
        // Leer el archivo y extraer los números
        while (getline(file3, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr.push_back(num);
        }
        file3.close();

        // Mostrar el array antes de ordenar
//        cout << "Array desordenado: ";
//        printArray(arr);

        // Aplicar Bubble Sort
        unsigned long long cantidadCondicionales  = bubbleSort(arr);
        cout << "Cantidad de comparaciones numeros ordenados: " << cantidadCondicionales << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: "<< endl;
//        printArray(arr);
//
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}