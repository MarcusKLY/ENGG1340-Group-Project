// password.cpp

// implement a wordle word-guessing game
// players need to input the correct word to unlock the next part of the game
// number of trials and length of the password vary with the difficulty chosen
// the password is randomly generated
// letter that is wrong appears in red
// letter that is correct but in wrong position appears in yellow
// letter that is correct and in correct position appears in green

#include "../header/password.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/main_menu.h"
#include "../header/battle.h"
#include "../header/save_game_checkpoint.h"
#include "../header/gameover.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

// function to generate a random password (randomly choose one from answer.txt)
string generatePassword(int PwLength)
{
    // open file
    ifstream file;
    file.open("src/answer.txt");
    // read the lines into a vector
    vector<string> answerlist;
    string ans;
    while (getline(file, ans))
    {
        answerlist.push_back(ans);
    }
    // while loop to check if the length of the password is valid
    //  generate a random number
    while (true)
    {

        // seed the random number generator with a high-resolution time point
        auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
        mt19937 generator(seed);

        // generate a random number between 1 and the size of the vector
        uniform_int_distribution<int> distribution(1, answerlist.size() - 1);
        int randomNumber = distribution(generator);

        // check if the length is valid
        if (answerlist[randomNumber].length() == PwLength)
        {
            // close file
            file.close();
            // return the password
            transform(answerlist[randomNumber].begin(), answerlist[randomNumber].end(), answerlist[randomNumber].begin(), ::toupper);
            return answerlist[randomNumber];
        }
        else
        {
            continue;
        }
    }
}

// function to check if the player input is valid (1. check length 2. check if it is included in dictionary.txt 3. check if it is a previous attempt)
void checkInput(int PwLength, int trials, vector<string> &attempts, string password, string input)
{
    string line;
    bool isWord = false;
    bool isTried = false;
    // loop until a valid input is entered
    while (true)
    {
        // ask for user input
        color_print(" ⬇️ PLEASE ENTER THE PASSWORD 🔑 ⬇️ ", bold_background_magenta);
        // print empty lines
        cout << endl;
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        cout << endl;
        // transform the input to lower case
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input == "/reveal")
        {
            // blink to show the password
            cout << endl;
            blink(2, "> > > 🤫 Shhh...please keep it a secret! 😎 The password is " + password + " < < <", 300, bold_yellow);
            color_print(" > > > 🤫 Shhh...please keep it a secret! 😎 The password is " + password + " < < <", bold_yellow);
            cout << endl;
            continue;
        }
        // check if it is valid (1. check length 2. check if it is included in dictionary.txt 3. check if it is a previous attempt)
        if (input.length() != PwLength)
        {
            cout << endl;
            blink(2, "> > > 🤬 PASSWORD MUST BE " + to_string(PwLength) + "-LETTER LONG! PLEASE TRY AGAIN! < < <", 300, bold_red);
            color_print("> > > 🤬 PASSWORD MUST BE " + to_string(PwLength) + "-LETTER LONG! PLEASE TRY AGAIN! < < <", bold_red);
            cout << endl;
            continue;
        }
        else
        {
            ifstream dictionary;
            dictionary.open("src/dictionary.txt");
            while (getline(dictionary, line))
            {
                if (line == input)
                {
                    isWord = true;
                    break;
                }
            }
            dictionary.close();
            if (!isWord)
            {
                transform(input.begin(), input.end(), input.begin(), ::toupper);
                cout << endl;
                blink(2, "> > > 🤬 " + input + " IS NOT A VALID WORD! PLEASE TRY AGAIN! < < <", 300, bright_red);
                color_print("> > > 🤬 " + input + " IS NOT A VALID WORD! PLEASE TRY AGAIN! < < <", bright_red);
                cout << endl;
                continue;
            }
        }
        for (int i = 0; i < attempts.size(); i++)
        {
            if (input == attempts[i])
            {
                transform(input.begin(), input.end(), input.begin(), ::toupper);
                cout << endl;
                blink(2, "> > > 🤬 YOU HAVE TRIED " + input + " BEFORE! PLEASE TRY AGAIN! < < <", 300, bright_red);
                color_print("> > > 🤬 YOU HAVE TRIED " + input + " BEFORE! PLEASE TRY AGAIN! < < <", bright_red);
                cout << endl;
                isTried = true;
                break;
            }
        }
        if (isTried)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    // add the valid input to the attempts vector
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    attempts.push_back(input);
}

