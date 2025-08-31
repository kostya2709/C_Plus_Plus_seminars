#include <vector>


template <typename T>
void foo(typename std::vector<T>::iterator vec) {

}

template <typename T>
void bar(std::vector<T> vec) {

}


int main() {
	bar(std::vector<int>());
	foo(std::vector<int>().begin());
}
