#include "genetic_algorithm.h"
#include <algorithm>

const int POPULATION_SIZE = 100;
const int MAX_GENERATIONS = 100;
const double MUTATION_RATE = 0.01;

GeneticAlgorithm::GeneticAlgorithm() {
    population.resize(POPULATION_SIZE);

    for (int i = 0; i < POPULATION_SIZE; ++i) {
        population[i] = Individual();
    }
}

void GeneticAlgorithm::run() {
    for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {
        std::sort(population.begin(), population.end());

        std::cout << "Generation " << generation << ": Best fitness = " << population[0].fitness << ", Best x = " << population[0].x << std::endl;

        // Create new generation through crossover and mutation
        for (int i = 0; i < POPULATION_SIZE / 2; ++i) {
            Individual parent1 = population[i];
            Individual parent2 = population[i + 1];

            Individual child1, child2;

            crossover(parent1, parent2, child1);
            crossover(parent1, parent2, child2);

            if (static_cast<double>(rand()) / RAND_MAX < MUTATION_RATE) {
                mutate(child1);
            }

            if (static_cast<double>(rand()) / RAND_MAX < MUTATION_RATE) {
                mutate(child2);
            }

            population[POPULATION_SIZE / 2 + i] = child1;
            population[POPULATION_SIZE / 2 + i + 1] = child2;
        }
    }

    std::sort(population.begin(), population.end());

    std::cout << "Final Result: Best fitness = " << population[0].fitness << ", Best x = " << population[0].x << std::endl;
}

void GeneticAlgorithm::crossover(const Individual& parent1, const Individual& parent2, Individual& child) {
    // Simple crossover: average of the parents' genes
    child.x = (parent1.x + parent2.x) / 2.0;
    child.fitness = fitnessFunction(child.x);
}

void GeneticAlgorithm::mutate(Individual& individual) {
    // Simple mutation: add a random value to the gene
    double mutation = (static_cast<double>(rand()) / RAND_MAX - 0.5) * 0.1;  // Small random mutation
    individual.x += mutation;
    individual.fitness = fitnessFunction(individual.x);
}
