CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD
EXEC = canvas
OBJECTS = a3q3.o canvas.o point.o rectangle.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
