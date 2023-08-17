// =================================================================
//
// File: sodas.h
//
// Authors: Arturo Díaz López  - A01709522
//          Diego Vega Camacho - A01704492
//          Ian Padrón Corona  - A01708940
//
// Description: Program that calculates the amount of bottles a
//              container can fill up based on its volume.
//
// =================================================================

#include <iostream>
#include <cstdio>
#include <random>

using namespace std;

void sodasProduction(int mlContainer, std::mt19937& gen){

    uniform_real_distribution<float> dist(0.0f, 5.0f);

    float radius = std::ceil(dist(gen));
    float height = std::ceil(dist(gen));

    float mainContainerVolume = radius * radius * 3.14159 * height;
    float mainContainerVolumeMl = mainContainerVolume * 1000000;

    float totalProd = mainContainerVolumeMl / mlContainer;
    int totalProdRed = static_cast<int>(totalProd);

    printf("The main container with a radius of %.0f meters,\nand a height of %.0f meters, can hold %i \nbottles of %i mL.\n",  radius, 
                                                                                                                                height, 
                                                                                                                                totalProdRed, 
                                                                                                                                mlContainer);

}