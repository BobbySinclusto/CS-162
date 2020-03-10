CC = g++ -std=c++11 -g
exe_file = zoo_tycoon

$(exe_file): Animal.o Bear.o SeaLion.o Tiger.o helper_functions.o Zoo.o prog.o
	$(CC) Animal.o Bear.o SeaLion.o Tiger.o helper_functions.o Zoo.o prog.o -o $(exe_file)
Animal.o: Animal.cpp Animal.h
	$(CC) -c Animal.cpp
Bear.o: Bear.h Bear.cpp
	$(CC) -c Bear.cpp
SeaLion.o: SeaLion.h SeaLion.cpp
	$(CC) -c SeaLion.cpp
Tiger.o: Tiger.h Tiger.cpp
	$(CC) -c Tiger.cpp
helper_functions.o: helper_functions.h helper_functions.cpp
	$(CC) -c helper_functions.cpp
Zoo.o: Zoo.h Zoo.cpp
	$(CC) -c Zoo.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
.PHONY: clean
clean:
	rm -f *.out *.o $(exe_file)

