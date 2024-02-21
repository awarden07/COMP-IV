CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lboost_unit_test_framework -lboost_regex -lboost_date_time

DEPS = 

OBJECTS = 
MAIN_OBJECTS = main.o
PROGRAM = ps7

.PHONY: all clean lint

all: $(PROGRAM)
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): $(MAIN_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)


clean:
	rm .o $(PROGRAM)

lint:
	cpplint.cpp *.hpp