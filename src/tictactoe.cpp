// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include "../header/output_style.h"
#include "../header/tictactoe.h"
#include "../header/random#generator.h"

// using namespace std;

// const int SIZE = 3;
// enum class Player { none, human, computer };

// struct Board {
//     vector<vector<Player>> data;

//     Board() {
//         data.resize(SIZE, vector<Player>(SIZE, Player::none));
//     }

//     bool isFull() const {
//         for (const auto &row : data)
//             for (const auto &cell : row)
//                 if (cell == Player::none) return false;
//         return true;
//     }

//     void display() const {
//         cout << "\033[35m=====================\033[0m"<<endl;
//         cout << endl;
//         for (const auto &row : data) {
//             for (const auto &cell : row) {
//                 switch (cell) {
//                     case Player::human: cout <<"    "<< "\033[1;32mO\033[0m"; break;
//                     case Player::computer: cout <<"    "<< "\033[1;31mX\033[0m"; break;
//                     default: cout <<"    "<< "-";
//                 }
//                 cout << " ";
//             }
//             cout << endl;
//             cout << endl;
//         }
//         cout << "\033[35m=====================\033[0m"<<endl ;
//     }

//     bool checkWin(Player player) const {
//         for (int i = 0; i < SIZE; ++i) {
//             if ((data[i][0] == player && data[i][1] == player && data[i][2] == player) ||
//                 (data[0][i] == player && data[1][i] == player && data[2][i] == player))
//                 return true;
//         }
//         return (data[0][0] == player && data[1][1] == player && data[2][2] == player) ||
//                (data[0][2] == player && data[1][1] == player && data[2][0] == player);
//     }
// };

// bool isValidInput(const string &input) {
//     if (input.length() != 2) return false;
//     for (char c : input) {
//         if (c < '0' || c > '2') return false;
//     }
//     return true;
// }

// void humanMove(Board &board) {
//     int x, y;
//     string input;
//     bool validMove;

//     do {
//         cout << "Enter your move (row and column) "<<endl;
//         cout << "Range(0~2)(e.g., 01 for row 0 and column 1): ";
//         cin >> input;
//         validMove = false;

//         if (isValidInput(input)) {
//             x = input[0] - '0';
//             y = input[1] - '0';

//             if (board.data[x][y] == Player::none) {
//                 validMove = true;
//             } else {
//                 cout << "\033[1;31mTHE POSISTION HAS ALREADY BE CHOSEN !! ENTER AGAIN!!\033[0;0m" << endl;
//             }
//         } else {
//             cout << "\033[1;31mInvalid input. Please enter a valid move\033[0;0m" << endl;
//         }

//     } while (!validMove);

//     board.data[x][y] = Player::human;
// }

// void computerMove(Board &board) {
//     int x, y;
//     do {
//         x = rand() % SIZE;
//         y = rand() % SIZE;
//     } while (board.data[x][y] != Player::none);
//     board.data[x][y] = Player::computer;
// }

// int playTicTacToe() {
//     srand(time(nullptr));
//     Board board;
//     Player currentPlayer = Player::human;

//     while (!board.isFull() && !board.checkWin(Player::human) && !board.checkWin(Player::computer)) {
//         board.display();
//         if (currentPlayer == Player::human) {
//             humanMove(board);
//             currentPlayer = Player::computer;
//         } else {
//             computerMove(board);
//             currentPlayer = Player::human;
//         }
//     }

//     board.display();

//     if (board.checkWin(Player::human)) {
//         cout << "\033[1;32mThe door is unlocked!!\033[0m" << endl;
//         return 1;

//     } else if (board.checkWin(Player::computer)) {
//         cout << "\033[1;31mYou failed to unlock the door!\033[0m" << endl;
//         return 0;
//     } else {
//         cout << "\033[1;31mDRAW!! You failed to unlock the door!\033[0m" << endl;
//         return 0;
//     }

//     return 0;
// }
// int tictactoe()
// {
//     int winner = playTicTacToe();
//     return winner;
// }

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

