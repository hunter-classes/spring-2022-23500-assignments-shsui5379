main: main.o Dictionary.o List.o Node.o Person.o
	g++ -o main main.o Dictionary.o List.o Node.o Person.o

tests: tests.o Dictionary.o List.o Node.o Person.o
	g++ -o tests tests.o Dictionary.o List.o Node.o Person.o

clean:
	rm -f *.o


main.o: main.cpp Dictionary.h

tests.o: tests.cpp Dictionary.h ../../commons/doctest.h


Dictionary.o: Dictionary.cpp Dictionary.h List.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h Person.h

Person.o: Person.cpp Person.h