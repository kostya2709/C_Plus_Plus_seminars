#include <memory>

int main() {
	std::unique_ptr ptr = std::make_unique<int>(27);
	std::unique_ptr other = ptr;
}
