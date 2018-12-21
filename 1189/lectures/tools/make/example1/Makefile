myprogram: main.o list.o iter.o node.o
	g++-5 -std=c++14 main.o list.o iter.o node.o -o myprogram

list.o: list.cc list.h node.h
	g++-5 -std=c++14 -c list.cc

node.o: node.cc node.h list.h
	g++-5 -std=c++14 -c node.cc

iter.o: iter.cc list.h node.h
	g++-5 -std=c++14 -c iter.cc

main.o: main.cc list.h
	g++-5 -std=c++14 -c main.cc
