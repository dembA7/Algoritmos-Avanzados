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
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

const int INF = numeric_limits<int>::max();
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
// @complexity
// ==========================================================================================

bool readFromFile(const string &filename)
{
    ifstream inputFile(filename);

    if(!inputFile.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    int n;
    inputFile >> n;

    vector<vector<int>> distBtwnClnies(n, vector<int>(n, 0));
    vector<vector<int>> maxFluxBtwnClnies(n, vector<int>(n, 0));
    vector<pair<int, int>> coordsClnies(n, pair<int, int>(0, 0));
    pair<int, int> coordsNewClny(0, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inputFile >> distBtwnClnies[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inputFile >> maxFluxBtwnClnies[i][j];
        }
    }

    for (int i = 0; i < n + 1; ++i)
    {
        string linea = "";
        inputFile >> linea;

        stringstream ss(linea);

        char paren, comma;
        int x, y;
        ss >> paren >> x >> comma >> y >> paren;

        if (i <= n)
        {
            coordsClnies[i] = pair<int, int>(x, y);
        }
        else
        {
            coordsNewClny = pair<int, int>(x, y);
        }
    }
}

// ==========================================================================================
// Función dijkstra, implementación del algoritmo de Dijkstra para encontrar la forma óptima
// de cablear las colonias de la ciudad
// 
// @params graph: Distancias en kms entre las colonias de la ciudad
// @params start: Nodo inicial del grafo
//
// @return: Lista de arcos que representan la forma óptima de cablear las colonias de la 
//          ciudad
//
// @complexity 
// ==========================================================================================

// vector<pair<int, int> > dijkstra(const vector<vector<int> >& graph, int start){
//     int n = graph.size();
//     vector<int> distance(n, INF);
//     vector<bool> visited(n, false);
//     vector<pair<int, int> > result; 

//     priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

//     distance[start] = 0;
//     pq.push({0, start});

//     while(!pq.empty()){
//         int u = pq.top().second;
//         pq.pop();

//         if(visited[u]) continue;
//         visited[u] = true;

//         for(int v = 0; v < n; v++){
//             if(!visited[v] && graph[u][v] < distance[v]){
//                 distance[v] = graph[u][v];
//                 pq.push({distance[v], v});
//                 result.push_back({u, v});
//             }
//         }
//     }
//     return result;
// }

// ==========================================================================================
// Función salesmanProblem, implementación del algoritmo del vendedor, para encontrar el
// camino más corto que recorra todas las colonias de la ciudad al menos una vez y regrese
// a la colonia inicial
// 
// @params graph: Distancias en kms entre las colonias de la ciudad
// @params start: Nodo inicial del grafo
//
// @return: Regresa la ruta más corta a seguir para recorrer todas las colonias de la ciudad
//          al menos una vez y regresar a la colonia inicial
//
// @complexity 
// ==========================================================================================

vector<int> salesmanProblem(const vector<vector<int> >& graph, int start){
    int n = graph.size();
    vector<int> path;
    vector<int> vertices(n);

    for(int i = 0; i < n; i++){
        if(i != start) {
            vertices[i] = i;
        }
    }

    int minPath = INF;
    do {
        int currentPath = 0;
        int k = start;

        for(int i = 0; i < n - 1; i++){
            currentPath += graph[k][vertices[i]];
            k = vertices[i];
        }

        currentPath += graph[k][start];

        if(currentPath < minPath){
            minPath = currentPath;
            path = vertices;
        }
    } while(next_permutation(vertices.begin(), vertices.end()));

    path.push_back(start);
    path.insert(path.begin(), start);

    return path;
}

// ==========================================================================================
// Función fordFulkerson, implementación del algoritmo de Ford-Fulkerson, para calcular el
// flujo máximo de datos entre las colonias de la ciudad desde el nodo inicial hasta el nodo
// final
// 
// @params capacity: Capacidades máximas de flujo de datos entre colonia i y colonia j
// @params start: Nodo inicial del grafo
// @params end: Nodo final del grafo
//
// @return: Regresa el flujo máximo de datos entre las colonias de la ciudad desde el nodo
//          inicial hasta el nodo final
//
// @complexity 
// ==========================================================================================

int fordFulkerson(const vector<vector<int > >& capacity, int start, int end){
    int n = capacity.size();
    vector<vector<int> > residualCapacity = capacity;
    vector<int> parent(n - 1);
    int maxFlow = 0;

    while (true) {
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (!visited[v] && residualCapacity[u][v] > 0) {
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }

        if (!visited[end]) break;

        int pathFlow = INF;
        for (int v = end; v != start; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualCapacity[u][v]);
        }

        for (int v = end; v != start; v = parent[v]) {
            int u = parent[v];
            residualCapacity[u][v] -= pathFlow;
            residualCapacity[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

// ==========================================================================================
// Función findNearestCentral, encuentra la central más cercana a una colonia
// 
// @params newCentral: Par ordenado que representa la ubicación en un plano de la nueva 
// central
// @params centralLocations: Pares ordenados que representan la ubicación en un plano de las
// centrales
//
// @return: Índice de la central más cercana a la colonia utilizando la distancia euclidiana
//
// @complexity
// ==========================================================================================

double distanceBetweenColonies(const Colony& colony1, const Colony& colony2){
    return sqrt(pow(colony1.x - colony2.x, 2) + pow(colony1.y - colony2.y, 2));
}

int findNearestCentral(const Colony& newCentral, const vector<Colony>& centralLocations){
    int nearestCentral = -1;
    double minDistance = INF;

    for(int i = 0; i < centralLocations.size(); i++){
        double distance = distanceBetweenColonies(newCentral, centralLocations[i]);
        if(distance < minDistance){
            minDistance = distance;
            nearestCentral = i;
        }
    }
    return nearestCentral;
}

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

// void outputFile(const string& filename, const vector<pair<int, int> >& optimalCabling, const vector<int>& deliverPath, int maxFlow, double shortestDistance){
//     ofstream outputFile(filename);

//     if(!outputFile.is_open()) {
//         cout << "No se pudo abrir el archivo" << endl;
//         return;
//     }
//     outputFile << "Cableado óptimo: " << endl;
//     for (const)
// }

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

    cout << readFromFile("input01.txt");
    

    // // Numero de colonias en la ciudad
    // int n;
    // cin >> n;
    
    // // Distancias en kms entre las colonias de la ciudad
    // vector<vector<int> > graph(n, vector<int>(n));

    // // Capacidades máximas de flujo de datos entre colonia i y colonia j
    // vector<vector<int> > capacity(n, vector<int>(n));


    // // Pares ordenados que representan la ubicación en un plano de las centrales
    // vector<Colony> centralLocations;

    // // Par ordenado que representa la ubicación en un plano de la nueva central
    // Colony newCentral(0, 0);
    // cin >> newCentral.x >> newCentral.y;

    // string input1Content = readFromFile("input01.txt");
    // string input2Content = readFromFile("input02.txt");
    // string input3Content = readFromFile("input03.txt");

    // cout << "Archivo de entrada 1" << endl;
    // cout << input1Content << endl;
    // cout << " " << endl;

    // cout << "Archivo de entrada 2" << endl;
    // cout << input2Content << endl;
    // cout << " " << endl;

    // cout << "Archivo de entrada 3" << endl;
    // cout << input3Content << endl;
    // cout << " " << endl;

    // cout << "         Punto 01           " << endl;
    // cout << " " << endl;

    // // cout << "mcode1: " << endl;
    // // searchMaliciousCode(transmission1Content, mcode1Content, "transmission01.txt");
    // // cout << " " << endl;

    // // cout << "mcode2: " << endl;
    // // searchMaliciousCode(transmission1Content, mcode2Content, "transmission01.txt");
    // // cout << " " << endl;

    // // cout << "mcode3: " << endl;
    // // searchMaliciousCode(transmission1Content, mcode3Content, "transmission01.txt");
    // // cout << " " << endl;

    // cout << "         Punto 02           " << endl;
    // cout << " " << endl;

    // // cout << "mcode1: " << endl;
    // // searchMaliciousCode(transmission2Content, mcode1Content, "transmission02.txt");
    // // cout << " " << endl;

    // // cout << "mcode2: " << endl;
    // // searchMaliciousCode(transmission2Content, mcode2Content, "transmission02.txt");
    // // cout << " " << endl;

    // // cout << "mcode3: " << endl;
    // // searchMaliciousCode(transmission2Content, mcode3Content, "transmission02.txt");
    // // cout << " " << endl;

    // cout << "         Punto 03           " << endl;
    // cout << " " << endl;

    // cout << "         Punto 04           " << endl;
    // cout << " " << endl;
    
    // return 0;
}