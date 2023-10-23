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
// Función djikstra, imprime el arreglo de substrings ordenado alfabéticamente.
// 
// @params n: Vector de strings que contiene los substrings del string original.
//
// @return: Imprime el arreglo de substrings ordenado alfabéticamente.
// @complexity O(n)
// ==========================================================================================

void dijkstra(vector<vector<int> > &graph, int startNode, vector<int> &distances) {

  int numNodes = graph.size();
  vector<bool> visited(numNodes, false);

  distances.assign(numNodes, INF);
  distances[startNode] = 0;

  for (int i = 0; i < numNodes - 1; i++) {
    int minDistance = INF, minNode = -1;

    for (int node = 0; node < numNodes; node++) {
      if (!visited[node] && distances[node] < minDistance) {
        minNode = node;
        minDistance = distances[node];
      }
    }

    if (minNode == -1)
      break;

    visited[minNode] = true;

    for (int neighbour = 0; neighbour < numNodes; neighbour++) {
      if (!visited[neighbour] && graph[minNode][neighbour] != INF) {
        int newDistance = distances[minNode] + graph[minNode][neighbour];
        if (newDistance < distances[neighbour]) {
          distances[neighbour] = newDistance;
        }
      }
    }
  }
}

// ==========================================================================================
// Función printSubstrings, imprime el arreglo de substrings ordenado alfabéticamente.
// 
// @params n: Vector de strings que contiene los substrings del string original.
//
// @return: Imprime el arreglo de substrings ordenado alfabéticamente.
// @complexity O(n)
// ==========================================================================================

void floyd(vector<vector<int> > &graph) {

  int numNodes = graph.size();

  for (int i = 0; i < numNodes; i++)
    for (int j = 0; j < numNodes; j++)
      for (int k = 0; k < numNodes; k++)
        if (graph[j][i] != INF && graph[i][k] != INF &&
            graph[j][i] + graph[i][k] < graph[j][k])
          graph[j][k] = graph[j][i] + graph[i][k];
}

// ==========================================================================================
// Función main, imprime el arreglo de substrings ordenado alfabéticamente.
// 
// @params n: Vector de strings que contiene los substrings del string original.
//
// @return: Imprime el arreglo de substrings ordenado alfabéticamente.
// @complexity O(n)
// ==========================================================================================

int main() {
  int graphSize;

  cout << "Ingrese el tamaño de su grafo: ";
  cin >> graphSize;

  cout << "Ingrese los pesos de las conexiones\n";

  vector<vector<int> > graph(graphSize, vector<int>(graphSize));

  for (int i = 0; i < graphSize; i++)
    for (int j = 0; j < graphSize; j++) {
      int buffer;
      cin >> buffer;
      graph[i][j] = buffer == -1 ? INF : buffer;
    }

  cout << "Dijkstra results:" << endl;
  for (int i = 0; i < graphSize; i++) {
    vector<int> distances;
    dijkstra(graph, i, distances);

    for (int j = 0; j < distances.size(); j++) {
      if (j == i)
        continue;
      cout << "From node "
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
}