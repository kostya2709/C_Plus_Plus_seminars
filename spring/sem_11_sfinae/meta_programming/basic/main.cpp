#include <type_traits>

template <typename T>
struct type_identity {
	using type = T;
};

template <typename T>
using type_identity_t = type_identity<T>::type;


template <typename T, T x>
struct integral_constant {
	static constexpr T value = x;
};

template <bool b>
using bool_constant = integral_constant<bool, b>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;


int main() {

	static_assert(std::is_same_v<type_identity_t<int>, int>);
	static_assert(integral_constant<int, 5>::value == 5);
	static_assert(bool_constant<true>::value);
	static_assert(!bool_constant<false>::value);
	static_assert(true_type::value);
	static_assert(!false_type::value);


}
