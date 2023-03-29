CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

all: program

program: temp.o wordanimation.o
	$(CXX) $(CXXFLAGS) $^ -o $@

temp.o: temp.cpp wordanimation.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

wordanimation.o: wordanimation.cpp wordanimation.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o program

.PHONY: clean