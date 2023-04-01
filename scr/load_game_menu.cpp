//load_game_menu.cpp

#include "../header/choose_difficulty.h"
#include "../header/main_menu.h"
#include "../header/load_game_menu.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
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
vector<string> player_names;

void load_player_names() {
    player_names.clear();
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    int i = 0;
    for (const auto& player : player_manager.get_all_players()) {
        player_names.push_back(player.user_name);
        i++;
    }
    if (i<3){
        for (int j = i; j<3; j++){
            player_names.push_back("Empty Slot");
        }
    }
    player_names.push_back("Back");
}


const int WINDOW_WIDTH = 50;
const int WINDOW_HEIGHT = 10;


// draw a window with the given dimensions for load game menu
void drawWindowL(int x, int y, int width, int height) {
    cout << "\033[" << y << ";" << x << "H"; // move cursor to top-left corner of window
    cout << endl;
    cout << "+" << string(width - 2, '-') << "+" << endl; // top border
    for (int i = 0; i < height - 2; i++) {
        cout << "|" << string(width - 2, ' ') << "|" << endl; // sides
    }
    cout << "+" << string(width - 2, '-') << "+" << endl; // bottom border
}


// draw the load game menu
void drawMenuL(int selectedItem) {
    cout << "\033[2J\033[1;1H"; // clear screen and move cursor to top-left corner
    
    int windowX = (80 - WINDOW_WIDTH) / 2; // center the window horizontally
    int windowY = 1; // center the window vertically
    drawWindowL(windowX, windowY, WINDOW_WIDTH, WINDOW_HEIGHT);

    string title = "Load Game";
    int titleX = windowX + 5; // move title 10 characters to the left
    cout << "\033[" << windowY + 1 << ";" << titleX << "H"; // move cursor to title position
    cout << title << endl;

    for (int i = 0; i < static_cast<int>(player_names.size()); i++) {
        cout << "\033[" << windowY + 3 + i << ";" << windowX + 2 << "H"; // move cursor to left side of menu item
        if (i == selectedItem) {
            cout << "> "; // highlight selected item
        } else {
            cout << "  ";
        }
        cout << player_names[i] << endl;
    }
}


int load_game_menu() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // save terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // turn off line buffering and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply new terminal settings

    load_player_names();
    int selectedItem = 0;
    bool done = false;
    while (!done) {
        drawMenuL(selectedItem);
        char ch;
        if (read(STDIN_FILENO, &ch, 1) == 1) { // if a character was read
            if (ch == '\033') { // escape sequence
                if (read(STDIN_FILENO, &ch, 1) == 1) {
                    if (ch == '[') {
                        if (read(STDIN_FILENO, &ch, 1) == 1) {
                            if (ch == 'A') { // up arrow
                                selectedItem--;
                                if (selectedItem < 0) {
                                    selectedItem = 3;
                                }
                            } else if (ch == 'B') { // down arrow
                                selectedItem++;
                                if (selectedItem > 3) {
                                    selectedItem = 0;
                                }
                            }
                        }
                    }
                }
            } else if (ch == '\n') { // Enter key
                switch (selectedItem) {
                    case 0: // First slot
                        if (player_names [0] == "Empty Slot"){
                            color_print("\n\n\n\n              No save file found!", bold_red);
                            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        }
                        break;
                    case 1: // Second slot
                        if (player_names [1] == "Empty Slot"){
                            color_print("\n\n\n\n              No save file found!", bold_red);
                            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        }
                        // TODO: Add code to load game
                        break;
                    case 2: // Third Slot
                        if (player_names [2] == "Empty Slot"){
                            color_print("\n\n\n\n              No save file found!", bold_red);
                            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        }
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
