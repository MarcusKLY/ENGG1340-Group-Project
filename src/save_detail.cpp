// load_game_menu.cpp

#include "../header/save_detail.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/confirm_delete.h"
#include "../header/load_checkpoint.h"
#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

using namespace std;

const int WINDOW_WIDTH = 50;
const int WINDOW_HEIGHT = 10;

// draw a window with the given dimensions for load game menu
void drawWindowSD(int x, int y, int width, int height)
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

// draw the load game menu
void drawMenuSD(int selectedItem, string player_name)
{
    PlayerInfo player_info;
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    player_info = player_manager.get_player(player_name);

    cout << "\033[2J\033[1;1H"; // clear screen and move cursor to top-left corner

    int windowX = (80 - WINDOW_WIDTH) / 2; // center the window horizontally
    int windowY = 1;                       // center the window vertically
    drawWindowSD(windowX, windowY, WINDOW_WIDTH, WINDOW_HEIGHT);

    string title = "Save Detail";
    int titleX = windowX + 5;                               // move title 10 characters to the left
    cout << "\033[" << windowY + 1 << ";" << titleX << "H"; // move cursor to title position
    cout << title;
    cout << "\n\n|            Difficulty: " << player_info.difficulty << "\n|            Save Checkpoint: " << player_info.checkpoint << endl;
    cout << endl;

    string items[3] = {"Load Game", "Delete", "Back"};
    for (int i = 0; i < 3; i++)
    {
        cout << "\033[" << windowY + 6 + i << ";" << windowX + 2 << "H"; // move cursor to left side of menu item
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
    cout << "\n\n*Use arrow keys to navigate, enter to select" << endl;
}

int save_detail(string player_name)
{
    PlayerManager player_manager;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // save terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // turn off line buffering and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply new terminal settings

    int selectedItem = 0;
    bool done = false;
    while (!done)
    {
        drawMenuSD(selectedItem, player_name);
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
                switch (selectedItem)
                {
                case 0: // First slot
                    load_checkpoint(player_name);
                    done = true;
                    break;
                case 1: // Second slot
                    confirm_delete(player_name);
                    player_manager.load_players("saves.sav");
                    done = true;
                    break;
                case 2: // Third Slot
                    done = true;
                    break;
                }
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
    return 0;
}
