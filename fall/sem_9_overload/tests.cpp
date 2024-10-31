#include "reference.hpp"
#include <cassert>
#include <iostream>
#include <sstream>

#define CHECK_VALUES(num, exp_u, exp_v) \
    if (num.u != exp_u) { printf("Line %d: " #num ".u != %d\n", __LINE__, exp_u); assert(0); } \
    if (num.v != exp_v) { printf("Line %d: " #num ".v != %d\n", __LINE__, exp_v); assert(0); }


#define CHECK_CMP(value, exp) \
    if ((value) != exp) { printf("Line %d: " #value " != %d\n", __LINE__, exp); assert(0); }

void test_default_constructor() {
    ComplexNumber num1;
    CHECK_VALUES(num1, 0, 0);

    ComplexNumber num2 = ComplexNumber();
    CHECK_VALUES(num2, 0, 0);

    ComplexNumber num3 = {};
    CHECK_VALUES(num3, 0, 0);

    ComplexNumber num4{};
    CHECK_VALUES(num4, 0, 0);
}

void test_other_constructors() {
    ComplexNumber num1(1, 2);
    CHECK_VALUES(num1, 1, 2);

    ComplexNumber num2 = ComplexNumber(3, 4);
    CHECK_VALUES(num2, 3, 4);

    ComplexNumber num3(1);
    CHECK_VALUES(num3, 1, 0);

    ComplexNumber num4 = 1;
    CHECK_VALUES(num4, 1, 0);

    ComplexNumber num5{1, 2};
    CHECK_VALUES(num5, 1, 2);
}

void test_copy_constructor() {
    ComplexNumber num6(1, 0);
    ComplexNumber num7 = num6;
    CHECK_VALUES(num7, 1, 0);
}

void test_constructors() {
    test_default_constructor();
    test_other_constructors();
    test_copy_constructor();
}

void test_assignment() {
    ComplexNumber num1(1, 2);
    ComplexNumber num2(3, 4);
    num2 = num1;
    CHECK_VALUES(num2, 1, 2);
}

void test_arithm() {
    ComplexNumber num1(1, 2);
    ComplexNumber num2(3, 4);
    CHECK_VALUES((num1 + num2), 4, 6);

    num1 += num2;
    CHECK_VALUES(num1, 4, 6);

    ComplexNumber num3 = 5 + ComplexNumber(1, 2);
    CHECK_VALUES(num3, 6, 2);

    num1 + num2 = 5;
}

void test_inc() {
    ComplexNumber num1(1, 2);
    ComplexNumber num2 = ++num1;
    CHECK_VALUES(num1, 2, 2);
    CHECK_VALUES(num2, 2, 2);

    ComplexNumber num3(1, 2);
    ComplexNumber num4 = num3++;
    CHECK_VALUES(num3, 2, 2);
    CHECK_VALUES(num4, 1, 2);    
}

void test_compare() {
    ComplexNumber num1(1, 1);
    CHECK_CMP(num1 < 2, true);

    ComplexNumber num2(1, 1);
    CHECK_CMP(num1 < num2, false);

    ComplexNumber num3(1, 2);
    CHECK_CMP(num1 < num3, true);

    ComplexNumber num4(2, 1);
    CHECK_CMP(num1 < num4, true);

    ComplexNumber num5(2, 2);
    CHECK_CMP(num1 < num5, true);

    CHECK_CMP(num1 > 0, true);
    CHECK_CMP(num2 > num1, false);
    CHECK_CMP(num3 > num1, true);
    CHECK_CMP(num4 > num1, true);
    CHECK_CMP(num5 > num1, true);

    CHECK_CMP(num1 == num2, true);
    CHECK_CMP(num1 == num3, false);
    CHECK_CMP(ComplexNumber() == 0, true);

    CHECK_CMP(num1 != num2, false);
    CHECK_CMP(num1 != num3, true);

    CHECK_CMP(num1 <= num2, true);
    CHECK_CMP(num1 <= num3, true);    
    CHECK_CMP(num3 <= num1, false); 

    CHECK_CMP(num2 >= num1, true);
    CHECK_CMP(num3 >= num1, true); 
    CHECK_CMP(num1 >= num3, false);  
 
}

void test_output() {
    std::stringstream stream_str;
    ComplexNumber num(1, 2);
    stream_str << num;
    CHECK_CMP(stream_str.str() == "1 + i * 2", true);
    CHECK_CMP(stream_str.str() == "1 + i * 3", false);
}

void test_bool() {
    ComplexNumber num(1, 2);
    ComplexNumber zero;
    CHECK_CMP(bool(num), true);
    CHECK_CMP(bool(zero), false);

    while (zero) {
        CHECK_CMP(false, true);
    }

    while (num) {
        CHECK_CMP(true, true);
        break;
    }
}

int main() {
    test_constructors();
    test_assignment();
    test_arithm();
    test_inc();
    test_compare();
    test_output();
    test_bool();
}
