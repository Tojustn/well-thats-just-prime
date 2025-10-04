#include <iostream>
#include <vector>
#include "src/prime.hpp"

int main() {

    Factorizer factorizer;
  std::vector<int> primesOfTen{};

   primesOfTen = factorizer.prime(10);

  for (size_t i = 0; i<primesOfTen.size();++i){
    std::cout << primesOfTen[i] << " X ";
  }

  const int number = 13;

  std::cout << "\nIs " << number << " prime? " << (factorizer.isItPrime(number) ? "Yes" : "No") << std::endl;

  
}
