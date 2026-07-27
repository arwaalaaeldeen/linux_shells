CC = gcc
CFLAGS = -Wall -Wextra -g

# Target executable name
TARGET = femtoshell

# Default rule
all: $(TARGET)

$(TARGET): femtoshell.c
	$(CC) $(CFLAGS) femtoshell.c -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
