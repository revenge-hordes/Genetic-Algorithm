#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <vector>
#include "individual.h"

class GeneticAlgorithm {
public:
    GeneticAlgorithm();

    void run();

private:
    std::vector<Individual> population;

    void crossover(const Individual& parent1, const Individual& parent2, Individual& child);
    void mutate(Individual& individual);
};

#endif // GENETIC_ALGORITHM_H
