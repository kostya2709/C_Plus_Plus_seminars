#pragma once

template <typename T>
class TemplateClass {
public:
	TemplateClass(T x);
	const T& getData() const noexcept;
private:
	T data_;
};

// Explicit instantiation template class declarations (optional)
extern template class TemplateClass<int>;
extern template class TemplateClass<float>;

