CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = main
OBJECTS = main.o student.o regular.o coop.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
