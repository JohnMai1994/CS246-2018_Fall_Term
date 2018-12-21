CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = main
OBJECTS = main.o observer.o subject.o horserace.o bettor.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
