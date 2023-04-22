// Library.cpp

#include "../header/Library.h"
#include "../header/choose_event.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/main_menu.h"
#include "../header/battle.h"
#include "../header/Happy_Park.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int Library(string player_name)
{
    system("clear");
    this_thread::sleep_for(chrono::seconds(2));
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);
    char_typewriter("When you are still shocked seeing all the strange things, your phone starts ringing 📱", italic_green);
    char_typewriter("It is an anonymous call", italic_green);
    char_typewriter("Hoping it may explain all the mysterious things that happened, you decide to give it a go", italic_green);
    char_typewriter("You🙎: Hello? Who are you?", bold_magenta);
    char_typewriter("???👀: Come to the library", bold_magenta);
    char_typewriter("Beep beep beep...", italic_green);
    char_typewriter("The call got cut off", italic_green);

    vector<string> items;
    items.push_back("For sure");
    items.push_back("No! I am not getting into any more troubles");
    int go_library = choose_event(items, "Are you going to the library?");
    items.clear(); // Clear the vector
    if (go_library == 0)
    {
        char_typewriter("\nYou walk to the library", italic_green);
        walking_animation();
        char_typewriter("Peeking into the library from the entrance, there are the only lights on in the campus 💡", italic_green);
        char_typewriter("Ensuring nothing is weird around, you decide to go in", italic_green);
        char_typewriter("Biiiiii", italic_green);
        char_typewriter("You pass the entrance with a tap of your student ID card", italic_green);
        char_typewriter("The first thing you see is a half-eaten sXXway sandwich on the ground 🥪", italic_green);

        items.push_back("Yes please, I haven't eaten anything for hours");
        items.push_back("Mum tells me not to eat things picked on the ground");
        int pick_sandwich = choose_event(items, "Would you like to pick it up?");
        items.clear(); // Clear the vector
        if (pick_sandwich == 0)
        {
            char_typewriter("\nYou picked up the sandwich", italic_green);
            player_info.items.push_back("half-eaten sXXway sandwich");
            char_typewriter("All of a sudden, all the lights are off and the entrance is locked", italic_green);
            char_typewriter("You🙎: I guess this is not a good sign...", bold_magenta);
            char_typewriter("???👀: Didn't your mum teach you not to eat in the library!?", bold_magenta);
            char_typewriter("There is a loud and angry voice yelling at you", italic_green);
            char_typewriter("You🙎: I didn't. It... it is not...", bold_magenta);
            char_typewriter("Librarian 👩‍🏫: I am an experienced librarian. I ain't that stupid to get fooled by you!", bold_magenta);
            char_typewriter("Librarian 👩‍🏫: How dare you eat here. I should punish you 🤬", bold_magenta);
            //escape
        }
        else if (pick_sandwich == 1)
        {
            char_typewriter("\nYou feel disgusted eating a half-eaten sandwich and decide not to pick it up 🤢", italic_green);
            char_typewriter("Searching around in the library, there is nothing but silence", italic_green);
            char_typewriter("You🙎: This place is so weird. I should just leave 😰", bold_magenta);
            char_typewriter("You go back to the entrance but notice that the doors are locked", italic_green);
            char_typewriter("You have to solve the tic tac toe to unlock it", italic_green);
            //tic tac toe
        }
    }
    else if (go_library == 1)
    {
        char_typewriter("\nYou have a bad feeling going to the library", italic_green);
        char_typewriter("You🙎: I may just explore other places instead 🤔", bold_magenta);

        player_info.checkpoint = "Happy Park";
        player_manager.update_player(player_info);
        player_manager.save_players("saves.sav");
        items.push_back("Continue");
        items.push_back("Return to main menu");
        string question = "Game saved at checkpoint Happy Park. Do you want to continue?";
        int cgame = choose_event(items, question);
        items.clear(); // Clear the vector
        if (cgame == 0)
        {
            Happy_Park(player_name); 
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