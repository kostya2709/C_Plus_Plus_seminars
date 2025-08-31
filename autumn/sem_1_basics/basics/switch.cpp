#include <iostream>


int main() {
	int x = 1;
	int y = 1;
	
	switch (x) {
		case 1:	
			std::cout << 1;
			break;			
		case 0: 
			std::cout << 0;
			break;
		default:
			std::cout << "other";
	}
}
