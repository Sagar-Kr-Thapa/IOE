CC = g++

SOURCES = $(wildcard *.cpp)
BINARY = $(patsubst %.cpp, %, $(SOURCES))

% :%.cpp
	$(CC) $< -o $@

all : $(BINARY)

.PHONY : clean

clean : 
	rm -f $(BINARY)

