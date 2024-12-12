#include <type_traits>


template <typename Head, typename... Types>
struct is_homogeneous {
	using prev = is_homogeneous<Types...>;
	static constexpr bool value = prev::value && std::is_same_v<typename prev::type, Head>; 
	using type = Head;
};

template <typename T>
struct is_homogeneous<T> {
	using type = T;
	static constexpr bool value = true;
};

int main() {

	static_assert(is_homogeneous<int>::value);
	static_assert(is_homogeneous<int, int>::value);
	static_assert(!is_homogeneous<int, double>::value);

}
