CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

#Your .hpp files
DEPS = FibLFSR.hpp 

#Your compiled .o files
OBJECTS = FibLFSR.o test.o 

#The name of your program
PROGRAM = test PhotoMagic

.PHONY: all clean lint

all: $(PROGRAM)	

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): FibLFSR.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROGRAM) 

lint:
	cpplint.cpp *.hpp