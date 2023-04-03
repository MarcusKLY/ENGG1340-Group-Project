// load_checkpoint.cpp

#include "../header/load_checkpoint.h"
#include "../header/player.h"
#include "../header/story_background.h"

#include <iostream>
#include <string>

using namespace std;

// load the checkpoint of the player
void load_checkpoint(string player_name)
{
    cout << "\033[2J\033[1;1H"; // clear screen and move cursor to top-left corner
    PlayerInfo player_info;
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    player_info = player_manager.get_player(player_name);
    string checkpoint = player_info.checkpoint;
    string user_name = player_info.user_name;
    if (checkpoint == "Story Background")
    {
        story_background(user_name);
    }
}