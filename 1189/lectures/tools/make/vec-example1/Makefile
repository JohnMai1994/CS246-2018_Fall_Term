myprogram: main.o vec.o
	g++ main.o vec.o -o myprogram

vec.o: vec.cc vec.h
	g++ -std=c++14 -c vec.cc

main.o: main.cc vec.h
	g++ -std=c++14 -c main.cc

.PHONY: clean

clean:
	rm *.o myprogram
