// =================================================================
//
// File: shirts.h
//
// Authors: Arturo Díaz López    - A01709522
//          Diego Vega Camacho   - 
//          Ian Padrón Corona    -
//
// Description: 
//
// =================================================================

#include <iostream>
#include <cstdlib>

using namespace std;

int maquila(int n){
    float dias = 0;

    int prod_linea1 = rand() % 100;
    int prod_linea2 = rand() % 100;
    int prod_dia = prod_linea1 + prod_linea2;

    printf("La capacidad de producción es de %i camisas por día\n", prod_dia);

    dias = n / prod_dia;

    return (dias);

};

int main(){

    int num_camisas = 0;

    printf("Ingresa cuantas camisas quieres producir\n");
    cin >> num_camisas;

    return 0;
}
