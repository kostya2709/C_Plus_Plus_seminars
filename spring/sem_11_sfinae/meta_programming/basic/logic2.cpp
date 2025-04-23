#include <type_traits>

template<class...>
struct Conjunction : std::true_type {};
 
template<class B1>
struct Conjunction<B1> : B1 {};
 
template<class B1, class... Bn>
struct Conjunction<B1, Bn...>
    : std::conditional_t<bool(B1::value), Conjunction<Bn...>, B1> {};

int main() {
	
	static_assert(Conjunction<std::true_type, std::true_type>::value);
	static_assert(!Conjunction<std::true_type, std::false_type>::value);
	
	static_assert(!Conjunction<std::true_type, std::false_type, int>::value);

}
