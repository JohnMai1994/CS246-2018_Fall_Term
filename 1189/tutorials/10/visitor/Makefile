CXX = g++
CXXFLAGS = -std=c++14 -Werror -MMD
EXEC = visitor
OBJECTS = binarytreenode.o main.o nodecounter.o prettyprinter.o treenode.o unarytreenode.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
