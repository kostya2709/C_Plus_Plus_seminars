#include <iostream>

void foo() {
    throw std::string("a"); // 1
}

class Test {
public:
    Test() {
        std::cout << "Test()\n";
    }
    ~Test() {
        std::cout << "~Test()\n";
    }
};

int main() {
    try {
        Test test;
        foo();
    } catch (long x) {
        std::cout << "Exception long " << x << " was caught!\n";
    } catch (double x) {
        std::cout << "Exception double " << x << " was caught!\n";
    } catch (float x) {
        std::cout << "Exception float " << x << " was caught!\n";
    } catch (int x) {
        std::cout << "Exception int " << x << " was caught!\n";
    } catch (...) {
        std::cout << "Exception was caught!\n";
    }
}
