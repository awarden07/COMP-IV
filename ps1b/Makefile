CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework PhotoMagic.a 

#Your .hpp files
DEPS = FibLFSR.hpp PhotoMagic.hpp 

#Your compiled .o files
OBJECTS = FibLFSR.o PhotoMagic.o	
MAIN_OBJECTS = $(OBJECTS) main.o	
TEST_OBJECTS = $(OBJECTS) test.o	

#The name of your program
PROGRAM = PhotoMagic	
TEST_PROGRAM = test	

.PHONY: all clean lint

all: $(PROGRAM) $(TEST_PROGRAM)	

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): $(MAIN_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
$(TEST_PROGRAM): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROGRAM) $(TEST_PROGRAM)	

lint:
	cpplint.cpp *.hpp
