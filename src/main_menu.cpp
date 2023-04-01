// main_menu.cpp

#include "../header/main_menu.h"
#include "../header/choose_difficulty.h"
#include "../header/load_game_menu.h"
#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

const int WINDOW_WIDTH = 50;
const int WINDOW_HEIGHT = 10;

void drawWindowM(int x, int y, int width, int height)
{
    cout << "\033[" << y << ";" << x << "H"; // move cursor to top-left corner of window
    cout << endl;
    cout << "+" << string(width - 2, '-') << "+" << endl; // top border
    for (int i = 0; i < height - 2; i++)
    {
        cout << "|" << string(width - 2, ' ') << "|" << endl; // sides
    }
    cout << "+" << string(width - 2, '-') << "+" << endl; // bottom border
}

void drawMenuM(int selectedItem)
{
    cout << "\033[2J\033[1;1H"; // clear screen and move cursor to top-left corner

    int windowX = (80 - WINDOW_WIDTH) / 2; // center the window horizontally
    int windowY = 1;                       // center the window vertically
    drawWindowM(windowX, windowY, WINDOW_WIDTH, WINDOW_HEIGHT);

    string title = "Main Menu";
    int titleX = windowX + 5;                               // move title 10 characters to the left
    cout << "\033[" << windowY + 1 << ";" << titleX << "H"; // move cursor to title position
    cout << title << endl;

    string items[3] = {"New Game", "Load Game", "Exit"};
    for (int i = 0; i < 3; i++)
    {
        cout << "\033[" << windowY + 3 + i << ";" << windowX + 2 << "H"; // move cursor to left side of menu item
        if (i == selectedItem)
        {
            cout << "> "; // highlight selected item
        }
        else
        {
            cout << "  ";
        }
        cout << items[i] << endl;
    }
    cout << "\n\n\n\n\n*Use arrow keys to navigate, enter to select" << endl;
}

int main_menu()
{
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // save terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // turn off line buffering and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply new terminal settings

    int selectedItem = 0;
    bool done = false;
    while (!done)
    {
        drawMenuM(selectedItem);
        char ch;
        if (read(STDIN_FILENO, &ch, 1) == 1)
        { // if a character was read
            if (ch == '\033')
            { // escape sequence
                if (read(STDIN_FILENO, &ch, 1) == 1)
                {
                    if (ch == '[')
                    {
                        if (read(STDIN_FILENO, &ch, 1) == 1)
                        {
                            if (ch == 'A')
                            { // up arrow
                                selectedItem--;
                                if (selectedItem < 0)
                                {
                                    selectedItem = 2;
                                }
                            }
                            else if (ch == 'B')
                            { // down arrow
                                selectedItem++;
                                if (selectedItem > 2)
                                {
                                    selectedItem = 0;
                                }
                            }
                        }
                    }
                }
            }
            else if (ch == '\n')
            { // Enter key
                int temp = 1;
                switch (selectedItem)
                {
                case 0: // New Game
                    choose_difficulty();
                    break;
                case 1: // Load Game
                    while (true)
                    {
                        temp = load_game_menu();
                        if (temp == 0)
                        {
                            main_menu();
                        }
                    }
                    break;
                case 2:
                    cout << "\033[2J\033[1;1H";
                    cout << "Exiting..." << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                    done = true;
                    abort();
                    break;
                }
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
    return 0;
}
