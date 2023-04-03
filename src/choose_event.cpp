#include "../header/output_style.h"
#include "../header/choose_event.h"
#include "../header/word_style.h"
#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>

using namespace std;

int getKeyPress()
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

int choose_event(vector<string> options, string question)
{
    // Set up menu window
    color_print((question + " (Use arrow and enter key to control)"), bold_background_blue);
    for (int i = 0; i < options.size(); i++)
    {
        if (i == 0)
        {
            color_print(("> " + options[i]), blue);
        }
        else
        {
            color_print(("  " + options[i]), blue);
        }
    }

    // Wait for player input
    int key = 0;
    int selected_option = 0;
    while (key != '\n')
    {
        key = getKeyPress();
        switch (key)
        {
        case 65: // Up arrow
            if (selected_option > 0)
            {
                selected_option--;
            }
            break;
        case 66: // Down arrow
            if (selected_option < options.size() - 1)
            {
                selected_option++;
            }
            break;
        }
        // Redraw menu with updated selection
        cout << "\033[" << options.size() + 1 << "A"; // Move cursor up to top of menu
        color_print((question + " (Use arrow and enter key to control)"), bold_background_blue);
        for (int i = 0; i < options.size(); i++)
        {
            if (i == selected_option)
            {
                color_print(("> " + options[i]), blue);
            }
            else
            {
                color_print(("  " + options[i]), blue);
            }
        }
    }

    return selected_option;
}
