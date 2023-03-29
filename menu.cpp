#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // save terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // turn off line buffering and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply new terminal settings

    char ch;
    while (true) {
        if (read(STDIN_FILENO, &ch, 1) == 1) { // if a character was read
            if (ch == '\033') { // escape sequence
                if (read(STDIN_FILENO, &ch, 1) == 1) {
                    if (ch == '[') {
                        if (read(STDIN_FILENO, &ch, 1) == 1) {
                            if (ch == 'A') { // up arrow
                                std::cout << "Up arrow pressed" << std::endl;
                            } else if (ch == 'B') { // down arrow
                                std::cout << "Down arrow pressed" << std::endl;
                            } else if (ch == 'C') { // right arrow
                                std::cout << "Right arrow pressed" << std::endl;
                            } else if (ch == 'D') { // left arrow
                                std::cout << "Left arrow pressed" << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore terminal settings
    return 0;
}