#include <memory>
#include <functional>

int main() {
	
	auto uptr = std::make_unique<int>(27);
	auto sum = [uptr=std::move(uptr)](int x) -> int {
		return x + *uptr;
	};
	
	std::function<int(int)> func(std::move(sum));
}
