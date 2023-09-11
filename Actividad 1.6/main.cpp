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

bool isValidPoda(int x, int y, const vector<vector<int>> &maze, const vector<vector<int>> &solution) {
    return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 1 && solution[x][y] == 0;
}

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

bool isValidBacktracking(int x, int y, int M, int N, const vector<vector<int>> &maze, const vector<vector<int>> &solutionBacktracking) {
    if (x >= 0 && x < M && y >= 0 && y < N && maze[x][y] == 1 && solutionBacktracking[x][y] != 1) {
        return true;
    }
    return false;
}

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

void printMaze(const vector<vector<int>> &maze) {
    for (const auto &row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

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
        cout << "Backtracking Solution:\n";
        printMaze(solutionBacktracking);
    } else {
        cout << "No hay solución para backtracking." << endl;
    }

    return 0;
}
