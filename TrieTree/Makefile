CC=g++
CFLAGS=-std=c++11 -Og -g -Wall
LDFLAGS=
SOURCE=trietree.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=$(SOURCE:.cpp=)

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm $(EXECUTABLE)

