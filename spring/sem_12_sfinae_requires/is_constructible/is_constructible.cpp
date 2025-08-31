#include <type_traits>

struct Test {

	Test(int x, float y) {}
};

namespace detail {


	template <typename T, typename... Args>
	std::true_type helper(decltype(T(std::declval<Args>()...)), nullptr);


	template <typename...>
	std::false_type helper(...);

};

template <typename T, typename... Args>
struct is_constructible : decltype(detail::helper<T, Args...>(nullptr)) {};

template <typename T, typename... Args>
constexpr bool is_constructible_v = is_constructible<T, Args...>::value;

int main() {

	static_assert(is_constructible_v<Test, int, float>);
	static_assert(!is_constructible_v<Test, float>);

}