// Print the current state of the board with 'X' and 'O' characters inside the boxes
void printBoard(const vector<char> &board)
{
    cout << "\033[1m";
    cout << "     |     |     " << endl;
    cout << "  " << (board[0] == 'X' ? "\033[1;32mX\033[0m" : (board[0] == 'O' ? "\033[1;31mO\033[0m" : "\033[1m1\033[0m")) << "  |  "
         << (board[1] == 'X' ? "\033[1;32mX\033[0m" : (board[1] == 'O' ? "\033[1;31mO\033[0m" : "\033[1m2\033[0m")) << "  |  "
         << (board[2] == 'X' ? "\033[1;32mX\033[0m" : (board[2] == 'O' ? "\033[1;31mO\033[0m" : "\033[1m3\033[0m")) << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << (board[3] == 'X' ? "\033[1;32mX\033[0m" : (board[3] == 'O' ? "\033[1;31mO\033[0m" : "\033[1m4\033[0m")) << "  |  "
         << (board[4] == 'X' ? "\033[1;32mX\033[0m" : (board[4] == 'O' ? "\033[1;31mO\033[0m" : "\033[1m5\033[0m")) << "  |  "
         << (board[5] == 'X' ? "\033[1;32mX\033[0m" : (board[5] == 'O' ? "\033[1;31mO\033[0m" : "\033[1m6\033[0m")) << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << (board[6] == 'X' ? "\033[1;32mX\033[0m" : (board[6] == 'O' ? "\033[1;31mO\033[0m" : "\033[1m7\033[0m")) << "  |  "
         << (board[7] == 'X' ? "\033[1;32mX\033[0m" : (board[7] == 'O' ? "\033[1;31mO\033[0m" : "\033[1m8\033[0m")) << "  |  "
         << (board[8] == 'X' ? "\033[1;32mX\033[0m" : (board[8] == 'O' ? "\033[1;31mO\033[0m" : "\033[1m9\033[0m")) << "  " << endl;
    cout << "     |     |     " << endl
         << endl;
}

// Check if the game is over (win or draw)
int checkGame(const vector<char> &board)
{
    // Check rows
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] != ' ' && board[i] == board[i + 1] && board[i + 1] == board[i + 2])
            return 1;
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i] != ' ' && board[i] == board[i + 3] && board[i + 3] == board[i + 6])
            return 1;
    }
    // Check diagonals
    if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8])
        return 1;
    if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6])
        return 1;
    // Check if board is full (draw)
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
            return 0;
    }
    return -1;
}

// Get the computer's move (easy difficulty)
int getComputerMoveEasyNormal(const vector<char> &board)
{
    // Choose a random empty cell
    int move;
    do
    {
        move = randnum() % 9;
    } while (board[move] != ' ');
    return move;
}

// Get the computer's move (normal difficulty)
int getComputerMoveHard(const vector<char> &board)
{
    // Check if computer can win in one move
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            vector<char> boardCopy = board;
            boardCopy[i] = 'O';
            if (checkGame(boardCopy) == 1)
                return i;
        }
    }
    // Check if player can win in one move
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            vector<char> boardCopy = board;
            boardCopy[i] = 'X';
            if (checkGame(boardCopy) == 1)
                return i;
        }
    }
    // Choose a random empty cell
    int move;
    do
    {
        move = randnum() % 9;
    } while (board[move] != ' ');
    return move;
}

// Play Tic Tac Toe with the given difficulty level
int tictactoe(string difficulty)
{
    cout << (difficulty == "Normal") << endl;
    // Initialize board
    vector<char> board(9, ' ');
    // Print instructions
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "\033[1mYou are \033[0m\033[1;32mX\033[0m\033[1m, and the Door is \033[0m\033[1;31mO\033[0m\033[1m.\033[0m" << endl;
    cout << "Enter a number from 1 to 9 to make your move." << endl;
    // Print initial board
    printBoard(board);
    // Main game loop
    while (true)
    {
        // Player's turn
        int playerMove;
        cout << "Your move: ";
        while (true)
        {
            cin >> playerMove;
            if (cin.fail() || playerMove < 1 || playerMove > 9 || board[playerMove - 1] != ' ')
            {
                cout << "\033[7m\033[1;31mInvalid move. Please try again.\033[0m" << endl;
                cout << "Your move: ";
                cin.clear();                                         // clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore remaining characters in input stream
                continue;
            }
            break; // valid move entered, break out of loop
        }
        board[playerMove - 1] = 'X';
        printBoard(board);
        int result = checkGame(board);
        if (result == 1)
        {
            cout << "Congratulations! You win the Door!" << endl;
            return 1;
        }
        else if (result == -1)
        {
            cout << "It's a draw and you fail to unlock the door." << endl;
            return 0;
        }
        // Computer's turn
        int computerMove;
        if (difficulty == "Easy") // Easy
            computerMove = getComputerMoveEasyNormal(board);
        else if (difficulty == "Normal") // Normal
            computerMove = getComputerMoveEasyNormal(board);
        else if (difficulty == "Hard") // Hard
            computerMove = getComputerMoveHard(board);
        cout << "Door's move: " << computerMove + 1 << endl;
        board[computerMove] = 'O';
        printBoard(board);
        result = checkGame(board);
        if (result == 1)
        {
            cout << "Sorry, you lose and fail to unlock the door" << endl;
            return 0;
        }
        else if (result == -1)
        {
            cout << "It's a draw." << endl;
            return 0;
        }
    }
}