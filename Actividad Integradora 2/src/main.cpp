// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Programa que permite encontrar la distancia mínima entre una colonia y todas
//              las demas en una ciudad, así como la distancia mínima entre dos colonias
//              cualesquiera. El programa lee los datos de un archivo de texto y los almacena
//              en una estructura de datos. Posteriormente, se aplica el algoritmo de Dijkstra
//              para encontrar la distancia mínima entre una colonia y todas las demas.
//              Finalmente, se imprimen los resultados en la consola.
//
// ==========================================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

// ==========================================================================================
// Estructura City, almacena los datos de una ciudad
//
// @params nCities: Número de colonias en la ciudad
// @params distBtwnClnies: Distancias en kms entre las colonias de la ciudad
// @params maxFluxBtwnClnies: Flujo maximo entre las colonias de la ciudad
// @params coordsClnies: Coordenadas de las colonias de la ciudad
// @params coordsNewClny: Coordenadas de la nueva colonia
// ==========================================================================================

struct City {

    int nCities;
    vector<vector<int>> distBtwnClnies;
    vector<vector<int>> maxFluxBtwnClnies;
    vector<pair<int, int>> coordsClnies;
    pair<int, int> coordsNewClny;

    City(int n) :
        nCities(n),
        distBtwnClnies(n, std::vector<int>(n, 0)),
        maxFluxBtwnClnies(n, std::vector<int>(n, 0)),
        coordsClnies(n, std::pair<int, int>(0, 0)),
        coordsNewClny(0, 0) {}

    friend std::ostream &operator<<(std::ostream &os, const City &city) {
        os << "distBtwnClnies:" << endl;
        for (const auto &row : city.distBtwnClnies) {
            for (const auto &elem : row) {
                os << elem << ' ';
            }
            os << std::endl;
        }

        os << "maxFluxBtwnClnies:" << endl;
        for (const auto &row : city.maxFluxBtwnClnies) {
            for (const auto &elem : row) {
                os << elem << ' ';
            }
            os << endl;
        }

        os << "coordsClnies:" << endl;
        for (const auto &coord : city.coordsClnies) {
            os << '(' << coord.first << ", " << coord.second << ')' << endl;
        }

        os << "coordsNewClny: (" << city.coordsNewClny.first << ", " << city.coordsNewClny.second << ')' << endl;

        return os;
    }
};


// ==========================================================================================
// Función readFromFile, lee los datos de un archivo de texto y los almacena en una estructura
// de datos
//
// @params filename: Nombre del archivo de texto
//
// @return: Regresa una estructura de datos con los datos de la ciudad
// @complexity O(n)
// ==========================================================================================

City readFromFile(const string &filename) {
    
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    int n;
    inputFile >> n;
    
    City city(n);
    city.nCities = n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> city.distBtwnClnies[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> city.maxFluxBtwnClnies[i][j];
        }
    }

    for (int i = 0; i < n + 1; ++i) {
        string linea = "";
        inputFile >> linea;

        stringstream ss(linea);

        char paren, comma;
        int x, y;
        ss >> paren >> x >> comma >> y >> paren;

        (i < n) ? city.coordsClnies[i] = pair<int, int>(x, y) : city.coordsNewClny = pair<int, int>(x, y);

    }

    return city;
}


// ==========================================================================================
// Función minDistance, encuentra la distancia mínima entre una colonia y todas las demas
//
// @params n: Número de colonias en la ciudad
// @params dist: Distancias en kms entre las colonias de la ciudad
// @params sptSet: Arreglo de booleanos que indica si una colonia ya fue visitada
//
// @return: Regresa el índice de la colonia mas cercana
// @complexity O(n)
// ==========================================================================================

int minDistance(int n, const vector<int> &dist, const vector<bool> &sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}


