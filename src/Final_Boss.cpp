// Final_Boss.cpp

#include "../header/Final_Boss.h"
#include "../header/choose_event.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/main_menu.h"
#include "../header/battle.h"
#include "../header/save_game_checkpoint.h"
#include "../header/gameover.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int Final_Boss(string player_name)
{
    system("clear");
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);

    char_typewriter("The things that just happened scared the shit out of you ass 💩", italic_green);
    char_typewriter("You pinch yourself and see if you are dreaming or not 🤏", italic_green);
    char_typewriter("You🙎: Ouch! It hurts! I am not in a dream I guess", bold_magenta);
    char_typewriter("You slowly walk down the University Street", italic_green);
    char_typewriter("There are breeze blows towards you 🌬️", italic_green);
    char_typewriter("Looking out from here, you notice that Hong Kong is actually quite pretty", italic_green);
    char_typewriter("You🙎: It's actually quite pretty to look at Hong Kong from here", bold_magenta);
    char_typewriter("You look out from the University Street thinking it's all over", italic_green);
    this_thread::sleep_for(chrono::milliseconds(500));
    blink(5, "👧", 100, italic_green);
    char_typewriter("Girl👧: I admire you are not dead yet", bold_magenta);
    char_typewriter("A girl appeared out of nowhere", italic_green);
    char_typewriter("There is a red scar on her neck with a cable stuck in it", italic_green);
    char_typewriter("Girl👧: 👏👏👏👏 You are a lot stronger than I expected!", bold_magenta);
    char_typewriter("You🙎: Who are you?!", bold_magenta);
    char_typewriter("You🙎: Are you the one who did all this to me?!", bold_magenta);
    char_typewriter("You🙎: Why are you doing this to me?", bold_magenta);
    char_typewriter("Girl👧: Go ask your future self!", bold_magenta);
    char_typewriter("Girl screaming", italic_green);
    char_typewriter("Girl👧: That's the question that I want to ask you", bold_magenta);
    char_typewriter("She cried loudly", italic_green);
    char_typewriter("Girl👧: ARRRRRRRRRRRRR!!!!!!!", bold_magenta);
    char_typewriter("The girl slowly grew bigger", italic_green);
    char_typewriter("Her eyes completely become white when she rolls them back", italic_green);
    char_typewriter("Then she turned her head 180 degrees, revealing another more terrifying face behind her hair", italic_green);
    char_typewriter("Girl👧: WHY DIDN'T YOU HELP AND STOP HIM!", bold_magenta);
    char_typewriter("Girl👧: I want a life for a life!", bold_magenta);
    char_typewriter("You🙎: Again??\n", bold_magenta);

    int win = call_new_battle(player_name, "Girl👧", player_info.items, player_info.difficulty, 5, player_info.buff);
    if (win == 0)
    {
        char_typewriter("\nYou see the girl slowly burn herself away...", italic_green);
        char_typewriter("Girl👧: Why is there no justice!!!", bold_magenta);
        char_typewriter("Girl👧: One day I must let you get the taste of helpless and death", bold_magenta);
        char_typewriter("There is small note fell on the floor", italic_green);
        char_typewriter("You step forward cautiously, afraid of another trap\n", italic_green);
        char_typewriter("Find me, I am in the time tunnel\n", background_italic_cyan); // colour choice?
        char_typewriter("Where is time tunnel you wonder", italic_green);
        char_typewriter("You🙎: Ohhhh, its the indoor corridor which from Haking Wong Building to Stephen Hui Geological Museum", bold_magenta);
        char_typewriter("Then you walk away slowly, hoping this nightmare will pass soon", italic_green);
        walking_animation();
        save_game("Time Tunnel", player_name);
        return 0;
    }
    else if (win == 1)
    {
        char_typewriter("You slowly lose you consciousness in a pool of blood while feeling extremely pain...", italic_green);
        char_typewriter("Girl👧: FINALLLLLY", bold_magenta);
        char_typewriter("Girl👧: You can get a taste the feeling of helpless and death now", bold_magenta);
        char_typewriter("Girl👧: This is how I felt when I was killed, and nothing helped in your witness", bold_magenta);
        char_typewriter("Girl👧: GO TO HELLLLLL", bold_magenta);
        char_typewriter("Girl👧: HAHAHAHAHA\n", bold_magenta);
        gameover("Final Boss", player_name);
        return 0;
    }
    else if (win == 2)
    {
        char_typewriter("You all fell in a pool of blood and heard each other screaming in pain...", italic_green);
        char_typewriter("Girl👧: FINALLLLLY", bold_magenta);
        char_typewriter("Girl👧: You can get a taste the feeling of helpless and death now", bold_magenta);
        char_typewriter("Girl👧: This is how I felt when I was killed, and nothing helped in your witness", bold_magenta);
        char_typewriter("Girl👧: Let's meet again in HELLLLLL", bold_magenta);
        char_typewriter("Girl👧: HAHAHAHAHA\n", bold_magenta);
        gameover("Final Boss", player_name);
        return 0;
    }
    return 0;
}