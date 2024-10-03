#include <stdio.h>

int foo(int x) {
	int result = x * 8;
	return result;	
}

int main() {
	int x = 27;
	
	if (x < 30) {
		x = 31;
	} else {
		x = 0;
	}

	int y = foo(x);
}
