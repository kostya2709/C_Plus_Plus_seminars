#include <unordered_map>

struct Test {};

template <typename T>
requires requires (T a) {
// 	typename std::hash<T>; // ?
   std::hash<T>()(a); // ?
}

void test(const T& obj) {

	std::unordered_map<T, int> map;
	map[obj] = 1;

}

int main() {
   test(Test{});	
   test(0ull);
}
