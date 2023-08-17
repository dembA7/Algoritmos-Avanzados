// =================================================================
//
// File: shirts.h
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Program that calculates the necessary days to produce
//              a certain amount of shirts.
//
// =================================================================

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>

using namespace std;

void shirtsProduction(int shirts){
    
    int totalDays = 0;
    int totalProd = 0;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    while(totalProd < shirts){

        float lineOne = static_cast<int>(std::ceil(static_cast<float>(rand()) / RAND_MAX * 100));
        float lineTwo = static_cast<int>(std::ceil(static_cast<float>(rand()) / RAND_MAX * 100));
        int prodDay = lineOne + lineTwo;

        totalProd += prodDay;
        totalDays++;

        printf("The production of shirts on day %i was: %i.\n", totalDays, prodDay);
    }
    
    printf("The production was completed in %i days.\n", totalDays);

};