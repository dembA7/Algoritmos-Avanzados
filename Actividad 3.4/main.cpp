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
// @params c: Color para colorear el nodo
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
// Función graphColoringAux, función auxiliar para probar todas las combinaciones de colores
// 
// @params graph: Grafo a verificar
// @params m: Número de colores disponibles
// @params color: Vector de colores
// @params v: Nodo a verificar
//
// @return: Regresa true si existe una solución para colorear el grafo, false en otro caso
//
// @complexity O(n)
// ==========================================================================================
bool graphColoringAux(vector<vector<int> >& graph, int m, vector<int>& color, int v){
    if (v == graph.size())
        return true;

    for (int c = 1; c <= m; c++){
        if (isSafe(v, graph, color, c)){
            color[v] = c;
            if (graphColoringAux(graph, m, color, v + 1))
                return true;
            color[v] = -1;
        }
    }
    return false;
}

// ==========================================================================================
// Función graphColoring, función para coordinar la coloración del grafo 
// 
// @params graph: Grafo a verificar
// @params m: Número de colores disponibles
//
// @return: Resultados y estatus de la coloración del grafo
//
// @complexity O(n)
// ==========================================================================================

bool graphColoring(vector<vector<int> >& graph, int m) {
    vector<int> color(graph.size(), -1);

    if (graphColoringAux(graph, m, color, 0)){
        cout << "\nSolución encontrada" << endl;
        for (int i = 0; i < color.size(); i++){
            cout << "Vertice " << i << " = Color " << color[i] << endl;
        }
        return true;
    }
    else{
        cout << "\nNo existe solución" << endl;
        return false;
    }
}

// ==========================================================================================
// Función main, función principal que coordina y ejecuta el programa. Solicita número de 
// nodos, la matriz de adyacencia y el número de colores. Imprime la solución al problema
// de colorear un grafo utilizando el algoritmo de fuerza bruta y el algoritmo de 
// backtracking
//
// @params none
//
// @return: 0 si el programa se ejecutó correctamente.
//
// @complexity O(n^2)
// ==========================================================================================
int main(){
    int n;
    cout << "\nIngrese el número de nodos: ";
    cin >> n;

    vector<vector<int> > graph(n, vector<int>(n));
    cout << "\nIngrese la matriz de adyacencia: " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    int m;
    cout << "\nIngrese el número de colores: ";
    cin >> m;

    graphColoring(graph, m);

    return 0;
}