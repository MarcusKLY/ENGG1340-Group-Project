//tictactoe.cpp
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

enum class Player { None, Human, Computer };

struct Board {
    std::vector<std::vector<Player>> cells;
    Board() : cells(3, std::vector<Player>(3, Player::None)) {}

    void print() {
        for (const auto &row : cells) {
            for (const auto &cell : row) {
                if (cell == Player::None) std::cout << '-';
                else if (cell == Player::Human) std::cout << 'X';
                else std::cout << 'O';
            }
            std::cout << std::endl;
        }
    }

    bool makeMove(int row, int col, Player player) {
        if (cells[row][col] == Player::None) {
            cells[row][col] = player;
            return true;
        }
        return false;
    }
};

Player checkWinner(const Board &board);
Player getOpponent(Player player);
void humanTurn(Board &board);
void computerTurn(Board &board);


Player playTicTacToe(){
    srand(time(0));

    Board board;
    Player currentPlayer = Player::Human;

    while (checkWinner(board) == Player::None) {
        board.print();
        if (currentPlayer == Player::Human) {
            humanTurn(board);
        } else {
            computerTurn(board);
        }
        currentPlayer = getOpponent(currentPlayer);
    }

    board.print();
    if (checkWinner(board) == Player::Human) {
        std::cout << "You won!" << std::endl;
    } else {
        std::cout << "The computer won!" << std::endl;
    }

}
int main(){
    Player winner = playTicTacToe();
    return 0;
}

Player checkWinner(const Board &board) {
    // Check rows
    for (int row = 0; row < 3; ++row) {
        if (board.cells[row][0] != Player::None &&
            board.cells[row][0] == board.cells[row][1] &&
            board.cells[row][1] == board.cells[row][2]) {
            return board.cells[row][0];
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (board.cells[0][col] != Player::None &&
            board.cells[0][col] == board.cells[1][col] &&
            board.cells[1][col] == board.cells[2][col]) {
            return board.cells[0][col];
        }
    }

    // Check diagonals
    if (board.cells[0][0] != Player::None &&
        board.cells[0][0] == board.cells[1][1] &&
        board.cells[1][1] == board.cells[2][2]) {
        return board.cells[0][0];
    }

    if (board.cells[0][2] != Player::None &&
        board.cells[0][2] == board.cells[1][1] &&
        board.cells[1][1] == board.cells[2][0]) {
        return board.cells[0][2];
    }

    // No winner found
    return Player::None;
}

Player getOpponent(Player player) {
    return (player == Player::Human) ? Player::Computer : Player::Human;
}

void humanTurn(Board &board) {
    int row, col;
    do {
        std::cout << "Enter your move (1.row(0-2) and 'Enter' 2.col(0-2) and 'Enter'): ";
        std::cin >> row >> col;
    } while (!board.makeMove(row, col, Player::Human));
}

void computerTurn(Board &board) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!board.makeMove(row, col, Player::Computer));
}