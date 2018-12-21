CXX = g++
CXXFLAGS = -std=c++14 -MMD -L/usr/X11R6/lib -lX11 -g
EXEC = face
OBJECTS = face.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
