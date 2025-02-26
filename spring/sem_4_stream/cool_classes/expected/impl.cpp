#include <exception>
#include <expected>
#include <iostream>
#include <utility>

template <typename T, typename E>
class Expected {
private:
    union {
        T value_;
        E error_;
    };
    bool is_value_;

public:
    Expected(const T& val) : value_(val), is_value_(true) {}
    Expected(const E& err) : error_(err), is_value_(false) {}

    ~Expected() {
        if (is_value_) value_.~T();
        else error_.~E();
    }

    T& value() {
        if (!is_value_) throw std::bad_expected_access(error_);
        return value_;
    }

    E& error() {
        if (is_value_) throw std::bad_expected_access("");
        return error_;
    }

    bool has_value() const { return is_value_; }
};

int main() {

	Expected<int, double> value(27);
	std::cout << value.value() << '\n';

}
