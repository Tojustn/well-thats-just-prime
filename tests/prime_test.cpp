#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <vector>

#include "../src/prime.hpp"

TEST_CASE( "#prime" ) {
    Factorizer factorizer;

    REQUIRE( factorizer.prime(0) == std::vector<int>{} );
    REQUIRE( factorizer.prime(1) == std::vector<int>{} );
    REQUIRE( factorizer.prime(10) == std::vector<int> {2,5});
    REQUIRE( factorizer.prime(13) == std::vector<int> {13});
    REQUIRE( factorizer.prime(30) == std::vector<int> {2,3,5});

    REQUIRE( factorizer.isItPrime(0) == true);
    REQUIRE( factorizer.isItPrime(1) == true);
    REQUIRE( factorizer.isItPrime(10) == false);
    REQUIRE( factorizer.isItPrime(13) == true);
    REQUIRE( factorizer.isItPrime(30) == false);

    REQUIRE( factorizer.isItComposite(0) == false);
    REQUIRE( factorizer.isItComposite(1) == false);
    REQUIRE( factorizer.isItComposite(10) == true);
    REQUIRE( factorizer.isItComposite(13) == false);
    REQUIRE( factorizer.isItComposite(30) == true);

    REQUIRE(factorizer.reduce(0, 5) == "0");
    REQUIRE(factorizer.reduce(1, 1) == "1");
    REQUIRE(factorizer.reduce(1, 2) == "1/2");
    REQUIRE(factorizer.reduce(12, 8) == "3/2");
    REQUIRE(factorizer.reduce(100, 80) == "5/4");
    REQUIRE(factorizer.reduce(7, 7) == "1");
    REQUIRE(factorizer.reduce(5, 0) == "");
    REQUIRE(factorizer.reduce(3, 5) == "3/5");
    REQUIRE(factorizer.reduce(10, 1) == "10");
}

