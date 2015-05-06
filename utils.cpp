#include "utils.h"
#include <iostream>
#include <random>
using namespace std;

// Mersene Twister psendo-number generator
random_device rd;   // Obtain a random number from hardware
mt19937 eng(rd());  // Seed the generator

int RandomBetween(int begin, int end) {
    uniform_int_distribution<> range(begin,end);    // Define the range
    return (range(eng));
}
