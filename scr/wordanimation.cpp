//wordanimation.cpp

#include "../header/wordanimation.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

int animateP(string s) {
    string word = s;
    for (char c : word) {
        std::cout << c << std::flush;
        std::chrono::milliseconds timespan(100);
        std::this_thread::sleep_for(timespan);
    }
    std::cout << endl;
    return 0;
}