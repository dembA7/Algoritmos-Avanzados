// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Este programa encuentra una solución al problema de colorear un grafo
// utilizando el algoritmo de fuerza bruta y el algoritmo de backtracking
//
// ==========================================================================================

#include <iostream>
#include <vector>

using namespace std;

// ==========================================================================================
// Función isSafe, verifica si un nodo puede ser pintado con un color específico
// 
// @params v: Nodo a verificar
// @params graph: Grafo a verificar
// @params color: Vector de colores
// @params c: Color a verificar
//
// @return: Regresa true si el nodo puede ser pintado con el color c, false en otro caso
//
// @complexity O(n)
// ==========================================================================================

bool isSafe(int v, vector<vector<int> > &graph, vector<int> &color, int c){
    for (int i = 0; i < graph.size(); i++){
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

// ==========================================================================================
// Función graphColoring, función para coordinar la coloración del grafo 
// 
// @params graph: Grafo a verificar
// @params m: Número de colores disponibles
//
// @return: 
//
// @complexity O(n)
// ==========================================================================================

bool graphColoring(vector<vector<int> >& graph, int m) {

}

// ==========================================================================================
// Función graphColoringAux, función auxiliar para probar todas las combinaciones de colores
// 
// @params v: Nodo a verificar
//
// @return: 
//
// @complexity O(n)
// ==========================================================================================
bool graphColoringAux(){

}

// ==========================================================================================
// Función main, función principal que coordina y ejecuta el programa
//
// @return: Grafo coloreado
//
// @complexity O(n^2)
// ==========================================================================================
int main(){
    int n;
    cout << "Ingrese el número de nodos: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Ingrese la matriz de adyacencia: " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    int m;
    cout << "Ingrese el número de colores: ";
    cin >> m;

    graphColoring(graph, m);

    return 0;
}