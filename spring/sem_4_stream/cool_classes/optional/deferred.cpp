#include <optional>
#include <iostream>

class Test {
private:
    std::optional<double> last_seen;

public:
    void update(double value) {
        last_seen = value;
    }

	std::optional<double> get_last() const {
        return last_seen;
    }
};

void print(std::optional<double> value) {
	if (value) {
		std::cout << *value << '\n';
	} else {
		std::cout << "No value yet!\n";
	}
}


int main() {

	Test obj;
	print(obj.get_last());
//	double val = obj.get_last().value();

	obj.update(3.1415);
	print(obj.get_last());
}

