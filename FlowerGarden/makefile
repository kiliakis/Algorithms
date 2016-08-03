CC=g++
CFLAGS=-std=c++11 -Wall
LDFLAGS=
SOURCE=flowergarden.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=flowergarden

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE)
