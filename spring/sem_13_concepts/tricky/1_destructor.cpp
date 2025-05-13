#include <vector>
#include <iostream>


template<typename T>
class optional
{
public:
	optional() = default;

	~optional() requires(not std::is_trivially_destructible_v<T>) {
		std::cout << "Not trivially\n";
		if (has_value) {
			reinterpret_cast<T*>(&buff)->~T();
		}
	}

	~optional() = default;

private:
	alignas(T) std::byte buff[sizeof(T)];
	bool has_value;
};


int main() {
	
	optional<int> opt1;
	optional<std::vector<int>> opt2;

}
