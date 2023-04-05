// CYM.cpp

#include "../header/CYM.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/player.h"
#include "../header/choose_event.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int CYM(string player_name)
{
    system("clear"); // clear screen
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);
    char_typewriter("You have arrived at the CYM", italic_green);
    char_typewriter("Just when you step into the building, you see someone next to you", italic_green);
    char_typewriter("There is a old lady with a strange smile sitting on wheelchair 🦽 and doing nothing", italic_green);
    char_typewriter("She looks familiar, you seem to have seen her in some photos\n", italic_green);
    bool is_valid = false;
    while (!is_valid)
    {
        vector<string> items;
        items.push_back("Talk to her");
        items.push_back("Ignore her and continue walking");
        int choice = choose_event(items, "You are not sure if you should talk to her or not...");
        items.clear(); // Clear the vector
        switch (choice)
        {
        case 0:
            // code to handle "Talk to her" option
            char_typewriter("\nYou walk towards her and ask her if she is ok", italic_green);
            char_typewriter("You🙎: Excuse me, are you ok?", bold_magenta);
            char_typewriter("Old lady👵: Hi young people...", bold_magenta);
            is_valid = true;
            break;
        case 1:
            // code to handle "Continue staying without leaving" option
            is_valid = true;
            break;
        }
    }

    cout
        << "CYM";
    this_thread::sleep_for(chrono::seconds(2));
}
