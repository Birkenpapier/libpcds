#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Individual {
public:
    std::vector<int> chromosome;
    int fitness;

    Individual(int size) : chromosome(size), fitness(0) {
        for (int &gene : chromosome) {
            gene = rand() % 2;
        }
    }

    void calculateFitness() {
        fitness = std::count(chromosome.begin(), chromosome.end(), 1);
    }
};

class GeneticAlgorithm {
private:
    std::vector<Individual> population;
    int populationSize;
    int chromosomeSize;
    int maxGenerations;
    float mutationRate;
    float crossoverRate;

public:
    GeneticAlgorithm(int popSize, int chromoSize, int maxGen, float mutationR, float crossoverR)
        : populationSize(popSize), chromosomeSize(chromoSize),
          maxGenerations(maxGen), mutationRate(mutationR), crossoverRate(crossoverR) {
        for (int i = 0; i < populationSize; ++i) {
            population.emplace_back(chromosomeSize);
        }
    }

    void run() {
        for (int generation = 0; generation < maxGenerations; ++generation) {
            for (Individual &individual : population) {
                individual.calculateFitness();
            }

            std::sort(population.begin(), population.end(), [](const Individual &a, const Individual &b) {
                return a.fitness > b.fitness;
            });

            std::vector<Individual> newPopulation;
            for (int i = 0; i < populationSize; ++i) {
                Individual parent1 = selectParent();
                Individual parent2 = selectParent();
                Individual offspring = crossover(parent1, parent2);
                mutate(offspring);
                newPopulation.push_back(offspring);
            }

            population = newPopulation;

            if (generation % 10 == 0) {
                std::cout << "Generation: " << generation << " Best Fitness: " << population.front().fitness << std::endl;
            }
        }
    }

    Individual selectParent() {
        return population[rand() % populationSize];
    }

    Individual crossover(const Individual &parent1, const Individual &parent2) {
        Individual offspring(chromosomeSize);
        int crossoverPoint = rand() % chromosomeSize;
        for (int i = 0; i < chromosomeSize; ++i) {
            offspring.chromosome[i] = (i < crossoverPoint) ? parent1.chromosome[i] : parent2.chromosome[i];
        }
        return offspring;
    }

    void mutate(Individual &individual) {
        for (int &gene : individual.chromosome) {
            float randProb = static_cast<float>(rand()) / RAND_MAX;
            if (randProb < mutationRate) {
                gene = (gene == 1) ? 0 : 1; // Flip the gene
            }
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int populationSize = 100;
    int chromosomeSize = 64;
    int maxGenerations = 100;
    float mutationRate = 0.01f;
    float crossoverRate = 0.7f;

    GeneticAlgorithm ga(populationSize, chromosomeSize, maxGenerations, mutationRate, crossoverRate);
    ga.run();

    return 0;
}
