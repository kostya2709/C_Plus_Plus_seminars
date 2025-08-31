#include <iostream>
#include <string>

int main() {
    std::string s = "Greeting: world!";

    s.insert(10, "Hello, ");
    std::cout << s << "\n";  // Greeting: Hello, world!

    s.replace(10, 5, "Hi");
    std::cout << s << "\n";  // Greeting: Hi, world!

    s.erase(0, 10);
    std::cout << s << "\n";  // Hi, world!
}
