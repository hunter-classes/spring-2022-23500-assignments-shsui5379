main: main.o Node.o List.o
	g++ -o main main.o Node.o List.o


main.o: main.cpp Node.h

Node.o: Node.cpp Node.h

List.o: List.cpp List.h Node.h


clean:
	rm -f *.o