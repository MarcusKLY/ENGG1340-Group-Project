#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int randnum() {
    // seed the random number generator with a high-resolution time point
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    
    // generate a random number between 1 and 100
    uniform_int_distribution<int> distribution(1, 100);
    int randomNumber = distribution(generator);

    return randomNumber;
}