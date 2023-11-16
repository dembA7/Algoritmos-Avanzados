// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Programa que permite buscar un código malicioso en un archivo de transmisión
//              y encontrar el palíndromo más largo en una cadena.
//
// ==========================================================================================

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// ==========================================================================================
// Función readFromFile, lee el contenido de un archivo y lo devuelve como una cadena de 
// caracteres
// 
// @params filename: Archivo que se desea leer
//
// @return: Regresa el contenido del archivo como una cadena de caracteres
// @complexity O(n)
// ==========================================================================================

string readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "\nNo se encontro el archivo." << endl;
        return "";
    }

    std::string buffer;
    std::string line;

    while (std::getline(file, line)) {
        buffer += line;
    }

    file.close();
    return buffer;
}


// ==========================================================================================
// Función readFromFile, lee el contenido de un archivo y lo devuelve como una cadena de 
// caracteres
// 
// @params filename: Archivo que se desea leer
//
// @return: Regresa el contenido del archivo como una cadena de caracteres
// @complexity O(n)
// ==========================================================================================



// ==========================================================================================
// Función readFromFile, lee el contenido de un archivo y lo devuelve como una cadena de 
// caracteres
// 
// @params filename: Archivo que se desea leer
//
// @return: Regresa el contenido del archivo como una cadena de caracteres
// @complexity O(n)
// ==========================================================================================



// ==========================================================================================
// Función readFromFile, lee el contenido de un archivo y lo devuelve como una cadena de 
// caracteres
// 
// @params filename: Archivo que se desea leer
//
// @return: Regresa el contenido del archivo como una cadena de caracteres
// @complexity O(n)
// ==========================================================================================

// int main() {
//     int n;
//     vector<vector<int>> dist;

//     cout << "Incerta el número de colonias en la ciudad" << endl;
//     cin >> n;

//     vector<vector<int> > graph(n, vector<int>(n));
//     cout << "Incerta el grafo con las distancias en kms entre las colonias de la ciudad" << endl;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             cin >> graph[i][j];
//         }
//     }

// }

int main() {
    string input1Content = readFromFile("input01.txt");
    string input2Content = readFromFile("input02.txt");
    string input3Content = readFromFile("input03.txt");

    cout << "Archivo de entrada 1" << endl;
    cout << input1Content << endl;
    cout << " " << endl;

    cout << "Archivo de entrada 2" << endl;
    cout << input2Content << endl;
    cout << " " << endl;

    cout << "Archivo de entrada 3" << endl;
    cout << input3Content << endl;
    cout << " " << endl;

    // cout << "        T R A N S M I S S I O N  1               " << endl;
    // cout << " " << endl;

    // cout << "mcode1: " << endl;
    // searchMaliciousCode(transmission1Content, mcode1Content, "transmission01.txt");
    // cout << " " << endl;

    // cout << "mcode2: " << endl;
    // searchMaliciousCode(transmission1Content, mcode2Content, "transmission01.txt");
    // cout << " " << endl;

    // cout << "mcode3: " << endl;
    // searchMaliciousCode(transmission1Content, mcode3Content, "transmission01.txt");
    // cout << " " << endl;

    // cout << "        T R A N S M I S S I O N  2               " << endl;
    // cout << " " << endl;

    // cout << "mcode1: " << endl;
    // searchMaliciousCode(transmission2Content, mcode1Content, "transmission02.txt");
    // cout << " " << endl;

    // cout << "mcode2: " << endl;
    // searchMaliciousCode(transmission2Content, mcode2Content, "transmission02.txt");
    // cout << " " << endl;

    // cout << "mcode3: " << endl;
    // searchMaliciousCode(transmission2Content, mcode3Content, "transmission02.txt");
    // cout << " " << endl;


    // cout << "        S U B S T R I N G  C O M P A R T I D O  M A S  L A R G O       " << endl;
    // cout << " " << endl;
    // string longestCommonSubstring = findLongestCommonSubstring(transmission1Content, transmission2Content);
    // cout << longestCommonSubstring << endl;
    // cout << " " << endl;

    // cout << "Posiciones en la transmission1: " << endl;
    // searchSubstringPositions(transmission1Content, longestCommonSubstring);
    // cout << "\n" << endl;

    // cout << "Posiciones en la transmission2: " << endl;
    // searchSubstringPositions(transmission2Content, longestCommonSubstring);
    // cout << "\n" << endl;
    
    // cout << "        P A L I N D R O M O  M A S  L A R G O       " << endl;
    // cout << " " << endl;
    // string longestPalindrome;
    // int startIndex, endIndex;

    // cout << "Transmission 1" << endl;
    // findLongestPalindrome(transmission1Content, longestPalindrome, startIndex, endIndex);
    // cout << "Palindromo mas largo: " << longestPalindrome << endl;
    // cout << "Posicion inicial: " << startIndex << endl;
    // cout << "Posicion final: " << endIndex << endl;
    // cout << " " << endl;

    // cout << "Transmission 2" << endl;
    // findLongestPalindrome(transmission2Content, longestPalindrome, startIndex, endIndex);
    // cout << "Palindromo mas largo: " << longestPalindrome << endl;
    // cout << "Posicion inicial: " << startIndex << endl;
    // cout << "Posicion final: " << endIndex << endl;
    // cout << " " << endl;
    
    return 0;
}