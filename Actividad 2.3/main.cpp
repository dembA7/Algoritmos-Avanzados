// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona - A01708940
//
// Description: Implementación de hash string, toma como entrada un archivo de texto
//              y devuelve el hasheo concatenando la representación hexadecimal a dos dígitos
//              de cada columna del archivo.
//
// ==========================================================================================

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// ==========================================================================================
// Función main, genera la matriz a partir del archivo de entrada, la suma de las columnas
// y la representación hexadecimal de la suma de las columnas.
// 
// @params n: entero mayor a 16 y menor a 64, multiplo de 4.
// @params fileName: nombre del archivo de entrada.
//
// @return: 0 si el programa se ejecuta correctamente.
// @complexity O(n^2)
// ==========================================================================================

int main() {

cout << endl;
string fileName; cout << "Nombre del archivo: "; cin >> fileName;
int n; cout << "Ingresa un numero entre 16 y 64: "; cin >> n;
cout << endl;

vector<vector<char>> matrix;
ifstream inputFile(fileName);
int i = 0;
vector<char> aux(n, static_cast<char>(n));
char ch;

while (inputFile.get(ch)){
    if (ch == '\n'){ aux[i] = '-'; }
    else { aux[i] = ch; }
    if (i == n - 1) {
        matrix.push_back(aux);
        aux.assign(n, static_cast<char>(n));
        i = -1;
    }
    i++;
}

if (i != 0){
        matrix.push_back(aux);
}

cout << "Matriz generada: " << endl;
for (const vector<char> &row : matrix) {
        for (char col : row){
            cout << col << ' ';
        }
        cout << endl;
}

cout << endl;

vector<int> columnSums(matrix[0].size(), 0);

for (size_t col = 0; col < matrix[0].size(); col++){
        for (size_t row = 0; row < matrix.size(); row++) {
            if(matrix[row][col] == '-'){
                columnSums[col] += static_cast<int>('\n');
            } else{
                columnSums[col] += static_cast<int>(matrix[row][col]);
            }
        }
}

cout << "Suma de las columnas con % 256" << endl;
for (size_t col = 0; col < columnSums.size(); col++) {
        columnSums[col] = columnSums[col] % 256;
        cout << columnSums[col] << " ";
}

cout << endl;


vector<string> columnSumsHex;

for (int sum : columnSums) {
        stringstream ss;
        ss << uppercase << setfill('0') << setw(2) << hex << sum;
        columnSumsHex.push_back(ss.str());
}

string concatenatedHexValues;
for (const string &hexValue : columnSumsHex) {
        concatenatedHexValues += hexValue;
}

for (size_t i = 8; i < concatenatedHexValues.length(); i += 9) {
    concatenatedHexValues.insert(i, " ");
}

cout << endl;
cout << "Representacion en hexadecimal: " << endl;
cout << concatenatedHexValues << endl;
cout << endl;

return 0;
}