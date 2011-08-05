CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Game.cpp GameBoard.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=TicTacToe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

