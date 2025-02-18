#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
 
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::list<int> l{-1, -2, -3};
    std::copy(v.begin(), v.end(), std::next(l.begin())); 
    
	for (int n : l)
        std::cout << n << ' ';
    
	std::cout << '\n';
}
