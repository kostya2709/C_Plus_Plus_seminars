#include <iostream>
#include <compare>

class ComplexNumber {

public:
    ComplexNumber( int u = 0, int v = 0) : data(new int[2]{u, v}), u(data[0]), v(data[1]) {}
    // ComplexNumber() = default;
    ComplexNumber( const ComplexNumber& num) : data(new int[2]{num.u, num.v}), u(data[0]), v(data[1]) {}
    
    // ComplexNumber& operator=( const ComplexNumber& num) {
    //     if (this == &num) {
    //         return *this;
    //     }
    //     // delete[] this->data;
    //     // this->data = new int[2];
    //     u = num.u;
    //     v = num.v;
    //     return *this;
    // }

    ComplexNumber& operator=( ComplexNumber num) {
        ComplexNumber::swap(*this, num);
        return *this;
    }

    ComplexNumber& operator+=(const ComplexNumber& val) {
        u += val.u;
        v += val.v;
        return *this;
    }

    // ComplexNumber operator+(ComplexNumber val) {
    //     return val += *this;
    // }

    ComplexNumber& operator++() {
        ++u;
        return *this;
    }

    ComplexNumber operator++(int) {
        ComplexNumber tmp = *this;
        ++u;
        return tmp;
    }

    
    explicit operator bool()
    {
        return u || v;
    }

    int real() const {
       return u; 
    }

    int imaginary() const {
       return v; 
    }


    ~ComplexNumber() {
        delete [] data;
    }

    int* const data = nullptr;
    int& u;
    int& v;

friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& val);

constexpr auto operator<=>(const ComplexNumber& other) const {
    if (auto cmp = u <=> other.u; cmp != 0) return cmp;
    return v <=> other.v;
}

bool operator==(const ComplexNumber& rhs) const {
    // return u == rhs.u && v == rhs.v;
    return *this <=> rhs == 0;
}

private:

    static void swap(ComplexNumber& first, ComplexNumber& second)
    {
        std::swap(first.u, second.u);
        std::swap(first.v, second.v);
    }
};

ComplexNumber operator+(ComplexNumber lhs, const ComplexNumber& rhs)
{
    lhs += rhs;
    return lhs;
}

// bool operator<(const ComplexNumber& lhs, const ComplexNumber& rhs) const {
//     if (lhs.real() == rhs.real()) {
//         return lhs.imaginary() < rhs.imaginary();
//     } else {
//         return lhs.real() < rhs.real();
//     }
// }

// bool operator>(const ComplexNumber& lhs, const ComplexNumber& rhs) const {
//     return rhs < lhs;
// }

// bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs) const {
//     return !(rhs < lhs) && !(lhs < rhs);
// }

// bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs) const {
//     return !(lhs == rhs);
// }

// bool operator<=(const ComplexNumber& lhs, const ComplexNumber& rhs) const {
//     return (lhs < rhs) || (lhs == rhs);
// }

// bool operator>=(const ComplexNumber& lhs, const ComplexNumber& rhs) const {
//     return (lhs > rhs) || (lhs == rhs);
// }

std::ostream& operator<<(std::ostream& os, const ComplexNumber& val) {
    return os << val.u << " + i * " << val.v;
}
