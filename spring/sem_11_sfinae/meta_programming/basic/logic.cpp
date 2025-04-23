
#include <type_traits>

template <typename... Bs>
struct Conjunction {
	static constexpr bool value = (bool(Bs::value) &&...);
};

int main() {
	
	static_assert(Conjunction<std::true_type, std::true_type>::value);
	static_assert(!Conjunction<std::true_type, std::false_type>::value);
	
	static_assert(!Conjunction<std::true_type, std::false_type, int>::value);

}
