// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Aplicación de solución de laberintos utilizando backtracking y
//              ramificación y poda.
//
// ==========================================================================================

#include <iostream>
#include <vector>

using namespace std;

// ==========================================================================================
// Función que determina si un valor es válido para la solucion de ramificacion y poda.
//
// @param x, coordenada en el eje x.
// @param y, coordenada en el eje y.
// @param maze, matriz que representa el laberinto con obstáculos.
// @param solution, matriz que representa la solución parcial actual del laberinto.
//
// @complexity O(1)
// ==========================================================================================

bool isValidPoda(int x, int y, const vector<vector<int>> &maze, const vector<vector<int>> &solution) {
    return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 1 && solution[x][y] == 0;
}



// ==========================================================================================
// Función que resuelve el laberinto utilizando ramificación y poda.
//
// @param x, coordenada en el eje x.
// @param y, coordenada en el eje y.
// @param maze, matriz que representa el laberinto con obstáculos.
// @param solution, matriz que representa la solución parcial actual del laberinto.
//
// @return true si se encuentra una solución al laberinto.
//
// @complexity O(N)
// ==========================================================================================

bool solveMazePoda(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &solution) {
    if (x == maze.size() - 1 && y == maze[0].size() - 1) {
        solution[x][y] = 1;
        return true;
    }

    if (isValidPoda(x, y, maze, solution)) {
        solution[x][y] = 1;

        if (solveMazePoda(x + 1, y, maze, solution))
            return true;

        if (solveMazePoda(x, y + 1, maze, solution))
            return true;

        solution[x][y] = 0;
    }
    return false;
}



// ==========================================================================================
// Función que determina si un valor es válido para la solucion de backtracking.
//
// @param x, coordenada en el eje x.
// @param y, coordenada en el eje y.
// @param M, número de filas del laberinto.
// @param N, número de columnas del laberinto.
// @param maze, matriz que representa el laberinto con obstáculos.
// @param solutionBacktracking, matriz que representa la solución parcial actual del laberinto.
//
// @return true si (x, y) es una posicion válida para avanzar.
//
// @complexity O(1)
// ==========================================================================================

bool isValidBacktracking(int x, int y, int M, int N, const vector<vector<int>> &maze, const vector<vector<int>> &solutionBacktracking) {
    if (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1 && solutionBacktracking[x][y] != 1) {
        return true;
    }
    return false;
}



// ==========================================================================================
// Función que a través de backtracking, busca encontrar una solución para un laberinto
// bidimensional.
//
// @param x, coordenada en el eje x.
// @param y, coordenada en el eje y.
// @param M, número de filas del laberinto.
// @param N, número de columnas del laberinto, 
// @param solutionBacktracking, matriz que representa la solución parcial actual del laberinto.
//
// @complexity O(N)
// ==========================================================================================

bool solveMazeBacktracking(int x, int y, int M, int N, vector<vector<int>> &maze, vector<vector<int>> &solutionBacktracking) {
    if (x == M - 1 && y == N - 1) {
        solutionBacktracking[x][y] = 1;
        return true;
    }

    if (isValidBacktracking(x, y, M, N, maze, solutionBacktracking)) {
        solutionBacktracking[x][y] = 1;

        if (solveMazeBacktracking(x + 1, y, M, N, maze, solutionBacktracking)) {
            return true;
        }

        if (solveMazeBacktracking(x, y + 1, M, N, maze, solutionBacktracking)) {
            return true;
        }

        if (solveMazeBacktracking(x - 1, y, M, N, maze, solutionBacktracking)) {
            return true;
        }

        if (solveMazeBacktracking(x, y - 1, M, N, maze, solutionBacktracking)) {
            return true;
        }

        solutionBacktracking[x][y] = 0;
        return false;
    }
    return false;
}



// ==========================================================================================
// Función que imprime una matriz bidimensional en la consola.
//
// @param maze, matriz bidimensional a imprimir.
//
// @complexity O(N^2)
// ==========================================================================================

void printMaze(const vector<vector<int>> &maze) {
    for (const auto &row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}



// ==========================================================================================
// Función que resuelve el laberinto aplicando 'backtracking' y 'ramificación y poda'.
//
// @complexity O(N^2)
// ==========================================================================================

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> maze(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    vector<vector<int>> solutionPoda(M, vector<int>(N, 0));
    vector<vector<int>> solutionBacktracking(M, vector<int>(N, 0));

    cout << "\nOriginal Maze:\n";
    printMaze(maze);

    if (solveMazePoda(0, 0, maze, solutionPoda)) {
        cout << "\nRamificacion y Poda Solution:\n";
        printMaze(solutionPoda);
    } else {
        cout << "No hay solucion usando Ramificacion y Poda" << endl;
    }

    if (solveMazeBacktracking(0, 0, M, N, maze, solutionBacktracking)) {
        cout << "\nBacktracking Solution:\n";
        printMaze(solutionBacktracking);
    } else {
        cout << "No hay solución para backtracking." << endl;
    }

    cout << " " << endl;

    return 0;
}
