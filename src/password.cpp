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
string generatePassword(int PwLength) {
    // open file
    ifstream file;
    file.open("src/answer.txt");
    // read the lines into a vector
    vector<string> answerlist;
    string ans;
    while (getline(file, ans)) {
        answerlist.push_back(ans);
    }
    //while loop to check if the length of the password is correct
    // generate a random number
    while (true) {
        // srand(time(NULL));
        // int randomNumber=rand()%answerlist.size();

        // seed the random number generator with a high-resolution time point
        auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
        mt19937 generator(seed);
    
        // generate a random number between 1 and 100
        uniform_int_distribution<int> distribution(1, 100);
        int randomNumber = distribution(generator);

        // check if the length is correct
        if (answerlist[randomNumber].length()==PwLength) {
            // close file
            file.close();
            // return the password
            transform (answerlist[randomNumber].begin(), answerlist[randomNumber].end(), answerlist[randomNumber].begin(), ::toupper);
            return answerlist[randomNumber];
        }else{
            continue;
        }
    }
}

// function to check if the input is valid (1. check length 2. check if it is included in dictionary.txt 3. check if it is a previous attempt)
void checkInput(int PwLength, int trials, vector<string>& attempts, string password, string input) {
    // declare variables
    string line;
    bool isWord=false;
    bool isTried=false;
    // loop until a valid input is entered
    while (true) {
        // markers could enter "reveal" to reveal the password
        cout << "*** Markers could enter \"/reveal\" to bypass this ***" << endl;
        // ask for user input
        cout << "Please enter the password! >> ";
        cin >> input;
        // transform the input to lower case
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input=="/reveal") {
            cout << "Shhh...please keep it a secret! The password is " << password << endl;
            continue;
        }
        // check if it is valid (1. check length 2. check if it is included in dictionary.txt 3. check if it is a previous attempt)
        if (input.length()!=PwLength) {
            cout << "Password must be " << PwLength << "-letter long! Please try again!" << endl;
            continue;
        } else {
            ifstream dictionary;
            dictionary.open("src/dictionary.txt");
            while (getline(dictionary, line)) {
                if (line==input) {
                    isWord=true;
                    break;
                }
            }
            dictionary.close();
            if (!isWord) {
                transform(input.begin(), input.end(), input.begin(), ::toupper);
                cout << input << " is not a valid word! Please try again!" << endl;
                continue;
            }

        }
        for (int i=0; i<attempts.size(); i++) {
            if (input==attempts[i]) {
                transform(input.begin(), input.end(), input.begin(), ::toupper);
                cout << "You have tried " << input << " before! Please try again!" << endl;
                isTried = true;
                break;
            }
        }
        if (isTried) {
            continue;
        }else{
            break;
        }
    }
    // add the valid input to the attempts vector
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    attempts.push_back(input);
}

// function to print the game board (display the current and all the previous attempts with colors everytime the player enter): red for wrong letter, yellow for correct letter but wrong position, green for correct letter and correct position)
void printBoard(string password, vector<string> attempts) {
    // declare variables
    int PwLength = password.length();
    // add a check for the size of the attempts vector before accessing its back element. If the vector is empty, then the back element does not exist.
    if (attempts.size() == 0) {
        return;
    }
    // store all attempts with colors in an array for printing all at once later
    vector<string> coloredAttempts;
    for (int i = 0; i < attempts.size(); i++) {
        string attempt = attempts[i];
        string color = "";
        // check for correct letters in correct positions
        for (int j = 0; j < PwLength; j++) {
            if (attempt[j] == password[j]) {
                color += "\033[32m"; // green color
                color += attempt[j];
                color += "\033[0m"; // reset color
            }
        // check for correct letters in wrong positions
            else if (attempt[j] != password[j] && password.find(attempt[j]) != string::npos) {
                color += "\033[33m"; // yellow color
                color += attempt[j];
                color += "\033[0m"; // reset color
            }
        // check for wrong letters
            else if (attempt[j] != password[j] && password.find(attempt[j]) == string::npos) {
                color += "\033[31m"; // red color
                color += attempt[j];
                color += "\033[0m"; // reset color
            }
        }
        // add the colored attempt to the array
        coloredAttempts.push_back(color);
    }
    // print all attempts with colors
    for (int i = 0; i < coloredAttempts.size(); i++) {
        cout << coloredAttempts[i] << " ";
    }
    cout << endl;
}

// main function to return the result
bool password(string difficulty) {
    // declare variables
    int PwLength;
    int trials;
    string password;
    string input;
    vector<string> attempts;
    // set the length and number of trials according to the difficulty
    if (difficulty=="Easy") {
        PwLength=4;
        trials=10;
    } else if (difficulty=="Normal") {
        PwLength=5;
        trials=7;
    } else {
        PwLength=6;
        trials=5;
    }
    // generate a password
    password=generatePassword(PwLength);
    // start the game
    cout << "Welcome to the wordle game!" << endl;
    // loop for the game
    while ((attempts.size()<trials)) {
        printBoard(password, attempts);
        checkInput(PwLength, trials, attempts, password, input);
        if (attempts.back()==password) {
            printBoard(password, attempts);
            break;
    }
    }
    if (attempts.back()==password) {
        return 1;
    }else{
        cout << "PASSWORD RESET IN PROGRESS..." << endl;
        return 0;
    }
}