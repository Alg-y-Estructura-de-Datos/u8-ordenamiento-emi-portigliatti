/*
EJERCICIO 2
Crear un programa en C++ que lea la base de datos que el docente indique, y la ordene con el
algoritmo de ordenamiento insertSort a partir del dato también indicado por el docente.
Implemente dentro del algoritmo de ordenamiento el conteo de condicionales que requiere para
ordenar y muéstrelo por pantalla.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Función para aplicar Insertion Sort y contar comparaciones
unsigned long long insertionSort(vector<int> &arr) {
    unsigned long long contadorComparaciones = 0;
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int aux = arr[i];
        int marcador = i;

        // Comparar y desplazar elementos
        while (marcador > 0 && aux < arr[marcador - 1]) {
            arr[marcador] = arr[marcador - 1];
            marcador--;
            contadorComparaciones++;  // Cuenta cada comparación en el while
            contadorComparaciones++;
        }

        // Inserción
        arr[marcador] = aux;
        contadorComparaciones++;  // Cuenta la comparación fallida que sale del while
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
    ifstream file("C:/Users/Emilia/Desktop/Facultad/SEGUNDO AÑO/SEGUNDO SEMESTRE/Programación III/u8-ordenamiento-emi-portigliatti/cmake-build-debug/numeros.txt");
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

        // Aplicar Insertion Sort
        unsigned long long cantidadComparaciones = insertionSort(arr);
        cout << "Cantidad de comparaciones numeros al Azar: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
        // printArray(arr);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    // Leer y ordenar el segundo archivo
    ifstream file2("C:/Users/Emilia/Desktop/Facultad/SEGUNDO AÑO/SEGUNDO SEMESTRE/Programación III/u8-ordenamiento-emi-portigliatti/cmake-build-debug/numerosOrdenados.txt");
    arr.clear();
    if (file2.is_open()) {
        while (getline(file2, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr.push_back(num);
        }
        file2.close();

        // Aplicar Insertion Sort
        unsigned long long cantidadComparaciones = insertionSort(arr);
        cout << "Cantidad de comparaciones numeros ordenados: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
        // printArray(arr);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    // Leer y ordenar el tercer archivo
    ifstream file3("C:/Users/Emilia/Desktop/Facultad/SEGUNDO AÑO/SEGUNDO SEMESTRE/Programación III/u8-ordenamiento-emi-portigliatti/cmake-build-debug/numerosInversa.txt");
    arr.clear();
    if (file3.is_open()) {
        while (getline(file3, line, ',')) {
            stringstream ss(line);
            int num;
            ss >> num;
            arr.push_back(num);
        }
        file3.close();

        // Aplicar Insertion Sort
        unsigned long long cantidadComparaciones = insertionSort(arr);
        cout << "Cantidad de comparaciones numeros en orden inverso: " << cantidadComparaciones << endl;
        // Mostrar el array ordenado
        cout << "Array ordenado: ";
        // printArray(arr);

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
