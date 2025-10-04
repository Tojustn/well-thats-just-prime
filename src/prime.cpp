#include <vector>
#include "prime.hpp"
#include <string>
std::vector<int> Factorizer::prime(int number) {
   std::vector<int> primes{};

   if(number == 1 || number ==0){
      return primes;
   }
   while(number > 1){
      for(int i = 2; i <= number; ++i){
         if(number % i ==0){
            number = number/i;
            primes.push_back(i);
            break;
            }
      }
   }
   return primes;
}

bool Factorizer::isItPrime(int number){
   if(number == 0 || number ==1){
      return true;
   }
   return (number == prime(number)[0]);
}
bool Factorizer::isItComposite(int number){
   return !isItPrime(number);
}

std::string Factorizer::reduce(int num, int denom) {
   std::vector<int> numPrime{prime(num)};
   std::vector<int> denomPrime(prime(denom));
   std::string result{};

   if (denom == 0) {
      return "";
   }

   if (num == 0) {
      return "0";
   }

   // 2 x 2 x 3  12 -> 6 -> 2
   // 2 x 3      6 -> 3 -> 1
   int numIdx{};
   int denomIdx{};
   while (numIdx < numPrime.size() && denomIdx < denomPrime.size()){
      if (numPrime[numIdx] == denomPrime[denomIdx]) {

         num /= numPrime[numIdx];
         denom /= denomPrime[denomIdx];

         numIdx++;
         denomIdx++;
      }
      else if (numPrime[numIdx] > denomPrime[denomIdx]) {
         denomIdx++;
      }
      else {
         numIdx++;
      }
   }
   if (denom == 1) {
      return std::to_string(num);
   }else {
      return std::to_string(num) + "/" + std::to_string(denom);
   }
}
