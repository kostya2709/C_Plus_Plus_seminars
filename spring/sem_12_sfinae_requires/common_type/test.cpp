#include <type_traits>
#include <vector>

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

template<typename T>
auto foo(const T&, typename common_type<T, int>::type v) {}

auto foo(...) {}

template<typename T>
auto bar(const T&, typename std::common_type<T, int>::type v) {}

auto bar(...) {}

int main() {

	// foo(std::vector<int>(), 5);
	bar(std::vector<int>(), 5);

	static_assert(std::is_same_v<common_type<Base>::type, Base>);
	static_assert(std::is_same_v<common_type<Base, Derived1>::type, Base>);
}
