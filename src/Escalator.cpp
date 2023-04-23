// Escalator.cpp

#include "../header/Escalator.h"
#include "../header/choose_event.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/main_menu.h"
#include "../header/Final_Boss.h"
#include "../header/save_game_checkpoint.h"
#include "../header/gameover.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int Escalator(string player_name)
{
    system("clear");
    this_thread::sleep_for(chrono::seconds(2));
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);

    char_typewriter("You go to take the escalators", italic_green);
    char_typewriter("When the escalators are going up, you suddenly notice a little boy standing next to you\n", italic_green);

    vector<string> items;
    items.push_back("Ask questions about him");
    items.push_back("Shout at him");
    items.push_back("Stay silent");
    int talk_option = choose_event(items, "What would you say?");
    items.clear(); // Clear the vector
    if (talk_option == 0)
    {
        char_typewriter("\nYou🙎: Who are you?", bold_magenta);
        char_typewriter("Little boy👦: Who I am doesn't matter", bold_magenta);
    }
    else if (talk_option == 1)
    {
        char_typewriter("\nYou🙎: Stay away from me!", bold_magenta);
        char_typewriter("Little boy👦: Chill bro. Not like I am gonna hurt you", bold_magenta);
        char_typewriter("The little boy sounds a bit pissed", italic_green);
        char_typewriter("You🙎: Ughh sorry. Weird things just keep happening...", bold_magenta);
    }
    else if (talk_option == 2)
    {
        char_typewriter("\nYou🙎: ...", bold_magenta);
        char_typewriter("Little boy👦: ...", bold_magenta);
    }

    char_typewriter("You look closely at the little boy", italic_green);
    char_typewriter("Suprisingly, he is wearing a clown mask 🤡 and holding a balloon in his hand 🎈\n", italic_green);

    items.push_back("Ask if he needs help");
    items.push_back("Interrogate him");
    items.push_back("Stay silent");
    int talk_option_2 = choose_event(items, "What would you say next?");
    items.clear(); // Clear the vector

    if (talk_option_2 == 0)
    {
        char_typewriter("\nYou🙎: Are you okay? Why are you here alone", bold_magenta);
        char_typewriter("Little boy🤡🎈: Thanks for your kindness despite my weird appearance", bold_magenta);
    }
    else if (talk_option_2 == 1)
    {
        char_typewriter("\nYou🙎: I knew you are not normal! What you gonna do to me", bold_magenta);
        char_typewriter("Little boy🤡🎈: How rude! Just because of my appearance?", bold_magenta);
        char_typewriter("The little boy feels offended and starts crying 😭", italic_green);
        char_typewriter("Little boy🤡🎈: I will curse you for the rest of your journey to punish your rudeness 😡", bold_magenta);
        char_typewriter("You feel like you are losing power, your attack has decreased", italic_green);
        char_typewriter("The little boy vanishes after cursing you", italic_green);
        char_typewriter("You🙎: Well... I did not mean that", bold_magenta);
        char_typewriter("You🙎: It is what it is 🤷‍♂️, I should just keep going I guess\n", bold_magenta);

        int attack_buff = -1;
    }
    else if (talk_option_2 == 2)
    {
        char_typewriter("\nYou🙎: ...", bold_magenta);
        char_typewriter("Little boy🤡🎈: ...", bold_magenta);
        char_typewriter("The little boy breaks the silence", italic_green);
    }

    if (talk_option_2 == 0 or talk_option_2 == 2)
    {
        char_typewriter("Little boy🤡🎈: I am lost in the campus. Can you help me?", bold_magenta);
        items.push_back("For sure");
        items.push_back("No, I still have to deal with other things");
        int talk_option_3 = choose_event(items, "Your response?");
        items.clear(); // Clear the vector

        if (talk_option_3 == 0)
        {
            char_typewriter("\nYou🙎: Where are you going?", bold_magenta);
            char_typewriter("Little boy🤡🎈: Heaven", bold_magenta);
            char_typewriter("You🙎: Sorry where? What did you just say?", bold_magenta);
            char_typewriter("You ask again in disbelief", italic_green);
            char_typewriter("Little boy🤡🎈: Thank you for your kindness. Wish you the best of luck on the journey", bold_magenta);
            char_typewriter("Little boy🤡🎈: May the force be with you", bold_magenta);
            char_typewriter("You can feel the power, your attack has increased", italic_green);
            int attack_buff = 1;
            char_typewriter("After giving you the Xphone phone case, the little boy vanishes", italic_green);
            player_info.items.push_back("Xphone phone case");
            char_typewriter("You🙎: Wait... Why a phone case though?", bold_magenta);
            char_typewriter("You will not find the explanation...\n", italic_green);
        }
        else if (talk_option_3 == 1)
        {
            char_typewriter("\nThe little boy starts crying 😭", italic_green);
            char_typewriter("Little boy🤡🎈: Why don't you help me... Is it because of my appearance?", bold_magenta);
            char_typewriter("Little boy🤡🎈: You were the only one that can help me", bold_magenta);
            char_typewriter("Little boy🤡🎈: I will curse you for the rest of your journey 😡", bold_magenta);
            char_typewriter("You feel like you are losing power, your attack has decreased", italic_green);
            int attack_buff = -1;
            char_typewriter("The little boy vanishes after cursing you", italic_green);
            char_typewriter("You🙎: Well... say it earlier and maybe I will help", bold_magenta);
            char_typewriter("You🙎: It is what it is 🤷‍♂️, I should just keep going I guess\n", bold_magenta);
        }
    }
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
        Final_Boss(player_name); //buff
        return 0;
    }
    if (cgame == 1)
    {
        main_menu();
        return 0;
    }

    return 0;
}