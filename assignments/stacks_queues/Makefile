main: main.o Stack.o Node.o List.o Queue.o
	g++ -o main main.o Stack.o Node.o List.o Queue.o

tests: tests.o Stack.o Node.o List.o Queue.o
	g++ -o tests tests.o Stack.o Node.o List.o Queue.o

clean:
	rm -f *.o


main.o: main.cpp Stack.h Queue.h

tests.o: tests.cpp Stack.h Queue.h ../../commons/doctest.h

Stack.o: Stack.cpp Stack.h List.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

Queue.o: Queue.cpp Queue.h