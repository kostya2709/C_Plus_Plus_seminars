#include <vector>


template <typename T>
int foo(T x) {
	return x;
}


int main() {

	foo(8);
	foo(std::vector<int>());

}
