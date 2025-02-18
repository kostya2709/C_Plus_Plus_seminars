#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
 
int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::list<int> list{-1, -2, -3};
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ", ")); 
    
	std::cout << '\n';
}
