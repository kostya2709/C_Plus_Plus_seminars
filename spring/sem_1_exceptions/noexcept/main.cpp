#include <iostream>

void foo() noexcept {
    throw std::invalid_argument( "really bad arg\n");
}

constexpr bool flag = true;
constexpr bool flag2 = noexcept(foo());

// void bar() noexcept(flag) {
// void bar() noexcept( foo()) {
// void bar() noexcept(noexcept(foo())) {
// void bar() throw(int) {
// }


int main() {
    static_assert(flag);
    static_assert(flag2);
    static_assert(noexcept(bar));

    try {
        foo();
    } catch ( ... ) {
        std::cout << "Caught smth!\n";
    }

}
