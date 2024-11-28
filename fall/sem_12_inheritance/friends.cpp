#include <iostream>

class Granny {
protected:
    int x = 0;
    friend class Mom;
};

class Mom: private Granny {
private:
    int y = 1;
    void f(Mom m) {
        Granny& g = m;
        std::cout << m.y;
		std::cout << m.x;
		std::cout << m.Granny::x;
		std::cout << g.x;
    }
    // friend class Son;
};

class Son: private Mom {
    void f(Mom m) {
        Granny& g = m;
        std::cout << m.y;
		std::cout << m.x;
		std::cout << g.x;
    }

	void bar() {
		std::cout << x;
		std::cout << y;
	}

};


int main() {}
