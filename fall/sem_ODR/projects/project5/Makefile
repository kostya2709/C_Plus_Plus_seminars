
CC=g++
CFLAGS=-c -Wall

all: main.o print.o lucky.o
	$(CC) main.o print.o lucky.o

main.o:
	$(CC) $(CFLAGS) main.cpp

print.o:
	$(CC) $(CFLAGS) print.cpp

lucky.o:
	$(CC) $(CFLAGS) lucky.cpp

clean:
	rm -rf *.o a.out

