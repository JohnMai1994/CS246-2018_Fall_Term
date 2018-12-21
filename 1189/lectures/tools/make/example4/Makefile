CXX = g++-5
CXXFLAGS = -std=c++14 -Wall
EXEC = myprogram
OBJECTS = main.o list.o iter.o node.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

list.o: list.cc list.h node.h

node.o: node.cc node.h list.h

iter.o: iter.cc list.h node.h

main.o: main.cc list.h

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC}
