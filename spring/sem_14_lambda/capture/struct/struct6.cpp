#include <iostream>

struct TaskGeneratorOnce {
	
	auto GenerateTask() {
		return [this]() {
			std::cout << "Done work for " << x << '\n';
			delete this;
		};
	}

	int x = 27;
};

int main() {

	TaskGeneratorOnce* generator = new TaskGeneratorOnce();
	auto task = generator->GenerateTask();
	task();
}


