CC=g++
CFLAGS=-std=c++11 -Wall
LDFLAGS=
SOURCE=avoidroads.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=avoidroads

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE)
