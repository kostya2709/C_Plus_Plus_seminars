#include <iostream>
#include <iostream>

class Empty {

};

class NotEmpty : Empty {
 	int x;
};

int main() {
	std::cout << "sizeof(Empty) = " << sizeof(Empty) << '\n';
	std::cout << "sizeof(NotEmpty) = " << sizeof(NotEmpty) << '\n';
}
