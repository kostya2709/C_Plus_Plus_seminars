#include <iostream>
#include <map>

void iterate_range_based_for( const std::map<int, char>& dict) {
	
	std::cout << "iterate range based for:\n";
    for (auto elem : dict) {
        std::cout << elem.first << " " << elem.second << std::endl;
    }
	std::cout << "\n\n";
}

int main() {
    
    std::map<int, char> dict;
    dict[0] = 'a';
    dict[2] = 'c';
    dict[1] = 'b';
    
    iterate_range_based_for( dict);
}
