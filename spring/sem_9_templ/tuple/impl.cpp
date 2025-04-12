#include <iostream>

template <typename... Types>
struct tuple;

template <typename Head, typename... Tail>
struct tuple<Head, Tail...> {

	template <typename First, typename... Others>
	tuple(First&& head, Others&&... tail) : head_(std::forward<First>(head)), tail_(std::forward<Others>(tail)...) {
	}

private:
	Head head_;
	tuple<Tail...> tail_;

	template <size_t N, typename... Types>
	friend decltype(auto) get(tuple<Types...>& t);
};

template <>
struct tuple<> {};



template <size_t N, typename... Types>
decltype(auto) get(tuple<Types...>& t) {
	if constexpr (N == 0) {
		return t.head_;
	} else {
		return get<N - 1>(t.tail_);
	}
}


int main() {

	tuple<int, double, char> test(1, 3.1415, 'a');
	std::cout << "get<0>(test) = " << get<0>(test) << '\n';
	std::cout << "get<1>(test) = " << get<1>(test) << '\n';
	std::cout << "get<2>(test) = " << get<2>(test) << '\n';

}
