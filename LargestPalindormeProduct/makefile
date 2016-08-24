CC=g++
CFLAGS=-std=c++11 -Wall
LDFLAGS=
SOURCE=main.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=$(SOURCE:.cpp=)

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE)
