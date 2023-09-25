// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Algoritmo que dado un string, calcule el arreglo de substrings y lo 
// muestre ordenado alfabéticamente.
//
// ==========================================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

void printSubstrings(const std::vector<std::string>& substrings) {
    for (const std::string& substring : substrings) {
        std::cout << substring << std::endl;
    }
}

int main() {
    std::string inputString;
    std::cout << "Ingrese un string: ";
    std::cin >> inputString;

    std::unordered_set<std::string> substrings_set;

    for (size_t i = 0; i < inputString.length(); ++i) {
        for (size_t j = 1; j <= inputString.length() - i; ++j) {
            substrings_set.insert(inputString.substr(i, j));
        }
    }

    std::vector<std::string> substrings(substrings_set.begin(), substrings_set.end());

    std::sort(substrings.begin(), substrings.end());

    std::cout << "Substrings ordenados alfabeticamente:" << std::endl;
    printSubstrings(substrings);

    return 0;
}
