// password.cpp

#include "../header/password.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// implement a wordle word game acting like an password input
// users need to input the correct word to unlock the game
// the number of tired and number of charaters are different for different difficulty
// the word is randomly generated
// the correct charather but not correct position appears in yellow
// the wrong charather appears in red
// the correct charather with correct position appears in green
// Function to get a random 4-letter word from a list of words
string getRandomWord() {
    string word_array[] = {"apple", "banana", "cherry", "orange", "pear", "strawberry", "watermelon"};
    vector<string> words(word_array, word_array + sizeof(word_array) / sizeof(word_array[0]));
    srand(time(NULL)); // Seed random number generator
    int index = rand() % words.size(); // Generate random index
    string word = words[index];
    return word;
}
// Function to check if a character is in a string
bool containsChar(string str, char c) {
    for (char ch : str) {
        if (ch == c) {
            return true;
        }
    }
    return false;
}
// Function to play the "wordle" game

bool password(string difficulty)
{
    // int num = -1;
    // cin >> num;
    // if (num == 1)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
    string secret_word = getRandomWord(); // Choose a random 4-letter word
    int num_guesses = 6; // Number of guesses allowed
    string guess; // User's guess
    string used_letters = ""; // Letters the user has already guessed
    bool won = false; // Flag to indicate if the user has won the game

    cout << "Welcome to Wordle! You have " << num_guesses << " guesses to guess the secret word.\n";

    while (num_guesses > 0 && !won) {
        cout << "Secret word: ";
        for (char c : secret_word) {
            if (containsChar(used_letters, c)) {
                cout << c << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;

        cout << "Used letters: \n";
        // Print used letters in formatted box
        cout << "+-------------------+\n";
        cout << "| ";
        for (char c : used_letters) {
            cout << c << " ";
        }
        cout << "|\n";
        cout << "+-------------------+\n";

        cout << "Guess a letter: ";
        cin >> guess;

        // Check if guess is a single character
        if (guess.length() != 1) {
            cout << "Invalid guess. Please enter a single letter.\n";
            continue;
        }

        // Check if guess has already been used
        if (containsChar(used_letters, guess[0])) {
            cout << "You already guessed that letter. Please choose a different letter.\n";
            continue;
        }

        used_letters += guess[0]; // Add guess to list of used letters

        // Check if guess is in the secret word
        if (containsChar(secret_word, guess[0])) {
            cout << "Correct!\n";
            // Check if user has guessed all letters in the secret word
            won = true;
            for (char c : secret_word) {
                if (!containsChar(used_letters, c)) {
                    won = false;
                    break;
                }
            }
        } else {
            cout << "Incorrect.\n";
            num_guesses--;
        }
    }

    // Print game result
    if (won) {
        cout << "Congratulations, you guessed the secret word \"" << secret_word << "\"!\n";
    } else {
        cout << "Sorry, you ran out of guesses. The secret word was \"" << secret_word << "\".\n";
    }

    // Print list of used letters in formatted box
    cout << "Used letters: \n";
    cout << "+-------------------+\n";
    cout << "| ";
    for (char c : used_letters) {
        cout << c << " ";
    }
    cout << "|\n";
    cout << "+-------------------+\n";
    
    return 0;
}
