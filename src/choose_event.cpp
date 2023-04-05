#include "../header/output_style.h"
#include "../header/choose_event.h"
#include "../header/word_style.h"
#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>

using namespace std;

// Function to get arrow key input
int getKeyPress()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char buf[1];
    ssize_t n = read(STDIN_FILENO, buf, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    if (n == 1)
    {
        ch = buf[0];
    }
    else
    {
        ch = -1;
    }
    return ch;
}

// Function to print menu and handle arrow key input
int choose_event(vector<string> options, string question)
{
    // Set up menu window
    string new_question = question + " (Use arrow and enter key to control)";
    color_print(new_question, bold_background_blue);
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
        cout << "\033[" << new_question.length() << "D";
        color_print(new_question, bold_background_blue);
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
