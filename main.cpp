#include <iostream>
#include "genetic_algorithm.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    GeneticAlgorithm geneticAlgorithm;
    geneticAlgorithm.run();

    return 0;
}
