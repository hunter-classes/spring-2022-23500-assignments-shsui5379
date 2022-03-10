main: main.o Node.o List.o OList.o
	g++ -o main main.o Node.o List.o OList.o

tests: tests.o Node.o List.o OList.o
	g++ -o tests tests.o Node.o List.o OList.o


main.o: main.cpp Node.h List.h OList.h

tests.o: tests.cpp ../../commons/doctest.h OList.h

Node.o: Node.cpp Node.h

List.o: List.cpp List.h Node.h

OList.o: OList.cpp OList.h List.h


clean:
	rm -f *.o