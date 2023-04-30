// main.cpp

#include "../header/game_name.h"
#include "../header/main.h"
#include "../header/main_menu.h"
#include "../header/player.h"
#include "../header/choose_event.h"
#include "../header/output_style.h"
#include "../header/tictactoe.h"
#include "../header/terminal_size.h"

#include <iostream>
#include <thread>
#include <chrono>

#include "../header/Knowles.h"

using namespace std;

int main()
{
    checking();
    cout << tictactoe();

    // blink(30, "Welcome to the game", 10, italic_blue);
    //   Knowles("a");
    //    g_name();
    main_menu();
    // call_sample_battle();
    return 0;
}
