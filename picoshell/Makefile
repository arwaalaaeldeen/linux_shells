CC = gcc
CFLAGS = -Wall -Wextra -g

# Target executable name (change if needed)
TARGET = picoshell

# Source files
SRCS = picoshell.c functions.c exec.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o
