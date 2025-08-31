#include <type_traits>

struct NothrowMoveConstructible {

	NothrowMoveConstructible(NothrowMoveConstructible&&) noexcept {}
};

struct NonNothrowMoveConstructible {

	NonNothrowMoveConstructible(NonNothrowMoveConstructible&&) {}
};

struct NotMoveConstructible {

	NotMoveConstructible(NotMoveConstructible&&) = delete;
};

namespace detail {

	template <typename T>
	auto helper(decltype(nullptr)) -> std::bool_constant<noexcept(T(std::declval<T>()))>;

	template <typename...>
	std::false_type helper(...);

};

template <typename T>
struct is_nothrow_move_constructible : decltype(detail::helper<T>(nullptr)) {};

template <typename T>
constexpr bool is_nothrow_move_constructible_v = is_nothrow_move_constructible<T>::value;

int main() {

	static_assert(is_nothrow_move_constructible_v<NothrowMoveConstructible>);
	static_assert(!is_nothrow_move_constructible_v<NonNothrowMoveConstructible>);
	static_assert(!is_nothrow_move_constructible_v<NotMoveConstructible>);

}

