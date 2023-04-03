// word_style.cpp
// file for storing all the color options

#include "../header/word_style.h"
#include <string>
#include <vector>
#include <iostream>

ColorOption red = {"red", "\033[0;31m"};
ColorOption green = {"green", "\033[0;32m"};
ColorOption yellow = {"yellow", "\033[0;33m"};
ColorOption blue = {"blue", "\033[0;34m"};
ColorOption magenta = {"magenta", "\033[0;35m"};
ColorOption cyan = {"cyan", "\033[0;36m"};
ColorOption white = {"white", "\033[0;37m"};

ColorOption bold_red = {"bold_red", "\033[1;31m"};
ColorOption bold_green = {"bold_green", "\033[1;32m"};
ColorOption bold_yellow = {"bold_yellow", "\033[1;33m"};
ColorOption bold_blue = {"bold_blue", "\033[1;34m"};
ColorOption bold_magenta = {"bold_magenta", "\033[1;35m"};
ColorOption bold_cyan = {"bold_cyan", "\033[1;36m"};
ColorOption bold_white = {"bold_white", "\033[1;37m"};

ColorOption dark_red = {"dark_red", "\033[2;31m"};
ColorOption dark_green = {"dark_green", "\033[2;32m"};
ColorOption dark_yellow = {"dark_yellow", "\033[2;33m"};
ColorOption dark_blue = {"dark_blue", "\033[2;34m"};
ColorOption dark_magenta = {"dark_magenta", "\033[2;35m"};
ColorOption dark_cyan = {"dark_cyan", "\033[2;36m"};
ColorOption dark_white = {"dark_white", "\033[2;37m"};

ColorOption underline_red = {"underline_red", "\033[4;31m"};
ColorOption underline_green = {"underline_green", "\033[4;32m"};
ColorOption underline_yellow = {"underline_yellow", "\033[4;33m"};
ColorOption underline_blue = {"underline_blue", "\033[4;34m"};
ColorOption underline_magenta = {"underline_magenta", "\033[4;35m"};
ColorOption underline_cyan = {"underline_cyan", "\033[4;36m"};
ColorOption underline_white = {"underline_white", "\033[4;37m"};

ColorOption background_red = {"background_red", "\033[41m"};
ColorOption background_green = {"background_green", "\033[42m"};
ColorOption background_yellow = {"background_yellow", "\033[43m"};
ColorOption background_blue = {"background_blue", "\033[44m"};
ColorOption background_magenta = {"background_magenta", "\033[45m"};
ColorOption background_cyan = {"background_cyan", "\033[46m"};
ColorOption background_white = {"background_white", "\033[47m"};

ColorOption bold_background_red = {"bold_background_red", "\033[1;41m"};
ColorOption bold_background_green = {"bold_background_green", "\033[1;42m"};
ColorOption bold_background_yellow = {"bold_background_yellow", "\033[1;43m"};
ColorOption bold_background_blue = {"bold_background_blue", "\033[1;44m"};
ColorOption bold_background_magenta = {"bold_background_magenta", "\033[1;45m"};
ColorOption bold_background_cyan = {"bold_background_cyan", "\033[1;46m"};
ColorOption bold_background_white = {"bold_background_white", "\033[1;47m"};

ColorOption background_italic_red = {"background_italic_red", "\033[3;41m"};
ColorOption background_italic_green = {"background_italic_green", "\033[3;42m"};
ColorOption background_italic_yellow = {"background_italic_yellow", "\033[3;43m"};
ColorOption background_italic_blue = {"background_italic_blue", "\033[3;44m"};
ColorOption background_italic_magenta = {"background_italic_magenta", "\033[3;45m"};
ColorOption background_italic_cyan = {"background_italic_cyan", "\033[3;46m"};
ColorOption background_italic_white = {"background_italic_white", "\033[3;47m"};

ColorOption bold_background_italic_red = {"bold_background_italic_red", "\033[1;3;41m"};
ColorOption bold_background_italic_green = {"bold_background_italic_green", "\033[1;3;42m"};
ColorOption bold_background_italic_yellow = {"bold_background_italic_yellow", "\033[1;3;43m"};
ColorOption bold_background_italic_blue = {"bold_background_italic_blue", "\033[1;3;44m"};
ColorOption bold_background_italic_magenta = {"bold_background_italic_magenta", "\033[1;3;45m"};
ColorOption bold_background_italic_cyan = {"bold_background_italic_cyan", "\033[1;3;46m"};
ColorOption bold_background_italic_white = {"bold_background_italic_white", "\033[1;3;47m"};

ColorOption italic_red = {"italic_red", "\033[3;31m"};
ColorOption italic_green = {"italic_green", "\033[3;32m"};
ColorOption italic_yellow = {"italic_yellow", "\033[3;33m"};
ColorOption italic_blue = {"italic_blue", "\033[3;34m"};
ColorOption italic_magenta = {"italic_magenta", "\033[3;35m"};
ColorOption italic_cyan = {"italic_cyan", "\033[3;36m"};
ColorOption italic_white = {"italic_white", "\033[3;37m"};

ColorOption bold_italic_red = {"bold_italic_red", "\033[1;3;31m"};
ColorOption bold_italic_green = {"bold_italic_green", "\033[1;3;32m"};
ColorOption bold_italic_yellow = {"bold_italic_yellow", "\033[1;3;33m"};
ColorOption bold_italic_blue = {"bold_italic_blue", "\033[1;3;34m"};
ColorOption bold_italic_magenta = {"bold_italic_magenta", "\033[1;3;35m"};
ColorOption bold_italic_cyan = {"bold_italic_cyan", "\033[1;3;36m"};
ColorOption bold_italic_white = {"bold_italic_white", "\033[1;3;37m"};
