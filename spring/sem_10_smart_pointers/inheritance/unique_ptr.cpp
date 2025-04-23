#include <iostream>
#include <memory>

struct Base {
    virtual ~Base() {
        std::cout << "~Base\n";
    }
};

struct Derived : Base {
    ~Derived() {
        std::cout << "~Derived\n";
        delete ptr_;
    }
private:
    int* ptr_{new int(27)};
};


int main() {

	std::unique_ptr<Base> ptr(new Derived());

	auto derived_ptr = std::make_unique<Derived>();  
    std::unique_ptr<Base> base_ptr = std::move(derived_ptr);  
    derived_ptr.reset(); 

}  
