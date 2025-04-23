
#include "template_class.hpp"

#include <utility>

template <typename T>
TemplateClass<T>::TemplateClass(T x) : data_(std::move(x)) {}

template <typename T>
const T& TemplateClass<T>::getData() const noexcept {
    return data_;
}

template class TemplateClass<int>;
template class TemplateClass<float>;

