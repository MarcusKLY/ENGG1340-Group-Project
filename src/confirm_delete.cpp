// comfirm_delete.cpp

#include "../header/confirm_delete.h"
#include "../header/player.h"
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

// draw a window with the given dimensions for comfirm delete menu
void drawWindowCD(int x, int y, int width, int height)
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

// draw the comfirm delete menu
void drawMenuCD(int selectedItem)
{
    cout << "\033[2J\033[1;1H"; // clear screen and move cursor to top-left corner

    int windowX = (80 - WINDOW_WIDTH) / 2; // center the window horizontally
    int windowY = 1;                       // center the window vertically
    drawWindowCD(windowX, windowY, WINDOW_WIDTH, WINDOW_HEIGHT);

    string title = "Comfirm Delete?";
    int titleX = windowX + 5;                                   // move title 10 characters to the left
    cout << "\033[" << windowY + 1 << ";" << titleX - 1 << "H"; // move cursor to title position
    cout << title << endl;

    string items[3] = {"Confirm Delete!", "Noooooo!"};
    for (int i = 0; i < 2; i++)
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
    cout << "\n\n\n\n\n\n*Use arrow keys to navigate, enter to select" << endl;
}

// comfirm delete menu
int confirm_delete(string player_name)
{
    PlayerManager pm;
    PlayerInfo player_info;
    pm.load_players("saves.sav");
    player_info = pm.get_player(player_name);
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // save terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // turn off line buffering and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply new terminal settings

    int selectedItem = 0;
    bool done = false;
    while (!done)
    {
        drawMenuCD(selectedItem);
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
                                    selectedItem = 1;
                                }
                            }
                            else if (ch == 'B')
                            { // down arrow
                                selectedItem++;
                                if (selectedItem > 1)
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
                case 0: // Delete
                    done = true;
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
                    pm.delete_player(player_name);
                    break;
                case 1: // Back
                    done = true;
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
                    break;
                }
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
    return 0;
}
