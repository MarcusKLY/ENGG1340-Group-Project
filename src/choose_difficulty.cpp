// choose_difficulty.cpp

#include "../header/choose_difficulty.h"
#include "../header/main_menu.h"
#include "../header/story_background.h"
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

void drawWindowD(int x, int y, int width, int height)
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

void drawMenuD(int selectedItem)
{
    cout << "\033[2J\033[1;1H"; // clear screen and move cursor to top-left corner

    int windowX = (80 - WINDOW_WIDTH) / 2; // center the window horizontally
    int windowY = 1;                       // center the window vertically
    drawWindowD(windowX, windowY, WINDOW_WIDTH, WINDOW_HEIGHT);

    string title = "Difficulty";
    int titleX = windowX + 5;                               // move title 10 characters to the left
    cout << "\033[" << windowY + 1 << ";" << titleX << "H"; // move cursor to title position
    cout << title << endl;

    string items[4] = {"Easy", "Normal", "Hard", "Back"};
    for (int i = 0; i < 4; i++)
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
        // set text color based on difficulty level
        if (i == 0)
        {
            cout << "\033[32m"; // green for Easy
        }
        else if (i == 1)
        {
            cout << "\033[33m"; // yellow for Normal
        }
        else if (i == 2)
        {
            cout << "\033[31m"; // red for Hard
        }
        cout << items[i] << "\033[0m" << endl; // reset text color
    }
    cout << "\n\n\n\n*Use arrow keys to navigate, enter to select" << endl;
}

int choose_difficulty()
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
        drawMenuD(selectedItem);
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
                                    selectedItem = 3;
                                }
                            }
                            else if (ch == 'B')
                            { // down arrow
                                selectedItem++;
                                if (selectedItem > 3)
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
                switch (selectedItem)
                {
                case 0: // Easy
                    done = true;
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
                    story_background("Easy");
                    break;
                case 1: // Normal
                    done = true;
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
                    story_background("Normal");
                    break;
                case 2: // Hard
                    done = true;
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
                    story_background("Hard");
                    break;
                case 3: // Back
                    done = true;
                    break;
                }
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
    return 0;
}
