#include <iostream>
#include <vector>
#include <climits>

int pagarConMonedas(int cantidad, const std::vector<int>& monedasDisponibles) {
    std::vector<int> minMonedas(cantidad + 1, INT_MAX);
    minMonedas[0] = 0;  // No se necesitan monedas para pagar 0

    for (int i = 1; i <= cantidad; ++i) {
        for (int moneda : monedasDisponibles) {
            if (i >= moneda) {
                int minMonedasPosible = minMonedas[i - moneda] + 1;
                if (minMonedasPosible < minMonedas[i]) {
                    minMonedas[i] = minMonedasPosible;
                }
            }
        }
    }

    return minMonedas[cantidad];
}

int main() {
    int cantidad = 112;
    std::vector<int> monedasDisponibles = {1, 4, 9};
    int resultado = pagarConMonedas(cantidad, monedasDisponibles);
    std::cout << "Cantidad minima de monedas: " << resultado << std::endl;

    return 0;
}
