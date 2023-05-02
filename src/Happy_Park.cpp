// Happy_Park.cpp

#include "../header/Happy_Park.h"
#include "../header/choose_event.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/main_menu.h"
#include "../header/battle.h"
#include "../header/Stairs.h"
#include "../header/Escalator.h"
#include "../header/save_game_checkpoint.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// input: player name
// function for the story chapter "Happy Park"
int Happy_Park(string player_name)
{
    system("clear");
    this_thread::sleep_for(chrono::seconds(1));
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);
    char_typewriter("You then walk to the Happy Park", italic_green);
    walking_animation();
    char_typewriter("There is a sign in front of you:", italic_green);
    char_typewriter("  ←  Stairs    ", bold_background_cyan);
    char_typewriter("  Escalators ➡ \n", bold_background_cyan);

    vector<string> items;
    items.push_back("Left");
    items.push_back("Right");
    int choice = choose_event(items, "Which way do you want to go?");
    items.clear(); // Clear the vector

    if (choice == 0)
    {
        // option "Left" chosen
        char_typewriter("\nYou head to the stairs\n", italic_green);
        save_game("Stairs", player_name); // "Happy_Park" ended -> save game
    }
    else if (choice == 1)
    {
        // option "Right" chosen
        char_typewriter("\nYou head to the escalators\n", italic_green);
        save_game("Escalator", player_name); // "Happy_Park" ended -> save game
    }

    return 0;
}