#include <iostream>
#include <memory>

struct TaskGenerator {
	
	auto GenerateTask() {
		return [this]() {
			std::cout << "Done work for " << x << '\n';
		};
	}

	int x = 27;
};

auto foo() {
	auto generator = std::make_shared<TaskGenerator>();
	return generator->GenerateTask();
}

int main() {
	auto task = foo();
	task();
}


