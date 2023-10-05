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
#include <sstream>
#include <algorithm>
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
// Funcion calcularLPS: Calcula el arreglo de prefijos y sufijos más largo de un patrón
//
// @params patron: Patrón que se desea analizar
// @return: Regresa el arreglo de prefijos y sufijos más largo de un patrón
// @complexity O(n)
// =========================================================================================

vector<int> calcularLPS(const string &patron) {
    int longitudPatron = patron.length();
    vector<int> lps(longitudPatron);

    int longitudActual = 0;
    int i = 1;

    while (i < longitudPatron) {
        if (patron[i] == patron[longitudActual]) {
            longitudActual++;
            lps[i] = longitudActual;
            i++;
        } else {
            if (longitudActual != 0) {
                longitudActual = lps[longitudActual - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
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
//
// @complexity O(n)
// ==========================================================================================

void searchMaliciousCode(const string& transmission, const string& maliciousCode, const string& transmissionName) {
    int longitudTexto = transmission.length();
    int longitudPatron = maliciousCode.length();
    vector<pair<int, int>> coincidencias;

    vector<int> lps = calcularLPS(maliciousCode);

    int i = 0;
    int j = 0;

    while (i < longitudTexto) {
        if (maliciousCode[j] == transmission[i]) {
            i++;
            j++;
        }

        if (j == longitudPatron) {
            int inicio = i - j;
            int fin = i - 1;
            coincidencias.push_back(make_pair(inicio, fin));
            j = lps[j - 1];
        } else if (i < longitudTexto && maliciousCode[j] != transmission[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (coincidencias.empty()) { cout << "(false): Codigo malicioso: '" << maliciousCode << "' no encontrado en ("<< transmissionName << ")" << endl; }
    else {
        for (const auto &coincidencia : coincidencias) {
            cout << "(true) Posicion inicial: " << coincidencia.first << " Posicion final: " << coincidencia.second << endl;
        }
    }
}


// ==========================================================================================
// Función searchSubstringPositions, busca una subcadena en una cadena de transmisión y muestra la
//  posición donde se encuentra
//
// @params transmission: Texto de transmisión que se desea analizar
// @params substring: Subcadena que se desea buscar
//
// @return: Retorna los indices donde se encuentra la subcadena en la cadena de transmisión.
//         
// @complexity O(n)
// ==========================================================================================

void searchSubstringPositions(const string &transmission, const string &substring) {
    int longitudTexto = transmission.length();
    int longitudPatron = substring.length();
    vector<pair<int, int>> coincidencias;

    vector<int> lps = calcularLPS(substring);

    int i = 0;
    int j = 0;

    while (i < longitudTexto) {
        if (substring[j] == transmission[i]) {
            i++;
            j++;
        }

        if (j == longitudPatron) {
            int inicio = i - j;
            int fin = i - 1;
            coincidencias.push_back(make_pair(inicio, fin));
            j = lps[j - 1];
        } else if (i < longitudTexto && substring[j] != transmission[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (coincidencias.empty()) {
        cout << "(false): No hay posiciones para el substring compartido." << endl;
    }
    else {
        for (const auto &coincidencia : coincidencias) {
            cout << "Posicion inicial: " << coincidencia.first << " Posicion final: " << coincidencia.second << endl;
        }
    }
}


// ==========================================================================================
// Función findLongestCommonSubstring, busca el substring más largo común en dos cadenas
// y muestra su posición
//
// @params transmission1: Primer cadena de caracteres que se usará para buscar el substring 
//                        más largo
// @params transmission2: Segunda cadena de caracteres que se usará para buscar el substring 
//                        más largo
//
// @return: Imprime la información del substring más largo común entre las dos cadenas,
//          además, indica la posición donde se encuentra en la cadena
//
// @complexity O(n^2)
// ==========================================================================================

string findLongestCommonSubstring(const string& transmission1, const string& transmission2) {
    int len1 = transmission1.length();
    int len2 = transmission2.length();

    vector<vector<int > > dp(len1 + 1, vector<int>(len2 + 1, 0));
    
    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (transmission1[i - 1] == transmission2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    int startIndex = endIndex - maxLength + 1;
    if (maxLength > 0) {
        return transmission1.substr(startIndex, maxLength);
    } else {
        return "Archivo transmision no valido";
    }
}


// ==========================================================================================
// Función findLongestPalindrome, busca el substring más largo en una cadena palíndroma
//
// @params text: Cadena de caracteres que se usará para buscar el substring más largo
// @params longestPalindrome: Subcadena más larga que se encontró en la cadena
// @params startIndex: Posición inicial donde se encuentra el substring más largo
// @params endIndex: Posición final donde se encuentra el substring más largo
//
// @return: Información del substring más largo que se encontró en la cadena
//
// @complexity O(n^2)
// ==========================================================================================

void findLongestPalindrome(string text, string& longestPalindrome, int& startIndex, int& endIndex) {
    int n = text.length();
    int table[n][n] = {0};
    
    int maxLength = 1;
    int start = 0;

    for (int i = 0; i < n; i++) {
        table[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (text[i] == text[i+1]) {
            table[i][i+1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    for (int cl = 3; cl <= n; cl++) {
        for (int i = 0; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            if (text[i] == text[j] && table[i + 1][j - 1]) {
                table[i][j] = 1;
                start = i;
                maxLength = cl;
            }
        }
    }

    longestPalindrome = text.substr(start, maxLength);
    startIndex = start + 1;
    endIndex = start + maxLength;
}


// ==========================================================================================
// Función main, función principal del programa
//
// @return: 0 si el programa se ejecutó correctamente
//
// @complexity O(n)
// ==========================================================================================

int main() {
    string mcode1Content = readFromFile("mcode01.txt");
    string mcode2Content = readFromFile("mcode02.txt");
    string mcode3Content = readFromFile("mcode03.txt");
    string transmission1Content = readFromFile("transmission01.txt");
    string transmission2Content = readFromFile("transmission02.txt");

    cout << " " << endl;
    cout << "Archivo de transmission 1" << endl;
    cout << transmission1Content << endl;
    cout << " " << endl;

    cout << "Archivo de transmission 2" << endl;
    cout << transmission2Content << endl;
    cout << " " << endl;

    cout << "Archivo de mcode1" << endl;
    cout << mcode1Content << endl;
    cout << " " << endl;

    cout << "Archivo de mcode2" << endl;
    cout << mcode2Content << endl;
    cout << " " << endl;

    cout << "Archivo de mcode3" << endl;
    cout << mcode3Content << endl;
    cout << " " << endl;

    cout << "        T R A N S M I S S I O N  1               " << endl;
    cout << " " << endl;

    cout << "mcode1: " << endl;
    searchMaliciousCode(transmission1Content, mcode1Content, "transmission01.txt");
    cout << " " << endl;

    cout << "mcode2: " << endl;
    searchMaliciousCode(transmission1Content, mcode2Content, "transmission01.txt");
    cout << " " << endl;

    cout << "mcode3: " << endl;
    searchMaliciousCode(transmission1Content, mcode3Content, "transmission01.txt");
    cout << " " << endl;

    cout << "        T R A N S M I S S I O N  2               " << endl;
    cout << " " << endl;

    cout << "mcode1: " << endl;
    searchMaliciousCode(transmission2Content, mcode1Content, "transmission02.txt");
    cout << " " << endl;

    cout << "mcode2: " << endl;
    searchMaliciousCode(transmission2Content, mcode2Content, "transmission02.txt");
    cout << " " << endl;

    cout << "mcode3: " << endl;
    searchMaliciousCode(transmission2Content, mcode3Content, "transmission02.txt");
    cout << " " << endl;


    cout << "        S U B S T R I N G  C O M P A R T I D O  M A S  L A R G O       " << endl;
    cout << " " << endl;
    string longestCommonSubstring = findLongestCommonSubstring(transmission1Content, transmission2Content);
    cout << longestCommonSubstring << endl;
    cout << " " << endl;

    cout << "Posiciones en la transmission1: " << endl;
    searchSubstringPositions(transmission1Content, longestCommonSubstring);
    cout << "\n" << endl;

    cout << "Posiciones en la transmission2: " << endl;
    searchSubstringPositions(transmission2Content, longestCommonSubstring);
    cout << "\n" << endl;
    
    cout << "        P A L I N D R O M O  M A S  L A R G O       " << endl;
    cout << " " << endl;
    string longestPalindrome;
    int startIndex, endIndex;

    cout << "Transmission 1" << endl;
    findLongestPalindrome(transmission1Content, longestPalindrome, startIndex, endIndex);
    cout << "Palindromo mas largo: " << longestPalindrome << endl;
    cout << "Posicion inicial: " << startIndex << endl;
    cout << "Posicion final: " << endIndex << endl;
    cout << " " << endl;

    cout << "Transmission 2" << endl;
    findLongestPalindrome(transmission2Content, longestPalindrome, startIndex, endIndex);
    cout << "Palindromo mas largo: " << longestPalindrome << endl;
    cout << "Posicion inicial: " << startIndex << endl;
    cout << "Posicion final: " << endIndex << endl;
    cout << " " << endl;
    
    return 0;
}