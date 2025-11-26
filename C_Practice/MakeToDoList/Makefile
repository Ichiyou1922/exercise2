CC = gcc
CFLAGS = -wall -Wextra

app: main.o list.o file.o
	$(CC) $(CFLAGS) -o todo_app main.o list.o file.o

main.o: main.c list.h file.h
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

file.o: file.c file.h
	$(CC) $(CFLAGS) -c file.c

clean:
	rm -f *.o app

