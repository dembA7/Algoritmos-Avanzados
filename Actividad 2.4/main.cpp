// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Algoritmo que dado un string, calcula el arreglo de substrings y lo 
// muestre ordenado alfabéticamente.
//
// ==========================================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


// ==========================================================================================
// Función printSubstrings, imprime el arreglo de substrings ordenado alfabéticamente.
// 
// @params n: Vector de strings que contiene los substrings del string original.
//
// @return: Imprime el arreglo de substrings ordenado alfabéticamente.
// @complexity O(n)
// ==========================================================================================

void printSubstrings(const vector<string>& substrings) {
    for (const string& substring:substrings) {
        cout << substring << endl;
    }
}

// ==========================================================================================
// Funcion main, toma como entrada un string y devuelve el arreglo de substrings ordenado
// 
// @params n: String de entrada.
//
// @return: 0 si el programa se ejecuta correctamente.
// @complexity O(n)
// ==========================================================================================

int main() {
    string inputString;
    cout << "Ingrese un string: ";
    cin >> inputString;

    unordered_set<string> substrings_set;
    int j = inputString.length();
    for (size_t i = 0; i < inputString.length(); i++) {
        substrings_set.insert(inputString.substr(i, j));
    }

    vector<string> substrings(substrings_set.begin(), substrings_set.end());

    sort(substrings.begin(), substrings.end());

    cout << "Substrings ordenados alfabeticamente:" << endl;
    printSubstrings(substrings);

    return 0;
}
