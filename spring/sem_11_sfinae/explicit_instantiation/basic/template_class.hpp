#pragma once

#include <utility>


template <typename T>
class TemplateClass {
public:
    TemplateClass(T x);
    const T& getData() const noexcept;
private:
    T data_;
};

template <typename T>
TemplateClass<T>::TemplateClass(T x) : data_(std::move(x)) {}
	
template <typename T>
const T& TemplateClass<T>::getData() const noexcept {
	return data_;
}

