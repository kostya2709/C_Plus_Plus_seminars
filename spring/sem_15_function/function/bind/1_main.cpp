#include <iostream>
#include <functional>

int diff(int x, int y) {
	return x - y;
}

int main() {

	using namespace std::placeholders;
	std::function<int(int)> f = std::bind(diff, 12, _1);
	std::cout << f(5) << '\n';

}
