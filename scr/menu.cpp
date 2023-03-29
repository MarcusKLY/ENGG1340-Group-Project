#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <chrono>
#include <thread>

using namespace std;
const int WINDOW_WIDTH = 50;
const int WINDOW_HEIGHT = 10;

void drawWindow(int x, int y, int width, int height) {
    cout << "\033[" << y << ";" << x << "H"; // move cursor to top-left corner of window
    cout << endl;
    cout << "+" << std::string(width - 2, '-') << "+" << std::endl; // top border
    for (int i = 0; i < height - 2; i++) {
        std::cout << "|" << std::string(width - 2, ' ') << "|" << std::endl; // sides
    }
    std::cout << "+" << std::string(width - 2, '-') << "+" << std::endl; // bottom border
}


void drawMenu(int selectedItem) {
    std::cout << "\033[2J\033[1;1H"; // clear screen and move cursor to top-left corner
    
    int windowX = (80 - WINDOW_WIDTH) / 2; // center the window horizontally
    int windowY = (24 - WINDOW_HEIGHT) / 2; // center the window vertically
    drawWindow(windowX, windowY, WINDOW_WIDTH, WINDOW_HEIGHT);

    std::string title = "Main Menu";
    int titleX = windowX + 5; // move title 10 characters to the left
    std::cout << "\033[" << windowY + 1 << ";" << titleX << "H"; // move cursor to title position
    std::cout << title << std::endl;

    std::string items[3] = {"New Game", "Load Game", "Exit"};
    for (int i = 0; i < 3; i++) {
        std::cout << "\033[" << windowY + 3 + i << ";" << windowX + 2 << "H"; // move cursor to left side of menu item
        if (i == selectedItem) {
            std::cout << "> "; // highlight selected item
        } else {
            std::cout << "  ";
        }
        std::cout << items[i] << std::endl;
    }
}


int main() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // save terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // turn off line buffering and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply new terminal settings

    int selectedItem = 0;
    bool done = false;
    while (!done) {
        drawMenu(selectedItem);
        char ch;
        if (read(STDIN_FILENO, &ch, 1) == 1) { // if a character was read
            if (ch == '\033') { // escape sequence
                if (read(STDIN_FILENO, &ch, 1) == 1) {
                    if (ch == '[') {
                        if (read(STDIN_FILENO, &ch, 1) == 1) {
                            if (ch == 'A') { // up arrow
                                selectedItem--;
                                if (selectedItem < 0) {
                                    selectedItem = 2;
                                }
                            } else if (ch == 'B') { // down arrow
                                selectedItem++;
                                if (selectedItem > 2) {
                                    selectedItem = 0;
                                }
                            }
                        }
                    }
                }
            } else if (ch == '\n') { // Enter key
                switch (selectedItem) {
                    case 0:
                        std::cout << "Starting new game..." << std::endl;
                        // TODO: Add code to start new game
                        break;
                    case 1:
                        std::cout << "Loading game..." << std::endl;
                        // TODO: Add code to load game
                        break;
                    case 2:
                        std::cout << "\033[2J\033[1;1H";
                        std::cout << "Exiting..." << std::endl;
                        this_thread::sleep_for(chrono::seconds(1));
                        done = true;
                        break;
                }
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
    return 0;
}