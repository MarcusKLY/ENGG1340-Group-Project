// Stairs_enemy.cpp

#include "../header/Stairs_enemy.h"
#include "../header/player.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/battle.h"
#include "../header/save_game_checkpoint.h"
#include "../header/gameover.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int Stairs_Enemy(string player_name)
{
    char_typewriter("\nOut of curiosity, you decide to look back", italic_green);
    char_typewriter("You🙎: What the heck am I witnessing!?", bold_magenta);
    char_typewriter("There are countless skeletons dragging your legs 💀", italic_green);
    char_typewriter("You can't even see the other end of the stairs", italic_green);
    char_typewriter("Stair Monster👹: Another poor soul...", bold_magenta);
    char_typewriter("An enormous unknown creature appears in front of you", italic_green);
    char_typewriter("Stair Monster👹: I can't let you go once you see me 😈\n", bold_magenta);

    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);
    player_manager.update_player(player_info);
    player_manager.save_players("saves.sav");
    int win = call_new_battle(player_name, "Stair Monster👹", player_info.items, player_info.difficulty, 3, 0);
    if (win == 0)
    {
        char_typewriter("\nStair Monster👹: NO! No way I am losing to you", bold_magenta);
        char_typewriter("You kick the stair monster and it rolls down the stairs", italic_green);
        char_typewriter("Stair Monster👹: One day, I will catch you again here 😈", bold_magenta);
        char_typewriter("Stair Monster👹: Remember my words and wait for it", bold_magenta);
        char_typewriter("The stair monster keeps rolling and disappears in your vision", italic_green);
        char_typewriter("You🙎: I guess I will be taking the escalators from now on 😱", bold_magenta);
        char_typewriter("Skeletons💀: Thanks for setting us free", bold_magenta);
        char_typewriter("The skeletons vanish one by one in front of you...\n", italic_green);
        save_game("Final Boss", player_name);
        return 0;
    }
    else if (win == 1)
    {
        char_typewriter("\nYou slowly lose you consciousness in a pool of blood while feeling extremely painful... 😣", italic_green);
        char_typewriter("Stair Monster👹: GO TO HELLLLLL", bold_magenta);
        char_typewriter("Stair Monster👹: HAHAHAHAHA. Curiosity killed the cat! 😈", bold_magenta);
        char_typewriter("Stair Monster👹: Now, turn into a skeleton and become one of my slaves", bold_magenta);
        gameover("Stairs", player_name);
        return 0;
    }
    else if (win == 2)
    {
        char_typewriter("\nYou all fell in a pool of blood and heard each other screaming in pain...", italic_green);
        char_typewriter("Stair Monster👹: Let's meet again in HELLLLLL 😈", bold_magenta);
        gameover("Stairs", player_name);
        return 0;
    }
    return 0;
}