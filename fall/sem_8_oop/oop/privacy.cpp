#include <iostream>

class C {
private:
	class Inner {
	public:
    	int x = 1;
	private:
    	int y = 2;
	};

public:

	class Inner2 {
	public:
		int x = 3;
	};

	Inner f() {
    	return Inner();
	}
};

int main() {    
	C c;
	std::cout << c.f().x << '\n'; // CE or 1?
	// std::cout << c.f().y << '\n'; // CE or 2?
	// std::cout << C::Inner2().x << '\n'; // CE or 3?
	// std::cout << C::Inner().x << '\n'; // CE or 1?
}
