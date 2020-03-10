CC = g++ -std=c++11 -g
exe_file = crazy_eights

$(exe_file): helper_functions.o Card.o Deck.o Hand.o Player.o Game.o prog.o
	$(CC) helper_functions.o Card.o Deck.o Hand.o Player.o Game.o prog.o -o $(exe_file)
helper_functions.o: helper_functions.h helper_functions.cpp
	$(CC) -c helper_functions.cpp
Card.o: Card.h Card.cpp
	$(CC) -c Card.cpp
Deck.o: Deck.h Deck.cpp
	$(CC) -c Deck.cpp
Hand.o: Hand.h Hand.cpp
	$(CC) -c Hand.cpp
Player.o: Player.h Player.cpp
	$(CC) -c Player.cpp
Game.o: Game.h Game.cpp
	$(CC) -c Game.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
.PHONY: clean
clean:
	rm -f *.out *.o $(exe_file)

