//temp.cpp

#include "../header/output_style.h"
#include "../header/word_style.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    char_typewriter(s, dark_blue);
    char_typewriter(s, dark_blue);
    char_typewriter(s, dark_blue);
    line_typewriter(s, bold_blue);
    line_typewriter(s, underline_blue);
    return 0;
}