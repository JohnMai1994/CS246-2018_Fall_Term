CXX = g++-5
CXXFLAGS = -std=c++14 -Werror -MMD -lncurses -g
EXEC = maze
OBJECTS = keyboard.o  main.o  maze.o  model.o  standard.o controller.o curseControl.o curseView.o writtenView.o rightHand.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
