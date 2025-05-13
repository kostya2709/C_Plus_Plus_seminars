#include <iostream>
#include <memory>

struct TaskGenerator : std::enable_shared_from_this<TaskGenerator> {
	
	auto GenerateTask() {
		return [self=shared_from_this()]() {
			std::cout << "Done work for " << self->x << '\n';
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


