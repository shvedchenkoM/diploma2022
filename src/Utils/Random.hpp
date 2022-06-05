#ifndef DIPLOMA_RANDOM_HPP
#define DIPLOMA_RANDOM_HPP

#include <random>

class Random {
public:
    static int range(int start, int end) {
        std::random_device device;
        std::mt19937 rng(device());
        std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
        return (int)dist(rng);
    }
};


#endif //DIPLOMA_RANDOM_HPP
