CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD
EXEC = plan
OBJECTS = date.o a3q1.o call.o plan.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
