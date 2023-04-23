// story_background.cpp

#include "../header/story_background.h"
#include "../header/output_style.h"
#include "../header/word_style.h"
#include "../header/player.h"
#include "../header/choose_event.h"
#include "../header/password.h"
#include "../header/main_menu.h"
#include "../header/CYM.h"
#include "../header/Knowles.h"
#include "../header/choose_event_clear_screen.h"
#include <chrono>
#include <iostream>
#include <string>

using namespace std;

// Print the story background
int story_background(string player_name)
{
    system("clear"); // clear screen
    PlayerManager player_manager;
    player_manager.load_players("saves.sav");
    PlayerInfo player_info;
    player_info = player_manager.get_player(player_name);
    char_typewriter("Background:", bold_background_italic_cyan);
    char_typewriter("You are a HKU student", italic_green);
    char_typewriter("Today you have a lot of assignment waiting for you to finish ", italic_green);
    char_typewriter("So you stayed at KKL building to finish them", italic_green);
    char_typewriter("Unfortunately, you fell asleep...😴 ", italic_green);
    char_typewriter("When you wake up, you notice that it is already 3am on the clock", italic_green);
    char_typewriter("There is no one around you", italic_green);
    char_typewriter("You must go home immediately or your family will scold you", italic_green);
    char_typewriter("However, all the lights are off and the only light source is your phone📱\n\n", italic_green);
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
            char_typewriter("\nYou've slept too long, you can't sleep again! (choose again)        ", italic_green);
            clear_previous_lines(6);
            continue;
        case 1:
            // code to handle "Continue staying without leaving" option
            char_typewriter("\n...................Nothing happens (choose again)              ", italic_green);
            clear_previous_lines(6);
            continue;
            ;
        case 2:
            // code to handle "Take the elevator and leave" option
            char_typewriter("\nYou stand up and ready to leave                ", italic_green);
            is_valid = true;
            break;
        }
    }
    char_typewriter("When you are about to leave, you notice that there is a bottle of energy drink on your table\n", italic_green);
    is_valid = false;
    while (!is_valid)
    {
        vector<string> items;
        items.push_back("Take it");
        items.push_back("Just let it go");
        int choice = choose_event(items, "Are you going to take it?");
        items.clear(); // Clear the vector
        switch (choice)
        {
        case 0:
            char_typewriter("\nYou put the drink in your inventory", italic_green);
            char_typewriter("You then walk to the elevator and head to ground floor", italic_green);
            player_info.items.push_back("Energy Drink");
            is_valid = true;
            break;
        case 1:
            char_typewriter("\nYou then walk to the elevator and head to ground floor", italic_green);
            // code to handle "Continue staying without leaving" option
            is_valid = true;
            break;
        }
    }
    char_typewriter("When you reach the ground floor, there is a sign in front of you:\n", italic_green);
    char_typewriter("  ← CYM Building    ", bold_background_cyan);
    char_typewriter(" Knowles Building ➡ ", bold_background_cyan);
    cout << endl;
    is_valid = false;
    string choose_building;
    while (!is_valid)
    {
        vector<string> items;
        items.push_back("Left");
        items.push_back("Right");
        int choice = choose_event(items, "Which way do you want to go?");
        items.clear(); // Clear the vector
        switch (choice)
        {
        case 0:
            // turn left
            char_typewriter("\nYou walk to the left...", italic_green);
            choose_building = "CYM";
            is_valid = true;
            break;
        case 1:
            // turn right
            char_typewriter("\nYou walk to the right...", italic_green);
            choose_building = "Knowles";
            is_valid = true;
            break;
        }
    }
    char_typewriter("There is door locked with english vocabulary that is {passwordLength} characters long 🔒\nYou have to guess the password in {passwordAttempt} goes or less, or else the password would be reset\nA correct letter turns green\nA correct letter in the wrong place turns yellow\nAn incorrect letter turns grey", italic_green);
    bool pass = false;
    while (!pass)
    {
        pass = password(player_info.difficulty);
    }
    char_typewriter("You open the door and walk into the building\n", italic_green);
    walking_animation();
    system("clear"); // clear screen
    player_info.checkpoint = choose_building;
    player_manager.update_player(player_info);
    player_manager.save_players("saves.sav");
    is_valid = false;
    while (!is_valid)
    {
        vector<string> items1;
        items1.push_back("Continue");
        items1.push_back("Return to main menu");
        string question = "Game saved at checkpoint " + choose_building + ". Do you want to continue?";
        int choice = choose_event(items1, question);
        items1.clear(); // Clear the vector
        switch (choice)
        {
        case 0:
            if (choose_building == "CYM")
            {
                CYM(player_name);
            }
            else if (choose_building == "Knowles")
            {
                Knowles(player_name);
            }
            is_valid = true;
            break;
        case 1:
            main_menu();
            is_valid = true;
            break;
        }
    }
    return 0;
}
