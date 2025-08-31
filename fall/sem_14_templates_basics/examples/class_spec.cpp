#include <unordered_map>
#include <iostream>

class Test {
public:
	int x = 0;
	
	bool operator==(const Test& test) const {
		return x == test.x;
	}

};

template <>
struct std::hash<Test> {
	size_t operator()(const Test& test) const {
		return std::hash<int>()(test.x);
	}
};

struct Hasher {
	size_t operator()(const Test& test) const {
		return std::hash<int>()(test.x);
	}
};

int main() {

	Test test;	
	std::unordered_map<Test, int> map1;
	map1[test] = 0;

	std::unordered_map<Test, int, Hasher> map2;
	map2[test] = 1;
}

