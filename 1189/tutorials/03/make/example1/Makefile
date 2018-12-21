vec3d: main-vec3d.o vec3d.o
	g++ -std=c++14 main-vec3d.o vec3d.o -o vec3d

main-vec3d.o: main-vec3d.cc vec3d.h
	g++ -std=c++14 -c main-vec3d.cc

vec3d.o: vec3d.cc vec3d.h
	g++ -std=c++14 -c vec3d.cc

clean:
	rm *.o vec3d

.PHONY: clean
