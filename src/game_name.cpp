// game_name.cpp

#include "../header/game_name.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include <iostream>
#include <string>

using namespace std;

// print the game name
void g_name()
{
    cout << "\033[2J\033[1;1H"; // clear screen and move cursor to top-left corner
    line_typewriter("┋======================================┋", bold_red);
    line_typewriter("┋      ___ ___  ____  __.____ ___      ┋", bold_red);
    line_typewriter("┋     /   |   \\|    |/ _|    |   \\     ┋", bold_red);
    line_typewriter("┋    /    ~    \\      < |    |   /     ┋", bold_red);
    line_typewriter("┋    \\    Y    /    |  \\|    |  /      ┋", bold_red);
    line_typewriter("┋     \\___|_  /|____|__ \\______/       ┋", bold_red);
    line_typewriter("┋           \\/         \\/              ┋", bold_red);
    line_typewriter("┋__________.__                    .___ ┋", bold_red);
    line_typewriter("┋\\______   \\  |   ____   ____   __| _/ ┋", bold_red);
    line_typewriter("┋ |    |  _/  |  /  _ \\ /  _ \\ / __ |  ┋", bold_red);
    line_typewriter("┋ |    |   \\  |_(  <_> |  <_> ) /_/ |  ┋", bold_red);
    line_typewriter("┋ |______  /____/\\____/ \\____/\\____ |  ┋", bold_red);
    line_typewriter("┋        \\/                        \\/  ┋", bold_red);
    line_typewriter("┋      _____                           ┋", bold_red);
    line_typewriter("┋     /     \\   ____   ____   ____     ┋", bold_red);
    line_typewriter("┋    /  \\ /  \\ /  _ \\ /  _ \\ /    \\    ┋", bold_red);
    line_typewriter("┋   /    Y    (  <_> |  <_> )   |  \\   ┋", bold_red);
    line_typewriter("┋   \\____|__  /\\____/ \\____/|___|  /   ┋", bold_red);
    line_typewriter("┋           \\/                   \\/    ┋", bold_red);
    line_typewriter("┋======================================┋", bold_red);
}