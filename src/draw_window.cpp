// draw_window.cpp

#include "../header/draw_window.h"
#include <iostream>
#include <string>

using namespace std;

// draw a window with the given top-left corner coordinates and dimensions
void draw_window(int x, int y, int width, int height)
{
    cout << "\033[" << y << ";" << x << "H"; // move cursor to top-left corner of window
    cout << endl;
    cout << "+" << string(width - 2, '-') << "+" << endl; // top border
    for (int i = 0; i < height - 2; i++)
    {
        cout << "|" << string(width - 2, ' ') << "|" << endl; // sides
    }
    cout << "+" << string(width - 2, '-') << "+" << endl; // bottom border
}