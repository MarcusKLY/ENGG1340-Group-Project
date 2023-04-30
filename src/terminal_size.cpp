#include <iostream>
#include <signal.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "../header/game_name.h"
#include "../header/main.h"
#include "../header/main_menu.h"
#include "../header/player.h"
#include "../header/choose_event.h"
#include "../header/output_style.h"
#include "../header/terminal_size.h"

volatile sig_atomic_t terminal_resized = 0;

void handle_sigwinch(int sig)
{
    terminal_resized = 1;
}

bool check_terminal_size()
{
    struct winsize size;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == 0)
    {
        if (size.ws_col >= 150 && size.ws_row >= 40)
        {
            return true;
        }
        else
        {
            std::cout << "Current terminal size: " << size.ws_col << "x" << size.ws_row << std::endl;
            std::cout << "Please resize the terminal to 150x40." << std::endl;
        }
    }
    else
    {
        std::cerr << "Failed to get terminal size." << std::endl;
    }
    return false;
}

int checking()
{
    // Set up the signal handler for SIGWINCH
    struct sigaction sa;
    sa.sa_handler = handle_sigwinch;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGWINCH, &sa, NULL) == -1)
    {
        std::cerr << "Failed to set up signal handler." << std::endl;
        return 1;
    }
    if (!check_terminal_size())
    {
        // Continuously monitor the terminal size
        bool flag = false;
        while (true)
        {
            if (terminal_resized)
            {
                if (check_terminal_size())
                {
                    flag = true;
                    break;
                }
                terminal_resized = 0;
            }
            if (flag)
            {
                break;
            }
            usleep(100000); // Sleep for a short period to reduce CPU usage
        }
    }

    std::cout << "Terminal size is 150x40. Continuing..." << std::endl;

    std::cout << "The program is ended" << std::endl;

    return 0;
}