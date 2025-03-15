#include <iostream>
#include <optional>

template <typename T>
class Optional {
private:
    alignas(T) unsigned char data[sizeof(T)];
    bool engaged = false;

public:
    Optional() = default;
    
	Optional(const T& value) {
        new (data) T(value);
        engaged = true;
    }

    ~Optional() {
        reset();
    }

    bool has_value() const { return engaged; }

    T& value() {
        if (!engaged) throw std::bad_optional_access();
        return *reinterpret_cast<T*>(data);
    }

    void reset() {
        if (engaged) {
            reinterpret_cast<T*>(data)->~T();
            engaged = false;
        }
    }
};


int main() {

	Optional<double> test;
	test = 18;
	std::cout << test.value() << '\n';
}
