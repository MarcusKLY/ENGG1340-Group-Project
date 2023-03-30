//output_style.cpp

#include "../header/output_style.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

//animated cout function which print the string character by character
int char_typewriter(string s, ColorOption colorOptions) {
    chrono::milliseconds timespan(200);
    this_thread::sleep_for(timespan);
    string word = s;
    cout << colorOptions.code;
    for (char c : word) {
        cout << c << flush;
        chrono::milliseconds timespan(80);
        this_thread::sleep_for(timespan);
    }
    cout << "\033[0m" << endl; // Reset color to default
    return 0;
}

//animated cout function which print the string line with waiting time
int line_typewriter(string s, ColorOption colorOptions) {
    chrono::milliseconds timespan(200);
    this_thread::sleep_for(timespan);
    string word = s;
    cout << colorOptions.code;
    cout << word << flush;
    cout << "\033[0m" << endl; // Reset color to default
    return 0;
}