main: main.o Stack.o Node.o List.o
	g++ -o main main.o Stack.o Node.o List.o

tests: tests.o Stack.o Node.o List.o
	g++ -o tests tests.o Stack.o Node.o List.o

clean:
	rm -f *.o


main.o: main.cpp Stack.h

tests.o: tests.cpp Stack.h ../../commons/doctest.h

Stack.o: Stack.cpp Stack.h List.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h