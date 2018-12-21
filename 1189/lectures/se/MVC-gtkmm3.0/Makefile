CXX= g++-5 -std=c++14
CXXFLAGS = -Wall `pkg-config gtkmm-3.0 --cflags` -MMD
LDFLAGS=`pkg-config gtkmm-3.0 --libs`
SOURCES = $(wildcard *.cc) # list of all .cc files in the current directory
OBJECTS = ${SOURCES:.cc=.o} # .o files depend upon .cc files with same names
DEPENDS = ${OBJECTS:.o=.d}  # .d file is list of dependencies for corresponding .cc file
EXEC = mvc

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) $(CXXFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm $(EXEC) $(OBJECTS) $(DEPENDS)

-include ${DEPENDS} # reads the .d files and reruns dependencies
