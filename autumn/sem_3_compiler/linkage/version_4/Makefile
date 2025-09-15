
all: main

src.o: src.cpp
	g++ -c src.cpp

my_lib.o: my_lib.cpp
	g++ -c my_lib.cpp

main.o: main.cpp
	g++ -c main.cpp

main: main.o src.o my_lib.o
	g++ main.o src.o my_lib.o

clean:
	rm *.out *.o
	
