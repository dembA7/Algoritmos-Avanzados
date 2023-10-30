// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Implementación de "Knapsack problem" usando programación dinámica.
//
// ==========================================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================================================================
// Función knapsack, calcula el valor máximo que se puede obtener con una mochila de
// capacidad W y n objetos con pesos y valores dados.
//
// @params N: Número de objetos.
// @params values: Vector de valores de los objetos.
// @params weights: Vector de pesos de los objetos.
// @params W: Peso de la mochila.
//
// @return: Imprime el valor máximo que se puede obtener con una mochila de
// capacidad W y n objetos con pesos y valores dados.
//
// @complexity O(n^2)
// ==========================================================================================


int knapsack(int N, vector<int>& values, vector<int>& weights, int W) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    // Matriz generada
    cout << "\nMatriz generada:" << endl;
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    return dp[N][W];
}



// ==========================================================================================
// Función main, función principal del programa, lee los datos de entrada y llama a la
// función knapsack. Imprime el valor máximo que se puede obtener con una mochila de
// capacidad W y n objetos con pesos y valores dados.
//
// @params none
// @return: 0 si el programa se ejecutó correctamente.
//
// @complexity O(n)
// ==========================================================================================

int main() {
    int N;
    cout << "Numero de objetos:" << endl;
    cin >> N;
    vector<int> values(N);
    vector<int> weights(N);

    cout << "Beneficios:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    cout << "Pesos:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    cout << "Peso maximo de la mochila:" << endl;
    int W;
    cin >> W;

    int maxBenefit = knapsack(N, values, weights, W);

    cout << "\nBeneficio optimo: " << maxBenefit << "\n" << endl;

    return 0;
}