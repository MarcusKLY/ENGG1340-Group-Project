// password.cpp

#include "../header/password.h"
#include "../header/output_style.h"
#include "../header/word_style.h"

#include <iostream>
#include <fstream>
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

#include <algorithm>

using namespace std;

class LetterState {
public:
    char character;
    bool is_in_word;
    bool is_in_position;
    LetterState(char c) : character(c), is_in_word(false), is_in_position(false) {}
};

class Wordle {
public:
    string secret;
    vector<string> attempts;
    static const char VOIDED_LETTER = '*';
    Wordle(string s) : secret(s) {}

    void attempt(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        attempts.push_back(word);
    }

    vector<LetterState> guess(string word) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        vector<LetterState> result(word.size(), LetterState(' '));

        // Initialize the results array with all GREY letters.
        for (int i = 0; i < word.size(); i++) {
            result[i] = LetterState(word[i]);
        }

        // Make a copy of the secret so we can cross out 'used' letters.
        string remaining_secret = secret;

        // First, check for GREEN letters.
        for (int i = 0; i < word.size(); i++) {
            LetterState& letter = result[i];
            if (letter.character == remaining_secret[i]) {
                letter.is_in_position = true;
                remaining_secret[i] = VOIDED_LETTER;
            }
        }

        // Loop again and check for YELLOW letters.
        for (int i = 0; i < word.size(); i++) {
            LetterState& letter = result[i];

            // Skip this letter if it is already in the right place.
            if (letter.is_in_position) {
                continue;
            }

            // Otherwise, check if the letter is in the word, and void that index.
            for (int j = 0; j < word.size(); j++) {
                if (letter.character == remaining_secret[j]) {
                    remaining_secret[j] = VOIDED_LETTER;
                    letter.is_in_word = true;
                    break;
                }
            }
        }
        return result;
    }

    bool is_solved() {
        return !attempts.empty() && attempts.back() == secret;
    }

    int remaining_attempts(int passwordAttempt) {
        return passwordAttempt - attempts.size();
    }

    bool can_attempt(int passwordAttempt) {
        return remaining_attempts(passwordAttempt) > 0 && !is_solved();
    }
};

bool display_results(Wordle& wordle, int passwordLength, int passwordAttempt) {
    if (wordle.remaining_attempts(passwordAttempt) > 1 && !wordle.is_solved()) {
        cout << "You have " << wordle.remaining_attempts(passwordAttempt) << " more chances until triggering the security system to reset its password!" << endl;
    }
    else if (wordle.remaining_attempts(passwordAttempt) == 1) {
        cout << "You have ONE LAST CHANCE before triggering the security system to reset its password!" << endl;
    }
    vector<string> lines;

    for (string word : wordle.attempts) {
        vector<LetterState> result = wordle.guess(word);
        string colored_result_str = "";
        for (LetterState letter : result) {
            if (letter.is_in_position) {
                colored_result_str += "\033[32m" + string(1, letter.character) + "\033[0m ";
            }
            else if (letter.is_in_word) {
                colored_result_str += "\033[33m" + string(1, letter.character) + "\033[0m ";
            }
            else {
                colored_result_str += string(1, letter.character) + " ";
            }
        }
        lines.push_back(colored_result_str);
    }

    for (int i = 0; i < wordle.remaining_attempts(passwordAttempt); i++) {
        lines.push_back(string(passwordLength, '_'));
    }

    int content_length = passwordLength + passwordLength - 1 + 2;
    string top_border = "┌" + string(content_length, '─') + "┐";
    string bottom_border = "└" + string(content_length, '─') + "┘";
    string space = " ";
    cout << top_border << endl;

    for (string line : lines) {
        cout << "│" << space << line << space << "│" << endl;
    }

    cout <<"│" << space << string(passwordLength, '_') << space << "│" << endl;
    cout << bottom_border << endl;

    if (wordle.is_solved()) {
        cout << "Congratulations! You have successfully guessed the password: " << wordle.secret << endl;
        return true;
    }
    else {
        cout << "Sorry, you have exhausted all your attempts. The password was: " << wordle.secret << endl;
        return false;
    }
}

//Get a random password from answer.txt.
string get_random_password() {
ifstream file("answer.txt");
if (!file.fail()) {
    cout << "Unable to open file." << endl;
}else{

string password;
int line_number = 0;
string selected_line;
while (getline(file, password)) {
    //check if length of the password matches "passwordLenghth"
    if (password.length() != passwordLength) {
        continue;
    }
    if (rand() % ++line_number == 0) {
        transform(password.begin(), password.end(), password.begin(), ::toupper);
        selected_line = password;
    }
}

return selected_line;
}
}

bool play_password_game(int passwordLength, int passwordAttempt) {

    // Initialize the game state.
    Wordle wordle(password);

    while (wordle.can_attempt(passwordAttempt)) {
        cout << "Enter your guess (" << wordle.remaining_attempts(passwordAttempt) << " attempts left): ";
        string guess;
        cin >> guess;

        // Check if the guess is valid.
        if (guess.size() != passwordLength) {
            cout << "Your guess must be " << passwordLength << " characters long." << endl;
            continue;
        }
        if (count_if(guess.begin(), guess.end(), [](char c) { return !isalpha(c); }) > 0) {
            cout << "Your guess must contain only alphabetic characters." << endl;
            continue;
        }
        if (wordle.attempts.size() > 0 && find(wordle.attempts.begin(), wordle.attempts.end(), guess) != wordle.attempts.end()) {
            cout << "You already guessed that word!" << endl;
            continue;
        }

        // Add the guess to the game state.
        wordle.attempt(guess);

        // Display the game state.
        if (display_results(wordle, passwordLength, passwordAttempt)) {
            return true;
        }
    }
    return false;
}

int main() {
    if ( difficulty == "Easy" ) {
        passwordLength = 4;
        passwordAttempt = 10;
    } else if ( difficulty == "Normal" ) {
        passwordLength = 5;
        passwordAttempt = 8;
    } else if ( difficulty == "Hard" ) {
        passwordLength = 6;
        passwordAttempt = 4;
    } else {
        cout << "Invalid difficulty level. Please try again." << endl;
        return 0;
    }
    int passwordLength = 5;
    int passwordAttempt = 10;
    bool won = play_password_game(passwordLength, passwordAttempt);
    if (won) {
        cout << "You won!" << endl;
    }
    else {
        cout << "You lost!" << endl;
    }
    return 0;
}
//bool password(std::string difficulty);