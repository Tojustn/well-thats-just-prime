#pragma once
#include <vector>
#include <string>
class Factorizer{


    public:
        std::vector<int> prime(int);

        bool isItPrime(int);

        bool isItComposite(int);

        std::string reduce(int, int);
};
