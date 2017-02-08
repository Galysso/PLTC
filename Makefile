CXX = g++
SOURCES = Generator/Generator.cpp Algorithmes/A1.cpp Algorithmes/A2.cpp Algorithmes/A3.cpp
CFLAGS = -Wall -g -Ofast
LDFLAGS =
.PHONY = clean

all: main

main: $(SOURCES:.cpp=.o) $(LDFLAGS)

clean: 
	rm ./Generator/*.o
	rm ./Algorithmes/*.o
