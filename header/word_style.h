// word_style.h

#ifndef WORD_STYLE_H
#define WORD_STYLE_H

#include <string>
#include <vector>

// struct for color options
struct ColorOption
{
    std::string name;
    std::string code;
};

// extern for color options
extern ColorOption red;
extern ColorOption green;
extern ColorOption blue;
extern ColorOption yellow;
extern ColorOption magenta;
extern ColorOption cyan;
extern ColorOption white;

// bold colors
extern ColorOption bold_red;
extern ColorOption bold_green;
extern ColorOption bold_blue;
extern ColorOption bold_yellow;
extern ColorOption bold_magenta;
extern ColorOption bold_cyan;
extern ColorOption bold_white;

// dark colors
extern ColorOption dark_red;
extern ColorOption dark_green;
extern ColorOption dark_blue;
extern ColorOption dark_yellow;
extern ColorOption dark_magenta;
extern ColorOption dark_cyan;
extern ColorOption dark_white;

// underline colors
extern ColorOption underline_red;
extern ColorOption underline_green;
extern ColorOption underline_blue;
extern ColorOption underline_yellow;
extern ColorOption underline_magenta;
extern ColorOption underline_cyan;
extern ColorOption underline_white;

// background colors
extern ColorOption background_red;
extern ColorOption background_green;
extern ColorOption background_blue;
extern ColorOption background_yellow;
extern ColorOption background_magenta;
extern ColorOption background_cyan;
extern ColorOption background_white;

// bold background colors
extern ColorOption bold_background_red;
extern ColorOption bold_background_green;
extern ColorOption bold_background_blue;
extern ColorOption bold_background_yellow;
extern ColorOption bold_background_magenta;
extern ColorOption bold_background_cyan;
extern ColorOption bold_background_white;

// background italic colors
extern ColorOption background_italic_red;
extern ColorOption background_italic_green;
extern ColorOption background_italic_blue;
extern ColorOption background_italic_yellow;
extern ColorOption background_italic_magenta;
extern ColorOption background_italic_cyan;
extern ColorOption background_italic_white;

extern ColorOption bold_background_italic_red;
extern ColorOption bold_background_italic_green;
extern ColorOption bold_background_italic_blue;
extern ColorOption bold_background_italic_yellow;
extern ColorOption bold_background_italic_magenta;
extern ColorOption bold_background_italic_cyan;
extern ColorOption bold_background_italic_white;

extern ColorOption italic_red;
extern ColorOption italic_green;
extern ColorOption italic_blue;
extern ColorOption italic_yellow;
extern ColorOption italic_magenta;
extern ColorOption italic_cyan;
extern ColorOption italic_white;

extern ColorOption bold_italic_red;
extern ColorOption bold_italic_green;
extern ColorOption bold_italic_blue;
extern ColorOption bold_italic_yellow;
extern ColorOption bold_italic_magenta;
extern ColorOption bold_italic_cyan;
extern ColorOption bold_italic_white;

extern ColorOption light_red;
extern ColorOption light_green;
extern ColorOption light_blue;
extern ColorOption light_yellow;
extern ColorOption light_magenta;
extern ColorOption light_cyan;
extern ColorOption light_white;

extern ColorOption bright_red;
extern ColorOption bright_green;
extern ColorOption bright_blue;
extern ColorOption bright_yellow;
extern ColorOption bright_magenta;
extern ColorOption bright_cyan;
extern ColorOption bright_white;

extern ColorOption background_light_red;
extern ColorOption background_light_green;
extern ColorOption background_light_blue;
extern ColorOption background_light_yellow;
extern ColorOption background_light_magenta;
extern ColorOption background_light_cyan;
extern ColorOption background_light_white;

extern ColorOption background_bright_red;
extern ColorOption background_bright_green;
extern ColorOption background_bright_blue;
extern ColorOption background_bright_yellow;
extern ColorOption background_bright_magenta;
extern ColorOption background_bright_cyan;
extern ColorOption background_bright_white;

