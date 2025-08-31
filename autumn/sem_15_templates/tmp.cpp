#include <type_traits>

template <typename First, typename Second, typename... Tail>
struct is_homo {
	static const bool value = std::is_same_v<First, Second> && is_homo<Second, Tail...>::value;
};

template <typename First, typename Second>
struct is_homo<First, Second> {
	static const bool value = std::is_same_v<First, Second>;
};

template <typename... Types>
const bool is_homo_v = is_homo<Types...>::value;

int main() {

	static_assert(is_homo_v<int, int, int>);
	static_assert(is_homo_v<int, int>);
	static_assert(!is_homo_v<int, float, int>);
}
