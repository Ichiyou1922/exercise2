CC = gcc
CFLAGS = -Wall -Wextra -o2
TARGET = image_proc
OBJS = main.o filter.o io.o

image_proc: main.o filter.o io.o
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c filter.h io.h
	$(CC) $(CFLAGS) -c main.c

filter.o: filter.c filter.h 
	$(CC) $(CFLAGS) -c filter.c

io.o: io.c io.h
	$(CC) $(CFLAGS) -c io.c

clean:
	rm -f *.o $(TARGET)

