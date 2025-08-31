#include <string>

template <typename T, typename U>
class Pair {
public:
    T first;
    U second;

    Pair() : first(T()), second(U()) {}

    Pair(const T& a, const U& b) : first(a), second(b) {}

    Pair(const Pair& other) : first(other.first), second(other.second) {}

    template <typename V, typename W>
    Pair(const Pair<V, W>& other); // : first(other.first), second(other.second) {}

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }
};

template <typename T, typename U>
template <typename V, typename W>
Pair<T, U>::Pair(const Pair<V, W>& other) : first(other.first), second(other.second) {}


template <typename T, typename U>
Pair<T, U> make_pair(const T& a, const U& b) {
    return Pair<T, U>(a, b);
}


int main() {
    Pair<int, double> p1(1, 3.14);
    Pair<int, double> p2 = make_pair(2, 6.28);
    Pair<int, double> p3(p1);
    Pair<std::string, int> p4(std::string("example"), 42.32);
    return 0;
}