// ==========================================================================================
// Función printSolutionDijkstra, imprime la distancia mínima entre una colonia y todas las
// demas
//
// @params city: Colonia a la que se le aplicó el algoritmo
// @params n: Número de colonias en la ciudad
// @params dist: Distancias en kms entre las colonias de la ciudad
//
// @complexity O(n)
// ==========================================================================================

void printSolutionDijkstra(int city, int n, const vector<int> &dist) {
    for (int i = 0; i < n; i++) {
        if (i != city) {
            cout << "Colonia " << city + 1 << " a colonia " << i + 1 << ": " <<  dist[i] << endl;
        }
    }
}


// ==========================================================================================
// Función dijkstra, implementación del algoritmo de Dijkstra para encontrar la distancia
// mínima entre una colonia y todas las demas
//
// @params n: Número de colonias en la ciudad
// @params graph: Distancias en kms entre las colonias de la ciudad
// @params city: Colonia a la que se le aplicara el algoritmo
//
// @complexity O(n)
// ==========================================================================================

void dijkstra(int n, const vector<vector<int>> &graph, int city) {
    vector<int> dist(n, INT_MAX);
    vector<bool> sptSet(n, false);

    dist[city] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(n, dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolutionDijkstra(city, n, dist);
}


// ==========================================================================================
// Función findNearestCity, encuentra la colonia mas cercana a una colonia dada
//
// @params numCities: Número de colonias en la ciudad
// @params distanceMatrix: Distancias en kms entre las colonias de la ciudad
// @params city: Colonia a la que se le aplicara el algoritmo
// @params visited: Arreglo de booleanos que indica si una colonia ya fue visitada
//
// @return: Regresa el índice de la colonia mas cercana
// @complexity O(n)
// ==========================================================================================

int findNearestCity(int numCities, const vector<vector<int>> &distanceMatrix, int city, vector<bool> &visited) {
    int minDistance = INT_MAX;
    int nearestCity = -1;

    for (int i = 0; i < numCities; ++i) {
        if (!visited[i] && distanceMatrix[city][i] < minDistance) {
            minDistance = distanceMatrix[city][i];
            nearestCity = i;
        }
    }

    return nearestCity;
}

// ==========================================================================================
// Función smp, implementación del algoritmo de la colonia mas cercana para encontrar el
// recorrido mas corto que pase por todas las colonias de una ciudad
//
// @params numCities: Número de colonias en la ciudad
// @params distanceMatrix: Distancias en kms entre las colonias de la ciudad
//
// @return: Regresa el costo total del recorrido
// @complexity O(n)
// ==========================================================================================

int smp(int numCities, const vector<vector<int>> &distanceMatrix) {
    vector<bool> visited(numCities, false);
    vector<int> path;
    int totalDistance = 0;

    int currentCity = 0;
    path.push_back(currentCity + 1);
    visited[currentCity] = true;

    for (int i = 0; i < numCities; ++i) {
        int nearestCity = findNearestCity(numCities, distanceMatrix, currentCity, visited);
        if (nearestCity != -1) {
            path.push_back(nearestCity + 1);
            visited[nearestCity] = true;
            totalDistance += distanceMatrix[currentCity][nearestCity];
            currentCity = nearestCity;
        }
    }
    path.push_back(path[0]);
    totalDistance += distanceMatrix[currentCity][path[0] - 1];

    cout << "El recorrido:" << endl;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        cout << path[i] << " -> ";
    }
    cout << path.back() << endl;

    cout << "El costo: " << totalDistance << endl;

    return totalDistance;
}

// ==========================================================================================
// Función bfs, encuentra el camino mas corto entre dos nodos de un grafo
//
// @params n: Número de colonias en la ciudad
// @params rfluxMatrix: Flujo residual entre las colonias de la ciudad
// @params s: Colonia de origen
// @params t: Colonia de destino
// @params parent: Arreglo que almacena el camino mas corto
//
// @return: Regresa true si existe un camino entre el nodo de origen y el nodo de destino
// @complexity O(n)
// ==========================================================================================

