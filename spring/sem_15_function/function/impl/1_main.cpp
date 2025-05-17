#include <iostream>

template <typename T>
class function;

template <typename Ret, typename... Args>
class function<Ret(Args...)> {
private:
	struct Base {
		virtual Ret call(Args...) = 0;
		virtual ~Base() = default;	
	};

	template <typename Foo>
	struct Derived : Base {
		Foo func;
		virtual ~Derived() = default;
		
		Derived(const Foo& func) : func(func) {}
		Ret call(Args... args) override {
			return func(std::forward<Args>(args)...);
		}
	};
private:
	Base* fptr_;

public:
	template <typename Foo>
	function(Foo&& func) : fptr_(new Derived<Foo>(func)) {}

	Ret operator()(Args... args) const {
		return fptr_->call(std::forward<Args>(args)...);
	}

	~function() {
		delete fptr_;
	}	
};

int sum(int x, int y) {
	return x + y;
}

int main() {

	function<int(int, int)> sum_func{sum};
	std::cout << "sum(1, 2) = " << sum(1, 2) << '\n';

}
