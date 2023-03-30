CXX = g++
CPPFLAGS = -std=c++11 -Wall -Wextra -pedantic

SRCS = scr/main.cpp scr/game_name.cpp scr/output_style.cpp scr/word_style.cpp scr/main_menu.cpp scr/choose_difficulty.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: program

program: $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@

%.o: %.cpp header/output_style.h header/word_style.h header/game_name.h header/main_menu.h header/choose_difficulty.h
	$(CXX) $(CPPFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) program

love: program
	./program || (make clean && false)

.PHONY: all clean love