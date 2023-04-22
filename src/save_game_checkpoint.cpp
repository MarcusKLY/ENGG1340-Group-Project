// save_game_checkpoint.cpp

#include "../header/save_game_checkpoint.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/player.h"
#include "../header/choose_event.h"
#include "../header/main_menu.h"

#include "../header/story_background.h"
#include "../header/CYM.h"
#include "../header/CYM_Toilet.h"
#include "../header/Knowles.h"
#include "../header/Library.h"
#include "../header/Happy_Park.h"
#include "../header/Stairs.h"
#include "../header/Escalator.h"
#include "../header/Final_Boss.h"


#include <iostream>
#include <string>

using namespace std;

int save_game(string reached_checkpoint, string player_name)
{
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);
    player_info.checkpoint = reached_checkpoint;
    player_manager.update_player(player_info);
    player_manager.save_players("saves.sav");

    vector<string> items;
    items.push_back("Continue");
    items.push_back("Return to main menu");
    string question = "Game saved at checkpoint " + reached_checkpoint +". Do you want to continue?";
    int cgame = choose_event(items, question);
    items.clear(); // Clear the vector
    if (cgame == 0)
    {
        if (reached_checkpoint == "Story Background")
        {
            story_background(player_name);
        }
        else if (reached_checkpoint == "CYM")
        {
            CYM(player_name);
        }
        else if (reached_checkpoint == "CYM Toilet")
        {
            CYM_Toilet(player_name);
        }
        else if (reached_checkpoint == "Knowles")
        {
            Knowles(player_name);
        }
        else if (reached_checkpoint == "Library")
        {
            Library(player_name);
        }
        else if (reached_checkpoint == "Happy Park")
        {
            Happy_Park(player_name);
        }
        else if (reached_checkpoint == "Stairs")
        {
            Stairs(player_name);
        }
        else if (reached_checkpoint == "Escalator")
        {
            Escalator(player_name);
        }
        else if (reached_checkpoint == "Final Boss")
        {
            Final_Boss(player_name); //buff
        }
        return 0;
    }
    if (cgame == 1)
    {
        main_menu();
        return 0;
    }
}