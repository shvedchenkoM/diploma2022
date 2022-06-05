#include "GeneticAlgorithm.hpp"
#include <iostream>
#include <set>
#include <thread>
#include "../Utils/Random.hpp"

std::vector<double> cross(std::vector<double> chromosome1, std::vector<double> chromosome2) {
    double length = (double) chromosome1.size();
    double split_position = Random::range(0, length - 1);
    std::vector<double> result;
//    create default vector
    for (double i = 0; i < split_position; i++) {
        result.push_back(chromosome1[i]);
    }
    for (double i = split_position; i < length; i++) {
        result.push_back(chromosome2[i]);
    }
// delete same elements
    for (double i = 0; i < result.size(); i++) {
        double x = result[i];
        for (double j = i + 1; j < result.size(); j++) {
            if (result[j] == x) {
                result.erase(result.begin() + j);
                break;
            }
        }
    }
//    generate list of needed elements
    std::set<double> s;
    for (double i = 0; i < length; i++)
        s.insert(chromosome1[i]);
    for (double &i: result) {
        s.erase(s.find(i));
    }
    std::vector<double> k;
    for (auto x: s) {
        k.push_back(x);
    }
    std::reverse(k.begin(), k.end());
//    int x = rand() % k.size();
//    std::swap(k[0], k[x]);
//    insert it
    for (double &i: k) {
        double pos = Random::range(0, (double) result.size() - 1);
        result.insert(result.begin() + pos, i);
    }


    return result;
}


void Chromosome::generate(double length) {
    std::vector<double> s;
    for (double i = 0; i < length; i++)
        s.push_back(i);
    std::vector<double> k;
    for (double &i: s) {
        double pos;
        if (k.empty()) {
            pos = 0;
        } else
            pos = Random::range(0, (double) k.size() - 1);
        k.insert(k.begin() + pos, i);
    }
    this->gens = k;
}


void generate_part(double count, double length, std::vector<Chromosome> &result, MetroMap map) {
    for (int i = 0; i < count; i++) {
        Chromosome new_chromosome;
        new_chromosome.generate(length);
        new_chromosome.dist = (double) map.getDistance_by_Dijkstra(new_chromosome.gens);
        result.push_back(new_chromosome);
    }
}


void cross_part(double count, std::vector<Chromosome> &result, MetroMap map,
                std::vector<Chromosome> chromosomes) {

    for (int i = 0; i < count; i++) {
        Chromosome x;
        Chromosome f = chromosomes[Random::range(0, chromosomes.size() - 1)];
        Chromosome m = chromosomes[Random::range(0, chromosomes.size() - 1)];
        x.gens = cross(f.gens, m.gens);
        x.dist = (double) map.getDistance_by_Dijkstra(x.gens);
        result.push_back(x);
    }
}


bool cmp(const Chromosome &a, const Chromosome &b) {
    return a.dist < b.dist;
}

void GeneticAlgorithm::generate() {
//    Create threads
    std::vector<std::thread> threads;
    std::vector<std::vector<Chromosome>> chromosomes_threads(this->processors);
    for (double i = 0; i < this->processors; i++) {
        threads.emplace_back(generate_part, maxCount / this->processors, map.getSize(),
                             std::ref(chromosomes_threads[i]), map);
    }
//    Wait for it
    for (auto &thread: threads)
        thread.join();
//    Reparce
    for (auto &chromosomes_thread: chromosomes_threads) {
        for (auto &j: chromosomes_thread) {
            chromosomes.push_back(j);
        }
    }
    sort(chromosomes.begin(), chromosomes.end(), cmp);
}

GeneticAlgorithm::GeneticAlgorithm(double countGeneration, double maxCount, double minCount, MetroMap map,
                                   double processors) {
    this->countGeneration = countGeneration;
    this->maxCount = maxCount;
    this->minCount = minCount;
    this->processors = processors;
    this->map = std::move(map);
    generate();
    prdouble_the_best();

}

void GeneticAlgorithm::Run() {
    for (double i = 0; i < countGeneration; i++) {
        oneGeneration();
    }
}

void GeneticAlgorithm::oneGeneration() {
//    Natural(Programming))) ) Selection
    sort(chromosomes.begin(), chromosomes.end(), cmp);

    std::vector<Chromosome> newChromosomes;
    for (double j = 0; j < minCount; j++)
        newChromosomes.push_back(chromosomes[j]);
    chromosomes = newChromosomes;
    std::vector<std::thread> threads;
    std::vector<std::vector<Chromosome>> chromosomes_threads(this->processors);
    for (double j = 0; j < this->processors; j++) {
        threads.emplace_back(cross_part, maxCount / this->processors, std::ref(chromosomes_threads[j]),
                             map,
                             chromosomes);
    }
    for (auto &thread: threads)
        thread.join();

    for (auto &chromosomes_thread: chromosomes_threads) {
        for (auto &h: chromosomes_thread) {
            chromosomes.push_back(h);
        }
    }
    prdouble_the_best();
}

void GeneticAlgorithm::prdouble_the_best() {
    for (double gen: chromosomes[0].gens)
        std::cout << gen << " ";
    std::cout << " time:" << map.getDistance_by_Dijkstra(chromosomes[0].gens) << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}
