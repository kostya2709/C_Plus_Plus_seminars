#include <iostream>

template <typename T>
class function;

template <typename Ret, typename... Args>
class function<Ret(Args...)> {

	struct Base {
		virtual Ret operator()(Args... args) = 0;
		virtual ~Base() = default;
	};

	template <typename Foo>
	struct Derived : Base {
		Foo foo;
		Derived(const Foo& foo) : foo(foo) {}
		Ret operator()(Args... args) {
			obj.*foo(args - 1)
			return foo(std::forward<Args>(args)...);
		}
	};

public:
	Ret operator()(Args... args) {
		return (*foo)(std::forward<Args>(args)...);
	}

	template <typename Foo>
	function(const Foo& foo) : foo(new Derived(foo)) {
		
	}

	~function() {
		delete foo;
	}

private:
	Base* foo;
};

int sum(int x, int y) {
	return x + y;
}

int main() {
	function<int(int, int)> func(&sum);
	std::cout << func(1, 2) << '\n';
}

