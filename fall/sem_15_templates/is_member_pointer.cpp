#include <cassert>
#include <type_traits>

template<class T>
struct is_member_pointer_helper : std::false_type {};
 
template<class T, class U>
struct is_member_pointer_helper<T U::*> : std::true_type {};
 
template<class T>
struct is_member_pointer : is_member_pointer_helper<typename std::remove_cv<T>::type> {};


struct Test {
	void foo(int) {

	}
};

int main() {
	
	static_assert(is_member_pointer<void (Test::*)(int)>::value);
	static_assert(is_member_pointer<void>::value);
	
}