bool bfs(int n, const vector<vector<int>> &rfluxMatrix, int s, int t, int parent[]) {

    vector<bool> visited(n, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (visited[v] == false && rfluxMatrix[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

// ==========================================================================================
// Función fordFulkerson, implementación del algoritmo de Ford-Fulkerson para encontrar el
// flujo maximo entre dos nodos de un grafo
//
// @params n: Número de colonias en la ciudad
// @params fluxMatrix: Flujo entre las colonias de la ciudad
// @params s: Colonia de origen
// @params t: Colonia de destino
//
// @return: Regresa el flujo maximo entre el nodo de origen y el nodo de destino
// @complexity O(n)
// ==========================================================================================

int fordFulkerson(int n, const vector<vector<int>> &fluxMatrix, int s, int t) {
    int u, v;

    vector<vector<int>> rfluxMatrix(n, vector<int>(n, 0));
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rfluxMatrix[u][v] = fluxMatrix[u][v];

    int parent[n];
    int max_flow = 0;

    while (bfs(n, rfluxMatrix, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rfluxMatrix[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rfluxMatrix[u][v] -= path_flow;
            rfluxMatrix[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

// ==========================================================================================
// Función distanceBetweenColonies, calcula la distancia euclidiana entre dos colonias
//
// @params colony1: Par ordenado que representa la ubicación en un plano de la primera colonia
// @params colony2: Par ordenado que representa la ubicación en un plano de la segunda colonia
//
// @return: Regresa la distancia euclidiana entre las dos colonias
// @complexity O(1)
// ==========================================================================================

double distanceBetweenColonies(const pair<int, int> &colony1, pair<int, int> &colony2) {
    return sqrt(pow(colony1.first - colony2.first, 2) + pow(colony1.second - colony2.second, 2));
}

// ==========================================================================================
// Función findNearestCentral, encuentra la central mas cercana a una colonia
//
// @params newCentral: Par ordenado que representa la ubicación en un plano de la nueva
// central
// @params centralLocations: Pares ordenados que representan la ubicación en un plano de las
// centrales
//
// @return: Índice de la central mas cercana a la colonia utilizando la distancia euclidiana
//
// @complexity
// ==========================================================================================

int findNearestCentral(pair<int, int> &newCentral, vector<pair<int, int>> &centralLocations) {
    int nearestCentral = -1;
    pair<int, int> nearestCentralCoords;
    double minDistance = INT_MAX;

    for (int i = 0; i < centralLocations.size(); i++) {
        double distance = distanceBetweenColonies(newCentral, centralLocations[i]);
        if (distance < minDistance)
        {
            minDistance = distance;
            nearestCentral = i;
            nearestCentralCoords = centralLocations[i];
        }
    }

    printf("La central mas cercana a [%d,%d] es [%d,%d] con una distancia de %.3f.\n", newCentral.first, newCentral.second, nearestCentralCoords.first, nearestCentralCoords.second, minDistance);
    cout << endl;
    
    return nearestCentral;
}

// ==========================================================================================
// Función main, función principal del programa
//
// @params argc: Número de argumentos
// @params argv: Arreglo de argumentos
//
// @return: Regresa 0 si el programa termina correctamente
// @complexity O(n)
// ==========================================================================================

int main(int argc, char *argv[]) {

    City c1 = readFromFile("input03.txt");

    cout << "\nPunto 01\n" << endl;
    for (int city = 0; city < c1.nCities; city++) {
        dijkstra(c1.nCities, c1.distBtwnClnies, city);
        cout << endl;
    }

    cout << "\nPunto 02\n" << endl;
    smp(c1.nCities, c1.distBtwnClnies);

    cout << "\nPunto 03\n" << endl;
    cout << "Flujo maximo: " << fordFulkerson(c1.nCities, c1.maxFluxBtwnClnies, 0, c1.nCities-1) << endl;

    cout << "\nPunto 04\n" << endl;
    findNearestCentral(c1.coordsNewClny, c1.coordsClnies);

    return 0;
}