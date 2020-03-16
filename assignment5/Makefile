CC=g++ -std=c++11 -g -Wall
exe_file=awesome_program

$(exe_file): Node.hpp Linked_List.hpp helper_functions.o prog.o
	$(CC) Node.hpp Linked_List.hpp helper_functions.o prog.o -o $(exe_file)
helper_functions.o: helper_functions.h helper_functions.cpp
	$(CC) -c helper_functions.cpp
prog.o: Linked_List.hpp prog.cpp
	$(CC) -c prog.cpp
.PHONY: clean
clean:
	rm -f *.o $(exe_file)