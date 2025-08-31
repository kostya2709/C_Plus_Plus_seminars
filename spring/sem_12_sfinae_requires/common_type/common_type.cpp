#include <type_traits>

struct Base {};
struct Derived1 : Base {};
struct Derived2 : Base {};

template <typename... Types>
struct common_type;

template <typename T>
struct common_type<T> : std::type_identity<std::decay_t<T>> {};

template <typename U, typename V>
struct common_type<U, V> : std::type_identity<std::decay_t<decltype(true ? std::declval<U>() : std::declval<V>())>> {};

template <typename T, typename... Types>
struct common_type<T, Types...> : common_type<typename common_type<Types...>::type, std::decay_t<T>> {};

template <typename T>
void foo() = delete;

int main() {

	static_assert(std::is_same_v<common_type<Base>::type, Base>);
	static_assert(std::is_same_v<common_type<Base, Derived1>::type, Base>);
}
