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
#include <limits>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Colony {
    int x;
    int y;

    Colony(int _x, int _y): x(_x), y(_y) {}
};

// ==========================================================================================
// Función readFromFile, lee el contenido de un archivo y aplica un recorrido sobre el mismo
// para almacenar los valores correspondientes a las respectivas variables para su análisis
// posterior
// 
// @params filename: Archivo que se desea leer
// @params n: Número de colonias en la ciudad
// @params graph: Distancias en kms entre las colonias de la ciudad
// @params capacity: Capacidades máximas de flujo de datos entre colonia i y colonia j
// @params centralLocations: Pares ordenados que representan la ubicación en un plano de las
//                           centrales
// @params newCentral: Par ordenado que representa la ubicación en un plano de la nueva central
//
// @return: Regresa true si el archivo se pudo abrir y leer correctamente, false en caso
//          contrario
// @complexity O(n)
// ==========================================================================================

bool readFromFile(const string& filename, int& n, vector<vector<int> >& graph, vector<vector<int> >& capacity, vector<Colony>& centralLocations, Colony& newCentral) {
    ifstream inputFile(filename);

    if(!inputFile.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }

    inputFile >> n;

    graph.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            inputFile >> graph[i][j];
        }
    }

    capacity.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            inputFile >> capacity[i][j];
        }
    }

    centralLocations.resize(n);
    for (int i = 0; i < n; i++){
        int x, y;
        inputFile >> x >> y;
        centralLocations[i] = Colony(x, y);
    }

    inputFile >> newCentral.x >> newCentral.y;

    inputFile.close();
    return true;
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

int main() {
    // Numero de colonias en la ciudad
    int n;
    cin >> n;
    
    // Distancias en kms entre las colonias de la ciudad
    vector<vector<int> > graph(n, vector<int>(n));

    // Capacidades máximas de flujo de datos entre colonia i y colonia j
    vector<vector<int> > capacity(n, vector<int>(n));


    // Pares ordenados que representan la ubicación en un plano de las centrales
    vector<Colony> centralLocations;

    // Par ordenado que representa la ubicación en un plano de la nueva central
    Colony newCentral(0, 0);
    cin >> newCentral.x >> newCentral.y;

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

    cout << "         Punto 01           " << endl;
    cout << " " << endl;

    // cout << "mcode1: " << endl;
    // searchMaliciousCode(transmission1Content, mcode1Content, "transmission01.txt");
    // cout << " " << endl;

    // cout << "mcode2: " << endl;
    // searchMaliciousCode(transmission1Content, mcode2Content, "transmission01.txt");
    // cout << " " << endl;

    // cout << "mcode3: " << endl;
    // searchMaliciousCode(transmission1Content, mcode3Content, "transmission01.txt");
    // cout << " " << endl;

    cout << "         Punto 02           " << endl;
    cout << " " << endl;

    // cout << "mcode1: " << endl;
    // searchMaliciousCode(transmission2Content, mcode1Content, "transmission02.txt");
    // cout << " " << endl;

    // cout << "mcode2: " << endl;
    // searchMaliciousCode(transmission2Content, mcode2Content, "transmission02.txt");
    // cout << " " << endl;

    // cout << "mcode3: " << endl;
    // searchMaliciousCode(transmission2Content, mcode3Content, "transmission02.txt");
    // cout << " " << endl;

    cout << "         Punto 03           " << endl;
    cout << " " << endl;

    cout << "         Punto 04           " << endl;
    cout << " " << endl;
    
    return 0;
}