#include <iostream>
#include <tuple>

template<typename... Ts>
struct X {
    explicit X(const Ts&... values) : values_(std::make_tuple(std::ref(values)...)) {}
    
    std::tuple<const Ts&...> values_;
};

int main() {
    int i = 42;
    auto s = std::string("universe");
    
    auto x = X<int, std::string>(i, s);
    
    std::cout << "i = " << std::get<0>(x.values_) << '\n';
    std::cout << "s = " << std::get<1>(x.values_) << '\n';
}
