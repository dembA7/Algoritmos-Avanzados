// ==========================================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Coin change problem solution, dynamic programming
//              and greedy algorithm implementations.
//
// ==========================================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// ==========================================================================================
// Función que resuelve el problema del cambio de monedas usando programación dinámica.
//
// @param costoProducto, entero que contiene el costo del producto.
// @param pagoEfectivo, entero que contiene la cantidad con la que se paga el producto.
// @param denominaciones, arreglo que contiene las denominaciones de las monedas a utilizar.
//
// @complexity O(N log N)
// ==========================================================================================

vector<int> cambioDinamico(int costoProducto, int pagoEfectivo, const vector<int>& denominaciones) {

    // Paso 1: Calcular el monto total de cambio a retornar.
    int montoTotal = pagoEfectivo - costoProducto;
    int n = denominaciones.size();
    
    // Paso 2: Ordenar las denominaciones de mayor a menor.
    vector<int> denominacionesOrdenadas = denominaciones;
    sort(denominacionesOrdenadas.rbegin(), denominacionesOrdenadas.rend());

    // Paso 3: Inicializar un vector para almacenar la cantidad de monedas de cada denominación.
    vector<int> listaCambio(n, 0);
    
    // Paso 4: Crear un vector para almacenar la cantidad mínima de monedas necesarias.
    vector<int> dp(montoTotal + 1, INT_MAX);
    dp[0] = 0;

    // Paso 5: Llenar el vector utilizando programación dinámica.
    for (int i = 1; i <= montoTotal; i++) {
        for (int j = 0; j < n; j++) {
            if (denominacionesOrdenadas[j] <= i && dp[i - denominacionesOrdenadas[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - denominacionesOrdenadas[j]]);
            }
        }
    }

    // Paso 6: Reconstruir la solución a partir del vector dp.
    if (dp[montoTotal] != INT_MAX) {
        int i = montoTotal;
        while (i > 0) {
            for (int j = 0; j < n; j++) {
                if (i >= denominacionesOrdenadas[j] && dp[i] == 1 + dp[i - denominacionesOrdenadas[j]]) {
                    listaCambio[j]++;
                    i -= denominacionesOrdenadas[j];
                    break;
                }
            }
        }
    }

    return listaCambio;
}

// ==========================================================================================
// Función que resuelve el problema del cambio de monedas usando algortimos voraces.
//
// @param costoProducto, entero que contiene el costo del producto.
// @param pagoEfectivo, entero que contiene la cantidad con la que se paga el producto.
// @param denominaciones, arreglo que contiene las denominaciones de las monedas a utilizar.
//
// @complexity O(N log N)
// ==========================================================================================

vector<int> cambioVoraz(vector<int>& denominacionesMoneda, int costoProducto, int pagoEfectivo){
    
    int n = denominacionesMoneda.size();

    // Paso 1: Ordenar las denominaciones de mayor a menor
    vector<int> denominacionesOrdenadas = denominacionesMoneda;
    sort(denominacionesOrdenadas.rbegin(), denominacionesOrdenadas.rend());

    // Paso 2: Inicializamos un vector para almacenar la cantidad de monedas de cada denominación.
    vector<int> listaCambio(n, 0);

    // Paso 3: Calcular el monto total de cambio a retornar.
    int montoTotal = pagoEfectivo - costoProducto;

    // Paso 4: Iterar a través de las denominaciones ordenadas de mayor a menor.
    for (int i = 0; i < n; i++) {
        while (montoTotal >= denominacionesOrdenadas[i]) {
            listaCambio[i]++;
            montoTotal -= denominacionesOrdenadas[i];
        }
    }

    return listaCambio;
}


int main() {

    cout << "Introduzca la cantidad de denominaciones: ";
    int N; cin >> N;

    cout << "Introduzca las denominaciones de las monedas y/o billetes: " << endl;
    vector<int> denominaciones(N);
    for (int i = 0; i < N; i++) {
        cin >> denominaciones[i];
    }
    cout << "Introduzca el costo del producto: ";
    int costoProducto; cin >> costoProducto;
    
    cout << "Introduzca el valor de la moneda o billete a usar: ";
    int pagoEfectivo; cin >> pagoEfectivo;

    cout << " " << endl;

    vector<int> listaCambio = cambioDinamico(costoProducto, pagoEfectivo, denominaciones);
    cout << "------ Dynamic Programing ------" << endl; 
    for (int i = 0; i < N; i++) {
        cout << listaCambio[i] << endl;
    }

    cout << " " << endl;

    vector<int> listaCambioVoraz = cambioVoraz(denominaciones, costoProducto, pagoEfectivo);
    cout << "------ Greedy  Algorithm ------" << endl; 
    for (int i = 0; i < N; i++) {
        cout << listaCambioVoraz[i] << endl;
    }

    cout << " " << endl;

    return 0;
}