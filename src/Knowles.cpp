// Knowles.cpp

#include "../header/Knowles.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/player.h"
#include "../header/choose_event.h"
#include "../header/main_menu.h"
#include "../header/battle.h"
#include "../header/Library.h"
#include "../header/save_game_checkpoint.h"
#include "../header/gameover.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;

// input: player name
// function for the story chapter "Knowles"
int Knowles(string player_name)
{
    system("clear");
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);
    char_typewriter("You pass through the door and arrive at Knowles Building", italic_green);
    walking_animation();
    char_typewriter("When you are walking, you see a key on the ground\n", italic_green);

    vector<string> items;
    items.push_back("Take it");
    items.push_back("Just let it go");
    int pick_key = choose_event(items, "Would you like to pick it up?");
    items.clear(); // Clear the vector
    if (pick_key == 0)
    {
        // option "Take it" chosen
        char_typewriter("\nYou put the key in your inventory", italic_green);
        player_info.items.push_back("key");
    }
    else if (pick_key == 1)
    {
        // option "Just let it go" chosen
        char_typewriter("\nYou leave the key there and walk away", italic_green);
    }

    char_typewriter("After walking for a while, you start to feel like something is sneaking behind you\n", italic_green);
    items.push_back("Why not?");
    items.push_back("NO FOR SURE");
    int look_back = choose_event(items, "Would you like to have a look?");
    items.clear(); // Clear the vector
    if (look_back == 0)
    {
        // option "Why not?" chosen
        char_typewriter("\nOut of curiosity, you circle around to inspect your back", italic_green);
        char_typewriter("The only thing you can see is an old security guard floating", italic_green);
    }
    else if (look_back == 1)
    {
        // option "NO FOR SURE" chosen
        char_typewriter("\nYou decide to keep on walking rather than turning around", italic_green);
        this_thread::sleep_for(chrono::milliseconds(500));
        char_typewriter("Suddenly, an old security guard pops up in front of you❗️", italic_green);
    }

    char_typewriter("He is desperately searching every single corner of the building", italic_green);
    char_typewriter("Old security guard👮: Have you seen my key?\n", bold_magenta);
    int ignore_count = 0;
    bool is_valid = false;
    while (is_valid != true)
    {
        items.push_back("Ignore him and walk away");
        items.push_back("Scream and run away");
        items.push_back("Poke his stomach with your finger");
        items.push_back("Give him the key");
        int give_key = choose_event(items, "Your response?");
        items.clear(); // Clear the vector

        if (give_key == 0 && ignore_count == 0)
        {
            // option "Ignore him and walk away" chosen
            // player choose to ignore for the first time
            ignore_count++;
            char_typewriter("\nYou🙎: ......", bold_magenta);
            char_typewriter("You turn around and walk away pretending nothing happens", italic_green);
            walking_animation();
            char_typewriter("Old security guard👮: Hmm...hello? (Choose your response again)\n", bold_magenta);
        }
        else if (give_key == 0 && ignore_count == 1)
        {
            // option "Ignore him and walk away" chosen
            // player choose to ignore for the second time
            ignore_count++;
            char_typewriter("\nYou🙎: ......", bold_magenta);
            char_typewriter("You keep ignoring the old security guard", italic_green);
            walking_animation();
            char_typewriter("Old security guard👮: I AM ABOUT TO GET MAD 😡 (Choose your response again)\n", bold_magenta);
        }
        else if (give_key == 0 && ignore_count == 2)
        {
            // option "Ignore him and walk away" chosen
            // player choose to ignore for the third time
            is_valid = true;
            char_typewriter("\nOld security guard👮: You will pay for your disrespectfulness! 😡\n", bold_magenta);
            int win = call_new_battle(player_name, "Old security guard👮", player_info.items, player_info.difficulty, 1, 0); // call battle
            if (win == 0)
            {
                // player won the battle
                char_typewriter("\nThe old man starts to disappear in the air with his voice fading out...", italic_green);
                char_typewriter("Old security guard👮: AARGHHHH! My key is still missing! I cannot die here!!!", bold_magenta);
                char_typewriter("Old security guard👮: I will be back... to search for my key... AND TO TAKE REVENGE ON YOU!!!", bold_magenta);
                char_typewriter("You🙎: Well... that doesn't sound good", bold_magenta);
                char_typewriter("The old man's scream echoes through the building", italic_green);
                char_typewriter("You🙎: I am not staying here any longer! 😨", bold_magenta);
                char_typewriter("You decide to leave the building", italic_green);
                walking_animation();
                save_game("Library", player_name); // "Knowles" ended -> save game
                return 0;
            }
            else if (win == 1)
            {
                // player lost the battle
                char_typewriter("\nYou slowly lose you consciousness in a pool of blood while feeling extremely painful... 😣", italic_green);
                char_typewriter("Old security guard👮: GO TO HELLLLLL", bold_magenta);
                char_typewriter("Old security guard👮: HAHAHAHAHA. This is what you get for disrespecting me! 😈\n", bold_magenta);
                gameover("Knowles", player_name); // gameover
                return 0;
            }
            else if (win == 2)
            {
                // both player and enemy died -> player lost the battle
                char_typewriter("\nYou all fell in a pool of blood and heard each other screaming in pain...", italic_green);
                char_typewriter("Old security guard👮: Let's meet again in HELLLLLL 😈\n", bold_magenta);
                gameover("Knowles", player_name); // gameover
                return 0;
            }
        }

        if (give_key == 1)
        {
            // option "Scream and run away" chosen
            is_valid = true;
            char_typewriter("\nYou🙎: OMG nooo! Please don't bother me you old man!", bold_magenta);
            char_typewriter("You keep running away without a backward glance, hoping you can get rid of him 😨", italic_green);
            walking_animation();
            char_typewriter("However, no matter how far you run, he can always catch up in the blink of an eye", italic_green);
            char_typewriter("The moment you stop...", italic_green);
            this_thread::sleep_for(chrono::milliseconds(500));
            char_typewriter("Old security guard👮: HAHA! Got you!", bold_magenta);
            char_typewriter("Old security guard👮: You will pay for your unkindness! 😡\n", bold_magenta);

            int win = call_new_battle(player_name, "Old security guard👮", player_info.items, player_info.difficulty, 1, 0); // call battle
            if (win == 0)
            {
                // player won the battle
                char_typewriter("\nThe old man starts to vanish in the air with his voice fading out...", italic_green);
                char_typewriter("Old security guard👮: AARGHHHH! My key is still missing! I cannot die here!!!", bold_magenta);
                char_typewriter("Old security guard👮: I will be back... to search for my key... AND TO TAKE REVENGE ON YOU!!!", bold_magenta);
                char_typewriter("You🙎: Well... that doesn't sound good", bold_magenta);
                char_typewriter("The old man's scream echoes through the building", italic_green);
                char_typewriter("You🙎: I am not staying here any longer! 😨", bold_magenta);
                char_typewriter("You decide to leave the building", italic_green);
                walking_animation();
                save_game("Library", player_name); // "Knowles" ended -> save game
                return 0;
            }
            else if (win == 1)
            {
                // player lost the battle
                char_typewriter("\nYou slowly lose you consciousness in a pool of blood while feeling extremely painful... 😣", italic_green);
                char_typewriter("Old security guard👮: GO TO HELLLLLL", bold_magenta);
                char_typewriter("Old security guard👮: HAHAHAHAHA. This is what you get for not helping me! 😈\n", bold_magenta);
                gameover("Knowles", player_name);
                return 0;
            }
            else if (win == 2)
            {
                // both player and enemy died -> player lost the battle
                char_typewriter("\nYou all fell in a pool of blood and heard each other screaming in pain...", italic_green);
                char_typewriter("Old security guard👮: Let's meet again in HELLLLLL 😈\n", bold_magenta);
                gameover("Knowles", player_name); // gameover
                return 0;
            }
        }

        if (give_key == 2)
        {
            // option "Give him the key" chosen
            is_valid = true;
            char_typewriter("\nOld security guard👮: What are you doing?", bold_magenta);
            char_typewriter("The security guard sounds a bit mad", italic_green);
            char_typewriter("You🙎: Hmm...I mean, yeah...", bold_magenta);
            char_typewriter("You start running before even finishing your sentence 😨", italic_green);
            walking_animation();
            char_typewriter("However, no matter how far you run, he can always catch up in the blink of an eye", italic_green);
            char_typewriter("The moment you stop...", italic_green);
            this_thread::sleep_for(chrono::milliseconds(500));
            char_typewriter("Old security guard👮: HAHA! Got you.", bold_magenta);
            char_typewriter("Old security guard👮: You will pay for your disrespectfulness! 😡\n", bold_magenta);

            int win = call_new_battle(player_name, "Old security guard👮", player_info.items, player_info.difficulty, 1, 0); // call battle
            if (win == 0)
            {
                // player won the battle
                char_typewriter("\nThe old man starts to disappear in the air with his voice fading out...", italic_green);
                char_typewriter("Old security guard👮: AARGHHHH! My key is still missing! I cannot die here!!!", bold_magenta);
                char_typewriter("Old security guard👮: I will be back... to search for my key... AND TO TAKE REVENGE ON YOU!!!", bold_magenta);
                char_typewriter("You🙎: Well... that doesn't sound good", bold_magenta);
                char_typewriter("The old man's scream echoes through the building", italic_green);
                char_typewriter("You🙎: I am not staying here any longer! 😨", bold_magenta);
                char_typewriter("You decide to leave the building", italic_green);
                walking_animation();
                save_game("Library", player_name); // "Knowles" ended -> save game
                return 0;
            }
            else if (win == 1)
            {
                // player lost the battle
                char_typewriter("\nYou slowly lose you consciousness in a pool of blood while feeling extremely painful... 😣", italic_green);
                char_typewriter("Old security guard👮: GO TO HELLLLLL", bold_magenta);
                char_typewriter("Old security guard👮: HAHAHAHAHA. This is what you get for disrespecting me! 😈\n", bold_magenta);
                gameover("Knowles", player_name); // gameover
                return 0;
            }
            else if (win == 2)
            {
                // both player and enemy died -> player lost the battle
                char_typewriter("\nYou all fell in a pool of blood and heard each other screaming in pain...", italic_green);
                char_typewriter("Old security guard👮: Let's meet again in HELLLLLL 😈\n", bold_magenta);
                gameover("Knowles", player_name); // gameover
                return 0;
            }
        }

        if (give_key == 3)
        {
            // option "Give him the key" chosen
            if (find(player_info.items.begin(), player_info.items.end(), "key") != player_info.items.end()) // if key is in inventory
            {
                is_valid = true;
                player_info.items.pop_back(); // remove key from inventory
                char_typewriter("\nYou take the key out from the pocket 🔑", italic_green);
                char_typewriter("You🙎: Here you go", bold_magenta);
                char_typewriter("Old security guard👮: Wait...is that the key that I have been searching for years?", bold_magenta);
                char_typewriter("He holds and inspects the key carefully", italic_green);
                char_typewriter("Old security guard👮: Thank you so much young man 😊", bold_magenta);
                char_typewriter("Old security guard👮: This is the one...It's such a weight off my mind", bold_magenta);
                char_typewriter("The old security guard cannot hold back his tears 😭", italic_green);
                char_typewriter("When you are still confused what is going on, the old man starts to fade away", italic_green);
                char_typewriter("Old security guard👮: Thanks a lot 😊", bold_magenta);
                char_typewriter("The old man vanishes in the air with his voice fading out...", italic_green);
                char_typewriter("You🙎: Well... I guess I should leave this place", bold_magenta);
                walking_animation();
                cout << endl;
                save_game("Library", player_name); // "Knowles" ended -> save game
            }
            else
            {
                // key is not in inventory
                char_typewriter("\nYou don't have the key in your inventory (Choose your response again)\n", bold_red);
            }
        }
    }
    return 0;
}