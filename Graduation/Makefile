CC=g++
CFLAGS=-std=c++11 -O3 -Wall
LDFLAGS=
SOURCE=graduation.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=$(SOURCE:.cpp=)

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm $(EXECUTABLE)

