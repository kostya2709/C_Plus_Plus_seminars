#include <iostream>
#include <vector>

struct Test {

	std::vector<int> data_{10, 20, 30};

	std::vector<int> GetAllMyData() & {
		std::cout << "&\n";
		return data_;
	}

	std::vector<int> GetAllMyData() && {
		std::cout << "&&\n";
		return std::move(data_);
	}

};


int main() {
	Test test1;
	auto vec1 = test1.GetAllMyData();
	std::cout << test1.data_.size() << ' ' << vec1.size() << '\n';

	Test test2;
	auto vec2 = std::move(test2).GetAllMyData(); // Test().GetAllMyData()
	std::cout << test2.data_.size() << ' ' << vec2.size() << '\n';
}
