CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

# Your .hpp files
DEPS = CelestialBody.hpp Universe.hpp

# Object files for main program
MAIN_OBJECTS = CelestialBody.o Universe.o main.o

# Object files for tests
TEST_OBJECTS = CelestialBody.o Universe.o test.o

# Name for executable
PROGRAM = NBody
TEST_PROGRAM = test

.PHONY: all clean lint test NBody.a

all: $(PROGRAM) $(TEST_PROGRAM) NBody.a

CelestialBody.o: CelestialBody.cpp CelestialBody.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Universe.o: Universe.cpp Universe.hpp
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

test.o: test.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): NBody.a main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB) NBody.a

$(TEST_PROGRAM): test.o $(TEST_OBJECTS) NBody.a
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

NBody.a: CelestialBody.o Universe.o
	ar rcs $@ $^

clean:
	rm -f *.o $(PROGRAM) $(TEST_PROGRAM) NBody.a

lint:
	cpplint *.cpp *.hpp
