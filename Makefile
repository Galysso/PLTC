CXX = g++
SOURCES = Generator/Generator.cpp Algorithmes/A1.cpp
CFLAGS = -Wall -g -O3
LDFLAGS =
.PHONY = clean

all: main

main: $(SOURCES:.cpp=.o) $(LDFLAGS)

clean: 
	rm ./Generator/*.o
	rm ./Algorithmes/*.o
