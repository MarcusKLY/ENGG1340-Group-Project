CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

all: program

program: temp.o wordanimation.o
	$(CXX) $(CXXFLAGS) $^ -o $@

temp.o: scr/temp.cpp header/wordanimation.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

wordanimation.o: scr/wordanimation.cpp header/wordanimation.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o program

.PHONY: clean