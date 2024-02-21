CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

# Your .hpp files
DEPS = hexa.hpp

# Object files for main program and test program
OBJECTS = hexa.o 
MAIN_OBJECT = $(OBJECTS) main.o

# Names of your programs 
PROGRAM = Hexa

.PHONY: all clean lint Hexa

all: $(PROGRAM) lint

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): $(MAIN_OBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm .o $(PROGRAM)

lint:
	cpplint *.cpp *.hpp
