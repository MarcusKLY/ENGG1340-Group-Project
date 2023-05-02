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
#include <termios.h>
#include <unistd.h>
#include <csignal>

#include "../header/Knowles.h"

using namespace std;

void signalHandler(int signal) // turn terminal line buffering and echo on
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    exit(0);
}
int main()
{
    signal(SIGINT, signalHandler); // when interrupted with ctrl-c

    checking();
    // cout << tictactoe();

    // blink(30, "Welcome to the game", 10, italic_blue);
    //   Knowles("a");
    //    g_name();
    main_menu();
    // call_sample_battle();
    return 0;
}
