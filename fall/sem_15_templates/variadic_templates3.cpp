#include <type_traits>


template <typename Head, typename... Tail>
struct is_homogeneous {
	static constexpr bool value = (std::is_same_v<Head, Tail> && ...);  
};


int main() {

	static_assert(is_homogeneous<int>::value);
	static_assert(is_homogeneous<int, int>::value);
	static_assert(!is_homogeneous<int, double>::value);

}
