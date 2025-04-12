#include <type_traits>
#include <utility>

struct Test {
	template <typename Self>
	void foo(this Self&& self, int) {
		static_assert(std::is_same_v<Self, Test&>);
	}
};

struct Derived : Test { };

int main() {
	Test test;
	Derived derived;
	
	// test.foo(1);
	// std::move(test).foo(2);
    derived.foo(3);
}
