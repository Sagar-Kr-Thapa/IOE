CC = g++ -std=c++98

SOURCES = $(wildcard *.cpp)
BINARY = $(patsubst %.cpp, %, $(SOURCES))

% :%.cpp
	$(CC) $< -o $@

all : $(BINARY)

.PHONY : clean

clean : 
	rm -f $(BINARY) Student.dat Transaction.dat

