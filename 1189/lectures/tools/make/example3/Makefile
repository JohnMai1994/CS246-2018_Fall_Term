CXX = g++-5
CXXFLAGS = -std=c++14 -Wall

myprogram: main.o list.o iter.o node.o
	${CXX} ${CXXFLAGS} main.o list.o iter.o node.o -o myprogram

list.o: list.cc list.h node.h
	${CXX} ${CXXFLAGS} -c list.cc

node.o: node.cc node.h list.h
	${CXX} ${CXXFLAGS} -c node.cc

iter.o: iter.cc list.h node.h
	${CXX} ${CXXFLAGS} -c iter.cc

main.o: main.cc list.h
	${CXX} ${CXXFLAGS} -c main.cc

.PHONY: clean

clean:
	rm *.o myprogram
