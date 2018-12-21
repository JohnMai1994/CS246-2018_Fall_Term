CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g
EXEC = vec3d
OBJECTS = main-vec3d.o vec3d.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

main-vec3d.o: main-vec3d.cc vec3d.h

vec3d.o: vec3d.cc vec3d.h

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC}
