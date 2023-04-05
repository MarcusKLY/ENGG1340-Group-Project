// output_style.h

#ifndef OUTPUT_STYLE_H
#define OUTPUT_STYLE_H
#include <string>
#include "word_style.h"
using namespace std;

int char_typewriter(string s, ColorOption colorOptions);
int line_typewriter(string s, ColorOption colorOptions);
int color_print(string s, ColorOption colorOptions);
int color_print_no_newline(string s, ColorOption colorOptions);
void clear_previous_lines(int n);
void walking_animation();

#endif