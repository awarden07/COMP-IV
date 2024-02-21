CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

# Your .hpp files
DEPS = EDistance.hpp

# Object files for main program
MAIN_OBJECTS = EDistance.o main.o

# Object files for tests
TEST_OBJECTS = EDistance.o test.o

# Name for executable
PROGRAM = EDistance
TEST_PROGRAM = test

# Library file
LIBRARY = EDistance.a

.PHONY: all clean lint test

all: $(PROGRAM) $(TEST_PROGRAM)

main.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

test.o: test.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

EDistance.o: EDistance.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(MAIN_OBJECTS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(TEST_PROGRAM): $(TEST_OBJECTS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(LIBRARY): EDistance.o
	ar rcs $@ $^

clean:
	rm -f *.o $(PROGRAM) $(TEST_PROGRAM) $(LIBRARY)

lint:
	cpplint *.cpp *.hpp
