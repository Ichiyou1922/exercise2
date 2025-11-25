CC = gcc
CFLAGS = -Wall -Wextra

app: main.o calc.o
	$(CC) $(CFLAGS) -o app main.o calc.o

main.o: main.c calc.h
	$(CC) $(CFLAGS) -c main.c

calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c

clean: 
	rm -f *.o app

