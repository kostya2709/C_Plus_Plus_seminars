#include <iostream>

template <typename T>
class function;

template <typename Ret, typename... Args>
class function<Ret(Args...)> {

private:

	void* fptr_;

	using caller_ptr_t = Ret(*)(void*, Args...);
	caller_ptr_t caller_ptr_;
	
	using destroyer_ptr_t = void(*)(void*);
	destroyer_ptr_t destroyer_ptr_;

	template <typename Foo>
	static Ret caller(Foo* ptr, Args... args) {
		return (*ptr)(std::forward<Args>(args)...); // std::invoke?
	}
	
	template <typename Foo>
	static void destroyer(Foo* ptr) {
		delete ptr;
	}

public:
	template <typename Foo>
	function(const Foo& func) :
		fptr_(new Foo(func)),
		caller_ptr_(reinterpret_cast<caller_ptr_t>(&caller<Foo>)),
		destroyer_ptr_(reinterpret_cast<destroyer_ptr_t>(&destroyer<Foo>)) {}

	Ret operator()(Args... args) const {
		return caller_ptr_(fptr_, std::forward<Args>(args)...);
	}

	~function() {
		destroyer_ptr_(fptr_);
	}	
};

int sum(int x, int y) {
	return x + y;
}

int main() {

	function<int(int, int)> sum_func{&sum};
	std::cout << "sum(1, 2) = " << sum_func(1, 2) << '\n';

	return 0;
}
