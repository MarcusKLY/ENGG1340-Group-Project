// password.cpp

#include "../header/password.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include <iostream>
#include <string>

using namespace std;

// implement a wordle word game acting like an password input
// users need to input the correct word to unlock the game
// the number of tired and number of charaters are different for different difficulty
// the word is randomly generated
// the correct charather but not correct position appears in yellow
// the wrong charather appears in red
// the correct charather with correct position appears in green
bool password(string difficulty)
{
    int num = -1;
    cin >> num;
    if (num == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
