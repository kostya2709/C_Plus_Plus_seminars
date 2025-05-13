#include <iostream>

struct TaskGenerator {
	
	auto GenerateTask() {
		return [this]() {
			std::cout << "Done work for " << x << '\n';
		};
	}

	int x = 27;
};

int main() {

	TaskGenerator generator;
	auto task = generator.GenerateTask();
	task();
}


