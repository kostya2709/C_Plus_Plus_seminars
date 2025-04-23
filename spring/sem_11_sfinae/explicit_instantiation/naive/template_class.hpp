#pragma once

template <typename T>
class TemplateClass {
public:
	TemplateClass(T x);
	const T& getData() const noexcept;
private:
	T data_;
};

