CC = g++ -std=c++11 -Wall -g
exe_file = wumpus

$(exe_file): Event.o Wumpus.o Pit.o Bat.o Gold.o Room.o helper_functions.o AiData.o Game.o prog.o
	$(CC) Event.o Wumpus.o Pit.o Bat.o Gold.o Room.o helper_functions.o AiData.o Game.o prog.o -o $(exe_file)
Event.o: Event.h Event.cpp
	$(CC) -c Event.cpp
Wumpus.o: Event.h Wumpus.h Wumpus.cpp
	$(CC) -c Wumpus.cpp
Pit.o: Event.h Pit.h Pit.cpp
	$(CC) -c Pit.cpp
Bat.o: Event.h Bat.h Bat.cpp
	$(CC) -c Bat.cpp
Gold.o: Event.h Gold.h Gold.cpp
	$(CC) -c Gold.cpp
Room.o: Event.h Room.h Room.cpp
	$(CC) -c Room.cpp
Game.o: Room.h Event.h helper_functions.h AiData.h Game.h Game.cpp
	$(CC) -c Game.cpp
helper_functions.o: helper_functions.h helper_functions.cpp
	$(CC) -c helper_functions.cpp
AiData.o: AiData.h AiData.cpp
	$(CC) -c AiData.cpp
prog.o: helper_functions.h Game.h prog.cpp
	$(CC) -c prog.cpp
.PHONY: clean
clean:
	rm -f *.out *.o $(exe_file)

