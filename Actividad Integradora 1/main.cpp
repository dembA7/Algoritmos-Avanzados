// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Algoritmo que permite buscar un código malicioso en un archivo de transmisión
//              y encontrar el palíndromo más largo en una cadena.
//
// ==========================================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

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
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// ==========================================================================================
// Función isPalindrome, verifica si un texto es palíndromo o no
// 
// @params text: Texto que se desea verificar
//
// @return: Regresa el texto al revés
// @complexity O(n)
// ==========================================================================================

bool isPalindrome(const string& text) {
    string reversedText = text;
    reverse(reversedText.begin(), reversedText.end());
    return text == reversedText;
}

// ==========================================================================================
// Función searchMaliciousCode, busca si una subcadena de código malicioso está contenido 
// en un archivo de transmisión y muestra la posición donde se encuentra
// 
// @params transmission: Texto de transmisión que se desea analizar
// @params maliciousCode: Código malicioso que se desea buscar
// @params transmissionName: Nombre del archivo de transmisión que se desea analizar
//
// @return: Regresa true o false dependiendo si el código malicioso está contenido en el
//          archivo de transmisión
// @complexity O(n)
// ==========================================================================================

void searchMaliciousCode(const string& transmission, const string& maliciousCode, const string& transmissionName) {
    size_t pos = transmission.find(maliciousCode);

    if (pos != string::npos) {
        cout << "true " << pos / 2 + 1 << " (in " << transmissionName << ")" << endl;
    } else {
        cout << "false (in " << transmissionName << ")" << endl;
    }
}

// ==========================================================================================
// Función findLongestPalindrome, busca el palíndromo más largo en una cadena y muestra su
// posición
// 
// @params transmission: Texto de transmisión que se desea analizar
// @params maliciousCode: Código malicioso que se desea buscar
// @params transmissionName: Nombre del archivo de transmisión que se desea analizar
//
// @return: Regresa el palíndromo más largo identificado en los archivos de transmisión
// @complexity O(n)
// ==========================================================================================

void findLongestPalindrome(const string& transmission, const string& transmissionName) {
    int maxLength = 1;  // Longitud mínima de un palíndromo: 1
    int start = 0;  // Posición inicial del palíndromo

    int len = transmission.length();

    for (int i = 1; i < len; ++i) {
        // Buscar palíndromos con i como centro
        int low = i - 1;
        int high = i;
        while (low >= 0 && high < len && transmission[low] == transmission[high]) {
            if (high - low + 1 > maxLength) {
                maxLength = high - low + 1;
                start = low;
            }
            --low;
            ++high;
        }

        // Buscar palíndromos con i-1 e i como centro
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && transmission[low] == transmission[high]) {
            if (high - low + 1 > maxLength) {
                maxLength = high - low + 1;
                start = low;
            }
            --low;
            ++high;
        }
    }

    cout << start + 1 << " " << start + maxLength << " (in " << transmissionName << ")" << endl;
}

// ==========================================================================================
// Función findLongestCommonSubstring, busca el substring más largo común en dos cadenas 
// y muestra su posición
// 
// @params str1: Primer cadena de caracteres que se usará para buscar el substring más largo
// @params str2: Segunda cadena de caracteres que se usará para buscar el substring más largo
// @params transmissionName: 
//
// @return: Imprime la información del substring más largo común entre las dos cadenas, 
//          además, indica la posición donde se encuentra en la cadena
//
// @complexity O(n^2)
// ==========================================================================================

void findLongestCommonSubstring(const string& str1, const string& str2, const string& transmission1Name) {
    int len1 = str1.length();
    int len2 = str2.length();

    int maxLength = 0;
    int endingIndex = 0;

    // Inicializar una matriz para almacenar la longitud de la subcadena común
    int lcs[len1 + 1][len2 + 1];

    // Rellenar la matriz y encontrar la longitud de la subcadena común
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if (lcs[i][j] > maxLength) {
                    maxLength = lcs[i][j];
                    endingIndex = i - 1;
                }
            } else
                lcs[i][j] = 0;
        }
    }

    int startingIndex = endingIndex - maxLength + 1;

    cout << startingIndex + 1 << " " << endingIndex + 1 << " (in " << transmission1Name << ")" << endl;
}

int main() {
    // Leer el contenido de los archivos
    string mcode1Content = readFromFile("mcode1.txt");
    string mcode2Content = readFromFile("mcode2.txt");
    string mcode3Content = readFromFile("mcode3.txt");
    string transmission1Content = readFromFile("transmission1.txt");
    string transmission2Content = readFromFile("transmission2.txt");

    // Códigos maliciosos contenidos en las transmisiones
    cout << "\n======================================" << endl;
    cout << "Búsqueda del código malicioso          " << endl;
    cout << "======================================" << endl;
    searchMaliciousCode(transmission1Content, mcode1Content, "transmission1.txt");
    searchMaliciousCode(transmission1Content, mcode2Content, "transmission1.txt");
    searchMaliciousCode(transmission1Content, mcode3Content, "transmission1.txt");
    searchMaliciousCode(transmission2Content, mcode1Content, "transmission2.txt");
    searchMaliciousCode(transmission2Content, mcode2Content, "transmission2.txt");
    searchMaliciousCode(transmission2Content, mcode3Content, "transmission2.txt");

    // Palíndromos en las transmisiones
    cout << "\n======================================" << endl;
    cout << "Búsqueda de palindromos              " << endl;
    cout << "======================================" << endl;
    findLongestPalindrome(transmission1Content, "transmission1.txt");
    findLongestPalindrome(transmission2Content, "transmission2.txt");

    // Substring más largo común entre las transmisiones
    cout << "\n======================================" << endl;
    cout << "Búsqueda de subcadena común más largo      " << endl;
    cout << "======================================" << endl;
    findLongestCommonSubstring(transmission1Content, transmission2Content, "transmission1.txt");
    cout << "\n" << endl;
    return 0;
}
