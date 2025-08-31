#include <type_traits>

struct CopyConstructible {

	CopyConstructible(const CopyConstructible&) {}
};

struct NonCopyConstructible {

	NonCopyConstructible(const NonCopyConstructible&) = delete;
};

namespace detail {

	template <typename T>
	std::true_type helper(decltype(T(std::declval<const T&>()), nullptr));

	template <typename...>
	std::false_type helper(...);

};

template <typename T>
struct is_copy_constructible : decltype(detail::helper<T>(nullptr)) {};

template <typename T>
constexpr bool is_copy_constructible_v = is_copy_constructible<T>::value;

int main() {

	static_assert(is_copy_constructible_v<CopyConstructible>);
	static_assert(!is_copy_constructible_v<NonCopyConstructible>);

}

