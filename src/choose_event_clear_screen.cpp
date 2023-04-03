#include "../header/output_style.h"
#include "../header/choose_event_clear_screen.h"
#include "../header/word_style.h"
#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>

using namespace std;

int getKeyPressCS()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    if (ch == 27)
    {
        // Read the next two characters to get the arrow key code
        ch = getchar();
        if (ch == 91)
        {
            ch = getchar();
            switch (ch)
            {
            case 65: // Up arrow
                ch = 65;
                break;
            case 66: // Down arrow
                ch = 66;
                break;
            }
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int choose_event_clear_screen(vector<string> options, string question)
{
    // Set up menu window
    cout << "\033[2J\033[1;1H"; // Clear screen and move cursor to top left
    color_print(question, bold_background_blue);
    cout << endl;
    for (int i = 0; i < options.size(); i++)
    {
        if (i == 0)
        {
            color_print(("  " + options[i]), green);
        }
        else
        {
            color_print(("  " + options[i]), green);
        }
    }

    // Highlight first item
    int choice = 0;
    cout << "\033[" << choice + 3 << ";0H";
    color_print_no_newline(("> " + options[choice]), bold_background_green);
    int c;

    // Handle arrow key input
    while (true)
    {
        c = getKeyPressCS();
        switch (c)
        {
        case 65: // Up arrow
            if (choice > 0)
            {
                cout << "\033[" << choice + 3 << ";0H";
                color_print_no_newline(("  " + options[choice]), green);
                choice--;
                cout << "\033[" << choice + 3 << ";0H";
                color_print_no_newline(("> " + options[choice]), bold_background_green);
            }
            break;
        case 66: // Down arrow
            if (choice < options.size() - 1)
            {
                cout << "\033[" << choice + 3 << ";0H";
                color_print_no_newline(("  " + options[choice]), green);
                choice++;
                cout << "\033[" << choice + 3 << ";0H";
                color_print_no_newline(("> " + options[choice]), bold_background_green);
            }
            break;
        case 10: // Enter key
            goto endloop;
            break;
        }
    }

endloop:
    // Clean up termios
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    cout << "\033[2J\033[1;1H"; // Clear screen and move cursor to top left

    return choice;
}