// function to print the game board (display the current and all the previous attempts with colors everytime the player enter): red for wrong letter, yellow for correct letter but wrong position, green for correct letter and correct position)
void printBoard(string password, vector<string> attempts, int trials)
{
    // declare variables
    int PwLength = password.length();
    // add a check for the size of the attempts vector before accessing its back element. If the vector is empty, then the back element does not exist.
    cout << endl;
    if (attempts.size() == 0)
    {
        return;
    }
    // store all attempts with colors in an array for printing all at once later
    vector<string> coloredAttempts;
    for (int i = 0; i < attempts.size(); i++)
    {
        string attempt = attempts[i];
        string color = "";
        // check for correct letters in correct positions
        for (int j = 0; j < PwLength; j++)
        {
            if (attempt[j] == password[j])
            {
                // add letter spacing
                color += "\033[1;32m"; // green color
                color += " ";
                color += attempt[j];
                color += " ";
                color += "\033[0m"; // reset color
            }
            // check for correct letters in wrong positions
            else if (attempt[j] != password[j] && password.find(attempt[j]) != string::npos)
            {
                color += "\033[1;33m"; // yellow color
                // add letter spacing
                color += " ";
                color += attempt[j];
                color += " ";
                color += "\033[0m"; // reset color
            }
            // check for wrong letters
            else if (attempt[j] != password[j] && password.find(attempt[j]) == string::npos)
            {
                color += "\033[1;31m"; // red color
                color += " ";
                color += attempt[j];
                color += " ";
                color += "\033[0m"; // reset color
            }
        }
        // add the colored attempt to the array
        coloredAttempts.push_back(color);
    }
    // print all attempts with colors and within rainbow borders
    if (PwLength == 4)
    {
        cout << "\033[0;31m┌\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m┐\033[0m";
        cout << "\n";
    }
    else if (PwLength == 5)
    {
        cout << "\033[0;31m┌\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m┐\033[0m";
        cout << "\n";
    }
    else if (PwLength == 6)
    {
        cout << "\033[0;31m┌\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m┐\033[0m";
        cout << "\n";
    }
    for (int i = 0; i < coloredAttempts.size(); i++)
    {
        // odd numbers use yellow borders, even numbers use green borders
        if (i % 2 == 0)
        {
            cout << "\033[0;34m│ \033[0m" + coloredAttempts[i] + "\033[0;35m │\033[0m" << endl;
        }
        else
        {
            cout << "\033[0;35m│ \033[0m" + coloredAttempts[i] + "\033[0;36m │\033[0m" << endl;
        }
    }
    for (int i = 0; i < trials - coloredAttempts.size(); i++)
    {
        if (i % 2 == 0)
        {
            cout << "\033[0;33m│ \033[0m";
            for (int j = 0; j < PwLength; j++)
            {
                cout << "\033[1;35m - \033[0m";
            }
            cout << "\033[0;36m │\033[0m" << endl;
        }
        else
        {
            cout << "\033[0;32m│ \033[0m";
            for (int j = 0; j < PwLength; j++)
            {
                cout << "\033[1;35m - \033[0m";
            }
            cout << "\033[0;32m │\033[0m" << endl;
        }
    }
    if (PwLength == 4)
    {
        cout << "\033[0;31m└\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m┘\033[0m";
        cout << "\n";
    }
    else if (PwLength == 5)
    {
        cout << "\033[0;31m└\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m┘\033[0m";
        cout << "\n";
    }
    else if (PwLength == 6)
    {
        cout << "\033[0;31m└\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;31m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;33m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;32m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;36m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;34m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m─\033[0m";
        cout << "\033[0;35m┘\033[0m";
        cout << "\n";
    }
}

// main function to return the result
bool password(string difficulty)
{
    // declare variables
    int PwLength;
    int trials;
    string password;
    string input;
    vector<string> attempts;
    // set the length and number of trials according to the difficulty
    if (difficulty == "Easy")
    {
        PwLength = 4;
        trials = 10;
        // } else if (difficulty=="Normal") {
        //     PwLength=5;
        //     trials=7;
    }
    else if (difficulty == "Hard")
    {
        PwLength = 6;
        trials = 5;
    }
    else
    {
        PwLength = 5;
        trials = 7;
    }
    // generate a password
    password = generatePassword(PwLength);
    // loop for the game
    blink(3, "> > > 🥸  Markers could enter \"/reveal\" to crack this chapter 🥸  < < <", 500, bold_yellow);
    color_print("> > > 🥸  Markers could enter \"/reveal\" to crack this chapter 🥸  < < <", bold_yellow);
    while ((attempts.size() < trials))
    {
        printBoard(password, attempts, trials);
        // tell markers that they could enter "reveal" to reveal the password
        cout << endl;
        checkInput(PwLength, trials, attempts, password, input);
        if (attempts.back() == password)
        {
            printBoard(password, attempts, trials);
            break;
        }
    }
    if (attempts.back() == password)
    {
        return 1;
    }
    else
    {
        blink(3, "OH NO", 300, bold_background_red);
        char_typewriter("PASSWORD RESET IN PROGRESS...", bold_background_red);
        return 0;
    }
}