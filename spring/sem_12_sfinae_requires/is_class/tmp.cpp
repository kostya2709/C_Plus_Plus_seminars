#include <vector>

template <typename T>
std::true_type helper(int T::*);

template <typename T>
std::false_type helper(...);

template <typename T>
struct is_class : decltype(helper<T>(nullptr)) {};


int main() {

	static_assert(!is_class<int>::value);
	static_assert(is_class<std::vector<int>>::value);

}
