
// #include "template_foo.hpp"

template <typename T>
T template_foo(T x) {
    return x;
}

template float template_foo(float x);
template int template_foo(int x);

