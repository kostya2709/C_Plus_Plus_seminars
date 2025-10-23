#include <stdio.h>
#include <iostream>
#include <cmath>
#include "mylib.hpp"

enum class NUM_ROOTS : int {
	ZERO,
	ONE,
	TWO,
	INF
};

struct Roots {
	double first;
	double second;
	NUM_ROOTS num;
};

const double kEps = 1e-5;

bool isZero(double val) {
	return abs(val) < kEps;
}

Roots calcRoots(double a_coef, double b_coef, double c_coef) {
	if (isZero(a_coef)) {
		if (isZero(b_coef)) {
			if (isZero(c_coef)) {
				return Roots{0, 0, NUM_ROOTS::INF};
			}
			return Roots{0, 0, NUM_ROOTS::ZERO};
		}
		return Roots{-c_coef / b_coef, 0, NUM_ROOTS::ONE};
	}

	double descr = b_coef * b_coef - 4 * a_coef * c_coef;
	if (isZero(descr)) {
		double root = -b_coef / (2 * a_coef);
		return Roots{root, root, NUM_ROOTS::TWO};
	}

	if (descr < 0) {
		return Roots{0, 0 , NUM_ROOTS::ZERO};
	}

	double sqrt_descr = sqrt(descr);
	double first = (-b_coef + sqrt_descr) / (2 * a_coef);
	double second = (-b_coef - sqrt_descr) / (2 * a_coef);
	return Roots{first, second, NUM_ROOTS::TWO};
}	

int main()
{
	std::cout <<  ERROR_CODES::ELSE << '\n';
	std::cout <<  ERROR_CODES::BAD_ADRG << '\n';
	ERROR_CODES code = (ERROR_CODES)3;		
	/*
    float x_1, x_2;
    int a,b,c;
    scanf("%d %d %d", &a , &b,&c);
    float D = b*b -4 *a*c;
    if(D> 0){x_1=(-b +sqrt(D)) /2*a;x_2=(-b -sqrt(D)) /2/a;}
    printf("%d %d", x_1, x_2);
*/
	}

