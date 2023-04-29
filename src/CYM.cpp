// CYM.cpp

#include "../header/CYM.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/player.h"
#include "../header/choose_event.h"
#include "../header/CYM_Toilet.h"
#include "../header/main_menu.h"
#include "../header/battle.h"
#include "../header/save_game_checkpoint.h"
#include "../header/gameover.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// input: player name
// function for the story chapter "CYM"
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
    vector<string> items;
    items.push_back("Talk to her");
    items.push_back("Ignore her and continue walking");
    int leave = choose_event(items, "You are not sure if you should talk to her or not...");
    items.clear(); // Clear the vector
    if (leave == 0)
    {
        // code to handle "Talk to her" option
        char_typewriter("\nYou walk towards her and ask her if she is ok", italic_green);
        char_typewriter("You🙎: Excuse me, are you ok?", bold_magenta);
        char_typewriter("Old Lady👵: Hi young people...", bold_magenta);
        char_typewriter("Old Lady👵: I need to go upstairs, can you help me?\n", bold_magenta);
        items.push_back("Yeah, sure!");
        items.push_back("Nope and byeee~");
        int help = choose_event(items, "Do you want to help her?");
        items.clear(); // Clear the vector
        if (help == 0)
        {
            // code to handle "Yeah, sure!" option
            char_typewriter("\nOld Lady👵: Thank you! You are such a good guy! 😊", bold_magenta);
            char_typewriter("You🙎: No problem, I am just doing my job", bold_magenta);
            char_typewriter("Then you help her push the wheelchair up the escalator↗️", italic_green);
            char_typewriter("As the escalator slowly ascends, you try to remember who this lady is...", italic_green);
            this_thread::sleep_for(chrono::milliseconds(500));
            char_typewriter("Suddenly, the escalator stopped working❗️", italic_green);
            this_thread::sleep_for(chrono::milliseconds(500));
            blink(1, "BANG!", 1000, bold_background_red);
            char_typewriter("You🙎: Oh no! The escalator broke down!", bold_magenta);
            char_typewriter("You did not hold the wheelchair thighly when the escalator stopped working", italic_green);
            char_typewriter("The wheelchair fell down and the old lady fell down with it", italic_green);
            char_typewriter("You look down immediately, but you can only see the wheelchair, not the old lady", italic_green);
            char_typewriter("Old Lady👵: ARRRRRRRRR! It HURTS!", bold_magenta);
            char_typewriter("The lady disappeared, but you could still hear her screams echoing through the building.", italic_green);
            char_typewriter("You🙎: Are you ok...? Where are you...?", bold_magenta);
            char_typewriter("You asked in a panic, but there was no response", italic_green);
            char_typewriter("You try to find the old lady", italic_green);
            char_typewriter("When you turn around, you see her standing on the esclator looking down at you", italic_green);
            char_typewriter("Her face was covered in blood, and her eyes were full of hatred, yet still smiling 🤡", italic_green);
            char_typewriter("You🙎: Why... Why are you up there?", bold_magenta);
            char_typewriter("Chong🤡: Do you remember me? I am Chong Yuet Ming 🤡\n", bold_magenta);
            items.push_back("Walk up the escalator");
            items.push_back("Turn around and run away");
            int run = choose_event(items, "Do you want to walk up the escalator or run away?");
            items.clear(); // Clear the vector
            if (run == 0)
            {
                // code to handle "Walk up the escalator" option
                char_typewriter("\nYou walk up cautiously with you leg shaking", italic_green);
            }
            else if (run == 1)
            {
                // code to handle "Turn around and run away" option
                char_typewriter("\nYou immediately turn around and wanted to run away", italic_green);
                char_typewriter("However, you see Chong standing down there and staring at you", italic_green);
                char_typewriter("Chong🤡: Why are you trying to run away!?", bold_magenta);
            }
            char_typewriter("You🙎: Shouldn't you be ... dead?", bold_magenta);
            char_typewriter("Chong🤡: You made me feel so pain...!", bold_magenta);
            char_typewriter("You🙎: I am sorry, I didn't mean to...", bold_magenta);
            char_typewriter("Chong🤡: It's no use saying sorry now!!!", bold_magenta);
            char_typewriter("Chong🤡: I guess there is no choice but to kill you for revenge!", bold_magenta);
            char_typewriter("You clench your fists and ready to fight 👊\n", italic_green);

            int win = call_new_battle(player_name, "Chong🤡", player_info.items, player_info.difficulty, 1, 0); // call battle
            if (win == 0)
            {
                // player won the battle
                char_typewriter("\nYou see Chong slowly dissapearing...", italic_green);
                char_typewriter("Chong🤡: Why!!!", bold_magenta);
                char_typewriter("Chong🤡: I will come back and revenge!!!", bold_magenta);
                char_typewriter("You walk away with extreme fatigue...", italic_green);
                walking_animation();
                save_game("Library", player_name); // "CYM" ended -> save game
                return 0;
            }
            else if (win == 1)
            {
                // player lost the battle
                char_typewriter("\nYou slowly lose you consciousness in a pool of blood while feeliong extremely pain...", italic_green);
                char_typewriter("Chong🤡: GO TO HELLLLLL", bold_magenta);
                char_typewriter("Chong🤡: HAHAHAHAHA\n", bold_magenta);
                gameover("CYM", player_name); // gameover
                return 0;
            }
            else if (win == 2)
            {
                // both player and enemy died -> player lost the battle
                char_typewriter("\nYou all fell in a pool of blood and heard each other screaming in pain...", italic_green);
                char_typewriter("Chong🤡: Let's meet again in HELLLLLL\n", bold_magenta);
                gameover("CYM", player_name); // gameover
                return 0;
            }
        }
        else if (help == 1)
        {
            // code to handle "Help her" option
            char_typewriter("\nYou walk away and leave the old lady alone", italic_green);
            char_typewriter("You🙎: Sorry, I have to go now", bold_magenta);
            char_typewriter("Old Lady👵: ......", bold_magenta);
            player_info.checkpoint = "CYM Toilet";
            player_manager.update_player(player_info);
            player_manager.save_players("saves.sav");
            items.push_back("Continue");
            items.push_back("Return to main menu");
            string question = "Game saved at checkpoint CYM Toilet. Do you want to continue?";
            int cgame = choose_event(items, question);
            items.clear(); // Clear the vector
            if (cgame == 0)
            {
                CYM_Toilet(player_name);
                return 0;
            }
            if (cgame == 1)
            {
                main_menu();
                return 0;
            }
        }
    }

    else if (leave == 1)
    {
        // code to handle "Leave her alone" option
        char_typewriter("\nYou walk away and leave the old lady alone\n", italic_green);
        player_info.checkpoint = "CYM Toilet";
        player_manager.update_player(player_info);
        player_manager.save_players("saves.sav");
        items.push_back("Continue");
        items.push_back("Return to main menu");
        string question = "Game saved at checkpoint CYM Toilet. Do you want to continue?";
        int cgame = choose_event(items, question);
        items.clear(); // Clear the vector
        if (cgame == 0)
        {
            CYM_Toilet(player_name);
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
