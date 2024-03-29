CC = gcc

CFLAGS = -c -Wall

LDFLAGS =

SOURCES = main.c gpio-mmap.c
OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = gpio-test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
