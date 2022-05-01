main: main.o BSTree.o Node.o
	g++ -o main main.o BSTree.o Node.o

tests: tests.o BSTree.o Node.o
	g++ -o tests tests.o BSTree.o Node.o

clean:
	rm -f *.o


main.o: main.cpp BSTree.h Node.h

tests.o: tests.cpp BSTree.h Node.h ../../commons/doctest.h

BSTree.o: BSTree.cpp BSTree.h Node.h

Node.o: Node.cpp Node.h