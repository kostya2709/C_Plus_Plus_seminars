#include <iostream>
#include <memory>

struct A { int a = 1; };  
struct B { int b = 2; };  
struct C : A, B {};  

int main() {
    auto c_ptr = std::make_shared<C>();  
    std::shared_ptr<B> b_ptr(c_ptr, static_cast<B*>(c_ptr.get()));  

	std::cout << "use_count: " << c_ptr.use_count() << '\n';
    std::cout << "value: " << b_ptr->b << '\n';
}
