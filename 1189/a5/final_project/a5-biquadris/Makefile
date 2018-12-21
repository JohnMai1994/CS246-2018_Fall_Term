CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD -L/usr/X11/lib 
EXEC = biquadris
OBJECTS = main.o Board.o BasicBoard.o cell.o Block.o LBlock.o IBlock.o OBlock.o XBlock.o CBlock.o SBlock.o TBlock.o JBlock.o ZBlock.o Level.o StarBlock.o window.o draw.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}  -lX11 

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
