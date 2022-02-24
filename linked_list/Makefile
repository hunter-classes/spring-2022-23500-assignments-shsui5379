main: main.o Node.o
	g++ -o main main.o Node.o


main.o: main.cpp Node.h

Node.o: Node.cpp Node.h


clean:
	rm -f *.o