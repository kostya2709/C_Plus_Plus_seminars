
template <int N, int D>
struct is_prime_helper {
    static const bool value = (N % D != 0) && is_prime_helper<N, D - 1>::value;
};

template <int N>
struct is_prime_helper<N, 1> {
    static const bool value = true;
};

template <int N>
struct is_prime {
    static const bool value = is_prime_helper<N, N / 2>::value;
};

template <>
struct is_prime<0> {
    static const bool value = false;
};

template <>
struct is_prime<1> {
    static const bool value = false;
};

template <>
struct is_prime<2> {
    static const bool value = true;
};

template <int N>
const bool is_prime_v = is_prime<N>::value;

int main() {
    static_assert(is_prime<2>::value, "2 is a prime number");
    static_assert(is_prime<3>::value, "3 is a prime number");
    static_assert(!is_prime<4>::value, "4 is not a prime number");
    static_assert(is_prime_v<17>, "17 is a prime number");
    return 0;
}

