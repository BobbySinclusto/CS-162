CC = g++ -std=c++11
exe_file = budget_buddy

$(exe_file): budget_buddy.o prog.o
	$(CC) budget_buddy.o prog.o -o $(exe_file)
budget_buddy.o: budget_buddy.cpp
	$(CC) -c budget_buddy.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
.PHONY: clean
clean:
	rm -f *.out *.o $(exe_file)

