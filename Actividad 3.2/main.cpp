// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Implementación de los algoritmos Djikstra y Floyd
//
// ==========================================================================================

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

// ==========================================================================================
// Función djikstra, imprime las distancias más cortas desde un nodo de inicio utilizando
// el algoritmo de Dijkstra
// 
// @params graph: Matriz de adyasencia que representa el grafo dirigido.
// @params startNode: Nodo de inicio para el algoritmo.
// @params distances: Vector de distancias más cortas desde el nodo de inicio.
//
// @return: Imprime las distancias más cortas desde un nodo de inicio utilizando
// el algoritmo de Dijkstra
//
// @complexity O(n^3)
// ==========================================================================================

void dijkstra(vector<vector<int> > &graph, int start, vector<int> &dist) {

  int nodes = graph.size();
  vector<bool> visited(nodes, false);

  dist.assign(nodes, INF);
  dist[start] = 0;

  for (int i = 0; i < nodes - 1; i++) {
    int minDist = INF, minNode = -1;

    for (int node = 0; node < nodes; node++) {
      if (!visited[node] && dist[node] < minDist) {
        minNode = node;
        minDist = dist[node];
      }
    }

    if (minNode == -1)
      break;

    visited[minNode] = true;

    for (int neighbor = 0; neighbor < nodes; neighbor++) {
      if (!visited[neighbor] && graph[minNode][neighbor] != INF) {
        int newDist = dist[minNode] + graph[minNode][neighbor];
        if (newDist < dist[neighbor]) {
          dist[neighbor] = newDist;
        }
      }
    }
  }
}

// ==========================================================================================
// Función djikstra, imprime las distancias más cortas desde un nodo de inicio utilizando
// el algoritmo de Floyd.
//
// @params graph: Matriz de adyasencia que representa el grafo dirigido.
//
// @return: Imprime las distancias más cortas desde un nodo de inicio utilizando
// el algoritmo de Floyd.
//
// @complexity O(n^3)
// ==========================================================================================

void floyd(vector<vector<int> > &graph) {

  int nodes = graph.size();

  for (int i = 0; i < nodes; i++)
    for (int j = 0; j < nodes; j++)
      for (int k = 0; k < nodes; k++)
        if (graph[j][i] != INF && graph[i][k] != INF &&
            graph[j][i] + graph[i][k] < graph[j][k])
          graph[j][k] = graph[j][i] + graph[i][k];
}

// ==========================================================================================
// Función main, recibe la matriz de adyasencia que representa el grafo dirigido y llama a
// las funciones de Dijkstra y Floyd.
//
// @return: Imprime las distancias más cortas desde un nodo de inicio utilizando
// el algoritmo de Dijkstra y Floyd.
//
// @complexity O(n)
// ==========================================================================================

int main() {
  int graphSize;

  cout << "\nD J I K S T R A  A N D  F L O Y D  A L G O R I T H M S \n";

  cout << "\nIngrese el tamaño de su grafo: ";
  cin >> graphSize;

  cout << "\nIngrese la matriz:\n";

  vector<vector<int> > graph(graphSize, vector<int>(graphSize));

  for (int i = 0; i < graphSize; i++)
    for (int j = 0; j < graphSize; j++) {
      int buffer;
      cin >> buffer;
      graph[i][j] = buffer == -1 ? INF : buffer;
    }

  cout << "\nDijkstra results:" << endl;
  for (int i = 0; i < graphSize; i++) {
    vector<int> distances;
    dijkstra(graph, i, distances);

    for (int j = 0; j < distances.size(); j++) {
      if (j == i)
        continue;
      cout << "node "
           << i + 1 << " to node "
           << j + 1 << ": ";
      if (distances[j] == INF)
        cout << "No path\n";
      else
        cout << distances[j] << endl;
    }
  }

  cout << "\nFloyd results:" << endl;
  vector<vector<int> > res(graph);
  floyd(res);
  for (auto i : res) {
    for (auto j : i) {
      if (j == INF)
        cout << "No path ";
      else
        cout << j << " ";
    }
    cout << endl;
  }
  
  cout << " \n" << endl;
}