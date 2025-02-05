#include <iostream>

int main() try {
    throw 1;
} catch (int x) {
    std::cout << "Caught int " << x << '\n'; 
}