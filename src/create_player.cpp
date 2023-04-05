// create_player.cpp

#include "../header/create_player.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/story_background.h"

#include <chrono>
#include <iostream>
#include <string>

using namespace std;

// initializing the game(player's name, difficulty, etc.) and start the game
int create_player(string difficulty) //
{
    system("clear"); // clear screen
    // initialize the player
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    string user_name;
    vector<string> player_names;
    // load the player names from the save file
    int i = 0;
    for (const auto &player : player_manager.get_all_players())
    {
        player_names.push_back(player.user_name);
        i++;
    }
    // check for repeated or empty names
    bool allow = false;
    while (!allow)
    {
        color_print("Please enter your name: ", bold_blue);
        getline(cin, user_name);
        if (user_name == "")
        {
            color_print("Please enter a valid name!", bold_red);
            this_thread::sleep_for(chrono::seconds(1));
            system("clear"); // clear screen
        }
        else
        {
            for (int i = 0; i < player_names.size(); i++)
            {
                if (user_name == player_names[i])
                {
                    color_print("This name has been used. Please enter another name!", bold_red);
                    this_thread::sleep_for(chrono::seconds(1));
                    system("clear"); // clear screen
                    break;
                }
                else if (i == player_names.size() - 1)
                {
                    allow = true;
                }
            }
        }
    }
    player_info.user_name = user_name;
    player_info.user_id = user_name;
    if (difficulty == "Easy")
    {
        player_info.difficulty = "Easy";
        player_info.hp = 80;
    }
    else if (difficulty == "Medium")
    {
        player_info.difficulty = "Medium";
        player_info.hp = 70;
    }
    else if (difficulty == "Hard")
    {
        player_info.difficulty = "Hard";
        player_info.hp = 60;
    }
    player_info.checkpoint = "Story Background";
    player_manager.add_player(player_info);
    player_manager.save_players("saves.sav");
    system("clear"); // clear screen
    story_background(user_name);
}