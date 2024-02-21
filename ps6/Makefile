CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

# Your .hpp files
DEPS = RandWriter.hpp

# Object files for main program
MAIN_OBJECTS = RandWriter.o TextWriter.o

# Object files for tests
TEST_OBJECTS = RandWriter.o test.o

LIBRARY = TextWriter.a

# Name for executables
PROGRAM = TextWriter
TEST_PROGRAM = test

.PHONY: all clean lint test

all: $(PROGRAM) $(TEST_PROGRAM)

TextWriter.o: TextWriter.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

RandWriter.o: RandWriter.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

test.o: test.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(MAIN_OBJECTS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(TEST_PROGRAM): $(TEST_OBJECTS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(LIBRARY): RandWriter.o
	ar rcs $@ $^

clean:
	rm -f *.o $(PROGRAM) $(TEST_PROGRAM)

lint:
	cpplint *.cpp *.hpp
