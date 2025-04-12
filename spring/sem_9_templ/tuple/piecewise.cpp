#include <iostream>
#include <string>
#include <utility>
#include <map>
 
int main()
{
    std::map<std::string, std::string> m;
 
    m.emplace(std::make_pair("b", "abcd"));
    m.emplace("d", "ddd");
    
	m.emplace(std::piecewise_construct,
              std::forward_as_tuple("c"),
              std::forward_as_tuple(10, 'c'));
   //  an alternative is: m.try_emplace("c", 10, 'c');
 
    for (const auto& p : m)
        std::cout << p.first << " => " << p.second << '\n';
}
