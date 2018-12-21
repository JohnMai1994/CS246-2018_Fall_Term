CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla 
EXEC = a4q5
OBJECTS = main.o allcaps.o echo.o textprocess.o dropfirst.o count.o double.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

