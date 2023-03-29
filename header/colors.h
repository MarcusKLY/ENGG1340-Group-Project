//colors.h

#ifndef COLORS_H
#define COLORS_H

#include <string>
#include <vector>


struct ColorOption {
    std::string name;
    std::string code;
};

extern ColorOption red;
extern ColorOption green;
extern ColorOption blue;

extern std::vector<ColorOption> colorOptions;

#endif