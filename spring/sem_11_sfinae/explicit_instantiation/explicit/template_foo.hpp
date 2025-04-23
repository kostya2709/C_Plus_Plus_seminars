#pragma once

template <typename T>
T template_foo(T);

// Declaration of explicit instantiations (optional)
extern template float template_foo(float);
extern template int template_foo(int);

