CC = g++ -std=c++11

exe: program.cpp dllist.hpp
	$(CC) -o program.exe program.cpp

test: unit-test.cpp dllist.hpp
	$(CC) -o unit-test.exe unit-test.cpp

clean:
	rm *.exe
