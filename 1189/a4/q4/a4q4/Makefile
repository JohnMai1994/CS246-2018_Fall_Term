CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla -L/usr/X11R6/lib 
EXEC = a4q4 
OBJECTS = main.o cell.o grid.o window.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
