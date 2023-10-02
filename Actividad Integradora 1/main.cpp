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

    while (std::getline(file, line))
    {
        buffer += line;
    }

    file.close();
    return buffer;
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
    size_t startPos = 0;

    while (pos != string::npos) {
        size_t endPos = pos + maliciousCode.length() - 1;
        cout << "(true) Posicion inicial: " << pos << "  Posicion final: " << endPos << endl;
        startPos = pos + maliciousCode.length();
        pos = transmission.find(maliciousCode, startPos);
    }

    if (startPos == 0) {
        cout << "Codigo Malicioso: '" << maliciousCode << "' no encontrado en (" << transmissionName << ")" << endl;
    }
}


// ==========================================================================================
// Función findLongestCommonSubstring, busca el substring más largo común en dos cadenas
// y muestra su posición
//
// @params transmission1: Primer cadena de caracteres que se usará para buscar el substring más largo
// @params transmission2: Segunda cadena de caracteres que se usará para buscar el substring más largo
//
// @return: Imprime la información del substring más largo común entre las dos cadenas,
//          además, indica la posición donde se encuentra en la cadena
//
// @complexity O(n^2)
// ==========================================================================================

string findLongestCommonSubstring(const string& transmission1, const string& transmission2) {
    int len1 = transmission1.length();
    int len2 = transmission2.length();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
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
        return "Archivo tranmision no valido";
    }
}


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
    cout << findLongestCommonSubstring(transmission1Content, transmission2Content);
    cout << "\n" << endl;
    return 0;
}
