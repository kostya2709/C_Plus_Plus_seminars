#include <stdio.h>
#include <cmath>
#include <vector>
#include <iostream>

enum Solution_num {
    ZERO,
    ONE,
    TWO,
    INF
};

const double kEps = 1e-9;

bool isZero(double x) {
    return fabs(x) < kEps;
}



struct Roots {
    Solution_num roots_num;
    std::vector<double> answer;
};

Roots solve_square(const double a, const double b, const double c) {
    
    Roots result;

    if (isZero(a)) {
        if (isZero(b)) {
            if (isZero(c)) {
                result.roots_num = Solution_num::INF;
                return result;
            }
            result.roots_num = Solution_num::ZERO;
            return result;
        }
        result.roots_num = Solution_num::ONE;
        result.answer.push_back(-c / b);
        return result;
    }

    double D = b * b - 4 * a * c;
    if (isZero(D)) {
        result.roots_num = Solution_num::ONE;
        result.answer.push_back(-b / (2 * a));
        return result;
    }

    if (D > 0) {
        result.roots_num = Solution_num::TWO;
        result.answer.push_back((-b + sqrt(D)) / (2 * a));
        result.answer.push_back((-b - sqrt(D)) / (2 * a));
        return result;
    }

    result.roots_num = Solution_num::ZERO;
    return result;
}

int main()
{
    Roots answer = solve_square(1, 1, -2);
    if (answer.roots_num == Solution_num::INF) {
        std::cout << "INF\n";
    } else {
        for (int i = 0; i < answer.roots_num; ++i) {
            std::cout << answer.answer[i] << "\n";
        }
    }

    return 0;
}

