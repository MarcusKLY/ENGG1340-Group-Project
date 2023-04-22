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

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int Happy_Park(string player_name)
{
    system("clear");
    this_thread::sleep_for(chrono::seconds(2));
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);
    char_typewriter("You then walk to the Happy Park", italic_green);
    walking_animation();
    char_typewriter("There is a sign in front of you:", italic_green);
    char_typewriter("  ←  Stairs   ", bold_background_cyan);
    char_typewriter("  escalators ➡ ", bold_background_cyan);

    vector<string> items;
    items.push_back("Left");
    items.push_back("Right");
    int choice = choose_event(items, "Which way do you want to go?");
    items.clear(); // Clear the vector

    if (choice == 0)
    {
        player_info.checkpoint = "Stairs";
        player_manager.update_player(player_info);
        player_manager.save_players("saves.sav");
        items.push_back("Continue");
        items.push_back("Return to main menu");
        string question = "Game saved at checkpoint Stairs. Do you want to continue?";
        int cgame = choose_event(items, question);
        items.clear(); // Clear the vector
        if (cgame == 0)
        {
            Stairs(player_name);
            return 0;
        }
        if (cgame == 1)
        {
            main_menu();
            return 0;
        }
    }
    else if (choice == 1)
    {
        player_info.checkpoint = "Escalator";
        player_manager.update_player(player_info);
        player_manager.save_players("saves.sav");
        items.push_back("Continue");
        items.push_back("Return to main menu");
        string question = "Game saved at checkpoint Escalator. Do you want to continue?";
        int cgame = choose_event(items, question);
        items.clear(); // Clear the vector
        if (cgame == 0)
        {
            Escalator(player_name); 
            return 0;
        }
        if (cgame == 1)
        {
            main_menu();
            return 0;
        }
    }

    return 0;
}