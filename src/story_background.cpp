// story_background.cpp

#include "../header/story_background.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/player.h"
#include "../header/choose_event.h"
#include <chrono>
#include <iostream>
#include <string>

using namespace std;

// Print the story background
int story_background(string player_name)
{
    char_typewriter("Background:", bold_background_italic_cyan);
    char_typewriter("You are a HKU student", italic_cyan);
    char_typewriter("Today you have a lot of assignment waiting for you to finish ", italic_cyan);
    char_typewriter("So you stayed at KKL building to finish them", italic_cyan);
    char_typewriter("Unfortunately, you fell asleep...😴 ", italic_cyan);
    char_typewriter("When you wake up, you notice that it is already 3am on the clock", italic_cyan);
    char_typewriter("There is no one around you", italic_cyan);
    char_typewriter("You must go home immediately or your family will scold you", italic_cyan);
    char_typewriter("However, all the lights are off and the only light source is your phone📱\n\n", italic_cyan);
    // Call menu function with custom options and question
    bool is_valid = false;
    while (!is_valid)
    {
        vector<string> items;
        items.push_back("Continue sleeping");
        items.push_back("Continue staying without leaving");
        items.push_back("Take the elevator and leave");
        int choice = choose_event(items, "What do you want to do now?");
        items.clear(); // Clear the vector
        switch (choice)
        {
        case 0:
            // code to handle "Continue sleeping" option
            char_typewriter("\nYou've slept too long, you can't sleep again!", italic_green);
            clear_previous_lines(6);
            continue;
        case 1:
            // code to handle "Continue staying without leaving" option
            char_typewriter("\n...................Nothing happens", italic_green);
            clear_previous_lines(6);
            continue;
            ;
        case 2:
            // code to handle "Take the elevator and leave" option
            color_print("\nYou stand up and ready to leave\n", italic_green);
            break;
        }
        this_thread::sleep_for(chrono::seconds(2));
    }
}
