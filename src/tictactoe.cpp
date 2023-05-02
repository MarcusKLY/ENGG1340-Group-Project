#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../header/output_style.h"
#include "../header/tictactoe.h"

using namespace std;

const int SIZE = 3;
enum class Player { none, human, computer };

struct Board {
    vector<vector<Player>> data;

    Board() {
        data.resize(SIZE, vector<Player>(SIZE, Player::none));
    }

    bool isFull() const {
        for (const auto &row : data)
            for (const auto &cell : row)
                if (cell == Player::none) return false;
        return true;
    }

    void display() const {
        cout << "\033[35m=====================\033[0m"<<endl;
        cout << endl;
        for (const auto &row : data) {
            for (const auto &cell : row) {
                switch (cell) {
                    case Player::human: cout <<"    "<< "\033[1;32mO\033[0m"; break;
                    case Player::computer: cout <<"    "<< "\033[1;31mX\033[0m"; break;
                    default: cout <<"    "<< "-";
                }
                cout << " ";
            }
            cout << endl;
            cout << endl;
        }
        cout << "\033[35m=====================\033[0m"<<endl ;
    }

    bool checkWin(Player player) const {
        for (int i = 0; i < SIZE; ++i) {
            if ((data[i][0] == player && data[i][1] == player && data[i][2] == player) ||
                (data[0][i] == player && data[1][i] == player && data[2][i] == player))
                return true;
        }
        return (data[0][0] == player && data[1][1] == player && data[2][2] == player) ||
               (data[0][2] == player && data[1][1] == player && data[2][0] == player);
    }
};

bool isValidInput(const string &input) {
    if (input.length() != 2) return false;
    for (char c : input) {
        if (c < '0' || c > '2') return false;
    }
    return true;
}

void humanMove(Board &board) {
    int x, y;
    string input;
    bool validMove;

    do {
        cout << "Enter your move (row and column) "<<endl;
        cout << "Range(0~2)(e.g., 01 for row 0 and column 1): ";
        cin >> input;
        validMove = false;

        if (isValidInput(input)) {
            x = input[0] - '0';
            y = input[1] - '0';

            if (board.data[x][y] == Player::none) {
                validMove = true;
            } else {
                cout << "\033[1;31mTHE POSISTION HAS ALREADY BE CHOSEN !! ENTER AGAIN!!\033[0;0m" << endl;
            }
        } else {
            cout << "\033[1;31mInvalid input. Please enter a valid move\033[0;0m" << endl;
        }

    } while (!validMove);

    board.data[x][y] = Player::human;
}




void computerMove(Board &board) {
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (board.data[x][y] != Player::none);
    board.data[x][y] = Player::computer;
}

int playTicTacToe() {
    srand(time(nullptr));
    Board board;
    Player currentPlayer = Player::human;

    while (!board.isFull() && !board.checkWin(Player::human) && !board.checkWin(Player::computer)) {
        board.display();
        if (currentPlayer == Player::human) {
            humanMove(board);
            currentPlayer = Player::computer;
        } else {
            computerMove(board);
            currentPlayer = Player::human;
        }
    }

    board.display();

    if (board.checkWin(Player::human)) {
        cout << "\033[1;32mThe door is unlocked!!\033[0m" << endl;
        return 1;

    } else if (board.checkWin(Player::computer)) {
        cout << "\033[1;31mYou failed to unlock the door!\033[0m" << endl;
        return 0;
    } else {
        cout << "\033[1;31mDRAW!! You failed to unlock the door!\033[0m" << endl;
        return 0;
    }   

    return 0;
}
int tictactoe()
{
    int winner = playTicTacToe();
    return winner;
}