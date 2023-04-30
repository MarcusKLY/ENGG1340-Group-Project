// Library.cpp

#include "../header/Library.h"
#include "../header/choose_event.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/main_menu.h"
#include "../header/battle.h"
#include "../header/Happy_Park.h"
#include "../header/save_game_checkpoint.h"
#include "../header/gameover.h"
#include "../header/Library_escape.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int Library(string player_name)
{
    system("clear");
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
    char_typewriter("The call got cut off\n", italic_green);

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
        char_typewriter("The first thing you see is a half-eaten sXXway sandwich on the ground 🥪\n", italic_green);

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
            int escape = Library_escape(player_name);
            while (escape == 0)
            {
                char_typewriter("The librarian loses track of you", italic_green);
                char_typewriter("You sneak back to the entrance and try to unlock the door", italic_green);
                char_typewriter("You have to win the tic tac toe in order to unlock it\n", italic_green);
                //tic tac toe
                break; // 
            }
            if (escape == 1)
            {
                char_typewriter("You get caught by the librarian and dragged back to the entrance", italic_green);
                char_typewriter("Librarian 👩‍🏫: You little rat!", bold_magenta);
                char_typewriter("Librarian 👩‍🏫: Clean the place or wait for your punishment 😡\n", bold_magenta);

                items.push_back("Okay... I will clean the place");
                items.push_back("No! I did nothing wrong");
                int clean_library = choose_event(items, "What's your decision");
                items.clear(); // Clear the vector

                if (clean_library == 0)
                {
                    char_typewriter("\nLibrarian 👩‍🏫: That's a smart choice. Clean it and I will let you go", bold_magenta);
                    char_typewriter("After spending 30 minutes to clean the place, the librarian finally approves you to leave", italic_green);
                    char_typewriter("You leave the library feeling extremely exhausted", italic_green);
                    walking_animation();
                    char_typewriter("You🙎: The guy who asked me to come here must be trolling 🙄\n", bold_magenta);
                    save_game("Happy Park", player_name);
                    return 0;
                }
                else if (clean_library == 1)
                {
                    char_typewriter("\nLibrarian 👩‍🏫: Such a naughty kid! I must punish you\n", bold_magenta);
                    int win = call_new_battle(player_name, "Librarian 👩‍🏫", player_info.items, player_info.difficulty, 3, 0);
                    if (win == 0)
                    {
                        char_typewriter("\nLibrarian 👩‍🏫: AARGHHHH", bold_magenta);
                        char_typewriter("The scream is so scary and deafening that you have to cover your ears", italic_green);
                        char_typewriter("Librarian 👩‍🏫: You are extremely lucky this time...", bold_magenta);
                        char_typewriter("Librarian 👩‍🏫: If you dare to eat here once more, I WILL BE BACK TO KILL YOU", bold_magenta);
                        char_typewriter("The dying librarian slowly disappears", italic_green);
                        walking_animation();
                        char_typewriter("You rush out of the library without a doubt", italic_green);
                        char_typewriter("You🙎: The guy who called me must be trolling 🙄\n", bold_magenta);
                        save_game("Happy Park", player_name);
                        return 0;
                    }
                    else if (win == 1)
                    {
                        char_typewriter("\nYou slowly lose you consciousness in a pool of blood while feeling extremely painful... 😣", italic_green);
                        char_typewriter("Librarian 👩‍🏫: GO TO HELLLLLL", bold_magenta);
                        char_typewriter("Librarian 👩‍🏫: HAHAHAHAHA. This is what you get for disrespecting this holy place! 😈", bold_magenta);
                        gameover("Library", player_name);
                        return 0;
                    }
                    else if (win == 2)
                    {
                        char_typewriter("\nYou all fell in a pool of blood and heard each other screaming in pain...", italic_green);
                        char_typewriter("Librarian 👩‍🏫: Let's meet again in HELLLLLL 😈", bold_magenta);
                        gameover("Library", player_name);
                        return 0;
                    }
                }
            }
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
        char_typewriter("You🙎: I may just explore other places instead 🤔\n", bold_magenta);

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