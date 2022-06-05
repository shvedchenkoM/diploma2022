#ifndef DIPLOMA_GENETICALGORITHM_HPP
#define DIPLOMA_GENETICALGORITHM_HPP

#include <vector>
#include "../Data/MetroMap.hpp"

struct Chromosome {
    std::vector<double> gens;
    long double dist;

    void generate(double length);
};


class GeneticAlgorithm {
private:
    double countGeneration;
    double maxCount;
    MetroMap map;
    std::vector<Chromosome> chromosomes;
    double processors;
    double minCount;

    void oneGeneration();

    void generate();

    void prdouble_the_best();

public:
    GeneticAlgorithm(double countGeneration, double maxCount, double minCount, MetroMap map, double processors);

    void Run();
};


#endif //DIPLOMA_GENETICALGORITHM_HPP
