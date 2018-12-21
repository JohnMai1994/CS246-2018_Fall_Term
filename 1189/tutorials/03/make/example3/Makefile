CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD
EXEC = vec3d
OBJECTS = main-vec3d.o vec3d.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
