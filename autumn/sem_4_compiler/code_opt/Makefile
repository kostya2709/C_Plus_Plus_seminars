
all:
	g++ main.cpp
	./a.out > tmp

fast:
	g++ -Ofast main.cpp
	./a.out > tmp

disass:
	objdump -d -M intel ./a.out > disass
