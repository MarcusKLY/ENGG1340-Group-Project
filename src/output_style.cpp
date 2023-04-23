// output_style.cpp

#include "../header/output_style.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

// animated cout function which print the string character by character
int char_typewriter(string s, ColorOption colorOptions)
{
    chrono::milliseconds timespan(2); // 200
    this_thread::sleep_for(timespan);
    string word = s;
    cout << colorOptions.code;
    for (char c : word)
    {
        cout << c << flush;
        chrono::milliseconds timespan(2); // 200
        this_thread::sleep_for(timespan);
    }
    cout << "\033[0m" << endl; // Reset color to default
    return 0;
}

// animated cout function which print the string line with waiting time
int line_typewriter(string s, ColorOption colorOptions)
{
    chrono::milliseconds timespan(2);
    this_thread::sleep_for(timespan);
    string word = s;
    cout << colorOptions.code;
    cout << word << flush;
    cout << "\033[0m" << endl; // Reset color to default
    return 0;
}

// cout function which print the string with color
int color_print(string s, ColorOption colorOptions)
{
    cout << colorOptions.code;
    cout << s << flush;
    cout << "\033[0m" << endl; // Reset color to default
    return 0;
}

// cout function which print the string with color without new line
int color_print_no_newline(string s, ColorOption colorOptions)
{
    cout << colorOptions.code;
    cout << s << flush;
    cout << "\033[0m"; // Reset color to default
    return 0;
}

// clear the previous n lines
void clear_previous_lines(int n)
{
    cout << "\033[" << n << "A"; // Move cursor up n lines
    for (int i = 0; i < n; i++)
    {
        cout << "\033[2K"; // Clear the line
    }
}

// animation of walking
#include <iostream>
#include <chrono>
#include <thread>

void walking_animation()
{
    // Define animation frames
    char frames[4][5][6] = {
        {{" o   "},
         {"-|-  "},
         {"/ \\  "},
         {"     "},
         {"     "}},
        {{" o   "},
         {"-|-  "},
         {" /\\  "},
         {"     "},
         {"     "}},
        {{" o   "},
         {"-|-  "},
         {" /\\  "},
         {"  |  "},
         {"     "}},
        {{" o   "},
         {"-|-  "},
         {" /\\  "},
         {" | | "},
         {"     "}}};

    // Main animation loop
    for (int i = 0; i < 20; i++)
    {
        if (i > 0)
        {
            // Clear previous frame
            std::cout << "\033[5A\033[2K\033[2K\033[2K\033[2K\033[2K";
        }
        // Calculate current frame
        int frame_index = i % 4;
        char(*frame)[6] = frames[frame_index];

        // Print walking character
        for (int j = 0; j < 5; j++)
        {
            std::cout << std::string(i, ' ') << frame[j] << std::endl;
        }

        // Pause for a short time
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Function that blinks a string in the console.
// text: the text that will blink
// bTime: the time in milliseconds between each blink
void blinkOnce(string text, int bTime, ColorOption colorOptions)
{
    // Print the text in the specified color
    cout << colorOptions.code << text << flush;
    // Reset color to default
    cout << "\033[0m";
    // Wait for bTime milliseconds
    this_thread::sleep_for(chrono::milliseconds(bTime));

    // Erase the text by moving the cursor to the beginning of the line and printing spaces
    cout << "\r" << string(text.length(), ' ') << flush;
    std::cout << "\033[2K\r";

    // Wait for bTime milliseconds
    this_thread::sleep_for(chrono::milliseconds(bTime));
}

// Function that blinks a string multiple times in the console.
// number: the number of times the text will blink
// text: the text that will blink
// bTime: the time in milliseconds between each blink
void blink(int number, string text, int bTime, ColorOption colorOptions)
{
    for (int x = 0; x < number; x++)
    {
        blinkOnce(text, bTime, colorOptions);
    }
    cout << endl;
}