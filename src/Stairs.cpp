// Stairs.cpp

#include "../header/Stairs.h"
#include "../header/choose_event.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/main_menu.h"
#include "../header/Final_Boss.h"
#include "../header/save_game_checkpoint.h"
#include "../header/gameover.h"
#include "../header/Stairs_enemy.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int Stairs(string player_name)
{
    system("clear");
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);

    char_typewriter("You slowly walk up the stairs", italic_green);
    char_typewriter("But the more you walk, the heavier your feet become", italic_green);
    char_typewriter("You🙎: Maybe I am just tired", bold_magenta);
    char_typewriter("You keep walking and walking...", italic_green);
    char_typewriter("However, it seems like you are never reaching an end", italic_green);
    char_typewriter("Suddenly, you recall a myth that is well known in the campus...\n", italic_green);
    this_thread::sleep_for(chrono::seconds(1));
    char_typewriter("Long time ago, a little boy died here falling down the stairs", italic_cyan);
    char_typewriter("Since then, hundreds of people are trapped here in this infinite staircase", italic_cyan);
    char_typewriter("They are never out again...", italic_cyan);
    char_typewriter("Some say they die of exhaustion while climbing stairs", italic_cyan);
    char_typewriter("Some say they kill each other due to the hopelessness", italic_cyan);
    char_typewriter("The strong emotions, miserableness and hopelessness, eventually lead to the birth of the stair monster", italic_cyan);
    this_thread::sleep_for(chrono::seconds(1));
    char_typewriter("\nYou🙎: No way this is happening to me 😱", bold_magenta);
    char_typewriter("You feel like something is dragging your legs and it's getting heavier", italic_green);
    char_typewriter("Your sixth sense tells you not to look behind!\n", bold_red);

    vector<string> items;
    items.push_back("Keep walking");
    items.push_back("Look back to see what is messing with you");
    int look_back = choose_event(items, "What you gonna do?");
    items.clear(); // Clear the vector
    if (look_back == 0)
    {
        char_typewriter("\nYou believe in your sixth sense and decide not to look back", italic_green);
        char_typewriter("After several minutes, you have a strong feeling that you are reaching the end", italic_green);
        char_typewriter("However, your feet are so heavy that you can barely make a step\n", italic_green);

        items.push_back("Keep walking, still");
        items.push_back("I cannot resist looking back ANYMORE");
        int look_back_again = choose_event(items, "What now?");
        items.clear(); // Clear the vector
        if (look_back_again == 0)
        {
            char_typewriter("\nYou🙎: It is just a myth... It is fine...", bold_magenta);
            char_typewriter("You keep comforting yourself while trying your best to overcome the weights", italic_green);
            char_typewriter("And finally there is an end!", italic_green);
            char_typewriter("The moment you make the last step, the weights on your legs are gone", italic_green);
            char_typewriter("You🙎: Told you it is just a myth... Haha... haha", bold_magenta);
            char_typewriter("You🙎: 😓😓😓\n", bold_magenta);

            player_info.checkpoint = "Final Boss";
            player_manager.update_player(player_info);
            player_manager.save_players("saves.sav");
            items.push_back("Continue");
            items.push_back("Return to main menu");
            string question = "Game saved at checkpoint Final Boss. Do you want to continue?";
            int cgame = choose_event(items, question);
            items.clear(); // Clear the vector
            if (cgame == 0)
            {
                Final_Boss(player_name);
                return 0;
            }
            if (cgame == 1)
            {
                main_menu();
                return 0;
            }
        }
        else if (look_back_again == 1)
        {
            Stairs_Enemy(player_name);
            return 0;
        }
    }
    else if (look_back == 1)
    {
        Stairs_Enemy(player_name);
        return 0;
    }

    return 0;
}