extern ColorOption background_light_italic_red;
extern ColorOption background_light_italic_green;
extern ColorOption background_light_italic_blue;
extern ColorOption background_light_italic_yellow;
extern ColorOption background_light_italic_magenta;
extern ColorOption background_light_italic_cyan;
extern ColorOption background_light_italic_white;

extern ColorOption background_bright_italic_red;
extern ColorOption background_bright_italic_green;
extern ColorOption background_bright_italic_blue;
extern ColorOption background_bright_italic_yellow;
extern ColorOption background_bright_italic_magenta;
extern ColorOption background_bright_italic_cyan;
extern ColorOption background_bright_italic_white;

extern ColorOption light_italic_red;
extern ColorOption light_italic_green;
extern ColorOption light_italic_blue;
extern ColorOption light_italic_yellow;
extern ColorOption light_italic_magenta;
extern ColorOption light_italic_cyan;
extern ColorOption light_italic_white;

extern ColorOption bright_italic_red;
extern ColorOption bright_italic_green;
extern ColorOption bright_italic_blue;
extern ColorOption bright_italic_yellow;
extern ColorOption bright_italic_magenta;
extern ColorOption bright_italic_cyan;
extern ColorOption bright_italic_white;

extern ColorOption background_dark_red;
extern ColorOption background_dark_green;
extern ColorOption background_dark_blue;
extern ColorOption background_dark_yellow;
extern ColorOption background_dark_magenta;
extern ColorOption background_dark_cyan;
extern ColorOption background_dark_white;

extern ColorOption background_dark_italic_red;
extern ColorOption background_dark_italic_green;
extern ColorOption background_dark_italic_blue;
extern ColorOption background_dark_italic_yellow;
extern ColorOption background_dark_italic_magenta;
extern ColorOption background_dark_italic_cyan;
extern ColorOption background_dark_italic_white;

extern ColorOption background_dark_bright_red;
extern ColorOption background_dark_bright_green;
extern ColorOption background_dark_bright_blue;
extern ColorOption background_dark_bright_yellow;
extern ColorOption background_dark_bright_magenta;
extern ColorOption background_dark_bright_cyan;
extern ColorOption background_dark_bright_white;

extern ColorOption background_dark_light_red;
extern ColorOption background_dark_light_green;
extern ColorOption background_dark_light_blue;
extern ColorOption background_dark_light_yellow;
extern ColorOption background_dark_light_magenta;
extern ColorOption background_dark_light_cyan;
extern ColorOption background_dark_light_white;

extern ColorOption background_dark_bold_red;
extern ColorOption background_dark_bold_green;
extern ColorOption background_dark_bold_blue;
extern ColorOption background_dark_bold_yellow;
extern ColorOption background_dark_bold_magenta;
extern ColorOption background_dark_bold_cyan;
extern ColorOption background_dark_bold_white;

extern ColorOption background_dark_bold_italic_red;
extern ColorOption background_dark_bold_italic_green;
extern ColorOption background_dark_bold_italic_blue;
extern ColorOption background_dark_bold_italic_yellow;
extern ColorOption background_dark_bold_italic_magenta;
extern ColorOption background_dark_bold_italic_cyan;
extern ColorOption background_dark_bold_italic_white;

extern ColorOption background_dark_italic_red;
extern ColorOption background_dark_italic_green;
extern ColorOption background_dark_italic_blue;
extern ColorOption background_dark_italic_yellow;
extern ColorOption background_dark_italic_magenta;
extern ColorOption background_dark_italic_cyan;
extern ColorOption background_dark_italic_white;

extern ColorOption background_dark_bold_red;
extern ColorOption background_dark_bold_green;
extern ColorOption background_dark_bold_blue;
extern ColorOption background_dark_bold_yellow;
extern ColorOption background_dark_bold_magenta;
extern ColorOption background_dark_bold_cyan;
extern ColorOption background_dark_bold_white;

extern std::vector<ColorOption> colorOptions;

#endif