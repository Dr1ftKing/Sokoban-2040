OBJECTS = Sokoban.o main.o
CC = g++ -g
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 

all: $(OBJECTS) Sokoban #lint



Sokoban.o: Sokoban.hpp Sokoban.cpp 
	$(CC) $(CFLAGS) -c Sokoban.cpp -o Sokoban.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

Sokoban: Sokoban.o
	$(CC) $(CFLAGS) -o PS4a $(OBJECTS) -o Sokoban $(LIB)

lint:
	cpplint --filter=-runtime/references,-build/include_subdir,-build/header_guard,-build/c++11 *.cpp *.hpp

clean:
	rm *.o Sokoban