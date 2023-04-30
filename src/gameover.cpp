// gameover.cpp

#include "../header/gameover.h"
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

// input: checkpoint name, player name
// call the function of the story part where the player died if the player choose to continue, otherwise return to main menu
int gameover(string checkpoint, string player_name)
{
    char_typewriter(".", bold_red);
    char_typewriter(".", bold_red);
    char_typewriter(".", bold_red);
    char_typewriter("YOU DIED", bold_background_red);
    char_typewriter("Game Over", bold_red);

    this_thread::sleep_for(chrono::seconds(2));

    vector<string> items;
    items.push_back("Load Game");
    items.push_back("Return to main menu");
    string question = "Game saved at checkpoint " + checkpoint + ". Do you want to continue?";
    int cgame = choose_event(items, question);
    items.clear(); // Clear the vector
    if (cgame == 0) // Continue
    {
        if (checkpoint == "Story Background")
        {
            story_background(player_name);
        }
        else if (checkpoint == "CYM")
        {
            CYM(player_name);
        }
        else if (checkpoint == "CYM Toilet")
        {
            CYM_Toilet(player_name);
        }
        else if (checkpoint == "Knowles")
        {
            Knowles(player_name);
        }
        else if (checkpoint == "Library")
        {
            Library(player_name);
        }
        else if (checkpoint == "Happy Park")
        {
            Happy_Park(player_name);
        }
        else if (checkpoint == "Stairs")
        {
            Stairs(player_name);
        }
        else if (checkpoint == "Escalator")
        {
            Escalator(player_name);
        }
        else if (checkpoint == "Final Boss")
        {
            Final_Boss(player_name);
        }
        return 0;
    }
    if (cgame == 1) // Return to main menu
    {
        main_menu();
        return 0;
    }
    return 0;
}