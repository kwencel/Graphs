#include <iostream>
#include <chrono>
#include <random>

using namespace std;

// Mersene Twister psendo-number generator
unsigned seed = (unsigned int) std::chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);  // Seed the generator

int RandomBetween(int begin, int end) {
    uniform_int_distribution<> range(begin,end);    // Define the range
    return range(eng);
}

bool GreaterThanZero(int number) {
    return number > 0;
}
