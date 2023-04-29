// CYM_Toilet.cpp

#include "../header/CYM_Toilet.h"
#include "../header/choose_event.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/save_game_checkpoint.h"
#include "../header/gameover.h"
#include "../header/battle.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// input: player name
// function for the story chapter "CYM_Toilet"
int CYM_Toilet(string player_name)
{
    system("clear");
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);

    char_typewriter("\nYou ignored her and walked away", italic_green);
    walking_animation();
    char_typewriter("But then you suddenly want to go to toilet so badly 🚽\n", italic_green);

    vector<string> items;
    items.push_back("Head to toilet");
    items.push_back("Hold back your pee");
    int pee_1 = choose_event(items, "Would you go to the toilet?");
    items.clear(); // Clear the vector
    if (pee_1 == 0)
    {
        // option "Head to toilet" chosen
        char_typewriter("\nYou walk to the toilet", italic_green);
        walking_animation();
    }
    else if (pee_1 == 1)
    {
        char_typewriter("\nYou feel like your bladder is going to explode\n", italic_green);
        items.push_back("YES");
        items.push_back("NO");
        int pee_2 = choose_event(items, "Do you still want to hold you pee?");
        items.clear(); // Clear the vector

        if (pee_2 == 0)
        {
            // option "YES" chosen in question "Do you still want to hold you pee?"
            char_typewriter("\nYou feel like your pee is leaking out\n", italic_green);
            items.push_back("YES");
            items.push_back("NO");
            int pee_3 = choose_event(items, "You SURE you want to hold you pee?");
            items.clear(); // Clear the vector

            if (pee_3 == 0)
            {
                // option "YES" chosen in question "You SURE you want to hold you pee?"
                char_typewriter("\n......", italic_green);
                char_typewriter("......", italic_green);
                char_typewriter("......", italic_green);
                char_typewriter("You peed yourself", italic_green);
                char_typewriter("You🙎: Shitttt...", bold_magenta);
                char_typewriter("You have to go to the washroom to tidy up yourself", italic_green);
                walking_animation();
            }
            else if (pee_3 == 1)
            {
                // option "NO" chosen in question "You SURE you want to hold you pee?"
                char_typewriter("\nYou walk to the toilet while trying your best to hold your pee", italic_green);
                walking_animation();
            }
        }
        else if (pee_2 == 1)
        {
            // option "NO" chosen in question "Do you still want to hold you pee?"
            char_typewriter("\nYou run to the toilet", italic_green);
            walking_animation();
        }
    }

    char_typewriter("shhhhhhh💦", italic_green);
    char_typewriter(".....", italic_green);
    char_typewriter(".....", italic_green);
    char_typewriter("You done urinating and washing your hands", italic_green);
    char_typewriter("When you cast an eye on the mirror, you notice that there is something there", italic_green);
    blink(10, "🤡", 100, bold_red);
    char_typewriter("You see from the mirror that the old lady is behind you\n", italic_green);

    items.push_back("Break the mirror");
    items.push_back("Turn over");
    int action = choose_event(items, "Your action:");
    items.clear(); // Clear the vector
    if (action == 0)
    {
        // option "Break the mirror" chosen
        char_typewriter("\nYou clench your fists and hit the mirror", italic_green);
        this_thread::sleep_for(chrono::milliseconds(200));
        blink(1, "BANG!", 1000, bold_background_red);
        char_typewriter("\nThe mirror is shattered", italic_green);
        char_typewriter("You🙎: I am just probably too fatigued and got the illusion", bold_magenta);
        char_typewriter("You try to comfort yourself", italic_green);
        char_typewriter("Then you turn over...you see the old lady standing in front of you", italic_green);
    }
    else if (action == 1)
    {
        // option "Turn over" chosen
        char_typewriter("\nThen you turn over with you leg shaking", italic_green);
        char_typewriter("...you see the old lady standing in front of you", italic_green);
    }

    char_typewriter("Old Lady: Why didn't you help me...", bold_magenta);
    char_typewriter("You🙎: But why are you here... shouldn't you be down there?", bold_magenta);
    char_typewriter("Old Lady: ANSER MY QUESTIONNNNN!!!!\n", bold_magenta);

    items.push_back("Because you look so strange");
    items.push_back("Because you look too beautiful and I am shy to talk with you");
    int answer = choose_event(items, "Your answer:");
    items.clear(); // Clear the vector
    if (answer == 0)
    {
        // option "Because you look so strange" chosen
        char_typewriter("\nChong🤡: You saying that me, Chong Yuet Ming, is STRANGE???", bold_magenta);
        char_typewriter("Chong🤡: HOW DARE ARE YOU!", bold_magenta);
    }
    else if (answer == 1)
    {
        // option "Because you look too beautiful and I am shy to talk with you" chosen
        char_typewriter("\nChong🤡: I am CHONG YUET MING, but you didn't help me!!!", bold_magenta);
        char_typewriter("You🙎: Sorry...I am a really shy person...🙈", bold_magenta);
        char_typewriter("Chong🤡: Don't give any excuses, it's you fault!!!", bold_magenta);
    }

    char_typewriter("\nYou can feel that she is enraged", italic_green);
    char_typewriter("And she start reaching out her hands", italic_green);
    char_typewriter("You try to step back but you can't", italic_green);
    char_typewriter("Chong🤡: I AM GOING TO KILL YOU\n", bold_magenta);
    int win = call_new_battle(player_name, "Chong🤡", player_info.items, player_info.difficulty, 1, 0); // call battle
    if (win == 0)
    {
        // player won the battle
        char_typewriter("\nYou see Chong slowly disappearing...", italic_green);
        char_typewriter("Chong🤡: Why!!!", bold_magenta);
        char_typewriter("Chong🤡: I will come back and revenge!!!", bold_magenta);
        char_typewriter("You walk away with extreme fatigue...", italic_green);
        walking_animation();
        save_game("Library", player_name); // "CYM_Toilet" ended -> save game
        return 0;
    }
    else if (win == 1)
    {
        // player lost the battle
        char_typewriter("\nYou slowly lose your consciousness in a pool of blood while feeling extremely pain...", italic_green);
        char_typewriter("Chong🤡: GO TO HELLLLLL", bold_magenta);
        char_typewriter("Chong🤡: HAHAHAHAHA\n", bold_magenta);
        gameover("CYM Toilet", player_name); // gameover
        return 0;
    }
    else if (win == 2)
    {
        // both player and enemy died -> player lost the battle
        char_typewriter("\nYou all fell in a pool of blood and heard each other screaming in pain...", italic_green);
        char_typewriter("Chong🤡: Let's meet again in HELLLLLL\n", bold_magenta);
        gameover("CYM Toilet", player_name); // gameover
        return 0;
    }

    return 0;
}
