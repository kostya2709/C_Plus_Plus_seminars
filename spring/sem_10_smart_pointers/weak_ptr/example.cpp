#include <iostream>
#include <memory>

int main() {
	
	auto shared = std::make_shared<int>(1);
	std::cout << shared.use_count() << '\n';

	std::weak_ptr<int> weak = shared;
	std::cout << shared.use_count() << '\n';

	{
		auto ptr = weak.lock();
		std::cout << shared.use_count() << '\n';
	}

}
