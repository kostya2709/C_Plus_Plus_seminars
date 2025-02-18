#include <list>
#include <iostream>
#include <type_traits>

// #include "naive.hpp"
// #include "spec.hpp"
// #include "constexpr.hpp"

using std::distance;
using std::advance;
// using naive::advance;
// using spec::advance;
// using constexpr_sol::advance;

void check_distance() {
    
    std::list<int> data = {1, 2, 3, 4, 5};
    std::list<int>::iterator iter = data.begin();
    
    advance( iter, 3);
    
    std::cout << *iter << std::endl; 
}

void check_advance() {

    std::list<int> data = {1, 2, 3, 4, 5};
    std::list<int>::iterator iter = data.begin();
    std::list<int>::iterator iter_end = data.end();

    std::cout << distance( iter, iter_end) << std::endl;
}

int main() {

    check_distance();
    check_advance();

}
