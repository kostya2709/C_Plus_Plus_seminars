#include <iostream>

class ComplexNumber {
public:

    ComplexNumber(int a = 0, int b = 0) : data(new int[2]), u(data[0]), v(data[1]) {
        data[0] = a;
        data[1] = b;
    }

    ComplexNumber(const ComplexNumber& other) : ComplexNumber(other.u, other.v) { }

    ComplexNumber& operator=(const ComplexNumber& other) {
        u = other.u;
        v = other.v;
        return *this;
    }

    ComplexNumber& operator+=(const ComplexNumber& other) {
        u += other.u;
        v += other.v;
        return *this;
    }

    explicit operator bool() const {
        return u || v;
    }

    const int& operator[](size_t idx) const {
        return data[idx];
    }

    int& operator[](size_t idx) {
        return data[idx];
    }


    auto operator<=>(const ComplexNumber& rhs)const {
        
    }

    bool operator==(const ComplexNumber& rhs)const = default;

    ~ComplexNumber() {
        delete[] data;
    }

    void swap(ComplexNumber& other) {
        std::swap(u, other.u);
        std::swap(this->v, other.v);
        std::swap(data, other.data);
    }

    int* data;
    int& u;
    int& v;
};

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    ComplexNumber obj(lhs);
    obj += rhs;
    return obj;
}

// bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs) {
//     return (lhs.u == rhs.u) && (lhs.v == rhs.v);
// }

// bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs) {
//     return !(lhs == rhs);
// }

// bool operator<(const ComplexNumber& lhs, const ComplexNumber& rhs) {
//     if (lhs.u == rhs.u) {
//         return lhs.v < rhs.v;
//     }
//     return lhs.u < rhs.u;
// }

// bool operator>(const ComplexNumber& lhs, const ComplexNumber& rhs) {
//     return rhs < lhs;
// }

// bool operator>=(const ComplexNumber& lhs, const ComplexNumber& rhs) {
//     return (lhs > rhs) || (lhs == rhs);
// }


// bool operator<=(const ComplexNumber& lhs, const ComplexNumber& rhs) {
//     return (lhs < rhs) || (lhs == rhs);
// }
