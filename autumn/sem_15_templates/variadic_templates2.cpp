#include <type_traits>

template <typename First, typename Second, typename... Types>
struct is_homogeneous {
	static constexpr bool value = std::is_same_v<First, Second>
        	&& is_homogeneous<Second, Types...>::value;
};

template <typename First, typename Second>
struct is_homogeneous<First, Second> {
	static constexpr bool value = std::is_same_v<First, Second>;
};

int main() {

	static_assert(is_homogeneous<int, int>::value);
	static_assert(!is_homogeneous<int, char>::value);
	static_assert(!is_homogeneous<int, double>::value);

}
