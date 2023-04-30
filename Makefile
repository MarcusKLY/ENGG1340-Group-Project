CXX = g++
CPPFLAGS = -std=c++11 -w #-Wall -Wextra -pedantic #add -Wall -Wextra -pedantic for more warnings

SRCDIR = src
INCDIR = header

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, obj/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

INCS = $(wildcard $(INCDIR)/*.h)
INCFLAGS = $(addprefix -I,$(INCDIR))

MKDIR_P = mkdir -p
$(shell $(MKDIR_P) obj)

all: program

program: $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@

obj/%.o: $(SRCDIR)/%.cpp $(wildcard $(INCDIR)/*.h)
	$(CXX) $(CPPFLAGS) $(INCFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

love: program
	./program || (make clean && false)

clean:
	rm -f $(OBJS) $(DEPS) program

.PHONY: all clean

.SUFFIXES:
.SUFFIXES: .cpp .h

$(SRCDIR)/%.cpp:
$(INCDIR)/%.h: