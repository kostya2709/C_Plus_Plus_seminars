#include <iostream>

template <typename T>
auto foo(T obj) {
	return obj;
}

template <typename T>
requires requires (T a) {
	{foo(a)} -> std::same_as<int>;
}
void bar(T obj) {
	int x = foo(obj);
}

int main() {

	bar(1);
	bar('a');
	bar(nullptr);

}
