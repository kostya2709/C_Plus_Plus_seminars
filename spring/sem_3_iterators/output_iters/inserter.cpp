#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
 
int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::list<int> list{-1, -2, -3};
    std::copy(vec.begin(), vec.end(), std::inserter(list, std::next(list.begin()))); 
    
	for (int elem : list)
        std::cout << elem << ' ';
    
	std::cout << '\n';
}
