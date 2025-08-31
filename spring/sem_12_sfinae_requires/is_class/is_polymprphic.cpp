#include <type_traits>

struct NonDynamic {};

struct Dynamic {
	virtual ~Dynamic() {}
};

struct Base {};
struct Derived : Base {};

namespace detail
{
    template<class T>
    std::true_type helper(
        decltype(dynamic_cast<const void*>(static_cast<T*>(nullptr)))
    );

    template<class T>
    std::false_type helper(...);
}
 
template<class T>
struct is_polymorphic : decltype(detail::helper<T>(nullptr)) {};


int main() {


	NonDynamic non_dynamic;
	Dynamic dynamic;
	Derived derived;

//	auto test1 = dynamic_cast<void*>(&non_dynamic);
	auto test2 = dynamic_cast<void*>(&dynamic);
	auto test3 = dynamic_cast<Base*>(&derived);

	static_assert(is_polymorphic<Dynamic>::value);
	static_assert(!is_polymorphic<NonDynamic>::value);
	static_assert(!is_polymorphic<int>::value);

}
