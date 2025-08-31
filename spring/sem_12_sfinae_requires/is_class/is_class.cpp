#include <type_traits>


class Test1 {};

struct Test2 {};

namespace detail
{
    template<class T>
    std::true_type test(int T::*);
 
    template<class>
    std::false_type test(...);
}
 
template<class T>
struct is_class : decltype(detail::test<T>(nullptr)) {};

int main() {

	static_assert(!is_class<int>::value);
	static_assert(is_class<Test1>::value);
	static_assert(is_class<Test2>::value);

}

