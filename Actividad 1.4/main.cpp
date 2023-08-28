// =================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Merge sort algorithm, divide and conquer implementation.
//
// =================================================================

#include <iostream>
#include <vector>
#include <fstream>

// Función para combinar dos subarreglos ordenados en un solo arreglo ordenado
void merge(std::vector<double>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crear arreglos temporales para almacenar los subarreglos
    std::vector<double> L(n1);
    std::vector<double> R(n2);

    // Copiar datos a los arreglos temporales L[] y R[]
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[middle + 1 + j];
    }

    // Combinar los arreglos temporales en el arreglo original arr[]
    int i = 0; // Índice para el subarreglo izquierdo
    int j = 0; // Índice para el subarreglo derecho
    int k = left; // Índice para el arreglo combinado

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Función principal de Merge Sort
void mergeSort(std::vector<double>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Ordenar las dos mitades
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Combinar las mitades ordenadas
        merge(arr, left, middle, right); // Complejidad: O(N)
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " archivo1 archivo2 ..." << std::endl;
        return 1;
    }

    for (int fileIndex = 1; fileIndex < argc; ++fileIndex) {
        std::ifstream inputFile(argv[fileIndex]);

        if (!inputFile) {
            std::cerr << "No se pudo abrir el archivo " << argv[fileIndex] << std::endl;
            continue;
        }

        int N;
        inputFile >> N;

        std::vector<double> arr(N);
        for (int i = 0; i < N; ++i) {
            inputFile >> arr[i];
        }

        inputFile.close();

        mergeSort(arr, 0, N - 1); // Complejidad: O(N log N)

        std::cout << "Valores ordenados del archivo '" << argv[fileIndex] << "' de menor a mayor: ";
        for (double val : arr) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}