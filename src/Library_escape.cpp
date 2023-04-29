// Library_escape.cpp

#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/player.h"
#include "../header/choose_event.h"
#include "../header/main_menu.h"

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int Library_escape(string player_name)
{
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);

    float time_allowed;
    if (player_info.difficulty == "Easy")
    {
        time_allowed = 10;
    }
    else if (player_info.difficulty == "Normal")
    {
        time_allowed = 7;
    }
    else if (player_info.difficulty == "Hard")
    {
        time_allowed = 5;
    }

    this_thread::sleep_for(chrono::seconds(2));
    string time_left = "RUN! You have " + to_string(time_allowed) + " seconds to make your decision!\n";
    char_typewriter(time_left, bold_red);
    vector<string> items;

    // First option
    chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
    items.push_back("Turn left");
    items.push_back("Go forward");
    int option_1 = choose_event(items, "Which way?");
    items.clear(); // Clear the vector
    cout << endl;

    // late input for 1st option
    if (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time).count() / 1000.0 >= time_allowed)
    {
        char_typewriter("Too late!\n", bold_red);
        return 1; // false for escaping
    }

    // Second option
    start_time = chrono::steady_clock::now();
    if (option_1 == 0)
    {
        // "turn left" chosen in first option
        items.push_back("Go up the stairs");
        items.push_back("Wait for the lift");
        items.push_back("Go into the toilet");
        int option_2 = choose_event(items, "Next move?");
        items.clear(); // Clear the vector
        cout << endl;

        // late input for 2nd option
        if (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time).count() / 1000.0 >= time_allowed)
        {
            char_typewriter("You are making decisions too slow!\n", bold_red);
            return 1; // false for escaping
        }

        // Third option
        start_time = chrono::steady_clock::now();
        if (option_2 == 0)
        {
            // "go up the stairs" chosen in second option
            items.push_back("Hide on the second floor");
            items.push_back("Keep going up");
            int option_3 = choose_event(items, "What now?");
            items.clear(); // Clear the vector
            cout << endl;

            // late input for 3rd option
            if (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time).count() / 1000.0 >= time_allowed)
            {
                char_typewriter("Be decisive!\n", bold_red);
                return 1; // false for escaping
            }

            if (option_3 == 0)
            {
                // "hide on the second floor" chosen in third option
                return 0; // true for escaping
            }
            else if (option_3 == 1)
            {
                // "keep going up" chosen in third option
                char_typewriter("You ran too fast and tumbled\n", italic_green);
                return 1; // false for escaping
            }
        }
        else if (option_2 == 1)
        {
            // "wait for the lift" chosen in second option
            char_typewriter("You know it takes time to wait for the lift right?\n", italic_green);
            return 1; // false for escaping
        }
        else if (option_2 == 2)
        {
            // "go into the toilet" chosen in second option
            char_typewriter("It's a dead end. What are you thinking?\n", italic_green);
            return 1; // false for escaping
        }
    }

    else if (option_1 == 1)
    {
        // "go forward" chosen in first option
        items.push_back("Go up the stairs");
        items.push_back("Hide behind the rubbish bin");
        items.push_back("Hide under the table");
        int option_2 = choose_event(items, "Next move?");
        items.clear(); // Clear the vector
        cout << endl;

        // late input for 2nd option
        if (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time).count() / 1000.0 >= time_allowed)
        {
            char_typewriter("Make your decision quicker!", bold_red);
            return 1; // false for escaping
        }

        // Third option
        start_time = chrono::steady_clock::now();
        if (option_2 == 0)
        {
            // "go up the stairs" chosen in second option
            items.push_back("Keep going up");
            items.push_back("Go back down using another staircase");
            int option_3 = choose_event(items, "What now?");
            items.clear(); // Clear the vector
            cout << endl;

            // late input for 3rd option
            if (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time).count() / 1000.0 >= time_allowed)
            {
                char_typewriter("Be decisive!\n", bold_red);
                return 1; // false for escaping
            }

            if (option_3 == 0)
            {
                // "keep going up" chosen in third option
                return 0; // true for escaping
            }
            else if (option_3 == 1)
            {
                // "go back down using another staircase" chosen in third option
                char_typewriter("You run too fast and actually run back into the librarian downstairs\n", italic_green);
                return 1; // false for escaping
            }
        }
        else if (option_2 == 1)
        {
            // "hide behind the rubbish bin" chosen in second option
            char_typewriter("It's such an obvious spot. What are you thinking?\n", italic_green);
            return 1; // false for escaping
        }
        else if (option_2 == 2)
        {
            // "hide under the table" chosen in second option
            return 0; // true for escaping
        }
    }

    return 0;
}