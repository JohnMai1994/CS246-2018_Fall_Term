CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD
EXEC = emailgroups
OBJECTS = a3q2.o group.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
