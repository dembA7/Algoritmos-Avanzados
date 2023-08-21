// =================================================================
//
// File: main.cpp
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Unit cases for shirts and bottles functions.
//
// =================================================================

#include <iostream>
#include <ctime>
#include "shirts.h"
#include "sodas.h"

using namespace std;

int main(){

    std::random_device rd;
    std::mt19937 gen(rd());
    
    printf("==============================================\n");
    printf("================ Activity 1.1 ================\n");
    printf("==============================================\n");
    printf("\n");
    
    printf("================ UC1 Shirts ==================\n");
    shirtsProduction(500);
    printf("==============================================\n");
    printf("\n");

    printf("================ UC2 Shirts ==================\n");
    shirtsProduction(737);
    printf("==============================================\n");
    printf("\n");

    printf("================ UC3 Shirts ==================\n");
    shirtsProduction(96);
    printf("==============================================\n");
    printf("\n");

    printf("================ UC4 Shirts ==================\n");
    shirtsProduction(938);
    printf("==============================================\n");
    printf("\n");

    printf("================ UC1 Bottles =================\n");
    sodasProduction(355, gen);
    printf("==============================================\n");
    printf("\n");

    printf("================ UC2 Bottles =================\n");
    sodasProduction(600, gen);
    printf("==============================================\n");
    printf("\n");

    printf("================ UC3 Bottles =================\n");
    sodasProduction(2500, gen);
    printf("==============================================\n");
    printf("\n");

    printf("================ UC4 Bottles =================\n");
    sodasProduction(1250, gen);
    printf("==============================================\n");
    printf("\n");
    
    return 0;
}