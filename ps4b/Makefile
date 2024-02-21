CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

# Your .hpp files
DEPS = Sokoban.hpp

# Object files for main program
MAIN_OBJECTS = Sokoban.o main.o

# Name for executable
PROGRAM = Sokoban

.PHONY: all clean lint Sokoban Sokoban.a

all: $(PROGRAM) Sokoban.a

Sokoban.o: Sokoban.cpp Sokoban.hpp
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): main.o Sokoban.o Sokoban.a
	$(CC) $(CFLAGS) -o $@ $^ $(LIB) Sokoban.a

Sokoban.a: Sokoban.o main.o
	ar rcs $@ $^

clean: 
	rm -f *.o $(PROGRAM) Sokoban.a

lint:
	cpplint *.cpp *.hpp
