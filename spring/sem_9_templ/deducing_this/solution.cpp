#include <iostream>
#include <vector>

template <typename T>
void check_type() = delete;


template <typename T>
struct Test {

private:
	std::vector<T> data_;

public:	
	Test(int x) : data_(x) {}

	template <typename Self>
	auto&& GetData(this Self&& self) {
		// some hard work...
		return std::forward<Self>(self).data_;
	}
};

template <typename T>
struct Container {

private:
	Test<T> test_{27};

public:
	/*
	std::vector<T>& GetData() & {
		return test_.GetData();
	}*/

	auto&& GetData(this auto&& self) {

		return std::forward_like<decltype(self)>(self.test_).GetData();
		// return std::forward<decltype(self)>(self).test_.GetData();
	}
/*
	std::vector<T>&& GetData() && {
		return std::move(test_).GetData();
	}
	
	const std::vector<T>& GetData() const & {
		return test_.GetData();
	}
	
	const std::vector<T>&& GetData() const && {
		return std::move(test_).GetData();
	}
*/
};


int main() {
	Container<int> cont;
	const Container<int>& cont_ref = cont;
	const std::vector<int>& test = cont_ref.GetData();

	
//	check_type<decltype(cont.GetData())>();
	check_type<decltype(std::move(cont).GetData())>();
/*	check_type<decltype(cont_ref.GetData())>();
	check_type<decltype(std::move(cont_ref).GetData())>();
	*/
	
}

